#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
//Construir um programa que faça a busca sequencial em um vetor de n posição entrado
//pelo usuário, retorne a posiçaõ do valor encontrado

int main()

{
   int i,tam,buscar;
   int posicao;

    cout << "\n...........Busca sequencial.............\n\t" << endl;
    cout << "\n...... Digite o tamanho do vetor!.......\n\t" << endl;
    cin>>tam;
//entrando com o vetor;

    int vet[tam];

    for ( i=0 ; i<tam ; i++ ){
        cout << "\n Digite um numero \n" << endl;
        cin>>vet[i];
    }
    system("CLS");  //limpa o que ja foi digitado:

   cout << "\n...........Exercicio 1 .............\n\t" << endl;
   cout << "\n...........Busca sequencial.............\n\t" << endl;

        cout<<"\n o vetor digitado eh:"<<endl;

// mostrando o vetor:

        for (i=0; i<tam; i++)
            cout<<vet[i]<<" ";
// busca pela posicao do valor que o usuario deseja:
            cout << "\n Digite o valor que voce deseja buscar!\n" << endl;
            cin>>buscar;

             for (i=0;i<tam;i++){

                if (vet[i]==buscar){
                    posicao=i+1;
                    i=tam;

            cout << "\n O valor se enontra na posicao:\n" <<posicao<< endl;

                }
                        if (i==tam-1 && vet[i]!=buscar)
                        cout<<"este valor nao se encontra"<<endl;
             }


    return  0 ;
}
