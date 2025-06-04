/* Programa para criar os 20 primeiros termos da serie de Fibonacci:
   1    1   2   3   5   8   ... armazenando-os em uma fila.
   Percorrer a fila somando os seus termos.
*/
#include <stdio.h>
#include <stdlib.h>
/* definicao de tipo */
struct lista
{
    int x;
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
void fila_insere(Fila* f, int dado)
{
  Lista* n = (Lista*)malloc(sizeof(Lista));
  n -> x = dado;
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
        printf("%d\t",q->x);
      else
        printf("\nFila Vazia\n");
    printf("\n");
}
void fila_soma(Fila* f)
{
    Lista* q;
    float soma;
    soma = 0;
    for (q = f->ini;q != NULL;q = q->prox)
       soma = soma + q->x;
    printf("\nSoma dos termos da serie : %f\n",soma);
    printf("\n");
}

int main()
{
    Fila* f;
    int termo1, termo2, aux, contador;
    f = fila_cria();
    termo1 = 1;
    termo2 = 1;
    for (contador = 1;contador  <= 20;contador++)
    {
       fila_insere(f,termo1);
       aux = termo1 + termo2;
       termo1 = termo2;
       termo2 = aux;
    }
    printf("\n\nConteudo da  fila\n");
    fila_imprime(f);
    fila_soma(f);
    fila_libera(f);
    return 0;
}
