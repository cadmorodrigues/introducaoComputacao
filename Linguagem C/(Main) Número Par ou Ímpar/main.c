//Inclus�o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Fun��o Principal
int main()
{
    //Declara��o de vari�veis
    int x;

    //Inicializa��o das vari�veis
    x=0;

    //Entrada de dados
    printf ("Bem vindo(a)!\n");
    printf("Entre com um valor inteiro.\n");
    scanf ("%i", &x);

    //Processamento
    //Testando se � par
    if (x%2==0)
    {
        printf("O numero eh par.\n");
    }
    else
    {
        printf("O numero eh impar\n");
    }

    return 0;
}
