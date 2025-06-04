#include <stdio.h>
#include <stdlib.h>
/* definicao de tipo */
struct lista
{
    int num;
    int den;
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
void fila_insere(Fila* f, int x,int y)
{
  Lista* n = (Lista*)malloc(sizeof(Lista));
  n -> num = x;
  n -> den = y;
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
        printf("%d/%d\t",q->num,q->den);
      else
        printf("\nFila Vazia\n");
    printf("\n");
}
void fila_soma(Fila* f)
{
    Lista* q;
    float soma;
    soma = 0;
    if (f != NULL)
      for (q = f->ini;q != NULL;q = q->prox)
        soma = soma + 1.0*q->num/q->den;
      printf("\nSoma dos termos da serie : %f\n",soma);
    printf("\n");
}
int main()
{
    Fila* f;
    f = fila_cria();
    int sinal = 1 , contador;
    float numerador = 480, denominador = 10 , numerador_aux;
    for(contador = 1; contador <= 30; contador ++)
    {
        numerador=numerador-5;
        denominador++;
        numerador_aux=numerador*sinal;
        fila_insere(f,numerador_aux,denominador);
        sinal=-sinal;
    }
    printf("Conteudo da  fila\n\n");
    fila_imprime(f);
    fila_soma(f);
    fila_libera(f);
    return 0;
}
