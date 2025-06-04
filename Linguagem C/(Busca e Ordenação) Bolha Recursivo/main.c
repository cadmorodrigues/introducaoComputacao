#include <stdio.h>
#include <stdlib.h>
void bolha_rec(int n, int* v)
{
    int j,aux,temp,troca;
    troca = 0;
      for (j = 0;j < n-1;j++)
        if (v[j] > v[j+1])
        {
          temp    = v[j];
          v[j]    = v[j+1];
          v[j+1]  = temp;
          troca   = 1;
        }
      for (aux = 0;aux < n;aux++)
        printf("%3d",v[aux]);
      printf("\n");
      if (troca != 0)
      bolha_rec(n-1,v);
}

int main()
{
    int i,tamanho;
    int v[100];
    srand(time(NULL));
    tamanho = rand()%21;
    printf("Tamanho do vetor : %d\n",tamanho);
    for (i = 0;i < tamanho;i++)
      v[i] = rand() % 11;
    printf("Vetor criado\n\n");
    for (i=0;i < tamanho;i++)
      printf("%d ",v[i]);
    printf("\n\n\nOrdenando o vetor\n\n");
    bolha_rec(tamanho,v);
    printf("\nVetor ordenado\n\n");
    for (i=0;i < tamanho;i++)
      printf("%d ",v[i]);
    printf("\n");
    return 0;
}
