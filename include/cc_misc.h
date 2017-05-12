#ifndef __MISC_H
#define __MISC_H
#include <stdio.h>
#include <stdlib.h>
#include "cc_dict.h"
#include "cc_tree.h"
#include "cc_gv.h"

/*
** Definições da etapa 4
*/

#define VARIAVEL 100
#define VETOR    101
#define FUNCAO   102
#define LITERAL  103


#define INT_SIZE 4
#define FLOAT_SIZE 8
#define BOOL_SIZE 1
#define CHAR_SIZE 1

#define IKS_INT 1
#define IKS_FLOAT 2
#define IKS_CHAR 3
#define IKS_STRING 4
#define IKS_BOOL 5
#define IKS_SUCCESS 0 //caso nÃ£o houver nenhum tipo de erro
/* VerificaÃ§Ã£o de declaraÃ§Ãµes */
#define IKS_ERROR_UNDECLARED 1 //identificador nÃ£o declarado
#define IKS_ERROR_DECLARED 2 //identificador jÃ¡ declarado
/* Uso correto de identificadores */
#define IKS_ERROR_VARIABLE 3 //identificador deve ser utilizado como variÃ¡vel
#define IKS_ERROR_VECTOR 4 //identificador deve ser utilizado como vetor
#define IKS_ERROR_FUNCTION 5 //identificador deve ser utilizado como funÃ§Ã£o
/* Tipos e tamanho de dados */
#define IKS_ERROR_WRONG_TYPE 6 //tipos incompatÃ­veis
#define IKS_ERROR_STRING_TO_X 7 //coerÃ§Ã£o impossÃ­vel do tipo string
#define IKS_ERROR_CHAR_TO_X 8 //coerÃ§Ã£o impossÃ­vel do tipo char
/* Argumentos e parÃ¢metros */
#define IKS_ERROR_MISSING_ARGS 9 //faltam argumentos
#define IKS_ERROR_EXCESS_ARGS 10 //sobram argumentos
#define IKS_ERROR_WRONG_TYPE_ARGS 11 //argumentos incompatÃ­veis
/* VerificaÃ§Ã£o de tipos em comandos */
#define IKS_ERROR_WRONG_PAR_INPUT 12 //parÃ¢metro nÃ£o Ã© identificador
#define IKS_ERROR_WRONG_PAR_OUTPUT 13 //parÃ¢metro nÃ£o Ã© literal string ou expressÃ£o
#define IKS_ERROR_WRONG_PAR_RETURN 14 //parÃ¢metro nÃ£o Ã© expressÃ£o

#define IKS_ERROR_DEBUG -1

//compatÃ­vel com tipo do retorno

int getLineNumber (void);
void yyerror (char const *mensagem);
void main_init (int argc, char **argv);
void main_finalize (void);

typedef enum
{
  true,
  false
} bool;

typedef union entry_value
{
  bool  cBoolean;
  int   cInteger;
  float cFloat;
  char  cChar;
  char* cString;
} entryValue;

typedef struct type_list
{
  int IKSType;
  struct type_list* next;
} TList;

typedef struct dict_entry
{
  int line;
  int token;
  bool declared;
  int IKSType;
  int isA; //IS A VARIABLE,VECTOR,FUNCTION, setado pelo parser
  int size;
  int nArgs;
  TList* typeList;
  TList* typeList2;
  entryValue literal;

  unsigned long long newoff;

  int dimSize[20];
  int nDimension;
  int dimCall[20];
  bool global;
  unsigned long long offsetBase;
  unsigned long long offset;

} dictEntry;

typedef struct ast_node
{
  char code[100000];
  char reg[10];
  bool ifSelse;
  int AST_TYPE;
  dictEntry* entry;
} ASTNode;

void comp_print_table (void);
int comp_get_line_number (void);
void dictDestroy(comp_dict_t* dict);
void stackDestroy(comp_dict_t* dict);
void dictDestroyItem(comp_dict_item_t* item);
void Trash(comp_dict_t* dict);
/*
** Funcoes da etapa 3
*/
ASTNode* ASTNewNode(int AST_TYPE , dictEntry* dEntry);
void ASTDestroy(comp_tree_t *tree);
comp_tree_t* ASTSymbolEntry(dictEntry* dEntry, int AST_TYPE);
void ASTInsertNode(comp_tree_t *tree, comp_tree_t *node);
void ASTInsertTwoNodes(comp_tree_t *tree, comp_tree_t *nodeA, comp_tree_t *nodeB);
void ASTGraphvizDeclare (const int tipo, const void *pointer, char *name);
void ASTGraphvizConnect (const void *p1, const void *p2);
char* ASTGetLiteral (dictEntry* dEntry);

/*
** Funcoes da etapa 4
*/
void stackPush(comp_dict_t** dict);
void stackPop(comp_dict_t** dict);

void setIKSType(dictEntry** entry, int IKSType);
int cohersionChecker(dictEntry* destiny, dictEntry* source);
int cohersionCheckerINT(int destino, int fonte);
void isDeclared(comp_dict_t* dict, dictEntry** entry);

void declare(comp_dict_t* dict, dictEntry** entry, int IKSType);
void declarevector(comp_dict_t* dict, dictEntry** entry, int IKSType, int nDimension, int* vector);

void isASet (dictEntry** entry, int isA);
void isACheck(comp_dict_t* dict ,dictEntry* entry, int isA);
void isNumber(dictEntry* entry);
void setArgs(dictEntry** entry, int IKSType);
void checkNArgs(comp_dict_t* dict, dictEntry* entry, int nArgs);
TList* getListArgs(dictEntry* entry);
TList* checkTypeArgs(dictEntry* entry, TList* typeList);

void checkOutput(dictEntry* entry);
void checkInput(dictEntry* entry);
void checkReturn(dictEntry** entry, int returnType);


dictEntry* dictFind(comp_dict_t* dict, char* key);
dictEntry* getEntry(comp_dict_t* dict, dictEntry* entry);
dictEntry* getEntryKey(comp_dict_t* dict, char* key);
void destroyEntry(dictEntry* entry);

/*
** Funcoes da etapa 5
*/

void setDimensionV (dictEntry** entry, int nDimension, int* vector);
int dimensionSize(dictEntry* entry);

void newLabel (char* dest);
void newRegister (char* dest);
void codeGen(comp_tree_t* tree_a);
void codeLit(comp_tree_t* tree_a);
void codeIdent(comp_tree_t* tree_a);
void codeVec(comp_tree_t* tree_a);
void codeProg(comp_tree_t* tree_a);
void codeFunc(comp_tree_t* tree_a);
void codeAtrib(comp_tree_t* tree_a);
void codeIf(comp_tree_t* tree_a);
void codeArim(comp_tree_t* tree_a);
void codeDoWhile(comp_tree_t* tree_a);
void codeWhileDo(comp_tree_t* tree_a);
void codeBlock(comp_tree_t* tree_a);
void codeInv(comp_tree_t* tree_a);
void codeAnd(comp_tree_t* tree_a);
void codeOr(comp_tree_t* tree_a);
void codeComp(comp_tree_t* tree_a);
void codeNot(comp_tree_t* tree_a);
unsigned long long matrixAddressCalc(dictEntry* dEntry, int* vec);




#endif
