#include <stdio.h>
#include <stdlib.h>
int busca_bin(int n, int* vet,int elem)
{
    /*no inicio, consideramos todo o vetor */
    int ini = 0;
    int fim = n-1;
    int meio;
    /*enquanto a parte restante for maior que zero */
    while (ini <= fim)
    {
        meio = (ini + fim)/2;
        if (elem < vet[meio])
        fim = meio - 1; /* ajusta a posicao final*/
        else
         if (elem > vet[meio])
         ini = meio + 1; /* ajusta a posicao inicial*/
         else
         return meio; /* elemento encontrado */
    }
    return -1; /* nao encontrou */
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
    resp = busca_bin(tam, vetor,num);
    if (resp != -1)
      printf("\n%d encontrado no vetor na posicao %d.\n",num,resp+1);
    else
      printf("\n%d nao encontrado no vetor.\n",num);
    return 0;
}
