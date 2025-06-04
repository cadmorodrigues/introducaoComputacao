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
void fila_insere(Fila* f, float x, float y)
{
  Lista* n = (Lista*)malloc(sizeof(Lista));
  n -> ang = x;
  n -> sen = y;
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
        printf("Angulo: %.2f | Seno: %.2f\n",q->ang,q->sen);
      else
        printf("\nFila Vazia\n");
    printf("\n");
}

//Função de Fatorial
float fatorial(float num)
{
	if (num)
  	  return num*fatorial(num-1);
	else return 1;
}

int main()
{
    Fila* f;
    f = fila_cria();
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
        fila_insere(f,A,senoA);
    }
    system("cls");
    printf("\nTabela de Angulos e Senos respectivos em radianos\n\n");
    fila_imprime(f);
    fila_libera(f);
    return 0;
}
