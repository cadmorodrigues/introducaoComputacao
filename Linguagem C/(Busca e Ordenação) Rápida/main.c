#include <stdio.h>
#include <stdlib.h>
void rapida(int n, int* v)
{
    int a,b,temp,x,aux;
    if( n <= 1)
    return;
    else
    {
        x = v[0];
        a = 1;
        b = n-1;

       do
       {
           while (a < n && v[a] <= x)
             a++;
           while (v[b] > x)
             b--;
           if (a < b)   /* faz a troca */
           {
              temp = v[a];
              v[a] = v[b];
              v[b] = temp;
              a++;
              b--;
           }
       }
       while (a <= b);
       /* troca o pivo */
       v[0] = v[b];
       v[b] = x;
       printf("\nOrdenacao do primeiro subvetor\n");
       for (aux = 0;aux<n;aux++)
         printf("%d ",v[aux]);
       printf("\n");
       /* ordena os subvetores restantes*/
       rapida(b,v);
       printf("\nOrdenacao do segundo subvetor\n");
       for (aux = 0;aux<n;aux++)
         printf("%d ",v[aux]);
       printf("\n");
       rapida(n-a,&v[a]);
    }
}
int main()
{
    int i;
    int v[15] = {25,48,37,2,12,57,86,39,33,92,21,1,95,56,11};
    printf("Vetor criado\n\n");
    for (i=0;i<15;i++)
    printf("%d ",v[i]);
    printf("\n");
    rapida(15,v);
    printf("\n\nVetor ordenado\n\n");
    for (i=0;i<15;i++)
    printf("%d ",v[i]);
    printf("\n");
    return 0;
}
