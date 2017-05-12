#include <stdio.h>
#include <string.h>
#include "cc_misc.h"
#include "cc_dict.h"
#include "cc_tree.h"
#include "cc_gv.h"
#include "main.h"
#include "cc_ast.h"

extern char* yytext;
extern int lines;
extern void cc_dict_etapa_1_print_entrada (char *token, int line);
comp_dict_t* dict;
comp_tree_t* ASTRoot;
int dim[20];
int globalScope = 0; //zero quando global, maior que zero quando não global
unsigned long long RBSSoffset = 0;
unsigned long long FPoffset = 0;
comp_dict_t* trashDict = NULL;

int comp_get_line_number (void)
{
  return lines;
}

void yyerror (char const *mensagem)
{
  int ln = comp_get_line_number();
  fprintf (stderr, "%s\nline: %d\n", mensagem, ln);
  fprintf (stderr, "Erro linha %d - mensagem %s caractere \"%s\" \n", ln, mensagem, yytext);
}

void main_init (int argc, char **argv)
{  //implemente esta funÃ§Ã£o com rotinas de inicializaÃ§Ã£o, se necessÃ¡rio
  dict = dict_new();
  ASTRoot = tree_new();
}

void main_finalize (void)
{  //implemente esta funÃ§Ã£o com rotinas de inicializaÃ§Ã£o, se necessÃ¡rio

  codeGen(ASTRoot);
  ASTNode* raiz = (ASTNode*)ASTRoot->value;
  char* strcode = raiz->code;
  printf("%s", strcode);
  ASTDestroy(ASTRoot);
  dictDestroy((comp_dict_t*)dict);
  stackDestroy((comp_dict_t*)trashDict);
  exit(IKS_SUCCESS);
}

void comp_print_table (void)
{
  int i = 0;
  dictEntry* entry;
  for (i = 0; i < dict->size ; i++)
    {if (dict->data[i])
      {
      entry = dict->data[i]->value;
      cc_dict_etapa_2_print_entrada ((char*)dict->data[i]->key, entry->line, entry->token);
      }
    }
//cc_dict_etapa_1_print_entrada(dict->data[i]->key, dict->data[i]->value);
}

///////////////////////////////////////////////////////////////
//
//        Nome: dictDestroy
//   DescriÃ§ao: FunÃ§ao que destroi a tabela de simbolos
//
//     CriaÃ§ao: 13/10/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
void dictDestroy(comp_dict_t* dict)
{
  int i, l;
  for (i = 0, l = dict->size; i < l; ++i) {
    if (dict->data[i]) {
      dictDestroyItem(dict->data[i]);
    }
  }

  free(dict->data);
  free(dict);
}

///////////////////////////////////////////////////////////////
//
//        Nome: stackDestroy
//   DescriÃ§ao: FunÃ§ao que destroi a tabela de simbolos
//
//     CriaÃ§ao: 13/10/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
void stackDestroy(comp_dict_t* dict)
{
  int i, l;
  for (i = 0, l = dict->size; i < l; ++i) {
    if (dict->data[i]) {
      dictDestroyItem(dict->data[i]);
    }
  }
   
  if (dict->next != NULL)
  {
    stackDestroy(dict->next);
  }
  free(dict->data);
  free(dict);
}
///////////////////////////////////////////////////////////////
//
//        Nome: dictDestroyItem
//   DescriÃ§ao: FunÃ§ao que cria a estrutura de nodo da AST
//
//     CriaÃ§ao: 04/09/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
void dictDestroyItem(comp_dict_item_t* item)
{
  comp_dict_item_t *ptr;
  dictEntry* entry;
  if (item == NULL)
    return;

  ptr = item;
  while (ptr != NULL)
    {
    ptr = item->next;

    if(item->value != NULL)
      {
      entry = (dictEntry*)item->value;

      if(entry->token == SIMBOLO_LITERAL_STRING ||entry->token == SIMBOLO_IDENTIFICADOR)
        {
        free(entry->literal.cString);
        }
      free(entry);
      }

    free(item->key);
    free(item);
    item = ptr;
  }
}

///////////////////////////////////////////////////////////////
//
//        Nome: ASTNewNode
//   DescriÃ§ao: FunÃ§ao que cria a estrutura de nodo da AST
//
//     CriaÃ§ao: 04/09/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
ASTNode* ASTNewNode(int AST_TYPE , dictEntry* dEntry)
{
    ASTNode* newNode = malloc(sizeof(ASTNode));

    newNode->AST_TYPE = AST_TYPE;
    newNode->entry = dEntry;
    if(AST_TYPE == AST_IF)
      { //if sem else
        newNode->AST_TYPE = AST_IF_ELSE;
        newNode->ifSelse = true;
      }
    else
      newNode->ifSelse = false;

    return newNode;
}
///////////////////////////////////////////////////////////////
//
//        Nome: ASTNewNode
//   DescriÃ§ao: FunÃ§ao que cria a estrutura de nodo da AST
//
//     CriaÃ§ao: 04/09/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
comp_tree_t* ASTSymbolEntry(dictEntry* dEntry, int AST_TYPE)
{
    comp_tree_t* symbol_entry;
    symbol_entry = tree_make_node(NULL);

    symbol_entry->value = ASTNewNode(AST_TYPE,dEntry);

    return symbol_entry;
}
///////////////////////////////////////////////////////////////
//
//        Nome: ASTInsertNode
//   DescriÃ§ao: Insere um nodo na arvore e interliga o nodo do Graphviz
//
//     CriaÃ§ao: 17/10/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
void ASTInsertNode(comp_tree_t *tree, comp_tree_t *node)
{
  if (node != NULL && tree!=NULL)
    tree_insert_node(tree, node);
  ASTGraphvizConnect(tree, node);
}

///////////////////////////////////////////////////////////////
//
//        Nome: ASTInsertTwoNodes
//   DescriÃ§ao: Insere um dois nodos na arvore e interliga o nodo do Graphviz
//
//     CriaÃ§ao: 04/09/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
void ASTInsertTwoNodes(comp_tree_t *tree, comp_tree_t *nodeA, comp_tree_t *nodeB)
{
  if (nodeA != NULL && tree!=NULL)
    {
     tree_insert_node(tree, nodeA);
     ASTGraphvizConnect(tree, nodeA);
    }

  if (nodeB != NULL && tree!=NULL)
    {
     tree_insert_node(tree, nodeB);
     ASTGraphvizConnect(tree, nodeB);
    }
}

///////////////////////////////////////////////////////////////
//
//        Nome: ASTDestroy
//   DescriÃ§ao: Insere um nodo na arvore e interliga o nodo do Graphviz
//
//     CriaÃ§ao: 04/09/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
void ASTDestroy(comp_tree_t *tree)
{
  comp_tree_t *ptr = tree;
  do{
    if(ptr->first != NULL)
      ASTDestroy(ptr->first);

   // ASTNode* node = tree->value;
    //if (node->code != NULL)
      //free(node->code);
    
    
    //if (node->reg != NULL)
     // free(node->reg);
    
    free(tree->value);
    ptr = ptr->next;
    free(tree);
    tree = ptr;
    } while(ptr != NULL);
}
///////////////////////////////////////////////////////////////
//
//        Nome: ASTGraphvizDeclare
//   DescriÃ§ao: Declara os nodos da arvore do Graphviz
//
//     CriaÃ§ao: 04/09/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
void ASTGraphvizDeclare (const int tipo, const void *pointer, char *name)
{
    if (pointer != NULL)
      gv_declare(tipo, pointer, name);
    if (name != NULL)
      free (name);
}
///////////////////////////////////////////////////////////////
//
//        Nome: ASTGraphvizConnect
//   DescriÃ§ao: Interliga os nodos da arvore do Graphviz
//
//     CriaÃ§ao: 04/09/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
void ASTGraphvizConnect (const void *p1, const void *p2)
{
    if(p1 != NULL && p2 != NULL)
    {
     gv_connect(p1, p2);
    }
}
///////////////////////////////////////////////////////////////
//
//        Nome: ASTGetLiteral
//   DescriÃ§ao: Pega o literal da estrtura de dados e devolve como uma string
//
//     CriaÃ§ao: 04/09/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
char* ASTGetLiteral (dictEntry* dEntry)
{
  char* retorno = (char*)calloc(250,sizeof(char));
  if(dEntry != NULL)
  {

    switch (dEntry->token)
    {
      case SIMBOLO_LITERAL_INT:   sprintf (retorno,"%d" ,dEntry->literal.cInteger); break;
      case SIMBOLO_LITERAL_FLOAT: sprintf (retorno, "%.2f",dEntry->literal.cFloat); break;
      case SIMBOLO_LITERAL_CHAR:  sprintf (retorno,"%c" ,dEntry->literal.cChar); break;
      case SIMBOLO_LITERAL_STRING:
      case SIMBOLO_IDENTIFICADOR: sprintf (retorno,"%s" ,dEntry->literal.cString); break;
      case SIMBOLO_LITERAL_BOOL: if(dEntry->literal.cBoolean)
                                    {
                                    sprintf(retorno, "true");
                                    }
                                  else
                                    {
                                    sprintf(retorno, "false");
                                    }
                                  break;
    }
  }
  else
  {
    retorno = NULL ;
  }
 return (char*)retorno;
}

///////////////////////////////////////////////////////////////
//
//        Nome: setIKSType
//   Descriçao: seta o tipo do nodo
//
//     CriaÃ§ao: 17/10/2016
//  Modificada:
//
///////////////////////////////////////////////////////////////
void setIKSType(dictEntry** entry, int IKSType)
{ //printf(" setIKSType: \n");
  dictEntry* auxEntry = *entry;
  //char* str;
  //auxEntry = getEntry(dict, auxEntry);
  auxEntry->IKSType = IKSType;
  switch (IKSType){
    case IKS_INT: auxEntry->size = INT_SIZE; break;// printf("eh INT - tamanho %d\n", auxEntry->size);
    case IKS_FLOAT: auxEntry->size = FLOAT_SIZE; break; //printf("eh FLOAT - tamanho %d\n", auxEntry->size);
    case IKS_BOOL: auxEntry->size = BOOL_SIZE; break; //printf("eh BOOL - tamanho %d\n", auxEntry->size);
    case IKS_CHAR: auxEntry->size = CHAR_SIZE; break; //printf("eh CHAR - tamanho %d\n", auxEntry->size);
    case IKS_STRING:auxEntry->size = strlen(auxEntry->literal.cString);//printf("eh STRING - tamanho %d\n", entry->size);
    }
  //str = ASTGetLiteral(auxEntry);
  //printf("|%s| tamanho %d\n", str, auxEntry->size);
  //free(str);
}

///////////////////////////////////////////////////////////////
//
//        Nome: cohersionChecker
//   Descriçao: varifica a coeÃ§ao dos parametrose faz a infereinca do tipo
//
//     CriaÃ§ao: 17/10/2016  Arthur Ribeiro
//  Modificada:	 17/10/2016  Gustavo Madeira Santana
//
///////////////////////////////////////////////////////////////
int cohersionChecker(dictEntry* destiny, dictEntry* source)
{ //printf(" cohersionChecker: \n");
  dictEntry* entry;
  int destino;
  int fonte;
  int retorno;
  //char* str;

  destiny = getEntry(dict, destiny);
  destino = destiny->IKSType;
  //str = ASTGetLiteral(destiny);
  //printf("%s destino %d | ", str ,destino);
  //free(str);

  source = getEntry(dict, source);
  fonte = source->IKSType;
  //str = ASTGetLiteral(source);
  //printf("%s fonte  %d | ", str ,fonte);
  //free(str);

  switch(destino){

    case IKS_INT:
      switch(fonte){
        case IKS_INT: retorno = IKS_INT;break;
        case IKS_FLOAT: retorno = IKS_FLOAT;break;
        case IKS_BOOL: retorno = IKS_INT;break;
        case IKS_CHAR: printf("IKS_INT <- IKS_ERROR_CHAR_TO_X\n"); exit(IKS_ERROR_CHAR_TO_X);
        case IKS_STRING: printf("IKS_INT <- IKS_ERROR_STRING_TO_X\n"); exit(IKS_ERROR_STRING_TO_X);
      } break;

    case IKS_FLOAT:
      switch(fonte){
        case IKS_INT: retorno = IKS_FLOAT;break;
        case IKS_FLOAT: retorno = IKS_FLOAT;break;
        case IKS_BOOL: retorno = IKS_FLOAT;break;
        case IKS_CHAR: printf("IKS_FLOAT <- IKS_ERROR_CHAR_TO_X\n"); exit(IKS_ERROR_CHAR_TO_X);
        case IKS_STRING:printf("IKS_FLOAT <- IKS_ERROR_STRING_TO_X\n"); exit(IKS_ERROR_STRING_TO_X);
      } break;

    case IKS_BOOL:
      switch(fonte){
        case IKS_INT: retorno = IKS_INT;break;
        case IKS_FLOAT: retorno = IKS_FLOAT;break;
        case IKS_BOOL: retorno = IKS_BOOL;break;
        case IKS_CHAR: printf("IKS_BOOL <- IKS_ERROR_CHAR_TO_X\n"); exit(IKS_ERROR_CHAR_TO_X);
        case IKS_STRING:printf("IKS_BOOL <- IKS_ERROR_STRING_TO_X\n"); exit(IKS_ERROR_STRING_TO_X);
      } break;

    case IKS_CHAR:
      switch(fonte){
        case IKS_CHAR: retorno = IKS_CHAR;break;
        case IKS_INT: printf("IKS_CHAR <- IKS_INT | IKS_ERROR_WRONG_TYPE\n"); exit(IKS_ERROR_WRONG_TYPE);
        case IKS_FLOAT: printf("IKS_CHAR <- IKS_FLOAT | IKS_ERROR_WRONG_TYPE\n"); exit(IKS_ERROR_WRONG_TYPE); exit(IKS_ERROR_WRONG_TYPE);
        case IKS_STRING: printf("IKS_CHAR <- IKS_STRING | IKS_ERROR_WRONG_TYPE\n"); exit(IKS_ERROR_STRING_TO_X);
        case IKS_BOOL: printf("IKS_CHAR <- IKS_BOOL | IKS_ERROR_WRONG_TYPE\n"); exit(IKS_ERROR_WRONG_TYPE);
      } break;

    case IKS_STRING:
      switch(fonte){
        case IKS_STRING: retorno = IKS_STRING;break;
        case IKS_INT: printf("IKS_STRING <- IKS_INT | IKS_ERROR_WRONG_TYPE\n"); exit(IKS_ERROR_WRONG_TYPE);
        case IKS_FLOAT: printf("IKS_STRING <- IKS_FLOAT | IKS_ERROR_WRONG_TYPE\n"); exit(IKS_ERROR_WRONG_TYPE);
        case IKS_CHAR: printf("IKS_STRING <- IKS_CHAR | IKS_ERROR_WRONG_TYPE\n"); exit(IKS_ERROR_CHAR_TO_X);
        case IKS_BOOL: printf("IKS_STRING <- IKS_BOOL | IKS_ERROR_WRONG_TYPE\n"); exit(IKS_ERROR_WRONG_TYPE);
      } break;
  }

 //printf("restultado = %d\n", retorno );
 return retorno;
}

///////////////////////////////////////////////////////////////
//
//        Nome: cohersionCheckerN
//   Descriçao: varifica a coeçao dos parametros e faz a
//              infereinca do tipo (etradas sao inteiros)
//
//     CriaÃ§ao: 21/10/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
int cohersionCheckerINT(int destino, int fonte)
{ //printf(" cohersionCheckerINT: \a");
  int retorno;

  //printf(" destino %d | ", destino);
  //printf(" fonte  %d | ", fonte);

  switch(destino){

    case IKS_INT:
      switch(fonte){
        case IKS_INT: retorno = IKS_INT;break;
        case IKS_FLOAT: retorno = IKS_FLOAT;break;
        case IKS_BOOL: retorno = IKS_INT;break;
        case IKS_CHAR: exit(IKS_ERROR_CHAR_TO_X);
        case IKS_STRING: exit(IKS_ERROR_STRING_TO_X);
      } break;

    case IKS_FLOAT:
      switch(fonte){
        case IKS_INT: retorno = IKS_FLOAT;break;
        case IKS_FLOAT: retorno = IKS_FLOAT;break;
        case IKS_BOOL: retorno = IKS_FLOAT;break;
        case IKS_CHAR: exit(IKS_ERROR_CHAR_TO_X);
        case IKS_STRING:exit(IKS_ERROR_STRING_TO_X);
      } break;

    case IKS_BOOL:
      switch(fonte){
        case IKS_INT: retorno = IKS_INT;break;
        case IKS_FLOAT: retorno = IKS_FLOAT;break;
        case IKS_BOOL: retorno = IKS_BOOL;break;
        case IKS_CHAR: exit(IKS_ERROR_CHAR_TO_X);
        case IKS_STRING: exit(IKS_ERROR_STRING_TO_X);
      } break;

    case IKS_CHAR:
      switch(fonte){
        case IKS_CHAR: retorno = IKS_CHAR;break;
        case IKS_INT: exit(IKS_ERROR_WRONG_TYPE);
        case IKS_FLOAT: exit(IKS_ERROR_WRONG_TYPE);
        case IKS_STRING: exit(IKS_ERROR_STRING_TO_X);
        case IKS_BOOL: exit(IKS_ERROR_WRONG_TYPE);
      } break;

    case IKS_STRING:
      switch(fonte){
        case IKS_STRING: retorno = IKS_STRING;break;
        case IKS_INT: exit(IKS_ERROR_WRONG_TYPE);
        case IKS_FLOAT: exit(IKS_ERROR_WRONG_TYPE);
        case IKS_CHAR:  exit(IKS_ERROR_CHAR_TO_X);
        case IKS_BOOL:  exit(IKS_ERROR_WRONG_TYPE);
      } break;
  }

 //printf("restultado = %d\n", retorno );
 return retorno;
}

///////////////////////////////////////////////////////////////
//
//        Nome: is_number
//   Descriçao: Se for um tipo que não seja número retorna erro
//
//     Criaçao: 17/10/2016  Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
void isNumber(dictEntry* entry){
    int tipo = entry->IKSType;
    //printf("isNumber: tipo %d\n", tipo);
    switch(tipo)
    {
      case IKS_CHAR: exit(IKS_ERROR_CHAR_TO_X); break;
      case IKS_STRING: exit(IKS_ERROR_STRING_TO_X); break;
      case IKS_BOOL:
      case IKS_FLOAT: exit(IKS_ERROR_WRONG_TYPE); break;
    }
}

///////////////////////////////////////////////////////////////
//
//        Nome: declare
//   Descriçao: adiciona um a varaiavel a tabela de simbolo juntamente com seu tipo
//
//     Criaçao: 20/10/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
void declare(comp_dict_t* dict, dictEntry** entry, int IKSType){
  //printf(" declare: ");
  dictEntry* auxEntry;
  dictEntry* auxEntry2 = *entry;

  char* key = (char*)calloc(sizeof(auxEntry2->literal.cString) + 2, sizeof(char));
  sprintf(key, "%d", auxEntry2->token);
  strcpy(key+1,(char*)auxEntry2->literal.cString);
  //consulta na tabela de símbolos
  //printf("key: %s ", key);
  auxEntry = (dictEntry*)dictFind(dict, key);

  if(auxEntry->declared == true)
    {
    //printf("declare - IKS_ERROR_DECLARED\n");
    exit(IKS_ERROR_DECLARED);
    }
  else
    {
    setIKSType(&auxEntry2, IKSType);
    //printf("declarada ");
    auxEntry2->declared = true;
    if(globalScope == 0)
      {
      //puts("globalScope ");
      auxEntry2->offset = RBSSoffset;
      auxEntry2->offsetBase = auxEntry2->offset;
      RBSSoffset = RBSSoffset + auxEntry2->size;
      auxEntry2->global = true;
      //printf("%d \n",auxEntry2->size);
      }
    else
      {
      //puts("naoéglobal");
      auxEntry2->offset = FPoffset;
      auxEntry2->offsetBase = auxEntry2->offset;
      FPoffset = FPoffset + auxEntry2->size;
      auxEntry2->global = false;
      }
    }

  free(key);
  //printf("\n");
}

///////////////////////////////////////////////////////////////
//
//        Nome: declare
//   Descriçao: adiciona um a varaiavel a tabela de simbolo juntamente com seu tipo
//
//     Criaçao: 20/10/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
void declarevector(comp_dict_t* dict, dictEntry** entry, int IKSType, int nDimension, int* vector){
  //printf(" declare: ");
  dictEntry* auxEntry;
  dictEntry* auxEntry2 = *entry;

  char* key = (char*)calloc(sizeof(auxEntry2->literal.cString) + 2, sizeof(char));
  sprintf(key, "%d", auxEntry2->token);
  strcpy(key+1,(char*)auxEntry2->literal.cString);
  //consulta na tabela de símbolos
  //printf("key: %s ", key);
  auxEntry = (dictEntry*)dictFind(dict, key);

  if(auxEntry->declared == true)
    {
    //printf("declare - IKS_ERROR_DECLARED\n");
    exit(IKS_ERROR_DECLARED);
    }
  else
    {
    setIKSType(&auxEntry2, IKSType);
    //printf("declarada ");
    auxEntry2->declared = true;
    //printf("nDimension: %d\n", nDimension);
    int sizeVector = 1;
    
    auxEntry2->nDimension = nDimension;

    int i =0;
    for(i = 0; i<nDimension; i++)
      {
        auxEntry2->dimSize[i] = vector[i];
        // printf("dimsize %d: %d\n", i, auxEntry2->dimSize[i]);
        sizeVector = (sizeVector) * vector[i];
      }
    auxEntry2->size = (auxEntry2->size) * sizeVector;
    //   auxEntry2->newoff = auxEntry2->size;

        // printf("sizevec %d\n", auxEntry2->size);

    if(globalScope == 0)
      {
        //puts("globalScope ");
        auxEntry2->offset = RBSSoffset;
        auxEntry2->offsetBase = auxEntry2->offset;
        RBSSoffset = RBSSoffset + auxEntry2->size;
        auxEntry2->global = true;
        //printf("%d \n",auxEntry2->size);
      }
    else
      {
      //puts("naoéglobal");
        auxEntry2->offset = FPoffset;
        auxEntry2->offsetBase = auxEntry2->offset;
        FPoffset = FPoffset + auxEntry2->size;
        auxEntry2->global = false;
      }
    }

  free(key);
  //printf("\n");
}



///////////////////////////////////////////////////////////////
//
//        Nome: isDeclared
//   Descriçao: adiciona um a varaiavel a tabela de simbolo juntamente com seu tipo
//
//     Criaçao: 20/10/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
void isDeclared(comp_dict_t* dict, dictEntry** entry){
  //printf(" isDeclared: ");
  dictEntry* auxEntry;
  dictEntry* auxEntry2;
  auxEntry2 = *entry;

  auxEntry = (dictEntry*)getEntry(dict, auxEntry2);
  //printf("size: %d\n", auxEntry->size);
  if(auxEntry == NULL)
    {
      printf("linha %d: variavel nao declarada \"%s\"\n", auxEntry2->line, auxEntry2->literal.cString);
      exit(IKS_ERROR_UNDECLARED);
    }
  else
  {
  *entry = auxEntry;
  // printf("antes: %d \n", auxEntry2->offsetBase);
  // printf("antes: %d \n", auxEntry2->offset);
  auxEntry2->offsetBase = auxEntry->offsetBase;
  auxEntry2->offset = auxEntry->offset;
  // auxEntry2->offset = auxEntry->newoff;

  // printf("depois: %d \n", auxEntry2->offsetBase);
  // printf("depois: %d \n", auxEntry2->offset);


  //printf("variavel %s declarada \n", auxEntry2->literal.cString);
  }


}

///////////////////////////////////////////////////////////////
//
//        Nome: setDimensionV
//   Descriçao: define a dimençao do vetor declarado
//
//     Criaçao: 29/10/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
void setDimensionV (dictEntry** entry, int nDimension, int* vector)
{
   //printf("nDimension: %d\n", nDimension);
  int sizeVector = 1;
  dictEntry* AuxEntry = *entry;
  AuxEntry->nDimension = nDimension;

  int i =0;
  for(i = 0; i<nDimension; i++)
    {
      AuxEntry->dimSize[i] = vector[i];
      // printf("dimsize %d: %d\n", i, AuxEntry->dimSize[i]);
      sizeVector = (sizeVector) * vector[i];
    }
  AuxEntry->size = (AuxEntry->size) * sizeVector;
  //   AuxEntry->newoff = AuxEntry->size;

      // printf("sizevec %d\n", AuxEntry->size);

  if(globalScope == 0)
    {
      //puts("globalScope ");
      AuxEntry->offset = RBSSoffset;
      AuxEntry->offsetBase = AuxEntry->offset;
      RBSSoffset = RBSSoffset + AuxEntry->size;
      AuxEntry->global = true;
      //printf("%d \n",AuxEntry->size);
    }
    else
    {
    //puts("naoéglobal");
      AuxEntry->offset = FPoffset;
      AuxEntry->offsetBase = AuxEntry->offset;
      FPoffset = FPoffset + AuxEntry->size;
      AuxEntry->global = false;
    }
}

///////////////////////////////////////////////////////////////
//
//        Nome: dimensionSize
//   Descriçao: retorna o tamanho da dimensao o vetor
//
//     Criaçao: 29/10/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
int dimensionSize(dictEntry* entry)
{
  return entry->literal.cInteger;
}

///////////////////////////////////////////////////////////////
//
//        Nome: isASet
//   Descriçao: adiciona um a varaiavel a tabela de simbolo juntamente com seu tipo
//
//     Criaçao: 20/10/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
void isASet (dictEntry** entry, int isA)
{ //printf(" isASet: \a");
  dictEntry* auxEntry;
  auxEntry = *entry;
  //auxEntry = getEntry(dict, auxEntry);
  //char* str = ASTGetLiteral(auxEntry);
  //printf("%s ",str);
  //free(str);
  auxEntry->isA = isA;

  //printf("(%d)\n", auxEntry->isA);
}

///////////////////////////////////////////////////////////////
//
//        Nome: isACheck
//   Descriçao: adiciona um a varaiavel a tabela de simbolo juntamente com seu tipo
//
//     Criaçao: 20/10/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
void isACheck(comp_dict_t* dict ,dictEntry* entry, int isA)
{ //printf(" isACheck: ");
   char* str = ASTGetLiteral(entry);
  dictEntry* auxEntry = getEntry(dict, entry);
  if(auxEntry != NULL)
    {
    if(auxEntry->isA != isA)
      {
      switch(auxEntry->isA)
        {
        case FUNCAO: printf("IKS_ERROR_FUNCTION\n"); exit(IKS_ERROR_FUNCTION);
        case VETOR: printf("IKS_ERROR_VECTOR\n"); exit(IKS_ERROR_VECTOR);
        case VARIAVEL: printf("IKS_ERROR_VARIABLE\n"); exit(IKS_ERROR_VARIABLE);
        case LITERAL: break;
        default: printf(" isACheck: linha: %d %s = %d valor nao reconhecido\n",auxEntry->line, str, auxEntry->isA); exit(IKS_ERROR_DEBUG);
        }
      }
    else
      {
      //printf(" passou no teste (%d == %d)\n", auxEntry->isA, isA);
      }
    }
  else
  {
  printf("auxEntry == NULL - NAO DEVERIA TER PASSADO NO TESTE DE DECLAÇAO\n");
  exit(IKS_ERROR_DEBUG);
  }
  free(str);
}

///////////////////////////////////////////////////////////////
//
//        Nome: setNArgs
//   Descriçao: define numero de argumentos da funcao
//
//     Criaçao: 22/10/2016  Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////

void setNArgs(dictEntry** entry, int nArgs)
{
  dictEntry* auxEntry = *entry;
  auxEntry->nArgs = nArgs;
 // printf(" num de argumentos: %d\n", auxEntry->nArgs);
}

///////////////////////////////////////////////////////////////
//
//        Nome: setArgs
//   Descriçao: define numero de argumentos da funcao
//
//     Criaçao: 22/10/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////v
void setArgs(dictEntry** entry, int IKSType)
{ //printf(" setArgs: \n ");
  dictEntry* auxEntry = *entry;

  if(auxEntry->typeList == NULL)
    {
    auxEntry->typeList = malloc(sizeof(struct type_list));
    auxEntry->typeList2 = auxEntry->typeList;
    auxEntry->typeList->IKSType = IKSType;
    auxEntry->typeList->next = NULL;
    }
  else
  {
    auxEntry->typeList2->next = malloc(sizeof(struct type_list));
    auxEntry->typeList2 = auxEntry->typeList2->next;
    auxEntry->typeList2->IKSType = IKSType;
    auxEntry->typeList2->next = NULL;
  }
  auxEntry->nArgs++;
  //entry = &auxEntry;
  //printf("%d argumentos\n",auxEntry->nArgs);
}

///////////////////////////////////////////////////////////////
//
//        Nome: checkNArgs
//   Descriçao: verifica o numero de argumentos de uma funçao
//
//     Criaçao: 20/10/2016  Arthur Ribeiro
//  Modificada: 22/10/2016  Gustavo Madeira Santana
//
///////////////////////////////////////////////////////////////
void checkNArgs(comp_dict_t* dict, dictEntry* entry, int nArgs)
{
  //printf(" checkNArgs: ");
  dictEntry* auxEntry;

  //printf("num args: %d\n", nArgs);

  auxEntry = getEntry(dict, entry);

  if(auxEntry != NULL && auxEntry->nArgs > nArgs)
  {
    printf(" line %d: faltam argumentos. haviam %d de %d esperados\n", entry->line, nArgs, auxEntry->nArgs);
    exit(IKS_ERROR_MISSING_ARGS);
  }
  else if(auxEntry != NULL && auxEntry->nArgs < nArgs)
  {
    printf(" line %d: argumentos em excesso %d onde sao esperados %d\n", entry->line, nArgs, auxEntry->nArgs);
    exit(IKS_ERROR_EXCESS_ARGS);
  }
  else if(auxEntry != NULL && auxEntry->nArgs == nArgs)
  {
    //printf(" número de parâmetros correto. haviam %d de %d esperados\n", nArgs, auxEntry->nArgs);
  }
}

///////////////////////////////////////////////////////////////
//
//        Nome: getListArgs
//   Descriçao: pega a lista de argumentos da entry
//
//     Criaçao: 22/10/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
TList* getListArgs(dictEntry* entry)
{ entry = getEntry(dict,  entry);
  return entry->typeList;
}

///////////////////////////////////////////////////////////////
//
//        Nome: checkTypeArgs
//   Descriçao: checa os tipos dos argumentos na chamanda de funçao
//
//     Criaçao: 22/10/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
TList* checkTypeArgs(dictEntry* entry, TList* typeList)
{ //printf("checkTypeArgs: \n");
  entry = getEntry(dict,  entry);
  //printf ("%d\n",entry->IKSType);
  if(typeList != NULL)
  { //printf("%d ",typeList->IKSType);
    if(entry->IKSType == IKS_STRING || typeList->IKSType == IKS_STRING || entry->IKSType == IKS_CHAR || typeList->IKSType == IKS_CHAR)
    {
      if(entry->IKSType != typeList->IKSType)
      {
        printf("line %d: Wrong type arguments at function call\n", entry->line);
        exit(IKS_ERROR_WRONG_TYPE_ARGS);
      }
    }
    if(typeList->next != NULL)
      return (typeList->next);
    else
      return NULL;
  }
  else
    return NULL;
}

///////////////////////////////////////////////////////////////
//
//        Nome: checkReturn
//   Descriçao: verifica as entradas do sistema
//
//     Criaçao: 20/10/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
void checkReturn(dictEntry** entry, int returnType)
{ dictEntry* auxEntry = *entry;
  auxEntry = getEntry(dict,auxEntry );
  //printf(" checkReturn: typeReturn: %d typeExp %d \n", returnType, auxEntry->IKSType);
  int ncoertion = cohersionCheckerINT(returnType, auxEntry->IKSType);
  auxEntry->IKSType =ncoertion;
  //printf("tipo de retorno OK - coerçao %d ", ncoertion);
  //if(entry->type != returnType)
  //  {
  //    printf("line %d: Wrong return type\n",element->line);
  //    exit(IKS_ERROR_WRONG_PAR_RETURN);
  //  }
}

///////////////////////////////////////////////////////////////
//
//        Nome: checkInput
//   Descriçao: verifica as entradas do sistema
//
//     Criaçao: 20/10/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
void checkInput(dictEntry* entry)
{
  if(entry->isA =! VARIAVEL)
    exit(IKS_ERROR_WRONG_PAR_INPUT);
}
///////////////////////////////////////////////////////////////
//
//        Nome: checkInput
//   Descriçao: verifica as entradas do sistema
//
//     Criaçao: 20/10/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
void checkOutput(dictEntry* entry)
{
  if(entry->IKSType == IKS_CHAR)
    exit(IKS_ERROR_WRONG_PAR_OUTPUT); //parametro nao e literal string ou expressao
}

///////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
//
//        Funcoes da pilha
//
///////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
//
//        Nome: stackPush
//   Descriçao: varifica a coeÃ§ao dos parametrose faz a infereinca do tipo
//
//     CriaÃ§ao: 17/10/2016  Arthur Ribeiro - Gustavo Madeira Santana
//   Modificada:
//
///////////////////////////////////////////////////////////////
void stackPush(comp_dict_t** dict)
{ //printf(" stackPush ");
  comp_dict_t* newDict = dict_new();
  comp_dict_t* auxDict;
  comp_dict_t* auxDict2;

  auxDict = *dict;
  *dict = newDict;
  auxDict2 = *dict;
  auxDict2->next = auxDict;
  globalScope++;
  //printf("dict pushed.\n");
}

///////////////////////////////////////////////////////////////
//
//        Nome: stackPop
//   Descriçao: varifica a coeÃ§ao dos parametrose faz a infereinca do tipo
//
//     CriaÃ§ao: 17/10/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:	 18/10/2016
//
///////////////////////////////////////////////////////////////
void stackPop(comp_dict_t** dict)
{ //printf(" stackPop \n");
  comp_dict_t* auxDict = *dict;
  if(dict != NULL){
    *dict = auxDict->next;
    auxDict->next = NULL;
  }
  //printf("dict poped ");
  //dictDestroy(auxDict);
  Trash(auxDict);
  globalScope--;
  //printf("and destroyed\n");

}

void Trash(comp_dict_t* dict)
{ 
  if(trashDict == NULL)
    { 
      trashDict = dict;
    }
  else
    {
      dict->next = trashDict;
      trashDict = dict;
    }

  //printf("dict pushed.\n");
}

///////////////////////////////////////////////////////////////
//
//        Nome: dictFind
//   Descriçao: varre a hash atars de uma poicao
//
//     CriaÃ§ao: 21/10/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
dictEntry* dictFind(comp_dict_t* dict, char* key)
{
  dictEntry* retorno = NULL;
  int i;
  comp_dict_item_t* item;

  for (i = 0; i < dict->size ; i++)
  {
    item = dict->data[i];
    if(item != NULL)
      if(strcmp(item->key,key)==0)
      {
        retorno = (dictEntry*)dict->data[i]->value;
        break;
      }
  }
  return retorno;
}

///////////////////////////////////////////////////////////////
//
//        Nome: getEntry
//   Descriçao: pega uma entrada declarada na tabela de simbolos
//
//     CriaÃ§ao: 22/10/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
dictEntry* getEntry(comp_dict_t* dict, dictEntry* entry)
{
  //printf(" getEntry: ");
  dictEntry* auxEntry;
  auxEntry = entry;
  char* str;

  // caso seja um literal nao pesquisa na tabela apenas utiliza o valor NAO necessaria pesquisa!
  if (entry->token == SIMBOLO_IDENTIFICADOR)
    {
      str = ASTGetLiteral(entry);
      //puts(str);
      char* key = (char*)calloc(sizeof(str) + 2, sizeof(char));
      sprintf(key, "%d", entry->token);
      strcpy(key+1,str);
      free(str);

      //printf("key: %s ", key);
      //puts("passou");

      while(1)
        {
          auxEntry = (dictEntry*)dict_get(dict, key);
          if(auxEntry != NULL && auxEntry->declared == true)
            {
              //printf("achou\n");
              break;
            }
          else
            {
              if(dict->next != NULL)
                {
                  dict = dict->next;
                  //printf("| foi para escopo acima | ");
                }
              else
                {
                  auxEntry = NULL;
                  //printf("nao achou.\n");
                  break;
                }
            }
        }
        free(key);
    }


  return auxEntry;
}

///////////////////////////////////////////////////////////////
//
//        Nome: destroyEntry
//   Descricao: destroi uma entrada na tabela de simbolos
//
//     Criacao: 22/10/2016  Arthur Ribeiro
//  Modificada:
//
///////////////////////////////////////////////////////////////
void destroyEntry(dictEntry* entry){
   char* str;

  if(entry->token == SIMBOLO_LITERAL_STRING || entry->token == SIMBOLO_IDENTIFICADOR)
    {
      str = entry->literal.cString;
      free (str);
    }
  free(entry);
}

///////////////////////////////////////////////////////////////
//
//        Nome: getEntryKey
//   Descriçao: pega uma entrada na tabela de simbolos
//
//     CriaÃ§ao: 22/10/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
dictEntry* getEntryKey(comp_dict_t* dict, char* key)
{
  //printf(" getEntry: ");
  dictEntry* auxEntry;
  int find;

  find = 0;
  while(find != 1)
  {
    auxEntry = (dictEntry*)dictFind(dict, key);

    if(auxEntry != NULL)
      {
      find = 1;
      //printf("auxEntry %d achou\n", auxEntry->nArgs);
      }
    else
      {
      if(dict->next != NULL)
        {
        dict = dict->next;
        //puts(" foi para escopo acima ");
        }
      else
      {
        //puts("nao achou.\n");
        break;
      }
    }
  }
  return auxEntry;
}

/////////////////////////////////////////////////
//
//              codigo etapa 5
//
////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
//
//        Nome: newLabel
//   Descriçao: Cria um novo label para iloc
//
//     Criaçao: 01/11/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
void newLabel (char* dest)
{
  static int count = 0;
  char aux[10];
  sprintf(aux, "%d", count);
  strcpy(dest, "L");
  strcat(dest, aux);
  count++;
}

///////////////////////////////////////////////////////////////
//
//        Nome: newRegister
//   Descriçao: Cria um novo registrador para iloc
//
//     Criaçao: 01/11/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
void newRegister (char* dest)
{
  static int count = 0;
  char aux[10];
  sprintf(aux, "%d", count);
  strcpy(dest, "r");
  strcat(dest, aux);
  count++;
}

///////////////////////////////////////////////////////////////
//
//        Nome: codeGen
//   Descriçao: Varre a arvore recursivamente gerando codigo
//
//     Criaçao: 01/11/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
void codeGen(comp_tree_t* tree_a)
{ int i;
  comp_tree_t* son;
  if (tree_a->childnodes != 0)
    son = tree_a->first;
  for (i=0; i< tree_a->childnodes; i++)
    {
      codeGen(son);
      son = son->next;
    }
  ASTNode* auxNode;
  auxNode = tree_a->value;

  if(auxNode != NULL)
  {
    switch (auxNode->AST_TYPE)
    {
      case AST_PROGRAMA: codeProg(tree_a); break;
      case AST_FUNCAO: codeFunc(tree_a); break;
      case AST_IF_ELSE: codeIf(tree_a); break;
      case AST_DO_WHILE: codeDoWhile(tree_a); break;
      case AST_WHILE_DO: codeWhileDo(tree_a); break;
      case AST_BLOCO: codeBlock(tree_a); break;
      case AST_LITERAL: codeLit(tree_a); break;
      case AST_IDENTIFICADOR: codeIdent(tree_a); break;
      case AST_ARIM_SOMA:
      case AST_ARIM_SUBTRACAO:
      case AST_ARIM_MULTIPLICACAO:
      case AST_ARIM_DIVISAO: codeArim(tree_a); break;
      case AST_ATRIBUICAO: codeAtrib(tree_a); break;
      case AST_ARIM_INVERSAO:  codeInv(tree_a); break;
      case AST_LOGICO_E:  codeAnd(tree_a); break;
      case AST_LOGICO_OU: codeOr(tree_a); break;
      case AST_LOGICO_COMP_DIF:
      case AST_LOGICO_COMP_IGUAL:
      case AST_LOGICO_COMP_LE:
      case AST_LOGICO_COMP_GE:
      case AST_LOGICO_COMP_L:
      case AST_LOGICO_COMP_G: codeComp(tree_a); break;
      case AST_LOGICO_COMP_NEGACAO: codeNot(tree_a); break;
      case AST_VETOR_INDEXADO: codeVec(tree_a); break;
      default:
        break;
    }
  }
}

///////////////////////////////////////////////////////////////
//
//        Nome: codeLit
//   Descriçao: retorna o literal para o codigo
//
//     Criaçao: 01/11/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
void codeLit(comp_tree_t* tree_a)
{ //puts ("codeLit - IN");
  ASTNode* aux;
  aux = tree_a->value;
  dictEntry* dEntry = aux->entry;
  char* str = ASTGetLiteral(dEntry);

  newRegister(aux->reg);

  sprintf(aux->code, "loadI %s => %s \n", str, aux->reg);
  free(str);
  //puts ("codeLit - OUT");
}

///////////////////////////////////////////////////////////////
//
//        Nome: codeIdent
//   Descriçao:
//
//     Criaçao: 01/11/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
void codeIdent(comp_tree_t* tree_a)
{ //puts ("codeIdent - IN");
  ASTNode* aux;
  aux = tree_a->value;
  dictEntry* dEntry = aux->entry;

  newRegister(aux->reg);

  if(dEntry->global == true)
    sprintf(aux->code,"loadAI rbss, %llu => %s\n",dEntry->offset, aux->reg);
  else
    sprintf(aux->code,"loadAI fp, %llu => %s\n",dEntry->offset, aux->reg);

  //puts ("codeIdent - OUT");
}

///////////////////////////////////////////////////////////////
//
//        Nome: codeVec
//   Descriçao:
//
//     Criaçao: 01/11/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
void codeVec(comp_tree_t* tree_a)
{ //puts ("codeVec - IN");
  ASTNode* aux = tree_a->first->value; //identificador
  dictEntry* dEntry = aux->entry;
  ASTNode* aux2 = tree_a->value;



  comp_tree_t* tree_walker = tree_a->next; //valor numerico
  ASTNode* ast_aux = tree_walker->value;

  int d=0;
  int vec[20];
  unsigned long long offset = 0;

  newRegister(aux->reg);

  for(d=0; d < dEntry->nDimension ; d++)
  {
    vec[d] = ast_aux->entry->literal.cInteger;
    if(tree_walker->first != NULL)
    {
      tree_walker = tree_walker->first;
      ast_aux = tree_walker->value;
    }
  }
  dEntry->offset = dEntry->offsetBase;
  offset = matrixAddressCalc(dEntry,vec);
  offset += dEntry->offset;
  dEntry->offset = offset;
  if(dEntry->global == true)
    {sprintf(aux2->code,"loadAI rbss, %llu => %s\n",offset, aux->reg);    }
  else{

    sprintf(aux2->code,"loadAI fp, %llu => %s\n",offset, aux->reg);
  }
////puts(aux->code);
//puts ("codeVec - OUT");
}

///////////////////////////////////////////////////////////////
//
//        Nome: codeProg
//   Descriçao: Gera o codigo do programa
//
//     Criaçao: 01/11/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
void codeProg(comp_tree_t* tree_a)
{
  ASTNode* aux = tree_a->value;
  ASTNode* aux_son = tree_a->first->value;
  strcpy(aux->code, aux_son->code);
}

///////////////////////////////////////////////////////////////
//
//        Nome: codeFunc
//   Descriçao: Gera o codigo do programa
//
//     Criaçao: 01/11/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
void codeFunc(comp_tree_t* tree_a)
{
  ASTNode* aux = tree_a->value;
  ASTNode* aux_son;

  if(tree_a->first != NULL)
    aux_son = tree_a->first->value;
  if(aux_son != NULL)
    strcpy(aux->code, aux_son->code);
}


///////////////////////////////////////////////////////////////
//
//        Nome: codeAtrib
//   Descriçao: Gera o codigo do programa
//
//     Criaçao: 01/11/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
void codeAtrib(comp_tree_t* tree_a)
{ //puts("codeAtrib - IN");
  ASTNode* aux;
  ASTNode* aux_left;
  ASTNode* aux_right;
  ASTNode* aux_last;


  if (tree_a->first->value != NULL)
    {
      aux_left = tree_a->first->value;
      aux_right = tree_a->first->next->value;

      aux = tree_a->value;


      char* operation_string;
      operation_string = malloc(50*sizeof(char));
      if(aux_left->entry != NULL) //é identificador
        {
            if(aux_left->entry->global == true)
              { //printf("Global:\n");
                sprintf(operation_string, "storeAI %s => rbss, %llu\n", aux_right->reg, aux_left->entry->offset);
                //printf("Global: %s\n",operation_string);
              }
            else
              { //printf("Local:\n");
                sprintf(operation_string, "storeAI %s => rarp, %llu\n", aux_right->reg, aux_left->entry->offset);
                //printf("Local: %s\n",operation_string);
              }
          strcpy(aux->code, aux_right->code);
          strcat(aux->code, operation_string);
        }
      else// é vetor indexado
        {
          strcpy(aux->code, aux_right->code);
          strcat(aux->code, aux_left->code);
          //printf("\n%d\n",aux_left->AST_TYPE);
        }

      if(tree_a->childnodes == 3){
        aux_last = tree_a->last->value;
        strcat(aux->code, aux_last->code);

      }
      free (operation_string);
    }
  //puts("codeAtrib - OUT");
}

///////////////////////////////////////////////////////////////
//
//        Nome: codeIf
//   Descriçao: Gera o codigo do programa
//
//     Criaçao: 01/11/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
void codeIf(comp_tree_t* tree_a)
{ //puts("codeIf - IN");
  ASTNode* aux;
  ASTNode* aux_left;
  ASTNode* aux_right;
  ASTNode* aux_right_next;
  ASTNode* aux_last;
  aux = tree_a->value;
  aux_left = tree_a->first->value; //primeiro filho
  aux_right = tree_a->first->next->value; // segundo filho

  if(tree_a->childnodes > 2){
    aux_right_next = tree_a->first->next->next->value;
  }
  aux_last = tree_a->last->value; //ultimo filho

  char* operation_string;

  operation_string = malloc(50*sizeof(char));

  char labelTrue[10];
  char labelFalse[10];
  char labelAfter[10];



  newLabel(labelFalse);
  newLabel(labelTrue);
  newLabel(labelAfter);


  sprintf(operation_string, "cbr %s -> %s, %s\n%s: nop\n",aux_left->reg,labelTrue,labelFalse,labelTrue);

  if(tree_a->childnodes == 4) //se for if com else e não for o ultimo comando
  {
  strcpy(aux->code, aux_left->code);
  strcat(aux->code, operation_string);
  strcat(aux->code, aux_right->code);
  strcat(aux->code, "jumpI -> ");
  strcat(aux->code, labelAfter);
  strcat(aux->code, "\n");
  strcat(aux->code, labelFalse);
  strcat(aux->code, ": nop\n");
  strcat(aux->code, aux_right_next->code);
  strcat(aux->code, labelAfter);
  strcat(aux->code, ": nop\n");
  strcat(aux->code, aux_last->code);
  }
  else if(tree_a->childnodes == 3)
  {
    if(aux->ifSelse == false)
    {
      strcpy(aux->code, aux_left->code);
      strcat(aux->code, operation_string);
      strcat(aux->code, aux_right->code);
      strcat(aux->code, "jumpI -> ");
      strcat(aux->code, labelAfter);
      strcat(aux->code, "\n");
      strcat(aux->code, labelFalse);
      strcat(aux->code, ": nop\n");
      strcat(aux->code, aux_right_next->code);
      strcat(aux->code, labelAfter);
      strcat(aux->code, ": nop\n");
    }
    else
    {
      strcpy(aux->code, aux_left->code);
      strcat(aux->code, operation_string);
      strcat(aux->code, aux_right->code);
      strcat(aux->code, "jumpI -> ");
      strcat(aux->code, labelAfter);
      strcat(aux->code, "\n");
      strcat(aux->code, labelFalse);
      strcat(aux->code, ": nop\n");
      strcat(aux->code, labelAfter);
      strcat(aux->code, ": nop\n");
      strcat(aux->code, aux_last->code);
    }
  }
  else
  {
    strcpy(aux->code, aux_left->code);
    strcat(aux->code, operation_string);
    strcat(aux->code, aux_right->code);
    strcat(aux->code, "jumpI -> ");
    strcat(aux->code, labelAfter);
    strcat(aux->code, "\n");
    strcat(aux->code, labelFalse);
    strcat(aux->code, ": nop\n");
    strcat(aux->code, labelAfter);
    strcat(aux->code, ": nop\n");
  }
  free(operation_string);
  //puts("codeIf - OUT");
}

///////////////////////////////////////////////////////////////
//
//        Nome: codeArim
//   Descriçao: Gera o codigo do programa
//
//     Criaçao: 01/11/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
void codeArim(comp_tree_t* tree_a)
{
  ASTNode* aux;
  ASTNode* aux_left;
  ASTNode* aux_right;

  aux_left = tree_a->first->value;
  aux_right = tree_a->first->next->value;
  aux = tree_a->value;

  char* operation_string;
  operation_string = malloc(50*sizeof(char));

  newRegister(aux->reg);

    switch (aux->AST_TYPE)
    {
      case AST_ARIM_SOMA:
        sprintf(operation_string,"add %s, %s => %s\n", aux_left->reg, aux_right->reg, aux->reg);
        strcpy(aux->code ,aux_left->code);
        strcat(aux->code, aux_right->code);
        strcat(aux->code,operation_string);
        break;
      case AST_ARIM_SUBTRACAO:
        sprintf(operation_string,"sub %s, %s => %s\n", aux_left->reg, aux_right->reg, aux->reg);
        strcpy(aux->code ,aux_left->code);
        strcat(aux->code, aux_right->code);
        strcat(aux->code,operation_string);
        break;
      case AST_ARIM_MULTIPLICACAO:
        sprintf(operation_string,"mult %s, %s => %s\n", aux_left->reg, aux_right->reg, aux->reg);
        strcpy(aux->code ,aux_left->code);
        strcat(aux->code, aux_right->code);
        strcat(aux->code,operation_string);
        break;
      case AST_ARIM_DIVISAO:
        sprintf(operation_string,"div %s, %s => %s\n", aux_left->reg, aux_right->reg, aux->reg);
        strcpy(aux->code ,aux_left->code);
        strcat(aux->code, aux_right->code);
        strcat(aux->code,operation_string);
        break;
      }
  free(operation_string);
  /*aux = tree_a->first->value;
  if (aux->AST_TYPE == AST_IDENTIFICADOR)
    printf(aux->local);*/
}

///////////////////////////////////////////////////////////////
//
//        Nome: codeDoWhile
//   Descriçao: Gera o codigo do programa
//
//     Criaçao: 01/11/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
void codeDoWhile(comp_tree_t* tree_a)
{
  ASTNode* aux;
  ASTNode* aux_left;
  ASTNode* aux_right;
  ASTNode* aux_last;

  aux = tree_a->value;
  aux_left = tree_a->first->value;
  aux_right = tree_a->first->next->value;
  aux_last = tree_a->last->value;

  char labelStart[10];
  char labelBranch[10];

  newLabel(labelStart);
  newLabel(labelBranch);

  char* operation_string1;
  char* operation_string2;

  operation_string1 = malloc(50*sizeof(char));
  operation_string2 = malloc(50*sizeof(char));

  //Do
  sprintf(operation_string1, "%s: nop\n", labelStart);
  //While
  sprintf(operation_string2, "cbr %s -> %s, %s\n%s: nop\n",aux_right->reg,labelStart,labelBranch,labelBranch);

  strcpy(aux->code, operation_string1);
  strcat(aux->code, aux_left->code);
  strcat(aux->code, aux_right->code);


  strcat(aux->code, operation_string2);

  if(tree_a->childnodes == 3)
    strcat(aux->code, aux_last->code);

  free(operation_string1);
  free(operation_string2);
}

///////////////////////////////////////////////////////////////
//
//        Nome: codeWhileDo
//   Descriçao: Gera o codigo do programa
//
//     Criaçao: 01/11/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
void codeWhileDo(comp_tree_t* tree_a)
{
  ASTNode* aux;
  ASTNode* aux_left;
  ASTNode* aux_right;
  ASTNode* aux_last;

  aux = tree_a->value;
  aux_left = tree_a->first->value;
  aux_right = tree_a->first->next->value;
  aux_last = tree_a->last->value;

  char labelStart[10];
  char labelBranch[10];
  char labelTrue[10];

  newLabel(labelStart);
  newLabel(labelBranch);
  newLabel(labelTrue);

  char* operation_string1;
  char* operation_string2;
  char* operation_string3;
  char* operation_string4;

  operation_string1 = malloc(50*sizeof(char));
  operation_string2 = malloc(50*sizeof(char));
  operation_string3 = malloc(50*sizeof(char));
  operation_string4 = malloc(50*sizeof(char));

  //Start
  sprintf(operation_string1, "%s: nop\n", labelStart);
  //Test
  sprintf(operation_string2, "cbr %s -> %s, %s\n%s: nop\n",aux_right->reg,labelTrue,labelBranch, labelTrue);
  //Branch
  sprintf(operation_string3, "jumpI -> %s\n", labelStart);
  //End
  sprintf(operation_string4, "%s: nop\n", labelBranch);

  strcpy(aux->code, operation_string1);
  strcat(aux->code, aux_right->code);
  strcat(aux->code, operation_string2);

  strcat(aux->code, aux_left->code);

  strcat(aux->code, operation_string3);
  strcat(aux->code, operation_string4);

  if(tree_a->childnodes == 3)
    strcat(aux->code, aux_last->code);

  free (operation_string1);
  free (operation_string2);
  free (operation_string3);
  free (operation_string4);
}

///////////////////////////////////////////////////////////////
//
//        Nome: codeBlock
//   Descriçao: Gera o codigo do programa
//
//     Criaçao: 01/11/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
void codeBlock(comp_tree_t* tree_a)
{ //puts("codeBlock - IN");
  ASTNode* aux = tree_a->value;
  ASTNode* aux_son = tree_a->first->value;
  strcpy(aux->code, aux_son->code);
  //puts("codeBlock - OUT");
}

///////////////////////////////////////////////////////////////
//
//        Nome: codeInv
//   Descriçao: Gera o codigo do programa
//
//     Criaçao: 01/11/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
void codeInv(comp_tree_t* tree_a)
{
  ASTNode* aux;
  ASTNode* aux_left;
  ASTNode* aux_right;

  aux = tree_a->value;
  aux_left = tree_a->first->value;
  aux_right = tree_a->first->next->value;

  dictEntry* dEntry = aux->entry;

  newRegister(aux->reg);

  sprintf(aux->code, "rsubI %s, 0 => %s\n", aux->reg, aux->reg);

}

///////////////////////////////////////////////////////////////
//
//        Nome: codeAnd
//   Descriçao: Gera o codigo do programa
//
//     Criaçao: 01/11/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
void codeAnd(comp_tree_t* tree_a)
{
  ASTNode* aux;
  ASTNode* aux_left;
  ASTNode* aux_right;

  aux = tree_a->value;
  aux_left = tree_a->first->value;
  aux_right = tree_a->first->next->value;

  dictEntry* dEntry = aux->entry;

  newRegister(aux->reg);

  char* operation_string;
  operation_string = malloc(50*sizeof(char));

  sprintf(operation_string,"add %s, %s => %s\n", aux_left->reg, aux_right->reg, aux_left->reg);
  //sprintf(operation_string, "i2i %s => %s\ncbr %s => %s, %s\n%s: nop\n",);
  strcpy(aux->code ,aux_left->code);
  strcat(aux->code, aux_right->code);
  strcat(aux->code,operation_string);


  free(operation_string);
}

///////////////////////////////////////////////////////////////
//
//        Nome: codeOr
//   Descriçao: Gera o codigo do programa
//
//     Criaçao: 01/11/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
void codeOr(comp_tree_t* tree_a)
{
  ASTNode* aux;
  ASTNode* aux_left;
  ASTNode* aux_right;

  aux = tree_a->value;
  aux_left = tree_a->first->value;
  aux_right = tree_a->first->next->value;

  newRegister(aux->reg);

  char* operation_string;
  operation_string = malloc(50*sizeof(char));

  sprintf(operation_string,"or %s, %s => %s\n", aux_left->reg, aux_right->reg, aux_left->reg);
  //sprintf(operation_string, "i2i %s => %s\ncbr %s => %s, %s\n%s: nop\n",);
  strcpy(aux->code ,aux_left->code);
  strcat(aux->code, aux_right->code);
  strcat(aux->code,operation_string);

  free(operation_string);
}

///////////////////////////////////////////////////////////////
//
//        Nome: codeComp
//   Descriçao: Gera o codigo do programa
//
//     Criaçao: 01/11/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
void codeComp(comp_tree_t* tree_a)
{
  ASTNode* aux;
  ASTNode* aux_left;
  ASTNode* aux_right;
  ASTNode* aux_last;

  aux = tree_a->value;
  aux_left = tree_a->first->value;
  aux_right = tree_a->first->next->value;
  aux_last = tree_a->last->value;

  char* operation_string;
  operation_string = malloc(50*sizeof(char));

  newRegister(aux->reg);

  switch(aux->AST_TYPE)
  {
      break;
    case AST_LOGICO_COMP_IGUAL:
      sprintf(operation_string, "cmp_EQ %s, %s -> %s\n", aux_left->reg, aux_right->reg, aux->reg);
      break;
    case AST_LOGICO_COMP_L:
      sprintf(operation_string, "cmp_LT %s, %s -> %s\n", aux_left->reg, aux_right->reg, aux->reg);
      break;
    case AST_LOGICO_COMP_G:
      sprintf(operation_string, "cmp_GT %s, %s -> %s\n", aux_left->reg, aux_right->reg, aux->reg);
      break;
    case AST_LOGICO_COMP_LE:
      sprintf(operation_string, "cmp_LE %s, %s -> %s\n", aux_left->reg, aux_right->reg, aux->reg);
      break;
    case AST_LOGICO_COMP_GE:
      sprintf(operation_string, "cmp_GE %s, %s -> %s\n", aux_left->reg, aux_right->reg, aux->reg);
      break;
    case AST_LOGICO_COMP_DIF:
      sprintf(operation_string, "cmp_NE %s, %s -> %s\n", aux_left->reg, aux_right->reg, aux->reg);
  }

  strcpy(aux->code, aux_left->code);
  strcat(aux->code, aux_right->code);
  strcat(aux->code, operation_string);

  free(operation_string);
}

///////////////////////////////////////////////////////////////
//
//        Nome: codeNot
//   Descriçao: Gera o codigo do programa
//
//     Criaçao: 01/11/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
void codeNot(comp_tree_t* tree_a)
{
  ASTNode* aux;
  ASTNode* aux_left;

  aux = tree_a->value;
  aux_left = tree_a->first->value;

  newRegister(aux->reg);

  char* operation_string;
  operation_string = malloc(50*sizeof(char));

  sprintf(operation_string,"xorI %s, 1 => %s\n", aux_left->reg, aux->reg);
  //sprintf(operation_string, "i2i %s => %s\ncbr %s => %s, %s\n%s: nop\n",);
  strcpy(aux->code ,aux_left->code);
  strcat(aux->code,operation_string);

  free(operation_string);

}

///////////////////////////////////////////////////////////////
//
//        Nome: matrixAddressCalc
//   Descriçao: Gera o codigo do programa
//
//     Criaçao: 01/11/2016  Arthur Ribeiro - Gustavo Madeira Santana
//  Modificada:
//
///////////////////////////////////////////////////////////////
unsigned long long matrixAddressCalc(dictEntry* dEntry, int* vec)
{
  unsigned long long temp = 0;
  int i = 0;


  temp = vec[0];
  if((dEntry->nDimension) > 1)
  for(i=1; i<dEntry->nDimension; i++)
    {temp = temp * dEntry->dimSize[i] + vec[i];}

  return temp*(dEntry->size);
}





