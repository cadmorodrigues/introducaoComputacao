//Inclus�o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Fun��o Principal
int main()
{
    //Declara��o de vari�veis
    float numerador;
    float denominador;
    float somatorio;

    //Inicializa��o das vari�veis
    numerador=1.0;
    denominador=1.0;
    somatorio=0;

    //Entrada de dados
    printf ("Somatorio da serie 1/1+3/1+5/3+...+99/50\n");

    //Processamento
    while (denominador<=50)
    {
        somatorio=somatorio+(numerador/denominador);
        numerador=numerador+2;
        denominador ++;
    }

    //Sa�da de dados
    printf ("A serie vale %f.",somatorio);

    return 0;
}
