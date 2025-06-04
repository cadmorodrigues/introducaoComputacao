%% main function
% mat : adjacency matrix to be treated
% a : departure node
% z : arrival node
%mat = [9999 2 1 9999 9999;
 %      2 9999 1 2 9999;
  %     1 1 9999 9999 4;
   %    9999 2 9999 9999 2;
    %   9999 3 4 2 9999]

%a = 1;

%z= 2;

function[]= main()

    mat=[9999 2 1 9999 9999; 
        2 9999 1 2 9999; 
        1 1 9999 9999 4; 
        9999 2 9999 9999 2; 
        9999 3 4 2 9999];
    
    %vertice de saida
    a = 1;

    %vertice de chegada
    z= 3;
    
    G=mat;
    [C, treatedPath] = Dijkstra(G, a, z);
    
    
    
    %prints the result
    fprintf('Custo total: %d\n', C)
    fprintf('Caminho: ')
    fprintf('%d ', treatedPath)
    fprintf('\n')
end

%% Dijkstra
% Calculates the most efficient path through a graph
% G : cost matrix of the graph
% a : departure node
% z : arrival node
%
% C : total cost form the departure node to the arrival node
% treatedPath : array representing nodes we passed through
function[C, treatedPath] = Dijkstra(G, a, z) 
    
    %calcula o tamanho da matriz G na linha 1
    sizeG = size(G, 1);

    % array containing costs of all the nodes 
    % L= dt[i] (contem os custos)
    L=ones(1,sizeG);
    
    %atribuindo infinito no vetor dt[i]
    L=L.*inf;
    L(a) = 0;

    % array containing already treated nodes
    %rot[i]
    S=[];

    % array containing previous node for each node
    path=zeros(1,sizeG);

    while (contains(S,z)==false)
        u = min(L, S);
        S=[S u];
        [L,path] = update(S, L, G, u, path);
    end
    C=L(z);
    treatedPath = treatPath(path, a, z);
end

%% contains
% Checks if a number is present in an array
% S : array
% z : number to be checked
% contains : true if z is in S, false if not
function[contains] = contains(S, z)
    contains = false;
    for i=1:length(S)
        if(S(i)==z)
            contains=true;
            break;
        end
    end
end

%% min
% Checks the minimum in an array if this minimum is not in another array
% L : the array where the minimum is searched for
% S : the array where the minimum can't be present
%
% u : the minimum
function[u] = min(L, S)
    min = inf;
    for i=1:length(L)
        if(contains(S,i)==false && L(i)<min)
            min=L(i);
            u=i;
        end 
    end
end

%% update
% Updates the weights and path arrays : all nodes accessible by u and not in S are updated
% S : nodes already treated
% L : total weights of all the nodes
% G : Cost matrix of the graph
% u : node we just treated
% path : array where path(i) represents the node we passed through before i
%
% L : updated weights
% path : updated previous nodes array
%
function[L,path] = update(S, L, G, u, path)
    for i=1:length(L)
        if(contains(S,i)==false)
            if(L(u)+G(u, i)) < L(i)
                L(i)=L(u)+G(i,u);
                path(i)=u;
            end
        end
    end
end

%% treatPath
% Reduces the path array size to the number of passed by nodes
% path : array where path(i) represents the node we passed through before i
% a : departure node
% z : arrival node
%
% treatedPath : reduced and ordered path
function[treatedPath] = treatPath(path, a, z)
    treatedPath=[z];
    while (path(z) ~= 0)
        treatedPath = [path(z) treatedPath];
        z = path(z);
    end
end