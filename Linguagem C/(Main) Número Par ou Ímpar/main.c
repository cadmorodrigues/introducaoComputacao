//Inclusão de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Função Principal
int main()
{
    //Declaração de variáveis
    int x;

    //Inicialização das variáveis
    x=0;

    //Entrada de dados
    printf ("Bem vindo(a)!\n");
    printf("Entre com um valor inteiro.\n");
    scanf ("%i", &x);

    //Processamento
    //Testando se é par
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
