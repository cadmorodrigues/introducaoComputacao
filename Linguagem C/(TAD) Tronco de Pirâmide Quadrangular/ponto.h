
#ifndef __PONTO_H__
#define __PONTO_H__ 0x01

// incluir arquivos de cabeçalhos da biblioteca padrão
#include <stdlib.h>

// definição do tipo de dado PONTO
typedef struct PONTO {
    double x, y;
} PONTO;

// Cabeçalhos (protótipos, headers) das funções do TAD PONTO
double DistanciaPonto(PONTO *P1, PONTO *P2);
void FinalizarPonto(PONTO *Ponto);
void IniciarPonto(PONTO **Ponto, double x, double y);
void MostrarPonto(PONTO *Ponto);

#endif
