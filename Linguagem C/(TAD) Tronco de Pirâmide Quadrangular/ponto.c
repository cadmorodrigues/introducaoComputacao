#include <math.h>
#include <stdio.h>

#include "ponto.h"

double DistanciaPonto(PONTO *Ponto1, PONTO *Ponto2) {
    return sqrt(pow(Ponto1->x - Ponto2->x,2) + pow(Ponto1->y - Ponto2->y,2));
}
void IniciarPonto(PONTO **Ponto, double x, double y) {
    (*Ponto) = malloc(sizeof(PONTO)); // alocar mem�ria para Ponto
    if ((*Ponto) == NULL) { // verificar se foi alocada mem�ria para Ponto
        puts("\nErro: (faltou mem�ria)\n"); // mensagem de alerta de erro
        exit(0); // encerrar a execu��o do programa
    }
    (*Ponto)->x = x; // atribuir x par�metro para o x (elemento, campo) de Ponto
    (*Ponto)->y = y; // atribuir y par�metro para o y (elemento, campo) de Ponto
}
void FinalizarPonto(PONTO *Ponto) {
    if (Ponto) // verificar se pontos est� alocado na mem�ria
        free(Ponto); // liberar a mem�ria alocada para Ponto
}
void MostrarPonto(PONTO *Ponto) {
    printf("\n(%.1lf,%.1lf)\n",Ponto->x,Ponto->y);
}
