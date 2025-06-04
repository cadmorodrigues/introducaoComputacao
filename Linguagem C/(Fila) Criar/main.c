#include <stdio.h>
#include <stdlib.h>
/* definicao de tipo */
struct lista
{
    int info;
    struct lista* prox;
};

typedef struct lista Lista;

struct fila
{
    Lista* ini;
    Lista* fim;
};
typedef struct fila Fila;
/* definicao de funcoes */

Fila* fila_cria(void)
{
  Fila* f = (Fila*)malloc(sizeof(Fila));
  f-> ini = NULL;
  f-> fim = NULL;
  return f;
}
void fila_insere(Fila* f, int v)
{
  Lista* n = (Lista*)malloc(sizeof(Lista));
  n -> info = v;
  n -> prox = NULL;
  if (f->fim != NULL)
    f->fim->prox = n;
  else
    f->ini = n;
  f->fim = n;
}
int fila_vazia(Fila* f)
{
    return (f->ini == NULL);
}

int fila_retira(Fila* f)
{
    Lista* t;
    int v;
    if (fila_vazia(f))
    {
      printf("\nFila vazia\n");
      exit(1);
    }
    t = f->ini;
    v = t->info;
    f->ini = t->prox;
    if (f->ini == NULL)
      f->fim = NULL;
    free(t);
    return v;
}

void fila_libera(Fila* f)
{
    Lista* q = f->ini;
    while (q != NULL)
    {
        Lista* t = q->prox;
        free(q);
        q = t;
    }
    f = q;
}
void fila_imprime(Fila* f)
{
    Lista* q;
    if (f != NULL)
      for (q = f->ini;q != NULL;q = q->prox)
        printf("%d\t",q->info);
      else
        printf("\nFila Vazia\n");
    printf("\n");
}
int main()
{
    Fila* f;
    int op,dado;
    char resp;
    f = NULL;
    do
    {
     system("cls");
     printf("\nManipulacao de Fila \n\n");
     printf("Menu de opcoes\n\n");
     printf("1 - Cria Fila\n\n");
     printf("2 - Insere elemento na Fila\n\n");
     printf("3 - Retira elemento na Fila\n\n");
     printf("4 - Imprime a Fila\n\n");
     printf("5 - Libera a Fila\n\n");
     printf("6 - Fim\n\n");
     printf("Digite sua opcao : ");
     scanf("%d",&op);
     fflush(stdin);
     switch(op)
     {
      case 1:  if (f == NULL)
               {
                 f = fila_cria();
                 printf("\nFila criada.\n");
                 system("pause");
               }
               else
               {
                   printf("Ja existe ma fila criada. Deseja elimina-la : S(im)/N(ao) : " );
                   scanf("%c",&resp);
                   fflush(stdin);
                   if (toupper(resp) == 'S')
                     {
                        f = fila_cria();
                        printf("\nFila criada.\n");
                        system("pause");
                     }

               }
               break;
      case 2:  printf("Digite o valor a ser inserido : ");
               scanf("%d",&dado);
               fflush(stdin);
               fila_insere(f,dado);
               system("pause");
               break;
      case 3:  if (f == NULL)
               {
                 printf("\nFila vazia\n");
                 system("pause");
               }
               else
               {
                   printf("Retirando o primeiro elemento da fila.\n");
                   fila_retira(f);
                   system("pause");
               }
      break;
      case 4:  if (f == NULL)
               {
                 printf("\nFila vazia\n");
                 system("pause");
               }
               else
               {
                 printf("\nConteudo da  fila\n");
                 fila_imprime(f);
                 system("pause");
               }
               break;
      case 5:  if (f == NULL)
               {
                  printf("\nFila vazia\n");
                  system("pause");
               }
               else
               {
                   printf("Eliminando a Fila da memoria\n");
                   fila_libera(f);
                   f = fila_vazia(f);
                   system("pause");
               }
               break;
      default: break;
     }
    }
    while(op != 6);
    printf("\n");
    return 0;
}
