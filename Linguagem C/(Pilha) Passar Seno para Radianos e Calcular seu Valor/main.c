/*Programa para ler um angulo em graus, converte-lo para radianos
e, calcular o seno deste angulo, usando a serie truncada abaxixo :
                3          5           7
sen(x) = x/1 - x / 6  +   x / 120   - x / 5040,armazenando seus
termos em   uma pilha e somando a quantidade de termos da pilha
*/
#include <stdio.h>
#include <stdlib.h>
/*definicao de funcao*/
double fatorial(double x)
{
    double fatx;
    int a;
    fatx = 1;
    for (a = 1;a <= x;a++)
    {
        fatx = fatx * a;
    }
    return fatx;
}
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
        printf("%lf\n",q->x);
      else
        printf("\nPilha Vazia\n");
    printf("\n");
}
void pilha_soma_pilha(Pilha* p)
{
    Lista* q, *aux;
    double soma;
    soma = 0;
    if (p != NULL)
      {
          q = p->prim;
          aux = q;
          while (q != NULL)
            {
                soma = soma + q->x;
                q = q->prox;
            }
          printf("%2.20lf\n",soma);
      }
      else
        printf("\nPilha Vazia\n");
    printf("\n");
}
int main()
{
    Pilha* p;
    double grau,radianos,fracao;
    int termo,sinal;
    p = pilha_cria();
    printf("Digite um angulo em graus : ");
    scanf("%lf",&grau);
    radianos = grau * 3.1415926536 / 180;
    termo = 1;
    sinal = 1;
     while (termo <= 7)
    {
      fracao = sinal*pow(radianos,termo)/fatorial(termo);
      pilha_insere(p,fracao);
      sinal = -sinal;
      termo = termo + 2;
    }
    pilha_imprime(p);
    printf(" Seno de %lf = ",grau);
    pilha_soma_pilha(p);
    pilha_libera(p);
    printf("\n\n");
    return 0;
}
