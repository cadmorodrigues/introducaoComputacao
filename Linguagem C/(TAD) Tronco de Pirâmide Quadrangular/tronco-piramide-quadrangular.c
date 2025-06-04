#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include <math.h>
#include "tronco-piramide-quadrangular.h"
#include "quadrado.h"

double AlturaTroncoPiramideQuadrangular(TRONCO_PIRAMIDE_QUADRANGULAR *TroncoPiramide)
{
    PONTO *Centro1,*Centro2;
    double k,j,i,b;
    k = (TroncoPiramide->BaseMaior->P4->y + TroncoPiramide->BaseMaior->P1->y)/2;
    j = (TroncoPiramide->BaseMaior->P1->x + TroncoPiramide->BaseMaior->P2->x)/2;

    IniciarPonto(&Centro1,j,k);
    printf("\nO centro do quadrado maior tem pontos: ");
    MostrarPonto(Centro1);

    i = (TroncoPiramide->BaseMenor->P4->y + TroncoPiramide->BaseMenor->P1->y)/2;
    b = (TroncoPiramide->BaseMenor->P1->x + TroncoPiramide->BaseMenor->P2->x)/2;

    IniciarPonto(&Centro2,b,i);
    TroncoPiramide->altura = DistanciaPonto(Centro2,Centro1);
    printf("O centro do quadrado menor tem pontos: ");
    MostrarPonto(Centro2);
    return TroncoPiramide->altura;
}
double AreaBaseMaiorTroncoPiramideQuadrangular(TRONCO_PIRAMIDE_QUADRANGULAR *TroncoPiramide)
{
    double areamaior;
    areamaior = AreaQuadrado(TroncoPiramide->BaseMaior);
    return areamaior;
}
double AreaBaseMenorTroncoPiramideQuadrangular(TRONCO_PIRAMIDE_QUADRANGULAR *TroncoPiramide)
{
    double areamenor;
    areamenor = AreaQuadrado(TroncoPiramide->BaseMenor);
    return areamenor;
}
double AreaTotalTroncoPiramideQuadrangular(TRONCO_PIRAMIDE_QUADRANGULAR *TroncoPiramide)
{
    double sup, infe;
    sup = DistanciaPonto(TroncoPiramide->BaseMenor->P1, TroncoPiramide->BaseMenor->P2);
    infe = DistanciaPonto(TroncoPiramide->BaseMaior->P1, TroncoPiramide->BaseMaior->P2);
    return (2*(sup+infe)*TroncoPiramide->altura + AreaQuadrado(TroncoPiramide->BaseMaior) + AreaQuadrado(TroncoPiramide->BaseMenor));
}
double AreaSuperficieLateralTroncoPiramideQuadrangular(TRONCO_PIRAMIDE_QUADRANGULAR *TroncoPiramide)
{
    double alt,dista,distb;
    dista = DistanciaPonto(TroncoPiramide->BaseMaior->P1,TroncoPiramide->BaseMaior->P2);
    distb = DistanciaPonto(TroncoPiramide->BaseMenor->P1, TroncoPiramide->BaseMenor->P2);
    alt = TroncoPiramide->altura;
    return (dista+distb)*2*alt ;

}
double ArestaTroncoPiramideQuadrangular(TRONCO_PIRAMIDE_QUADRANGULAR *TroncoPiramide)
{
    double arest;
    arest = DistanciaPonto(TroncoPiramide->BaseMenor->P1, TroncoPiramide->BaseMaior->P1);
    return arest;

}
double DiagonalBaseTroncoPiramideQuadrangular(TRONCO_PIRAMIDE_QUADRANGULAR *TroncoPiramide)
{


    return DiagonalQuadrado(TroncoPiramide->BaseMaior);
}
void IniciarTroncoPiramideQuadrangular(TRONCO_PIRAMIDE_QUADRANGULAR **TroncoPiramide, QUADRADO *QMaior, QUADRADO *QMenor)
{


    (*TroncoPiramide) = malloc(sizeof(TRONCO_PIRAMIDE_QUADRANGULAR));

    (*TroncoPiramide)->BaseMaior = QMaior;
    (*TroncoPiramide)->BaseMenor = QMenor;


    return;

}

void FinalizarTroncoPiramideQuadrangular(TRONCO_PIRAMIDE_QUADRANGULAR *TroncoPiramide)
{
    if (TroncoPiramide)
    {
        FinalizarPonto(TroncoPiramide->BaseMaior->P1);
        FinalizarPonto(TroncoPiramide->BaseMaior->P2);
        FinalizarPonto(TroncoPiramide->BaseMaior->P3);
        FinalizarPonto(TroncoPiramide->BaseMaior->P4);
        FinalizarPonto(TroncoPiramide->BaseMenor->P1);
        FinalizarPonto(TroncoPiramide->BaseMenor->P2);
        FinalizarPonto(TroncoPiramide->BaseMenor->P3);
        FinalizarPonto(TroncoPiramide->BaseMenor->P4);
    }


}
void MostrarTroncoPiramideQuadrangular(TRONCO_PIRAMIDE_QUADRANGULAR *TroncoPiramide)
{
    printf("Base Maior pontos: ");
    MostrarQuadrado(TroncoPiramide->BaseMaior);
    printf("Base Menor pontos: ");
    MostrarQuadrado(TroncoPiramide->BaseMenor);
    return;
}
double VolumeTroncoPiramideQuadrangular(TRONCO_PIRAMIDE_QUADRANGULAR *TroncoPiramide)
{
    double areame, areama, vol, alt, raiz;
    areame = AreaQuadrado(TroncoPiramide->BaseMenor);
    areama = AreaQuadrado(TroncoPiramide->BaseMaior);
    raiz = sqrt(areame*areama);
    alt = TroncoPiramide->altura;
    vol = (areama+raiz+areame)*alt/3;
    return vol;


}

