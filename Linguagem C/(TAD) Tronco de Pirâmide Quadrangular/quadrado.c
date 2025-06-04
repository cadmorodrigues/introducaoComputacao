#include "quadrado.h"
#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include <math.h>
double AreaQuadrado(QUADRADO *Quadrado)
{
    double reta = DistanciaPonto(Quadrado->P1,Quadrado->P2);
    return reta*reta;
}
double DiagonalQuadrado(QUADRADO *Quadrado)
{
    double reta = DistanciaPonto(Quadrado->P1,Quadrado->P2);
    return reta*sqrt(2);

}
double LadoQuadrado(QUADRADO *Quadrado)
{
    double reta = DistanciaPonto(Quadrado->P1,Quadrado->P2);
    return reta;
}
void FinalizarQuadrado(QUADRADO *Quadrado)
{
    free(Quadrado);
}
void IniciarQuadrado(QUADRADO **Quadrado, PONTO *P1, PONTO *P2, PONTO *P3, PONTO *P4)
{
    (*Quadrado) = malloc(sizeof(QUADRADO));

    (*Quadrado)->P1 = P1;
    (*Quadrado)->P2 = P2;
    (*Quadrado)->P3 = P3;
    (*Quadrado)->P4 = P4;

    return;

}
void MostrarQuadrado(QUADRADO *Quadrado)
{
    MostrarPonto(Quadrado->P1);
    MostrarPonto(Quadrado->P2);
    MostrarPonto(Quadrado->P3);
    MostrarPonto(Quadrado->P4);
    return;

}
double PerimetroQuadrado(QUADRADO *Quadrado)
{
    double reta = DistanciaPonto(Quadrado->P1,Quadrado->P2);
    return (reta*4);

}

