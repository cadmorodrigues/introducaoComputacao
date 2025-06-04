function result=mochila();
clear all
clc

% =========================================================================
% Informacoes sobre itens

% Problema simples
% p = [5 6 4]; % Peso associado
% b = [2 4 3]; % Beneficio associado
% C = 8;

% =========================================================================
% Beneficio e peso maximos

p = [5 6 4]; % Peso associado
b = [2 4 3]; % Beneficio associado
C = 8;

maxBeneficio = sum(b);
maxPeso = sum(p);

% =========================================================================
% RVNS

 % Numero de itens na mochila
[t nItens] = size(p);

nVizinhanca = 3;
iteracaoTotal = 8;
iteracaoAtual = 1;
fim = false;

while fim==false
    solucao = round(rand(1,nItens)); % Solucao inicial estocastica
    if fnPeso(solucao) <=C
        fim = true;
    else
         fim = false;
    end;
end

disp('===================== INICIO ============================')
beneficio = fnBeneficio(solucao)
peso = fnPeso(solucao)
nVizinhanca
iteracaoTotal
disp('==========================================================')

while iteracaoAtual<iteracaoTotal
    k = 1;

    % Passando pelo numero de estruturas de vizinhancas
    while k <= nVizinhanca

        % Melhorar a estrutura vizinhanca
        novaSolucao = Nopt(solucao, k);

        % Verificar se a nova solucao eh melhor
        if fnBeneficio(solucao) < fnBeneficio(novaSolucao)
            
            % Caso seja melhor, verificar a restricao
            if fnPeso(novaSolucao) <= C
                solucao = novaSolucao;
                k = 1;
                % ELSE, verificar restricao de peso
            else
                k= k+1;
            end
            
            % Else, verificar beneficio
        else
            k = k+1;
        end
        
    end
    
    iteracaoAtual = iteracaoAtual+1;
end

disp('================== Resultado =============================')
solucao
beneficio = fnBeneficio(solucao)
peso = fnPeso(solucao)
disp('==========================================================')


% =========================================================================
% =========================================================================
% FUNCOES
% =========================================================================
% =========================================================================



% =========================================================================
% Funcao n-opt
    function result=Nopt(itens, n);
        [t nItens] = size(itens); % Numero de itens na mochila
        
        % Sortear N elementos
        sorteado = floor(nItens*rand(1,n))+1;

        % Fazer as mudancas em cada item que foi sorteado
        for j=1:n
            
            % Modificar o valor J
            if itens(1,sorteado(1,j)) == 0
               itens(1,sorteado(1,j)) = 1;
            else
                itens(1,sorteado(1,j)) = 0;
            end
        end
        
        result=itens;
        return;
    end

% FIM - Funcao n-opt
% =========================================================================





% =========================================================================
% Funcao para calcular o beneficio

    function result=fnBeneficio(itens);
        [t nItens] = size(itens); % Numero de itens na mochila
        somaBeneficio=0;
        for i=1:nItens    
            % Caso o item esteja na mochila 
            if itens(1,i) == 1
                somaBeneficio = somaBeneficio + b(1,i);
            end
        end   
        result = somaBeneficio;
        return
    end
% FIM - Funcao para calcular o beneficio
% =========================================================================





% =========================================================================
% Funcao para calcular o peso

    function result=fnPeso(itens);
        [t nItens] = size(itens); % Numero de itens na mochila
        somaPeso = 0;
        for i=1:nItens    
            % Caso o item esteja na mochila 
            if itens(1,i) == 1
                somaPeso = somaPeso + p(1,i);
            end
        end   
        result = somaPeso;
        return
    end
% FIM - Funcao para calcular o peso
% =========================================================================

return
end