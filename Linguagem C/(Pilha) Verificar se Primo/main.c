/*Programa para ler um valor inteiro  e verificar se ele eh
ou ao primo,armazenando seus divisores em  uma pilha e contando
a quantidade de divisores presentes nela. (2 divisores  = primo
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
        printf("%d\t",q->x);
      else
        printf("\nPilha Vazia\n");
    printf("\n");
}
void pilha_conta_divisores(Pilha* p)
{
    Lista* q, *aux;
    int contador;
    contador = 0;
    if (p != NULL)
      {
          q = p->prim;
          aux = q;
          while (q != NULL)
            {
                contador = contador + 1;
                q = q->prox;
            }
      }
      else
        printf("\nPilha Vazia\n");

    if (contador == 2)
      printf("\n%d eh primo.",aux->x);
      else
        printf("\n%d nao eh primo.",aux->x);

    printf("\n");
}
int main()
{
    Pilha* p;
    int dado, divisor;
    p = pilha_cria();
    printf("Digite um valor inteiro : ");
    scanf("%d",&dado);
    divisor = 1;
     while (divisor <= dado)
    {
      if (dado % divisor == 0)
        pilha_insere(p,divisor);
      divisor = divisor + 1;
    }
    printf(" Divisores de %d\n\n",dado);
    pilha_imprime(p);
    pilha_conta_divisores(p);
    pilha_libera(p);
    printf("\n");
    return 0;
}
