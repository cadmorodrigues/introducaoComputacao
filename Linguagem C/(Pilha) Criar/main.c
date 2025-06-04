#include <stdio.h>
#include <stdlib.h>
/* definicao de tipo */
struct lista
{
    int x;
    struct lista* prox;
};

typedef struct lista Lista;

struct pilha
{
    Lista* prim;
};
typedef struct pilha Pilha;
/* definicao de funcoes */

Pilha* pilha_cria(void)
{
  Pilha* p = (Pilha*)malloc(sizeof(Pilha));
  p-> prim = NULL;
  return p;
}
void pilha_insere(Pilha* p, int dado)
{
  Lista* n = (Lista*)malloc(sizeof(Lista));
  n -> x = dado;
  n -> prox = p->prim;
  p->prim = n;
}int pilha_vazia(Pilha *p)
{
    return (p->prim == NULL);

}
void pilha_remove(Pilha* p)
{
  Lista* t;
  int v;
  if ( pilha_vazia(p) )
    {
        printf("\nPilha vazia\n");
        system("pause");
    }
    else
    {
        t = p->prim;
        v = t->x;
        p->prim = t->prox;
        free(t);
    }
}
int pilha_libera(Pilha* p)
{
    Lista* q = p->prim;
    while (q != NULL)
    {
        Lista* t = q->prox;
        free(q);
        q = t;
    }
    free(p);

}
void pilha_imprime(Pilha* p)
{
    Lista* q;
    if (p != NULL)
      for (q = p->prim;q != NULL;q = q->prox)
        printf("%d\t",q->x);
      else
        printf("\nPilha Vazia\n");
    printf("\n");
}

int main()
{
    Pilha* p;
    int op,dado;
    char resp;
    p = NULL;
    do
    {
     system("cls");
     printf("\nManipulacao de pilha\n\n");
     printf("Menu de opcoes\n\n");
     printf("1 - Cria pilha\n\n");
     printf("2 - Insere elemento na pilha\n\n");
     printf("3 - Imprime a pilha\n\n");
     printf("4 - Retira elemento da pilha\n\n");
     printf("5 - Libera a pilha\n\n");
     printf("6 - Fim\n\n");
     printf("Digite sua opcao : ");
     scanf("%d",&op);
     fflush(stdin);
     switch(op)
     {
         case 1: if (p != NULL)
                 {

                   printf("Existe uma pilha ja criada.Deseja criar outra ?  S/N : ");
                   scanf("%c",&resp);
                   fflush(stdin);
                   if( toupper(resp) != 'N')
                   {
                     p = pilha_cria();
                     printf("\nPilha criada\n");
                     system("pause");
                   }
                 }
                 else
                 {
                   p = pilha_cria();
                     printf("Pilha criada\n");
                     system("pause");
                     fflush(stdin);
                 }
         break;
         case 2: if (p != NULL)
                 {
                     printf("Digite o valor a ser inserido :");
                     scanf("%d",&dado);
                     pilha_insere(p,dado);
                     fflush(stdin);
                 }
                 else
                 printf("\n Crie a pilha antes de inserir elemento\n");
                 system("pause");
                 break;
         case 3: if (p == NULL)
                   {
                       printf("\nPilha vazia\n");
                       system("pause");
                   }
                   else
                     {
                       printf("\nConteudo da pilha\n");
                       pilha_imprime(p);
                       system("pause");
                     }

         break;
         case 4: if (p != NULL)
                  {
                     printf("Removendo o valor do topo da pilha.\n");
                     fflush(stdin);
                     pilha_remove(p);
                  }
                  else
                    printf("\nPilha vazia\n");
                  system("pause");
                  break;
         case 5:if ( p != NULL)
                {
                  printf("Eliminando a pilha da memoria\n");
                  pilha_libera(p);
                  p = NULL;
                  system("pause");
                }
                else
                printf("\nPilha Vazia\n");
         break;
         default : break;
     }
    }
    while(op != 6);
    printf("\n");
    return 0;
}
