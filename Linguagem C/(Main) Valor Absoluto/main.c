//Inclus�o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Fun��o Principal
int main()
{
    //Declara��o de vari�veis
    int x;
    int y;

    //Inicializa��o das vari�veis
    x=0;
    y=0;

    //Entrada de dados
    printf ("Bem vindo(a)!\n");
    printf("Entre com o valor inteiro.\n");
    scanf ("%i", &x);

    //Processamento
    y=abs(x);

    //Sa�da de dados
    printf ("O absoluto de %i eh %i.",x,y);

    return 0;
}
