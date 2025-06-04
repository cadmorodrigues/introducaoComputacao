/* Programa para criar os 20 primeiros termos da serie :
   1   1   2   3   4   9   8   27 ... armazenando-os em uma fila
*/
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
    int a,termo1,termo2;
    f = fila_cria();
    termo1 = 1;
    termo2 = 1;
    for (a = 1;a <= 20;a++)
    {
       if (a % 2 == 1)
       {
         fila_insere(f,termo1);
         termo1 = termo1 * 2;
       }
       else
       {
         fila_insere(f,termo2);
         termo2 = termo2 * 3;
       }
    }
    printf("\n\nConteudo da  fila\n");
    fila_imprime(f);
    fila_libera(f);
    return 0;
}
