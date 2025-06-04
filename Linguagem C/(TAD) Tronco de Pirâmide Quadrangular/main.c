#include <stdio.h>
#include <stdlib.h>
#include "quadrado.h"
#include "tronco-piramide-quadrangular.h"
#include "ponto.h"

int main()
{
    QUADRADO *QMaior,*QMenor;

    TRONCO_PIRAMIDE_QUADRANGULAR *Piramide;

    PONTO *P1,*P2,*P3,*P4,*P5,*P6,*P7,*P8;

    double x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8;

    printf("\nX do Ponto P1: ");
    scanf("%lf%*c", &x1);
    printf("\nY do Ponto P1: ");
    scanf("%lf%*c", &y1);
    printf("\nX do Ponto P2: ");
    scanf("%lf%*c", &x2);
    printf("\nY do Ponto P2: ");
    scanf("%lf%*c", &y2);
    printf("\nX do Ponto P3: ");
    scanf("%lf%*c", &x3);
    printf("\nY do Ponto P3: ");
    scanf("%lf%*c", &y3);



    printf("\nX do Ponto P4: ");
    scanf("%lf%*c", &x4);
    printf("\nY do Ponto P4: ");
    scanf("%lf%*c", &y4);
    printf("\nX do Ponto P5: ");
    scanf("%lf%*c", &x5);
    printf("\nY do Ponto P5: ");
    scanf("%lf%*c", &y5);
    printf("\nX do Ponto P6: ");
    scanf("%lf%*c", &x6);
    printf("\nY do Ponto P6: ");
    scanf("%lf%*c", &y6);
    printf("\nX do Ponto P7: ");
    scanf("%lf%*c", &x7);
    printf("\nY do Ponto P7: ");
    scanf("%lf%*c", &y7);
    printf("\nX do Ponto P8: ");
    scanf("%lf%*c", &x8);
    printf("\nY do Ponto P8: ");
    scanf("%lf%*c", &y8);


    IniciarPonto(&P1, x1, y1);
    IniciarPonto(&P2, x2, y2);
    IniciarPonto(&P3, x3, y3);

    IniciarPonto(&P4, x4, y4);

    IniciarPonto(&P5, x5, y5);

    IniciarPonto(&P6, x6, y6);

    IniciarPonto(&P7, x7, y7);

    IniciarPonto(&P8, x8, y8);

    IniciarQuadrado(&QMaior,P1, P2, P3, P4);
    IniciarQuadrado(&QMenor,P5, P6, P7, P8);

    IniciarTroncoPiramideQuadrangular(&Piramide, QMaior,QMenor);

    MostrarTroncoPiramideQuadrangular(Piramide);

    printf("\n diagonal da base: %.2lf",DiagonalBaseTroncoPiramideQuadrangular(Piramide));

    printf("\n aresta: %.2lf",ArestaTroncoPiramideQuadrangular(Piramide));

    printf("\n Area Base maior: %.2lf",AreaBaseMaiorTroncoPiramideQuadrangular(Piramide));
    printf("\n Area Base menor: %.2lf",AreaBaseMenorTroncoPiramideQuadrangular(Piramide));
    printf("\nAltura do tronco de piramide: %lf ",AlturaTroncoPiramideQuadrangular(Piramide));
    printf("\n area da superficie lateral: %.2lf",AreaSuperficieLateralTroncoPiramideQuadrangular(Piramide));
    printf("\n area total: %.2lf",AreaTotalTroncoPiramideQuadrangular(Piramide));
    fflush(stdin);
    printf("\nVolume: %.2lf",VolumeTroncoPiramideQuadrangular(Piramide));
    FinalizarTroncoPiramideQuadrangular(Piramide);
    return 0;
}
