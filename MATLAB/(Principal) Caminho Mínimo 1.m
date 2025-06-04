clear
clc

%distancia critica
d = input ('Digite a distância critica: ');

%distancia infinita
inf = intmax;

%Quantidade de cidades
n_cidades=input('Digite o número de cidades: ');

%matriz de distancias
for i=1:n_cidades
    for j=1:n_cidades
        M(i,j)=input('Digite a matriz distância, considerando a diagonal principal como inf ao invés de 0: ');
    end
end

M_original=M; %Manter matriz distancia original

%vetor com a populacao das cidades
for i=1:n_cidades
    P(i)=input('Digite a população de cada cidade: ');
end

%n contem a quantidade de cidades
n = size(M);
n = n(1);
l = false(n,n);

for i=1:n 
    distancia_atual = 0;
    l(i,i) = true;              %cidade i faz parte do meu conjunto
    while distancia_atual <= d
        [m,j] = min(M(i,:));    %procuro a cidade que esta mais perto da cidade i
        M(i,j) = d + 1;         %altero valor dessa cidade para ser maior que d e nao contar essa cidade de novo
        
        if d >= distancia_atual + m                 
            distancia_atual = distancia_atual + m;      %caso seja possivel chegar nessa cidade sem ultrapassar d adiciono esse valor a distancia_atual
            l(i,j) = true;
        else
            distancia_atual = intmax;                   %caso contrario para de procurar por outras cidades
        end
    end
end

%contem a soma das populacoes de um conjunto
populacao_total = zeros(1,n);

for i=1:n
    for j=1:n
        if l(i,j) == 1
            populacao_total(i) = populacao_total(i) + P(j);     %soma o valor das populacoes de todas as cidades no conjunto
        end
    end
end

[p,c] = max(populacao_total);               %identifica o conjunto com maior populacao
fprintf('A soma das populações é: %i',p);   %soma das populações
fprintf('\nCidades somadas:\n')
disp(l(c,:));      %cidades que foram somadas
