//Inclus�o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Fun��o Principal
int main()
{
    //Declara��o de vari�veis
    int x;
    int y;
    int soma;

    //Inicializa��o das vari�veis
    x=0;
    y=0;
    soma=0;

    //Entrada de dados
    printf ("Bem vindo(a)!\n");
    printf("Entre com dois valores inteiros separados por espaco.\n");
    scanf ("%i %i", &x,&y);

    //Processamento
    soma=x+y;

    //Sa�da de dados
    printf ("A soma de %i com %i eh %i.",x,y,soma);

    return 0;
}
