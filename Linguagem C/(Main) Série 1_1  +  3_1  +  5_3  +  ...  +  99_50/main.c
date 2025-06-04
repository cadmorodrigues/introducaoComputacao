//Inclusão de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Função Principal
int main()
{
    //Declaração de variáveis
    float numerador;
    float denominador;
    float somatorio;

    //Inicialização das variáveis
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

    //Saída de dados
    printf ("A serie vale %f.",somatorio);

    return 0;
}
