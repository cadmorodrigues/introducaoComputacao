
#ifndef __PONTO_H__
#define __PONTO_H__ 0x01

// incluir arquivos de cabe�alhos da biblioteca padr�o
#include <stdlib.h>

// defini��o do tipo de dado PONTO
typedef struct PONTO {
    double x, y;
} PONTO;

// Cabe�alhos (prot�tipos, headers) das fun��es do TAD PONTO
double DistanciaPonto(PONTO *P1, PONTO *P2);
void FinalizarPonto(PONTO *Ponto);
void IniciarPonto(PONTO **Ponto, double x, double y);
void MostrarPonto(PONTO *Ponto);

#endif
