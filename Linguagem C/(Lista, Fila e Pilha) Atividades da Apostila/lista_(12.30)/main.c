#include <stdio.h>
#include <stdlib.h>
/* definicao de tipo */
struct lista
{
    float ang;
    float sen;
    struct lista* prox;
};
typedef struct lista Lista;
/* definicao de funcoes */
Lista* lst_cria(void)
{
  return NULL;
}
Lista* lst_insere(Lista* l, float x,float y)
{
  Lista* novo  = (Lista*)malloc(sizeof(Lista));
  novo -> ang = x;
  novo -> sen = y;
  novo -> prox = l;
  return novo;
}

void lst_imprime(Lista* l)
{
    Lista* p;
    for (p = l;p != NULL;p = p->prox)
    {
        printf("Angulo: %.2f | Seno: %.2f \t",p->ang,p->sen);
        printf("\n");
    }
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

//Função de Fatorial
int fatorial(int num)
{
	if (num)
  	  return num*fatorial(num-1);
	else return 1;
}

int main()
{
    Lista* l;
    int s, contador, ntermos,expoente;
    float A, senoA;
    l = lst_cria();

    printf("\nEscolha a quantidade de termos a se mostrar os respectivos senos: ");
    scanf("%i",&s);
    while (s<=0)
    {
     printf("\nEscolha uma quantidade de termos valida: ");
     scanf("%i",&s);
    }
    for(contador = 1; contador <= s; contador ++)
    {
        printf("\nEscolha o angulo em radiano: ");
        scanf("%f",&A);
        expoente=1;
        senoA=0;
        for (ntermos = 1; ntermos <=4; ntermos ++)
        {
            senoA=senoA+(pow(A,expoente))/fatorial(expoente);
            expoente=expoente+2;
        }
        l = lst_insere(l,A,senoA);
    }
    system("cls");
    printf("\nTabela de Angulos e Senos respectivos em radianos\n\n");
    lst_imprime(l);
    printf("\n");
    lst_libera(l);
    return 0;
}
