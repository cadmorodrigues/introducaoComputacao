clc
clear

a=input('Entre com o valor de a: ');
b=input('Entre com o valor de b: ');
c=input('Entre com o valor de c: ');
d=input('Entre com o valor de d: ');
N=input('Entre com o valor de N: ');
A=input('Entre com o limite inferior do intervalo: ');
B=input('Entre com o limite superior do intervalo: ');
x0=input('Entre com o valor de x0: ');
t=input('Entre com a tolerancia: ');

while(1)
    
    opcao=menu('Calculo da raiz de uma equação de terceiro grau','Calculo usando N iterações','Calculo usando tolerância','Gráfico g(x) e h(x)','Calculo função f(x0)','Calculo função f(x) entre a e b','Finalizar programa');
    
    switch opcao
        case 1
            AA=A;
            BB=B;
            contador=1;
            while contador<=N
                
            yA=a*(AA^3)+b*(AA^2)+c*AA+d;
            yB=a*(BB^3)+b*(BB^2)+c*BB+d;
            xm=(AA+BB)/2;
            y=a*(xm^3)+b*(xm^2)+c*xm+d;
            if (y>0 && yA>0)
                AA=xm;
            end
            if (y>0 && yB>0)
                BB=xm;
            end
            if (y<0 && yA<0)
                AA=xm;
            end
            if (y<0 && yB<0)
                BB=xm;
            end
            contador=contador+1;
            end
            fprintf('O intervalo é  [%.2f,%.2f].\n',AA,BB);
            
        case 2
            AA=A;
            BB=B;
            xm=(AA+BB)/2;
            y=a*(xm^3)+b*(xm^2)+c*xm+d;
            while y>t
            yA=a*(AA^3)+b*(AA^2)+c*AA+d;
            yB=a*(BB^3)+b*(BB^2)+c*BB+d;
            xm=(AA+BB)/2;
            y=a*(xm^3)+b*(xm^2)+c*xm+d;
            disp('teste');
            if (y>0 && yA>0)
                AA=xm;
            end
            if (y>0 && yB>0)
                BB=xm;
            end
            if (y<0 && yA<0)
                AA=xm;
            end
            if (y<0 && yB<0)
                BB=xm;
            end
            end
            xm=(A+B)/2;
            fprintf('O intervalo é  [%.2f,%.2f], e o valor da raiz é %.2f.\n',AA,BB,xm);
            
        case 3
            xx=A:0.000001:B;
            yy=a.*(xx.^3)+b.*(xx.^2)+c.*xx+d; %o pontinho significa que a função vai receber cada elemento do vetor separadamente. um de cada vez
            plot(xx,yy);
            
        case 4
            y=a*(x0^3)+b*(x0^2)+c*x0+d;
            fprintf('O valor de f(%.2f)=%.2f.\n',x0,y);
            
        case 5
            xm=(A+B)/2;
            y=a*(xm^3)+b*(xm^2)+c*xm+d;
            fprintf('O valor é %.2f.\n',y);
        case 6
            break;
    end
    
    
end
