/* Programa para ler um valor inteiro na base 10 e convertwe-lo
para a base 2
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
{
  return NULL;
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
      printf("%d",p->info);
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
    int x,quociente, resto;
    printf("Digite um numero inteiro na base 10 : ");
    scanf("%d",&x);
    l = lst_cria();
    quociente = x;
    while(quociente != 0)
    {
      resto = quociente % 2;
      l = lst_insere(l,resto);
      quociente = quociente / 2;
    }
    printf("\n%d na base 2 eh igual a : ",x);
    lst_imprime(l);
    lst_libera(l);
    return 0;
}
