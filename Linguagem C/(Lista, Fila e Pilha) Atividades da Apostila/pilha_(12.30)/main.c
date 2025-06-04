#include <stdio.h>
#include <stdlib.h>

/* definicao de tipo */
struct lista
{
    float angulo;
    float seno;
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
  n -> angulo = dado;
  n -> seno = dado2;
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
        printf("Angulo: %.2f | Seno: %.2f\n",q->angulo,q->seno);
      else
        printf("\nPilha Vazia\n");
    printf("\n");
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
    Pilha* p;
    p = pilha_cria();
    int s, contador, ntermos,expoente;
    float A, senoA;

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
        pilha_insere(p,A,senoA);
    }
    system("cls");
    printf("\nTabela de Angulos e Senos respectivos em radianos\n\n");
    pilha_imprime(p);
    pilha_libera(p);
    printf("\n\n");
    return 0;
}
