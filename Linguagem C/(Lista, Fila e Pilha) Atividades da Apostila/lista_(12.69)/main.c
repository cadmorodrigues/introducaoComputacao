#include <stdio.h>
#include <stdlib.h>
/* definicao de tipo */
struct lista
{
    int nOctal;
    int nDecimal;
    struct lista* prox;
};
typedef struct lista Lista;
/* definicao de funcoes */
Lista* lst_cria(void)
{
  return NULL;
}
Lista* lst_insere(Lista* l, int x, int y)
{
  Lista* novo  = (Lista*)malloc(sizeof(Lista));
  novo -> nOctal = x;
  novo -> nDecimal = y;
  novo -> prox = l;
  return novo;
}

void lst_imprime(Lista* l)
{
    Lista* p;
    for (p = l;p != NULL;p = p->prox)
   {
        printf("\nOctal: %i | Decimal: %i", p->nOctal, p->nDecimal);
    }
    printf("\n");
}

//Função para converter octal para decimal
int base3_para_base10(int n)
{
    int decimal=0, i=0, resto;
    while (n!=0)
    {
        resto = n%10;
        n=n/10;
        decimal=decimal+resto*pow(8,i);
        ++i;
    }
    return decimal;
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
    l = lst_cria();
    int numeroDecimal,numeroOctal,quantidade_Termos,aux;
    printf("Para encerrar, tecle 0.");
    printf("\nEntre com o numero inteiro em base 3 a ser convertido para base 10: ");
    scanf("%i",&numeroOctal);
    while (numeroOctal!=0)
    {
        numeroDecimal=base3_para_base10(numeroOctal);
        l = lst_insere(l,numeroOctal,numeroDecimal);
        printf("Entre com o numero inteiro em base 3 a ser convertido para base 10: ");
        scanf("%i",&numeroOctal);
    }
    printf("\nTabela de conversao:");
    lst_imprime(l);
    lst_libera(l);
    printf("\n\n");
    return 0;
}
