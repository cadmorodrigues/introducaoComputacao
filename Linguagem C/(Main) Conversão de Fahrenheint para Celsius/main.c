//Inclus�o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Fun��o Principal
int main()
{
    //Declara��o de vari�veis
    int f;
    int linha;
    double c;

    //Inicializa��o das vari�veis
    f=-48;
    c=0;
    linha=0;

    //Cabe�alho da tabela
    printf ("Tabela de convers�o entre Celsius e Fahrenheit\n");
    printf("-------------------------------------------------\n");
    printf("Celsius\t\tFahrenheit\n");
    printf("-------------------------------------------------\n");

    //Processamento
    while (f<=128)
    {
        c=((5.0/9)*(f-32));
        linha++;
            //Melhorando sa�da de dados com paradas
            if (linha<20)
            {
              printf("%f\t\t%i\n",c,f);
            }
            else
            {
                system("pause");
                system("cls");
                linha=0;
                printf("Celsius\t\tFahrenheit\n");
                printf("-------------------------------------------------\n");
             }
        f++;
    }

    return 0;
}
