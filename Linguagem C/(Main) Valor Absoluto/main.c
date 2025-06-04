//Inclusão de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Função Principal
int main()
{
    //Declaração de variáveis
    int x;
    int y;

    //Inicialização das variáveis
    x=0;
    y=0;

    //Entrada de dados
    printf ("Bem vindo(a)!\n");
    printf("Entre com o valor inteiro.\n");
    scanf ("%i", &x);

    //Processamento
    y=abs(x);

    //Saída de dados
    printf ("O absoluto de %i eh %i.",x,y);

    return 0;
}
