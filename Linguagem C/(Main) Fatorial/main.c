//Inclusão de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Função Fatorial
double fatorial (int numer)
{
    //Definição variáveis locais
    int aux;
    double fat;

    //Inicialização de variáveis locais
    aux=0;
    fat=0;

    //Execução local
        for (aux=1; aux<=numer; aux ++)
        {
            fat=fat*aux;
        }

    return fat;
}

//Função Principal
int main()
{
    //Declaração de variáveis
    float numerador;
    float denominador;
    float somatorio;
    int termos;
    int x;

    //Inicialização das variáveis
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

    //Saída de dados
    printf ("A serie vale %f.",somatorio);

    return 0;
}
