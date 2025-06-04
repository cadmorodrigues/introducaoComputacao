#include <math.h>
#include <stdio.h>

#include "ponto.h"

double DistanciaPonto(PONTO *Ponto1, PONTO *Ponto2) {
    return sqrt(pow(Ponto1->x - Ponto2->x,2) + pow(Ponto1->y - Ponto2->y,2));
}
void IniciarPonto(PONTO **Ponto, double x, double y) {
    (*Ponto) = malloc(sizeof(PONTO)); // alocar memória para Ponto
    if ((*Ponto) == NULL) { // verificar se foi alocada memória para Ponto
        puts("\nErro: (faltou memória)\n"); // mensagem de alerta de erro
        exit(0); // encerrar a execução do programa
    }
    (*Ponto)->x = x; // atribuir x parâmetro para o x (elemento, campo) de Ponto
    (*Ponto)->y = y; // atribuir y parâmetro para o y (elemento, campo) de Ponto
}
void FinalizarPonto(PONTO *Ponto) {
    if (Ponto) // verificar se pontos está alocado na memória
        free(Ponto); // liberar a memória alocada para Ponto
}
void MostrarPonto(PONTO *Ponto) {
    printf("\n(%.1lf,%.1lf)\n",Ponto->x,Ponto->y);
}
