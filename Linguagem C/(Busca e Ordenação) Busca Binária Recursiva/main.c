#include <stdio.h>
#include <stdlib.h>
int busca_bin_rec(int n, int* vet,int elem)
{
    /*testa condicao de retorno: parte com tamanho zero */
    if (n <= 0)
    return 0;
    else
    {
        int meio = n/2; /* busca o elemento do meio */
        if (elem < vet[meio])
        return busca_bin_rec(meio,vet,elem);
        else
         if (elem > vet[meio])
         return busca_bin_rec(n-1-meio,&vet[meio+1],elem);
         else
         return 1; /* elemento encontrado */

    }
}
int main()
{
    int vetor[10] = {3,7,13,18,21,34,56,66,78,90};
    int tam = 10;
    int resp;
    int num;
    int a;
    printf("Conteudo do vetor\n");
    for (a = 0; a < tam;a++)
      printf("%d\t",vetor[a]);

    printf("\n\nDigite um numero inteiro : ");
    scanf("%d",&num);
    /* chamada da funcao de busca binaria */
    resp = busca_bin_rec(tam, vetor,num);
    if (resp != 0)
    printf("\n%d encontrado no vetor.\n",num);
    else
    printf("\n%d nao encontrado no vetor.\n",num);
    return 0;
}
