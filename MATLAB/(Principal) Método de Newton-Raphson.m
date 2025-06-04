%Algoritmo para o método de iterações Newton-Raphson
%Autor: Cádmo Rodrigues
%Fevereiro de 2017
 
clear
clc
format longeng
 
%%Dados
%Distâncias (mm) e ?2 (º)
r1 = 300;
r2 = 100;
r3 = 250;
r4 = 200;
t2 = 60;
t3 = 30; % Valor "chutado" para primeira interação
t4 = 100; % Valor "chutado" para primeira interação
n_iteracoes = 0; %Conta número de interações
rPg = 180/pi; %Constante para converter valor em radianos para graus 
Delta_Teta=[0 0];
 
%Funções
f1 = @(t3,t4) (r1+(r4*(cosd(180)*cosd(t4)+sind(180)*sind(t4)))-r2*cosd(t2)-r3*cosd(t3)); % Função f1 (eixo x)
f2 = @(t3,t4) (r4*(sind(180)*cosd(t4)-cosd(180)*sind(t4))-r3*sind(t3)-r2*sind(t2)); % Função f2 (eixo y)
 
%Derivadas
df1_t3 = @(t3,t4) r3*sind(t3);
df1_t4 = @(t3,t4) r4*((cosd(t4)*sind(180))-(sind(t4)*cosd(180)));
df2_t3 = @(t3,t4) -r3*cosd(t3);
df2_t4 = @(t3,t4) r4*((-sind(180)*sind(t4))-(cosd(180)*cosd(t4)));
 
%Primeiro cálculo com valores "chutados"
resp_f1 = f1(t3,t4);
resp_f2 = f2(t3,t4);
    
while (abs(resp_f1) >= 0.00000000001 && abs(resp_f2) >= 0.00000000001)
    %Calculando as funções e suas derivadas com os atuais valores de teta
    resp_df1_t3 = df1_t3(t3,t4);
    resp_df1_t4 = df1_t4(t3,t4);
    resp_df2_t3 = df2_t3(t3,t4);
    resp_df2_t4 = df2_t4(t3,t4);
    
    %Para achar ??3 e ??4, jogamos na série de Taylor e resolvemos o
    %sistema B=A.x
    A = [resp_df1_t3 , resp_df1_t4 ; resp_df2_t3 , resp_df2_t4];
    B = [-resp_f1 ; -resp_f2];
    Delta_Teta = linsolve(A,B);
    
    %Conferindo se ??3 e ??4 são zero, pois caso sejam, não há solução
    if (Delta_Teta(1)==0 || Delta_Teta(2)==0)
        disp('Processo encerrado, a solução não converge');
        break;
    end
    
    %Incrementando teta para próximo loop 
    t3 = t3 + Delta_Teta(1)*rPg;
    t4 = t4 + Delta_Teta(2)*rPg; 
    
    %Contando número de interações
    n_iteracoes = n_iteracoes + 1;
    
    %Calculando com novos valores e teta e verificando se iguala a zero
    resp_f1 = f1(t3,t4);
    resp_f2 = f2(t3,t4);
end
fprintf('\t\t\t---------------------------------------------------------\n');
fprintf('\t\t\t\tAlgoritmo para método de iterações Newton-Raphson\n\t\t\t\t\tAutor: Cádmo Rodrigues, Fevereiro de 2017\n');
fprintf('\t\t\t---------------------------------------------------------\n\n');
disp('Equacao f1: '); disp(f1); disp('Equacao f2: '); disp(f2);
fprintf('- > Depois de %i iterações, concluiu-se que teta t3 vale %.2fº\n\n',n_iteracoes,t3);
fprintf('- > Em relação à teta t4, devemos fazer uma observação.\n')
fprintf('\tComo trabalhamos com o ângulo de dentro e t4 foi escolhido como o ângulo de fora,\n');
fprintf('\tdevemos ainda subtrair 180º para achar o valor real de t4.\n');
fprintf('\n\t\t\t\t\tLogo, t4 = 180º - %.2fº\n',t4);
t4_externo=180-t4;
fprintf('\t\t\t\t\t\t\t t4 = %.2fº\n\n',t4_externo)
fprintf('- > Para confirmar o resultado, joguemos os valores de teta encontrados em f1 e f2. \n');
fprintf('\tObtemos, como resultado, \n\n\t\t\tf1(%.2fº,%.2fº) = %f e f2(%.2fº,%.2fº) = %f\n\n',t3,t4,abs(f1(t3,t4)),t3,t4,abs(f2(t3,t4)));
