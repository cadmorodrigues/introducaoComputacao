#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
//Construir um programa que faça a busca sequencial em um vetor de n posição entrado
//pelo usuário, retorne a posiçaõ do valor encontrado

void quickSort(int valor[], int esquerda, int direita)
{
    int i, j, x, y;
    i = esquerda;
    j = direita;
    x = valor[(esquerda + direita) / 2];

    while(i <= j)
    {
        while(valor[i] < x && i < direita)
        {
            i++;
        }
        while(valor[j] > x && j > esquerda)
        {
            j--;
        }
        if(i <= j)
        {
            y = valor[i];
            valor[i] = valor[j];
            valor[j] = y;
            i++;
            j--;
        }
    }
    if(j > esquerda)
    {
        quickSort(valor, esquerda, j);
    }
    if(i < direita)
    {
        quickSort(valor,  i, direita);
    }
}

int main ( ){

 int i,tam ;


    cout << "\n...........Ordenação Quick Sort.............\n\t" << endl;

	srand(3); // inicializador de numeros aleatorios:

        cout<<" \n........Digite o tamanho do vetor.................\n "<<endl;

        cin>>tam;
        int n=tam;
        int vet[tam]; // declarando os vetores:

        system("cls");

        cout <<"\n...........Ordenação Quick Sort ..........\n"<< endl;


        for(i=0;i<tam;i++){

            vet[i] = (rand()) % 100; // gera numeros aleatorios ate 100:
    }

            cout <<"\n...............Vetor gerado eh...............\n\t"<< endl;

            for(i=0;i<tam;i++)
                cout<< vet[i] <<" \t";
                system("PAUSE");  // VER O VETOR
                system("CLS");  //limpa o que ja foi digitado:

            //ordenando o vetor:
            cout <<"\n............... O vetor ordenado eh...............\n\t"<< endl;

            quickSort(vet,0,n);

        // mostrando o vetor ordenado:
            for (i=0; i<tam; i++)
            cout<<vet[i]<<" ";

return 0;
}

