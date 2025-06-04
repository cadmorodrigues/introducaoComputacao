
#ifndef __QUADRADO_H__
#define __QUADRADO_H__ 0x01

#include "ponto.h"

typedef struct QUADRADO {
    PONTO *P1, *P2, *P3, *P4;
} QUADRADO;

double AreaQuadrado(QUADRADO *Quadrado);
double DiagonalQuadrado(QUADRADO *Quadrado);
double LadoQuadrado(QUADRADO *Quadrado);
void FinalizarQuadrado(QUADRADO *Quadrado);
void IniciarQuadrado(QUADRADO **Quadrado, PONTO *P1, PONTO *P2, PONTO *P3, PONTO *P4);
void MostrarQuadrado(QUADRADO *Quadrado);
double PerimetroQuadrado(QUADRADO *Quadrado);

#endif

