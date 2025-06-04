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
/* definicao de funcoes */
Lista* lst_cria(void)
{
  return NULL;
}
Lista* lst_insere(Lista* l, int x,int y)
{
  Lista* novo  = (Lista*)malloc(sizeof(Lista));
  novo -> num = x;
  novo -> den = y;
  novo -> prox = l;
  return novo;
}

void lst_imprime(Lista* l)
{
    Lista* p;
    for (p = l;p != NULL;p = p->prox)
      printf("%d/%d\t",p->num,p->den);
    printf("\n");
}
void lst_soma_elementos_da_lista(Lista* l)
{
    Lista* p;
    float soma = 0;
    for (p = l;p != NULL;p = p->prox)
      soma = soma + 1.0*p->num/p->den;
    printf("\nSoma dos elementos da lista = %f\n",soma);
}
void lst_libera(Lista* l)
{
    Lista* p = l;
    while (p != NULL)
    {
        Lista* t = p->prox;
        free(p);
        p = t;
    }
}

int main()
{
    Lista* l;
    int numerador,denominador;
    numerador = 1;
    l = lst_cria();
    for(denominador = 1;denominador <= 50;denominador++)
    {
        l = lst_insere(l,numerador,denominador);
        numerador = numerador + 2;
    }
    printf("\nConteudo da lista encadeada\n\n");
    lst_imprime(l);
    lst_soma_elementos_da_lista(l);
    printf("\n");
    lst_libera(l);
    return 0;
}
