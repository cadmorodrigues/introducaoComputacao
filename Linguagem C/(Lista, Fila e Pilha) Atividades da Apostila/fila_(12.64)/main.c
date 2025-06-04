#include <stdio.h>
#include <stdlib.h>
/* definicao de tipo */
struct lista
{
    int num;
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
void fila_insere(Fila* f, int x)
{
  Lista* n = (Lista*)malloc(sizeof(Lista));
  n -> num = x;
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
        printf("%d\t",q->num);
      else
        printf("\nFila Vazia\n");
    printf("\n");
}

int main()
{
    Fila* f;
    f = fila_cria();
    int numero, divisor, soma_dos_divisores=0;
    for(numero=1; numero <= 100; numero++)
    {
        for (divisor=1; divisor <= 100; divisor++)
        {
            if (numero%divisor==0 && numero!=divisor)
            {
                soma_dos_divisores=soma_dos_divisores+divisor;
            }
        }
            if (soma_dos_divisores==numero)
            {
                fila_insere(f,numero);
            }
            soma_dos_divisores=0;
    }
    printf("\nNumeros perfeitos: \n\n");
    fila_imprime(f);
    fila_libera(f);
    return 0;
}
