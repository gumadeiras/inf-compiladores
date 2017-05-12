/*
Grupo 5
Arthur Ribeiro
Gustavo Madeira Santana
Tiago Elias Steinke
*/
%{
#include <stdio.h>
#include <stdlib.h>
#include "cc_tree.h" //funcoes da arvore
#include "parser.h"  //arquivo automaticamente gerado pelo bison
#include "cc_dict.h" //funcoes da hash
#include "cc_misc.h"
#include "main.h"

extern comp_dict_t *dict;
int lines = 1;

char* RemoveQuotes(char *key);
dictEntry* dictAdd(int tokenType ,char *lexema, int line);

%}

/*
gabriel recomendou separar o + e * da definiÃ§Ã£o de INT, FLOAT, CHAR etc
disse que vai ajudar em etapas futuras
*/

  /************ DEFINES ************/
DIGITO                    [0-9]
CARCATERE                 [A-Za-z_]
INT                       {DIGITO}+
FLOAT                     ({DIGITO}*\.{DIGITO}+|{DIGITO}+)
CHAR                      \'([^\\\']|\\.)*\'
STRING                    \"([^\\\"]|\\.)*\"
ID                        {CARCATERE}({CARCATERE}|{DIGITO})*
SINGLECOMMENT             (\/\/.*)
WHITESPACE                [ \t]
%x MULTICOMMENT

%%

  /************ PALAVRAS RESERVADAS ************/
int                       {return TK_PR_INT;}
float                     {return TK_PR_FLOAT;}
bool                      {return TK_PR_BOOL;}
char                      {return TK_PR_CHAR;}
string                    {return TK_PR_STRING;}
if                        {return TK_PR_IF;}
then                      {return TK_PR_THEN;}
else                      {return TK_PR_ELSE;}
while                     {return TK_PR_WHILE;}
do                        {return TK_PR_DO;}
input                     {return TK_PR_INPUT;}
output                    {return TK_PR_OUTPUT;}
return                    {return TK_PR_RETURN;}
const                     {return TK_PR_CONST;}
static                    {return TK_PR_STATIC;}
foreach                   {return TK_PR_FOREACH;}
for                       {return TK_PR_FOR;}
switch                    {return TK_PR_SWITCH;}
case                      {return TK_PR_CASE;}
break                     {return TK_PR_BREAK;}
continue                  {return TK_PR_CONTINUE;}
class                     {return TK_PR_CLASS;}
private                   {return TK_PR_PRIVATE;}
public                    {return TK_PR_PUBLIC;}
protected                 {return TK_PR_PROTECTED;}

  /************ OPERADORES COMPOSTOS ************/
"<="                      {return TK_OC_LE;}
">="                      {return TK_OC_GE;}
"=="                      {return TK_OC_EQ;}
"!="                      {return TK_OC_NE;}
"&&"                      {return TK_OC_AND;}
"||"                      {return TK_OC_OR;}
"<<"                      {return TK_OC_SL;}
">>"                      {return TK_OC_SR;}

  /************ CARACTERES ESPECIAIS ************/
[\,\;\:\(\)\[\]\{\}\+\-\*\/\<\>\=\!\&\$\%\#\^]  {return yytext[0];}

  /************ LITERAIS ************/
"true"                    {yylval.valor_simbolico_lexico = (dictEntry*)dictAdd(SIMBOLO_LITERAL_BOOL,   (char*)yytext, lines); return TK_LIT_TRUE;}
"false"                   {yylval.valor_simbolico_lexico = (dictEntry*)dictAdd(SIMBOLO_LITERAL_BOOL,   (char*)yytext, lines); return TK_LIT_FALSE;}
{INT}                     {yylval.valor_simbolico_lexico = (dictEntry*)dictAdd(SIMBOLO_LITERAL_INT,    (char*) yytext, lines); return TK_LIT_INT;}
{FLOAT}                   {yylval.valor_simbolico_lexico = (dictEntry*)dictAdd(SIMBOLO_LITERAL_FLOAT,  (char*)yytext, lines); return TK_LIT_FLOAT;}
{CHAR}                    {yylval.valor_simbolico_lexico = (dictEntry*)dictAdd(SIMBOLO_LITERAL_CHAR,   (char*)yytext, lines); return TK_LIT_CHAR;}
{STRING}                  {yylval.valor_simbolico_lexico = (dictEntry*)dictAdd(SIMBOLO_LITERAL_STRING, (char*)yytext, lines); return TK_LIT_STRING;}

  /************ OUTROS ************/
{ID}                      {yylval.valor_simbolico_lexico = dictAdd(SIMBOLO_IDENTIFICADOR,  (char*)yytext, lines); return TK_IDENTIFICADOR;}
{SINGLECOMMENT}

<INITIAL>{
"/*"                      BEGIN(MULTICOMMENT);
}
<MULTICOMMENT>{
"*/"                      BEGIN(INITIAL);
[^*\n]+
"*"
\n                        {lines++;}
}

\n                        {lines++;}
{WHITESPACE}
.                         {return TOKEN_ERRO;}
%%

///////////////////////////////////////////////////////////////
//
//        Nome: dictAdd
//   Descricao: FunÃ§ao que poe a estrutura de entrada na tabela de simbolos (hash)
//
//     Criacao: 07/09/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
dictEntry* dictAdd(int tokenType ,char *lexema, int line){

  dictEntry* retorno;
  dictEntry* entry;
  dictEntry* auxEntry;
  char* str;
  entry = malloc(sizeof(dictEntry));
  entry->token = tokenType;
  entry->line = line;
  entry->declared = false;
  entry->IKSType = 0;
  entry->isA = 0; //IS A VARIABLE,VECTOR,FUNCTION, setado pelo parser
  entry->size = 0;
  entry->nArgs = 0;
  entry->typeList = NULL;
  entry->typeList2= NULL;


  char* key = (char*)calloc(yyleng+2, sizeof(char));
  sprintf(key, "%d", entry->token);

  switch(tokenType)
    {
    case SIMBOLO_LITERAL_INT:     entry->literal.cInteger = atoi(lexema);
                                  strcpy(key+1,lexema);
                                  break;

    case SIMBOLO_LITERAL_FLOAT:   entry->literal.cFloat = atof(lexema);
                                  strcpy(key+1,lexema);
                                  entry->isA = LITERAL;
                                  break;

    case SIMBOLO_LITERAL_CHAR:    entry->literal.cChar = lexema[1];
                                  key[1] = entry->literal.cChar;
                                  entry->isA = LITERAL;
                                  break;

    case SIMBOLO_LITERAL_STRING:  entry->literal.cString = RemoveQuotes(lexema);
                                  strcpy(key+1,entry->literal.cString);
                                  entry->isA = LITERAL;
                                  break;

    case SIMBOLO_IDENTIFICADOR:   entry->literal.cString = (char*)calloc(yyleng+1, sizeof(char));
                                  strcpy((char*)entry->literal.cString , lexema);
                                  strcpy(key+1,lexema);
                                  break;

    case SIMBOLO_LITERAL_BOOL:   if(lexema == "true")
                                 entry->literal.cBoolean = true;
                                 else
                                 entry->literal.cBoolean = false;
                                 entry->isA = LITERAL;
                                 entry->declared = true;
                                 break;
    default: break;
    }


    auxEntry = dict_get(dict, key);
     if(auxEntry == NULL)
     {
       //printf("adicionou a tabela nao existia\n");
       dict_put(dict, key , entry);
       retorno = entry;
     }
     else
     { retorno =  auxEntry;
       auxEntry->line = line;
       destroyEntry(entry);
       //printf(" NAO adicionou JA existia\n");
     }


    //dict_debug_print(dict);
   free(key);

  return (dictEntry*) retorno;
}


///////////////////////////////////////////////////////////////
//
//        Nome: Remove Quotes
//   Descricao: FunÃ§ao que remove aspas da string
//
//     Criacao: 30/08/2016  Arthur Ribeiro
//  Modificada: 07/09/2016  Gustavo Madeira Santana (Etapa 2)
//              - adicao a tabela de simbolos tratada em outra funcao
//
///////////////////////////////////////////////////////////////
char* RemoveQuotes(char *key)
{
  int i;
  int txtSize = strlen(key)-1;
  char *tempStr = (char*) calloc (txtSize,sizeof(char*));

  for(i=1; i<txtSize; i++)
    tempStr[i-1]=key[i];


  return (tempStr);
}

