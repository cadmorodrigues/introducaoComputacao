//Inclusão de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Função Principal
int main()
{
    //Declaração de variáveis
    int x;
    int y;
    int soma;

    //Inicialização das variáveis
    x=0;
    y=0;
    soma=0;

    //Entrada de dados
    printf ("Bem vindo(a)!\n");
    printf("Entre com dois valores inteiros separados por espaco.\n");
    scanf ("%i %i", &x,&y);

    //Processamento
    soma=x+y;

    //Saída de dados
    printf ("A soma de %i com %i eh %i.",x,y,soma);

    return 0;
}
