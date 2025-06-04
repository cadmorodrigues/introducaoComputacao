#ifndef __TRONCO_PIRAMIDE_QUADRANGULAR_H__
#define __TRONCO_PIRAMIDE_QUADRANGULAR_H__ 0x01

#include "quadrado.h"

typedef struct TRONCO_PIRAMIDE_QUADRANGULAR {
    QUADRADO *BaseMaior, *BaseMenor;
    double altura;
} TRONCO_PIRAMIDE_QUADRANGULAR;

double AlturaTroncoPiramideQuadrangular(TRONCO_PIRAMIDE_QUADRANGULAR *TroncoPiramide);
double AreaBaseMaiorTroncoPiramideQuadrangular(TRONCO_PIRAMIDE_QUADRANGULAR *TroncoPiramide);
double AreaBaseMenorTroncoPiramideQuadrangular(TRONCO_PIRAMIDE_QUADRANGULAR *TroncoPiramide);
double AreaTotalTroncoPiramideQuadrangular(TRONCO_PIRAMIDE_QUADRANGULAR *TroncoPiramide);
double AreaSuperficieLateralTroncoPiramideQuadrangular(TRONCO_PIRAMIDE_QUADRANGULAR *TroncoPiramide);
double ArestaTroncoPiramideQuadrangular(TRONCO_PIRAMIDE_QUADRANGULAR *TroncoPiramide);
double DiagonalBaseTroncoPiramideQuadrangular(TRONCO_PIRAMIDE_QUADRANGULAR *TroncoPiramide);
void IniciarTroncoPiramideQuadrangular(TRONCO_PIRAMIDE_QUADRANGULAR **TroncoPiramide, QUADRADO *QMaior, QUADRADO *QMenor);
void FinalizarTroncoPiramideQuadrangular(TRONCO_PIRAMIDE_QUADRANGULAR *TroncoPiramide);
void MostrarTroncoPiramideQuadrangular(TRONCO_PIRAMIDE_QUADRANGULAR *TroncoPiramide);
double VolumeTroncoPiramideQuadrangular(TRONCO_PIRAMIDE_QUADRANGULAR *TroncoPiramide);

#endif

