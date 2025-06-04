//Inclus�o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Fun��o Fatorial
double fatorial (int numer)
{
    //Defini��o vari�veis locais
    int aux;
    double fat;

    //Inicializa��o de vari�veis locais
    aux=0;
    fat=0;

    //Execu��o local
        for (aux=1; aux<=numer; aux ++)
        {
            fat=fat*aux;
        }

    return fat;
}

//Fun��o Principal
int main()
{
    //Declara��o de vari�veis
    float numerador;
    float denominador;
    float somatorio;
    int termos;
    int x;

    //Inicializa��o das vari�veis
    termos=0;
    numerador=0;
    denominador=0;
    somatorio=0;
    x=0;

    //Entrada de dados
    printf ("Somatorio da serie e\n");
    printf ("Entre com o numero de termos da serie desejados\n");
    scanf("%i", &termos);
    printf ("Entre com um numero x\n");
    scanf("%i", &x);

    //Processamento
    while (termos>=0)
    {
        numerador=pow(x,termos);
        denominador=fatorial(termos);
        somatorio=somatorio+(numerador/denominador);
        termos --;
    }

    //Sa�da de dados
    printf ("A serie vale %f.",somatorio);

    return 0;
}
