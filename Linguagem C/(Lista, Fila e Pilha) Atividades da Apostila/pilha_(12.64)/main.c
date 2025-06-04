#include <stdio.h>
#include <stdlib.h>

/* definicao de tipo */
struct lista
{
    float num;
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
void pilha_insere(Pilha* p, float dado)
{
  Lista* n = (Lista*)malloc(sizeof(Lista));
  n -> num = dado;
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
        printf("%.2f\n",q->num);
      else
        printf("\nPilha Vazia\n");
    printf("\n");
}

int main()
{
    Pilha* p;
    int numero, divisor, soma_dos_divisores=0;
    p = pilha_cria();
    for(numero=1; numero <= 100; numero++)
    {
        for (divisor=1; divisor <= 100; divisor++)
        {
            if (numero%divisor==0 && numero!=divisor)
            {
                soma_dos_divisores=soma_dos_divisores+divisor;
            }
        }
            if (soma_dos_divisores==numero)
            {
                pilha_insere(p,numero);
            }
            soma_dos_divisores=0;
    }
    printf("\nNumeros perfeitos: \n\n");
    pilha_imprime(p);
    pilha_libera(p);
    printf("\n\n");
    return 0;
}
