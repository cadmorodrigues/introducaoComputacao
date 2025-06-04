/* Um pais A possui 200 milhoes de habitantes, com taxa de cresci-
mento anual de 1,5% e um pais B possui 90 milhoes de habitantes com
taxa anual de crescimento de 3%. Fazer um programa para mostrar a
variacao anual do numero de habitantes e mostrar em quan tos anos
o pais B ultrapassara o pais A.
*/
#include <stdio.h>
#include <stdlib.h>
/* definicao de tipo */
struct lista
{
    float  pop_A;
    float  pop_B;
    int    ano;
    struct lista* prox;
};
typedef struct lista Lista;
/* definicao de funcoes */
Lista* lst_cria(void)
{
  return NULL;
}
Lista* lst_insere(Lista* l, float x,float y, int i)
{
  Lista* novo  = (Lista*)malloc(sizeof(Lista));
  novo -> pop_A = x;
  novo -> pop_B = y;
  novo -> ano   = i;
  novo -> prox  = l;
  return novo;
}

void lst_imprime(Lista* l)
{
    Lista* p;
    for (p = l;p != NULL;p = p->prox)
      printf("%f\t%f\t%d\n",p->pop_A,p->pop_B,p->ano);
    printf("\n");
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
    int tempo;
    float pais_A, pais_B;
    pais_A = 200;
    pais_B = 90;
    tempo  = 0;
    l = lst_cria();
    while(pais_B <= pais_A)
    {
      pais_A = 1.015*pais_A;
      pais_B = 1.03*pais_B;
      tempo  = tempo + 1;
      l = lst_insere(l,pais_A,pais_B,tempo);
    }
    printf("Pop_A\t\tPop_B\t\tAno\n");
    lst_imprime(l);
    lst_libera(l);
    return 0;
}
