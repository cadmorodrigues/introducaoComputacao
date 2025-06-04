#include <stdio.h>
#include <stdlib.h>
void bolha(int n, int* v)
{
    int i,j,aux,temp,troca;
    for(i = n-1;i>=1;i--)
    {
      troca = 0;
      for (j=0;j<i;j++)
        if (v[j] > v[j+1])
        {
          temp    = v[j];
          v[j]    = v[j+1];
          v[j+1]  = temp;
          troca = 1;
        }
      for (aux = 0;aux<n;aux++)
        printf("%3d",v[aux]);
      printf("\n");
      if (troca == 0)
      return;
    }
}
int main()
{
    int i,tamanho;
    int v[100];
    srand(time(NULL));
    tamanho = rand()%11;
    printf("Tamanho do vetor : %d\n",tamanho);
    for (i = 0;i < tamanho;i++)
      v[i] = rand() % 11;
    printf("Vetor criado\n\n");
    for (i=0;i < tamanho;i++)
      printf("%d ",v[i]);
    printf("\n\n\nOrdenando o vetor\n\n");
    bolha(tamanho,v);
    printf("\n");
    return 0;
}
