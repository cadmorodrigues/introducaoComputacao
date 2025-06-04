/*Programa para ler um valor inteiro na base 10 e converte-lo
para a base 2, armazenando o resultado da conversao em uma pilha. */
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
        printf("%d",q->x);
      else
        printf("\nPilha Vazia\n");
    printf("\n");
}

int main()
{
    Pilha* p;
    int dado, quociente,resto;
    p = pilha_cria();
    printf("Digite um valor na base 10 : ");
    scanf("%d",&dado);
    quociente = dado;
    while (quociente != 0)
    {
      resto     = quociente % 2;
      pilha_insere(p,resto);
      quociente = quociente / 2;
    }
    printf("\n\n%d convertido para a base 2 : ",dado);
    pilha_imprime(p);
    pilha_libera(p);
    printf("\n");
    return 0;
}
