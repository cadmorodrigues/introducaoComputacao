#include <iostream>

#include <stdio.h>

#include <conio.h>

using namespace std;

int procura_elem(int vetor[], int num, int i){

if(vetor[i] == num)

return num;

procura_elem(vetor, num, i+1);

}

int main(){

int tamanho,i,cont,pos;

pos=0;

cout << "digite o tamanho do vetor no maximo 1000: ";

cin>> tamanho;

int vetor[tamanho];

for(i=0; i<tamanho; i++){

cout << "digite um valor para o vetor: ";

cin>> vetor[i];

}

cout << "\ndigite o valor que deseje ser encontrado: ";

cin>> cont;

printf("\n\n");

for( i=0 ; i<tamanho ; i++){

cout << vetor[i] << " ";

}

pos = procura_elem(vetor,cont,0);

printf(" posicao = %d\n", pos);

return 0;
}
