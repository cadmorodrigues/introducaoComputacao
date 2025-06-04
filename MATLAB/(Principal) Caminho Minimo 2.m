%distancia critica
d = 7;

%distancia infinita
inf = intmax;

%5 cidades
%matriz de distancias
M = [inf 5 2 3 4; 5 inf 1 1 5; 2 1 inf 2 4; 3 1 2 inf 6; 4 5 4 6 inf];

%vetor com a populacao das cidades
P = [200 150 325 230 120];

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
p           %soma das populações
l(c,:)      %cidades que foram somadas
