/*
Grupo 5
Arthur Ribeiro
Gustavo Madeira Santana
Tiago Elias Steinke
*/
%{
#include <stdio.h>
#include "cc_misc.h"
#include "cc_tree.h"
#include "cc_ast.h"
extern comp_tree_t* ASTRoot;
comp_dict_t* dict;
comp_tree_t* treeAux;
comp_tree_t* treeAux2;
bool isFArgs = false;
int  nFArgs  = 0;
int  FRteurnType;
dictEntry* IDReference;
TList* ArgsListType = NULL;
int nDimension = 0; //numero de dimensoes de um vetor
int dim[20];

%}

/*
** tipo associado ao yylval
*/
%union
{
  int IKSType;
  comp_tree_t* ast;
  struct dict_entry* valor_simbolico_lexico;
}

%type<ast> programa
%type<ast> declist
%type<ast> combloco
%type<ast> comandoCV
%type<ast> comdo
%type<ast> comwhile
%type<ast> comif
%type<ast> funcao
%type<ast> funcdecl
%type<ast> Vexplist
%type<ast> comsimples
%type<ast> comdecl
%type<ast> comvar
%type<ast> initvar
%type<ast> comatr
%type<ast> comio
%type<ast> comin
%type<ast> comout
%type<ast> callfunc
%type<ast> calldecl
%type<ast> comshift
%type<ast> RBCC
%type<ast> comreturn
%type<ast> comflux
%type<ast> listcom
%type<ast> exp
%type<ast> literal
%type<ast> litnumber
%type<ast> listexp
%type<ast> folha
%type<IKSType> vartype


/*
** <tipo> TOKENS
*/
%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_BOOL
%token TK_PR_CHAR
%token TK_PR_STRING
%token TK_PR_IF
%token TK_PR_THEN
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_DO
%token TK_PR_INPUT
%token TK_PR_OUTPUT
%token TK_PR_RETURN
%token TK_PR_CONST
%token TK_PR_STATIC
%token TK_PR_FOREACH
%token TK_PR_FOR
%token TK_PR_SWITCH
%token TK_PR_CASE
%token TK_PR_BREAK
%token TK_PR_CONTINUE
%token TK_PR_CLASS
%token TK_PR_PRIVATE
%token TK_PR_PUBLIC
%token TK_PR_PROTECTED
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token TK_OC_SL
%token TK_OC_SR
%token <valor_simbolico_lexico> TK_LIT_INT
%token <valor_simbolico_lexico> TK_LIT_FLOAT
%token <valor_simbolico_lexico> TK_LIT_FALSE
%token <valor_simbolico_lexico> TK_LIT_TRUE
%token <valor_simbolico_lexico> TK_LIT_CHAR
%token <valor_simbolico_lexico> TK_LIT_STRING
%token <valor_simbolico_lexico> TK_IDENTIFICADOR
%token TOKEN_ERRO

/*
** PRECEDENCIA
*/
%left '+' '-'
%left '*' '/' '%'
%left TK_OC_NE TK_OC_EQ TK_OC_GE TK_OC_LE '<' '>'
%left TK_OC_OR TK_OC_AND
%left '!''&'
%left '(' ')'
%left '='
%right  TK_PR_THEN TK_PR_ELSE
%nonassoc ':' '[' ']' ';' ','


%start      programa

%%

// --------------- GRAMATICA DA LINGUAGEM SAGA:

programa    :   declist { ASTGraphvizDeclare(AST_PROGRAMA, ASTRoot, NULL); ASTRoot->value = ASTNewNode(AST_PROGRAMA,NULL); ASTInsertNode(ASTRoot, $1); }
            ;

declist     :   funcao declist          { $$ = $1;  ASTInsertNode($$,$2); }
            |   varglobal ';' declist   { $$ = $3; }
            |   %empty                  { $$ = NULL; }//vazio
            ;

// VARIAVEIS GLOBAIS:
// tipo nome
// int x
// (tokens): (INT|FLOAT|BOOL|CHAR|STRING|NOVO TIPO) IDENTIFICADOR

varglobal   :   newtype
            |   newvar
            ;

newvar      :   TK_PR_STATIC vardecl
            |   vardecl
            ;

vardecl     :   vartype TK_IDENTIFICADOR {  declare(dict ,(dictEntry**)&$2, $1);
                                            setIKSType((dictEntry**)&$2, $1);
                                            isASet((dictEntry**)&$2, VARIAVEL);

                                         }

            |   vartype TK_IDENTIFICADOR '[' IntList ']' { //declare(dict ,(dictEntry**)&$2, $1);
                                                           //setIKSType((dictEntry**)&$2, $1);
                                                           
                                                           if(nDimension != 0)
                                                             {
                                                               declarevector(dict, (dictEntry**)&$2, $1, nDimension, dim);
                                                               isASet((dictEntry**)&$2, VETOR);
                                                               //setDimensionV((dictEntry**)&$2, nDimension, dim);
                                                               nDimension = 0;
                                                               int i =0;
                                                               for(i = 0; i<20; i++)
                                                                 dim[20] = 0;
                                                             }
                                                         }
            ;
IntList     : TK_LIT_INT ',' IntList                     {
                                                           dim[nDimension] = dimensionSize((dictEntry*) $1); nDimension++;
                                                         }
            | TK_LIT_INT                                 {
                                                           dim[nDimension] = dimensionSize((dictEntry*) $1); nDimension++;
                                                         }
            ;

// NOVOS TIPOS:
// class name [encapsulamento tipo identificador:encapsulamento tipo identificador:...];
// class name [protected int meuint:public float meufloat:...];
// (tokens): CLASS IDENTIFICADOR [(PROTECTED|PUBLIC|PRIVATE) (INT|FLOAT|BOOL|CHAR|STRING) IDENTIFICADOR:repete];

newtype     :   newtypedecl
            ;

newtypedecl :   TK_PR_CLASS newtypevar
            ;

newtypevar  :   TK_IDENTIFICADOR '[' fields ']' { (dictEntry*)$1;}
            ;

fields      :   fieldencap vartype fieldid
            ;

fieldencap  :   TK_PR_PROTECTED
            |   TK_PR_PRIVATE
            |   TK_PR_PUBLIC
            ;

vartype     :   TK_PR_INT    {$$ = IKS_INT;}
            |   TK_PR_FLOAT  {$$ = IKS_FLOAT;}
            |   TK_PR_CHAR   {$$ = IKS_CHAR;}
            |   TK_PR_STRING {$$ = IKS_STRING;}
            |   TK_PR_BOOL   {$$ = IKS_BOOL;}
            ;

fieldid     :   TK_IDENTIFICADOR
            |   TK_IDENTIFICADOR ':' fields
            ;

// DEFINICAO DE FUNCOES: - OK
// (static)? tipo name ((const)?tipo name, tipo name, ...){ bloco de comandos; }  -NÃƒO PODE VETOR DENTRO DO ()
// int foo(int a, const float b){ int name; }
// static int bar(const chat b){}
// (STATIC)? (INT|FLOAT|BOOL|CHAR|STRING) IDENTIFICADOR ( (CONST)? (INT|FLOAT|BOOL|CHAR}STRING) IDENTIFICADOR) { bloco de comandos; }

funcao      :   TK_PR_STATIC funcdecl { $$ = $2; }
            |   funcdecl              { $$ = $1; }
            ;

funcdecl    :   vartype TK_IDENTIFICADOR { declare(dict ,(dictEntry**)&$2, $1);
                                           setIKSType((dictEntry**)&$2, $1);
                                           isASet((dictEntry**)&$2, FUNCAO);
                                           IDReference = $2;
                                           FRteurnType = $1;
                                           stackPush(&dict);

                                         }

                            '(' arg ')'  {

                                         }

                          '{'listcom'}'  { stackPop(&dict);
                                           FRteurnType = 0;
                                           $$ = tree_make_node(NULL);
                                           ASTGraphvizDeclare(AST_FUNCAO, $$,ASTGetLiteral((dictEntry*)$2));
                                           ASTInsertNode($$, $9);
                                           $$->value = ASTNewNode(AST_FUNCAO,NULL);
                                         }
            ;

arg         :   %empty  // vazio (feito dessa forma para subir a palava vazia)
            |   arglist
            ;

arglist     :   argsdecl
            |   argsdecl ',' arglist
            ;

argsdecl    :   TK_PR_CONST vartype TK_IDENTIFICADOR { setArgs((dictEntry**)&IDReference, $2);
                                                       declare(dict ,(dictEntry**)&$3, $2);
                                                       setIKSType((dictEntry**)&$3, $2);
                                                       isASet((dictEntry**)&$3, VARIAVEL);
                                                     } //add to list de args
            |   vartype TK_IDENTIFICADOR { setArgs((dictEntry**)&IDReference, $1);
                                           declare(dict ,(dictEntry**)&$2, $1);
                                           setIKSType((dictEntry**)&$2, $1);
                                           isASet((dictEntry**)&$2, VARIAVEL);
                                          } //add to list de args
            ;

// INICIO COMANDO SIMPLES
///////////////////////////////////////////////////////////////////////////////////////////////////
// COMANDOS SIMPLES :
//
// * DeclaraÃ§ao de variavel local -
// * AtribuiÃ§ao -
// * Comando de I/O -
// * Chamada de funcao -
// * Comando de Shift -
// * Comando de RBCC (retorno, breack, continue, case ) -
// * Comando de fluxo -
// * Bloco de Comandos (* Comando Vazio) -

comsimples  :   comdecl  { $$ = $1; }
            |   comatr   { $$ = $1; }
            |   comio    { $$ = $1; }
            |   callfunc { $$ = $1; }
            |   comshift { $$ = $1; }
            |   RBCC     { $$ = $1; }
            |   comflux  { $$ = $1; }
            |   combloco { $$ = $1; }
            ;

// DECLARAÃ‡AO : //nÃ£o pode vetor
// (static)? (const)? tipo nome (<= (identificador|literal))?

comdecl     :   TK_PR_STATIC comvar             { $$ = $2; }
            |   TK_PR_STATIC TK_PR_CONST comvar { $$ = $3; }
            |   TK_PR_CONST comvar              { $$ = $2; }
            |   comvar                          { $$ = $1; }
            ;
comvar      :   vartype TK_IDENTIFICADOR                   { $$ = NULL;
                                                             declare(dict ,(dictEntry**)&$2, $1);
                                                             setIKSType((dictEntry**)&$2, $1);
                                                             isASet((dictEntry**)&$2, VARIAVEL);
                                                           }
            |   vartype TK_IDENTIFICADOR '[' IntList ']'

                                                           { $$ = NULL;
                                                             if(nDimension != 0)
                                                             {
                                                               declarevector(dict, (dictEntry**)&$2, $1, nDimension, dim);
                                                               isASet((dictEntry**)&$2, VETOR);
                                                               //setDimensionV((dictEntry**)&$2, nDimension, dim);
                                                               nDimension = 0;
                                                               int i =0;
                                                               for(i = 0; i<20; i++)
                                                                 dim[20] = 0;
                                                             }
                                                            }
            ;

            |   vartype TK_IDENTIFICADOR TK_OC_LE initvar  { declare(dict ,(dictEntry**)&$2, $1);
                                                             setIKSType((dictEntry**)&$2, $1);
                                                             isASet((dictEntry**)&$2, VARIAVEL);
                                                             dictEntry* destino = (dictEntry*)$2;
                                                             dictEntry* origem = ((ASTNode*)$4->value)->entry;
                                                             int IKSType = cohersionChecker(destino, origem);
                                                             setIKSType((dictEntry**)&destino, IKSType);

                                                             $$ = tree_make_node(NULL);
                                                             treeAux = ASTSymbolEntry((dictEntry*)$2,AST_IDENTIFICADOR);
                                                             ASTGraphvizDeclare(AST_IDENTIFICADOR, treeAux, ASTGetLiteral((dictEntry*)$2));
                                                             ASTGraphvizDeclare(AST_ATRIBUICAO, $$, NULL);
                                                             $$->value = ASTNewNode(AST_ATRIBUICAO,NULL);
                                                             ASTInsertNode($$, treeAux);
                                                             ASTInsertNode($$, $4);
                                                           }
            ;

initvar     :   TK_IDENTIFICADOR    { $$ = tree_make_node(NULL);
                                      ASTGraphvizDeclare(AST_IDENTIFICADOR, $$,  ASTGetLiteral((dictEntry*)$1));
                                      $$ = ASTSymbolEntry((dictEntry*)$1,AST_IDENTIFICADOR);
                                      isDeclared(dict,(dictEntry**)&$1);
                                    }
            |   literal             { $$ = $1; }
            ;

// ATRIBUIÇAO
// identificador = expressÃ£o
// identificador[expressÃ£o] = expressÃ£o
// identificador!campo = expressÃ£o //tipos do usuÃ¡rio

comatr      :   TK_IDENTIFICADOR '=' exp                       { isDeclared(dict, (dictEntry**)&$1);
                                                                 isACheck(dict,(dictEntry*)$1, VARIAVEL);
                                                                 dictEntry* destino = (dictEntry*)$1;
                                                                 dictEntry* origem = (dictEntry*)((ASTNode*)$3->value)->entry;
                                                                 int IKSType = cohersionChecker(destino, origem);
                                                                 setIKSType((dictEntry**)&destino, IKSType);

                                                                 $$ = tree_make_node(NULL);
                                                                 treeAux = ASTSymbolEntry((dictEntry*)$1,AST_IDENTIFICADOR);
                                                                 ASTGraphvizDeclare(AST_IDENTIFICADOR, treeAux, ASTGetLiteral((dictEntry*)$1));
                                                                 ASTGraphvizDeclare(AST_ATRIBUICAO, $$, NULL);
                                                                 $$->value = ASTNewNode(AST_ATRIBUICAO,NULL);
                                                                 ASTInsertNode($$, treeAux);
                                                                 ASTInsertNode($$, $3);
                                                               }

            |   TK_IDENTIFICADOR '[' Vexplist ']' '=' exp      {
                                                                 isDeclared(dict, (dictEntry**)&$1);
                                                                 isACheck(dict,(dictEntry*)$1, VETOR);

                                                                 dictEntry* destino = (dictEntry*)$1;
                                                                 dictEntry* origem = ((ASTNode*)$6->value)->entry;
                                                                 int IKSType = cohersionChecker(destino, origem);
                                                                 setIKSType((dictEntry**)&destino, IKSType);


                                                                 $$ = tree_make_node(ASTNewNode(AST_ATRIBUICAO,NULL));
                                                                 ASTGraphvizDeclare(AST_ATRIBUICAO, $$, NULL);
                                                                 treeAux = ASTSymbolEntry((dictEntry*)$1,AST_IDENTIFICADOR);
                                                                 ASTGraphvizDeclare(AST_IDENTIFICADOR, treeAux, ASTGetLiteral((dictEntry*)$1));



                                                                 treeAux2 = tree_make_node(ASTNewNode(AST_VETOR_INDEXADO,NULL));
                                                                 ASTGraphvizDeclare(AST_VETOR_INDEXADO, treeAux2, NULL);
                                                                 ASTInsertNode(treeAux2, treeAux);
                                                                 ASTInsertNode(treeAux2, $3);

                                                                 ASTInsertNode($$, treeAux2);
                                                                 ASTInsertNode($$, $6);

                                                               }


            |   TK_IDENTIFICADOR '!' TK_IDENTIFICADOR '=' exp  { $$ = tree_make_node(NULL);
                                                                 treeAux = ASTSymbolEntry((dictEntry*)$1,AST_IDENTIFICADOR);
                                                                 ASTGraphvizDeclare(AST_IDENTIFICADOR, treeAux, ASTGetLiteral((dictEntry*)$1));
                                                                 treeAux2 = ASTSymbolEntry((dictEntry*)$3,AST_IDENTIFICADOR);
                                                                 ASTGraphvizDeclare(AST_IDENTIFICADOR, treeAux2, ASTGetLiteral((dictEntry*)$3));
                                                                 $$->value = ASTNewNode(AST_ATRIBUICAO,NULL);
                                                                 ASTGraphvizDeclare(AST_ATRIBUICAO, $$, NULL);
                                                                 ASTInsertNode($$, treeAux);
                                                                 ASTInsertNode($$, treeAux2);
                                                                 ASTInsertNode($$, $5);
                                                               } //como identificar tipo do usuÃ¡rio
            ;

// COMANDOS DE I/O:
// input expressÃ£o
// output expressÃ£o, expressÃ£o, expressÃ£o

comio       :   comin  { $$ = $1; }
            |   comout { $$ = $1; }
            ;

comin       :   TK_PR_INPUT exp        { dictEntry* input = ((ASTNode*)$2->value)->entry;
                                         isDeclared(dict, (dictEntry**)&input);
                                         checkInput(input);
                                         $$ = tree_make_node(NULL);
                                         ASTGraphvizDeclare(AST_INPUT, $$, NULL);
                                         ASTInsertNode($$, $2);
                                         $$->value = ASTNewNode(AST_INPUT,NULL);
                                       }
            ;

comout      :   TK_PR_OUTPUT listexp   { $$ = tree_make_node(NULL);
                                         ASTGraphvizDeclare(AST_OUTPUT, $$, NULL);
                                         ASTInsertNode($$, $2);
                                         $$->value = ASTNewNode(AST_OUTPUT,NULL); }
            ;


// CHAMADA DE FUNCAO
// nome_funÃ§Ã£o(expressao, expressÃ£o) possivelmente vazia

callfunc    :   TK_IDENTIFICADOR {
                                   isDeclared(dict, (dictEntry**)&$1);
                                   isACheck(dict,(dictEntry*)$1, FUNCAO);
                                   isFArgs = true;
                                   nFArgs = 0;
                                   IDReference = (dictEntry*)$1;
                                   ArgsListType = getListArgs(IDReference);
                                 }

                '(' calldecl ')' { checkNArgs(dict, IDReference, nFArgs);
                                   nFArgs = 0;
                                   isFArgs = false;
                                   $$ = tree_make_node(NULL);
                                   treeAux = ASTSymbolEntry((dictEntry*)$1,AST_IDENTIFICADOR);
                                   ASTGraphvizDeclare(AST_IDENTIFICADOR, treeAux, ASTGetLiteral((dictEntry*)$1));
                                   ASTGraphvizDeclare(AST_CHAMADA_DE_FUNCAO, $$, NULL);
                                   $$->value = ASTNewNode(AST_CHAMADA_DE_FUNCAO,(dictEntry*)$1);
                                   ASTInsertNode($$, treeAux);
                                   ASTInsertNode($$, $4);
                                 }
            ;

calldecl    :   listexp { $$ = $1; }
            |   %empty  { $$ = NULL; }
            ;

// COMANDO DE SHIFT
// identificador <<|>> numero

comshift    :   TK_IDENTIFICADOR TK_OC_SL litnumber { $$ = tree_make_node(NULL);
                                                    treeAux = ASTSymbolEntry((dictEntry*)$1,AST_IDENTIFICADOR);
                                                    ASTGraphvizDeclare(AST_IDENTIFICADOR, treeAux, ASTGetLiteral((dictEntry*)$1));
                                                    ASTGraphvizDeclare(AST_SHIFT_LEFT, $$, NULL);
                                                    $$->value = ASTNewNode(AST_SHIFT_LEFT,NULL);
                                                    ASTInsertNode($$, treeAux);
                                                    ASTInsertNode($$, $3);
                                                    }
            |   TK_IDENTIFICADOR TK_OC_SR litnumber { $$ = tree_make_node(NULL);
                                                    treeAux = ASTSymbolEntry((dictEntry*)$1,AST_IDENTIFICADOR);
                                                    ASTGraphvizDeclare(AST_IDENTIFICADOR, treeAux, ASTGetLiteral((dictEntry*)$1));
                                                    ASTGraphvizDeclare(AST_SHIFT_RIGHT, $$, NULL);
                                                    $$->value = ASTNewNode(AST_SHIFT_RIGHT,NULL);
                                                    ASTInsertNode($$, treeAux);
                                                    ASTInsertNode($$, $3);
                                                    }
            ;

///////////////////////////////////////////////////////////
//COMANDOS DE RETORNO, BREAK, CONTINUE E CASE
// Return -
// Break -
// Continue -
// Case -

RBCC        :   comreturn   { $$ = $1; }
            |   combreak    { $$ = NULL; }
            |   comcontinue { $$ = NULL; }
            |   comcase     { $$ = NULL; }
            ;

// return
comreturn   :   TK_PR_RETURN exp { dictEntry* destino = ((ASTNode*)$2->value)->entry;
                                   checkReturn((dictEntry**)&destino, FRteurnType);
                                   $$ = tree_make_node(NULL);
                                   ASTGraphvizDeclare(AST_RETURN, $$, NULL);
                                   ASTInsertNode($$, $2);
                                   $$->value = ASTNewNode(AST_RETURN,destino);
                                 }
            ;

// break
combreak    :   TK_PR_BREAK
            ;
// continue
comcontinue :   TK_PR_CONTINUE
            ;

// case literal:
comcase     :   TK_PR_CASE TK_LIT_INT ':' comsimples';' combreak
            |   TK_PR_CASE TK_LIT_INT ':' comsimples';' combreak comcase
            ;

///////////////////////////////////////////////////////////
// COMANDOS DE CONTROLE DE FLUXO
// IF com ELSE opcional -
// Foreach -
// For -
// While -
// Do -
// Do While -
// Switch (construÃ§ao de seleÃ§ao) -

comflux     :   comif     { $$ = $1; }
            |   comshitch { $$ = NULL; }
            |   comfore   { $$ = NULL; }
            |   comfor    { $$ = NULL; }
            |   comwhile  { $$ = $1; }
            |   comdo     { $$ = $1; }
            ;

// if (expressaÌƒo) then comando
// if (expressaÌƒo) then comando else comando
comif       :   TK_PR_IF exp TK_PR_THEN comsimples ';' { $$ = tree_make_node(NULL); ASTGraphvizDeclare(AST_IF_ELSE, $$, NULL); ASTInsertNode($$, $2); ASTInsertNode($$, $4); $$->value = ASTNewNode(AST_IF,NULL); }
            |   TK_PR_IF exp TK_PR_THEN comsimples ';' TK_PR_ELSE comsimples { $$ = tree_make_node(NULL); ASTGraphvizDeclare(AST_IF_ELSE, $$, NULL); ASTInsertNode($$, $2); ASTInsertNode($$, $4); ASTInsertNode($$, $7); $$->value = ASTNewNode(AST_IF_ELSE,NULL); }
            ;

// foreach (identificador: comando, comando, ...) comando
comfore     :   TK_PR_FOREACH '(' TK_IDENTIFICADOR ':' listexp ')'comsimples
            ;

// for (lista: expressaÌƒo: comando, comando, ...) comando
comfor      :   TK_PR_FOR '(' listcomfor ':' exp ':' listcomfor ')'comsimples  // verificar o que Ã© lista
            ;

listcomfor  :   listcomfor','comsimples
            |   comsimples
            ;
// while (expressaÌƒo) do comando
comwhile    :   TK_PR_WHILE '('exp')' TK_PR_DO comsimples';'    { $$ = tree_make_node(NULL); ASTGraphvizDeclare(AST_WHILE_DO, $$, NULL); ASTInsertNode($$, $3); ASTInsertNode($$, $6); $$->value = ASTNewNode(AST_WHILE_DO,NULL); }
            ;

// do comando while (expressaÌƒo)
comdo       :   TK_PR_DO comsimples ';' TK_PR_WHILE '(' exp ')'';' { $$ = tree_make_node(NULL); ASTGraphvizDeclare(AST_DO_WHILE, $$, NULL); ASTInsertNode($$, $2); ASTInsertNode($$, $6); $$->value = ASTNewNode(AST_DO_WHILE,NULL); }
            ;

// switch
comshitch   :   TK_PR_SWITCH'('exp')'comsimples
            ;

///////////////////////////////////////////////////////////
// BLOCO DE COMANDOS
//{ COMANDOS SIMPLES;COMANDOS SIMPLES;COMANDOS SIMPLES;.... | }
combloco    :  {stackPush(&dict);} '{' listcom '}' { $$ = tree_make_node(NULL);
                                                     $$->value = ASTNewNode(AST_BLOCO,NULL);
                                                     ASTGraphvizDeclare(AST_BLOCO, $$, NULL);
                                                     ASTInsertNode($$,$3);
                                                     stackPop(&dict);
                                                   }
            ;

listcom     :   comandoCV';' listcom    { if ($1 != NULL) {$$ = $1;  ASTInsertNode($$,$3);} else {$$=$3;} }
            |   comandoCV               { $$ = $1; }
            ;

comandoCV   :   comsimples  { $$ = $1; }
            |   %empty      { $$ = NULL; }
            ;

//FIM COMANDO SIMPLES

///////////////////////////////////////////////////////////////////////////////////////////////////
// EXPRESSOES ARIMETICAS E LOGICAS
// FOLHAS    : indentificador | identificador [INTEIRO|litInteiro]
// EXPRESSAO : FOLHAS | EXPRESSAO OPERADOR EXPRESSAO | (EXPRESSAO)

// expressao
exp         :   exp '+' exp          { $$ = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_ARIM_SOMA,$$, NULL);
                                       ASTInsertTwoNodes($$,$1,$3);
                                       dictEntry* destino = ((ASTNode*)$1->value)->entry;
                                       dictEntry* origem = ((ASTNode*)$3->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKSType);
                                       $$->value = ASTNewNode(AST_ARIM_SOMA, destino);
                                     }

            |   exp '-' exp          { $$ = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_ARIM_SUBTRACAO,$$, NULL);
                                       ASTInsertTwoNodes($$,$1,$3);
                                       dictEntry* destino = ((ASTNode*)$1->value)->entry;
                                       dictEntry* origem = ((ASTNode*)$3->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKSType);
                                       $$->value = ASTNewNode(AST_ARIM_SUBTRACAO, destino);
                                     }
            |   exp '*' exp          { $$ = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_ARIM_MULTIPLICACAO,$$, NULL);
                                       ASTInsertTwoNodes($$,$1,$3);
                                       dictEntry* destino = ((ASTNode*)$1->value)->entry;
                                       dictEntry* origem = ((ASTNode*)$3->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKSType);
                                       $$->value = ASTNewNode(AST_ARIM_MULTIPLICACAO, destino);
                                     }
            |   exp '/' exp          { $$ = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_ARIM_DIVISAO,$$, NULL);
                                       ASTInsertTwoNodes($$,$1,$3);
                                       dictEntry* destino = ((ASTNode*)$1->value)->entry;
                                       dictEntry* origem = ((ASTNode*)$3->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKSType);
                                       $$->value = ASTNewNode(AST_ARIM_DIVISAO, destino);
                                     }
            |   exp '%' exp          { $$ = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_ARIM_DIVISAO,$$, NULL);
                                       ASTInsertTwoNodes($$,$1,$3);
                                       dictEntry* destino = ((ASTNode*)$1->value)->entry;
                                       dictEntry* origem = ((ASTNode*)$3->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKSType);
                                       $$->value = ASTNewNode(AST_ARIM_DIVISAO, destino);
                                     }
            |   exp '<' exp          { $$ = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_LOGICO_COMP_L,$$, NULL);
                                       ASTInsertTwoNodes($$,$1,$3);
                                       dictEntry* destino = ((ASTNode*)$1->value)->entry;
                                       dictEntry* origem = ((ASTNode*)$3->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKS_BOOL);
                                       $$->value = ASTNewNode(AST_LOGICO_COMP_L, destino);
                                     }
            |   exp '>' exp          { $$ = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_LOGICO_COMP_G,$$, NULL);
                                       ASTInsertTwoNodes($$,$1,$3);
                                       dictEntry* destino = ((ASTNode*)$1->value)->entry;
                                       dictEntry* origem = ((ASTNode*)$3->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKS_BOOL);
                                       $$->value = ASTNewNode(AST_LOGICO_COMP_G, destino);
                                     }
            |   exp TK_OC_LE exp     { $$ = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_LOGICO_COMP_LE,$$, NULL);
                                       ASTInsertTwoNodes($$,$1,$3);
                                       dictEntry* destino = ((ASTNode*)$1->value)->entry;
                                       dictEntry* origem = ((ASTNode*)$3->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKS_BOOL);
                                       $$->value = ASTNewNode(AST_LOGICO_COMP_LE, destino);
                                     }
            |   exp TK_OC_GE exp     { $$ = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_LOGICO_COMP_GE,$$, NULL);
                                       ASTInsertTwoNodes($$,$1,$3);
                                       dictEntry* destino = ((ASTNode*)$1->value)->entry;
                                       dictEntry* origem = ((ASTNode*)$3->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKS_BOOL);
                                       $$->value = ASTNewNode(AST_LOGICO_COMP_GE, destino);
                                     }
            |   exp TK_OC_EQ exp     { $$ = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_LOGICO_COMP_IGUAL,$$, NULL);
                                       ASTInsertTwoNodes($$,$1,$3);
                                       dictEntry* destino = ((ASTNode*)$1->value)->entry;
                                       dictEntry* origem = ((ASTNode*)$3->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKS_BOOL);
                                       $$->value = ASTNewNode(AST_LOGICO_COMP_IGUAL,destino);
                                     }
            |   exp TK_OC_NE exp     { $$ = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_LOGICO_COMP_DIF,$$, NULL);
                                       ASTInsertTwoNodes($$,$1,$3);
                                       dictEntry* destino = ((ASTNode*)$1->value)->entry;
                                       dictEntry* origem = ((ASTNode*)$3->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKS_BOOL);
                                       $$->value = ASTNewNode(AST_LOGICO_COMP_DIF,destino);
                                     }
            |   exp TK_OC_AND exp    { $$ = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_LOGICO_E,$$, NULL);
                                       ASTInsertTwoNodes($$,$1,$3);
                                       dictEntry* destino = ((ASTNode*)$1->value)->entry;
                                       dictEntry* origem = ((ASTNode*)$3->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKS_BOOL);
                                       $$->value = ASTNewNode(AST_LOGICO_E,destino);
                                     }
            |   exp TK_OC_OR exp     { $$ = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_LOGICO_OU,$$, NULL);
                                       ASTInsertTwoNodes($$,$1,$3);
                                       dictEntry* destino = ((ASTNode*)$1->value)->entry;
                                       dictEntry* origem = ((ASTNode*)$3->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKS_BOOL);
                                       $$->value = ASTNewNode(AST_LOGICO_OU,destino);
                                     }
            |   '(' exp ')'          { $$ = $2; }
            |   '+' exp              { $$ = $2; }
            |   '-' exp              { $$ = tree_make_node(ASTNewNode(AST_ARIM_INVERSAO,NULL));
                                       ASTGraphvizDeclare(AST_ARIM_INVERSAO,$$, NULL);
                                       ASTInsertNode($$, $2);
                                     }
            |   '!' exp              { $$ = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_LOGICO_COMP_NEGACAO,$$, NULL);
                                       ASTInsertNode($$, $2);
                                       dictEntry* destino = ((ASTNode*)$2->value)->entry;
                                       if(destino->IKSType != IKS_BOOL)
                                         exit(IKS_ERROR_WRONG_TYPE);
                                       $$->value = ASTNewNode(AST_LOGICO_COMP_NEGACAO,destino);
                                     }
            |   callfunc             { $$ = $1; }
            |   folha                { $$ = $1; }
            ;


folha       :   TK_IDENTIFICADOR           { $$ = ASTSymbolEntry((dictEntry*)$1,AST_IDENTIFICADOR);
                                             ASTGraphvizDeclare(AST_IDENTIFICADOR, $$, ASTGetLiteral((dictEntry*)$1));
                                             isDeclared(dict,(dictEntry**)&$1);
                                             isACheck(dict,(dictEntry*)$1, VARIAVEL);
                                           }

            |   TK_IDENTIFICADOR '['Vexplist']' {
            	                                  isDeclared(dict,(dictEntry**)&$1);
                                                  isACheck(dict,(dictEntry*)$1, VETOR);
                                                  isNumber($3->value);
                                                  $$ = tree_make_node(ASTNewNode(AST_VETOR_INDEXADO,(dictEntry*)$1));
                                                  ASTGraphvizDeclare(AST_VETOR_INDEXADO, $$, NULL);
                                                  treeAux = ASTSymbolEntry((dictEntry*)$1,AST_IDENTIFICADOR);
                                                  ASTGraphvizDeclare(AST_IDENTIFICADOR, treeAux, ASTGetLiteral((dictEntry*)$1));
                                                  ASTInsertTwoNodes($$,treeAux,$3);
                                                }
            |   literal { $$ = $1; }
            ;

Vexplist    :   exp ',' Vexplist                               { $$ = $1;
                                                                 ASTInsertNode($$,$3);
                                                                 dictEntry* auxEntry = ((ASTNode*)$1->value)->entry;
                                                                 isNumber(auxEntry);
                                                               }
            |   exp                                            { $$ = $1;
                                                                 dictEntry* auxEntry = ((ASTNode*)$1->value)->entry;
                                                                 isNumber(auxEntry);
                                                               }
            ;

///////////////////////////////////////////////////////////////////////////////////////////////////
//lista de expressoes  (utilizada: comando out, chamada de funÃ§ao)

listexp     :    exp ',' listexp { $$ = $1;
                                   ASTInsertNode($$,$3);
                                   nFArgs++;
                                   dictEntry* expEntry = ((ASTNode*)$1->value)->entry;
                                   TList *ListTypeUpdated = checkTypeArgs(expEntry, ArgsListType);
                                   ArgsListType = ListTypeUpdated;
                                  }
            |    exp             { $$ = $1;
                                   nFArgs++;
                                   dictEntry* expEntry = ((ASTNode*)$1->value)->entry;
                                   TList *ListTypeUpdated = checkTypeArgs(expEntry, ArgsListType);
                                   ArgsListType = ListTypeUpdated;
                                  }
            ;

// numero literal (usado no shift e na expressao)
litnumber   :   TK_LIT_INT        { $$ = ASTSymbolEntry((dictEntry*)$1,AST_LITERAL);
                                    ASTGraphvizDeclare(AST_LITERAL,$$, ASTGetLiteral((dictEntry*)$1));
                                    setIKSType((dictEntry**)&$1, IKS_INT);
                                  }

            |   TK_LIT_FLOAT      { $$ = ASTSymbolEntry((dictEntry*)$1,AST_LITERAL);
                                    ASTGraphvizDeclare(AST_LITERAL,$$, ASTGetLiteral((dictEntry*)$1));
                                    setIKSType((dictEntry**)&$1, IKS_FLOAT);
                                  }
            ;

literal     :   litnumber         { $$ = $1; }
            |   TK_LIT_STRING     { $$ = ASTSymbolEntry((dictEntry*)$1,AST_LITERAL);
                                    ASTGraphvizDeclare(AST_LITERAL,$$, ASTGetLiteral((dictEntry*)$1));
                                    setIKSType((dictEntry**)&$1, IKS_STRING);
                                  }

            |   TK_LIT_CHAR       { $$ = ASTSymbolEntry((dictEntry*)$1,AST_LITERAL);
                                    ASTGraphvizDeclare(AST_LITERAL,$$, ASTGetLiteral((dictEntry*)$1));
                                    setIKSType((dictEntry**)&$1, IKS_CHAR);
                                  }

            |   TK_LIT_TRUE       { $$ = ASTSymbolEntry((dictEntry*)$1,AST_LITERAL);
                                    ASTGraphvizDeclare(AST_LITERAL,$$, ASTGetLiteral((dictEntry*)$1));
                                    setIKSType((dictEntry**)&$1, IKS_BOOL);
                                  }

            |   TK_LIT_FALSE      { $$ = ASTSymbolEntry((dictEntry*)$1,AST_LITERAL);
                                    ASTGraphvizDeclare(AST_LITERAL,$$, ASTGetLiteral((dictEntry*)$1));
                                    setIKSType((dictEntry**)&$1, IKS_BOOL);
                                  }
            ;

%%
