#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
// programa que ordena gera um vetor aleatorio com partes inteiras.
  int main( )
{
//input
    int tam=0,i=0;
	srand(3); // inicializador de numeros aleatorios:

        cout <<"\n........Exercicio vetor aleatorio inteiro........."<< endl;
        cout<<" \n........Digite o tamanho do vetor.................\n "<<endl;

        cin>>tam;
        int vet[tam];

        system("cls");

        cout <<"\n........Exercicio vetor aleatorio inteiro.........\n"<< endl;


        for(i=0;i<tam;i++){

            vet[i] = (rand()) % 100; // gera numeros aleatorios ate 100:
    }

            cout <<"\n...............Vetor gerado eh...............\n\t"<< endl;

            for(i=0;i<tam;i++)
                cout<< vet[i] <<" \t";

	return (0);

}
