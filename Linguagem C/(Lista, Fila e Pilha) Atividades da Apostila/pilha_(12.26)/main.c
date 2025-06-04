#include <stdio.h>
#include <stdlib.h>

/* definicao de tipo */
struct lista
{
    float num;
    float den;
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
void pilha_insere(Pilha* p, float dado, float dado2)
{
  Lista* n = (Lista*)malloc(sizeof(Lista));
  n -> num = dado;
  n -> den = dado2;
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
        printf("%.2f/%.2f\t",q->num,q->den);
      else
        printf("\nPilha Vazia\n");
    printf("\n");
}

void pilha_soma(Pilha* p)
{
    Lista* q;
    float soma=0;

      for (q = p->prim;q != NULL;q = q->prox)
        {
        soma=soma+(q->num/q->den);
        }

    printf("\n\nSoma: %.2f \n",soma);
}

int main()
{
    Pilha* p;
    p = pilha_cria();
    float numerador,denominador,numerador1,numerador2;
    numerador1 = 38;
    numerador2 = 37;
    for(denominador = 1;denominador <= 37;denominador++)
    {
        numerador = numerador1 * numerador2;
        numerador1 --;
        numerador2 --;
        pilha_insere(p,numerador,denominador);
    }
    printf("\nConteudo da pilha:\n\n");
    pilha_imprime(p);
    pilha_soma(p);
    pilha_libera(p);
    printf("\n\n");
    return 0;
}
