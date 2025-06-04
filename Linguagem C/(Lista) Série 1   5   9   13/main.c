/* Programa para armazenar em uma lista os 20 primeiros termos
 da serie : 1   5   9   13  ...
Percorrer a lista e mostrar a soma de seus elementos
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
/* definicao de funcoes */

Lista* lst_cria(void)
{ Lista* n = (Lista*)malloc(sizeof(Lista));
  return n = NULL;
}
Lista* lst_insere(Lista* l, int i)
{
  Lista* novo  = (Lista*)malloc(sizeof(Lista));
  novo -> info = i;
  novo -> prox = l;
  return novo;
}

void lst_imprime(Lista* l)
{
    Lista* p;
    for (p = l;p != NULL;p = p->prox)
      printf("%d\t",p->info);
    printf("\n");
}
void lst_soma_elementos_da_lista(Lista* l)
{
    Lista* p;
    int soma = 0;
    for (p = l;p != NULL;p = p->prox)
      soma = soma + p->info;
    printf("\nSoma dos elementos da lista = %d\n",soma);
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
    int contador,termo,soma;
    termo = 1;
    l = lst_cria();
    for(contador = 1;contador <= 20;contador++)
    {
        l = lst_insere(l,termo);
        termo = termo + 4;
    }
    printf("\nConteudo da lista encadeada\n\n");
    lst_imprime(l);
    lst_soma_elementos_da_lista(l);
    printf("\n");
    lst_libera(l);
    return 0;
}

