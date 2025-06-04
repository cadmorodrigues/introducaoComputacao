
#include <stdio.h>
#include <stdlib.h>

/* definicao de tipo */
struct lista
{
    double x;
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
void pilha_insere(Pilha* p, double dado)
{
  Lista* n = (Lista*)malloc(sizeof(Lista));
  n -> x = dado;
  n -> prox = p->prim;
  p->prim = n;
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
        printf("%g\n",q->x);
      else
        printf("\nPilha Vazia\n");
    printf("\n");
}

int main()
{
    Pilha* p;
    int termo,i;
    i=1;
    termo=1;
    p = pilha_cria();
     while (i<=10)
    {
      pilha_insere(p,termo);
      termo=termo*2;
      i++;
    }
    pilha_imprime(p);
    pilha_libera(p);
    printf("\n\n");
    return 0;
}
