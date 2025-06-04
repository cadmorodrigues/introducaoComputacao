//Inclusão de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Função Principal
int main()
{
    //Declaração de variáveis
    int f;
    int linha;
    double c;

    //Inicialização das variáveis
    f=-48;
    c=0;
    linha=0;

    //Cabeçalho da tabela
    printf ("Tabela de conversão entre Celsius e Fahrenheit\n");
    printf("-------------------------------------------------\n");
    printf("Celsius\t\tFahrenheit\n");
    printf("-------------------------------------------------\n");

    //Processamento
    while (f<=128)
    {
        c=((5.0/9)*(f-32));
        linha++;
            //Melhorando saída de dados com paradas
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
