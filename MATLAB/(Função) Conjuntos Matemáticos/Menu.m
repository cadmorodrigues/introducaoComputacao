clc;
clear;
opcao=1;
while opcao>0 && opcao<=6
fprintf('*************** Laborat�rio de Programa��o *****************\n');
fprintf('*** Opera��es com conjuntos ***\n');
fprintf('1 � Gera��o de dois conjuntos de inteiros\n');
fprintf('2 � Mostrar conjuntos gerados\n');
fprintf('3 � Uni�o de dois conjuntos\n');
fprintf('4 � Interse��o dos conjuntos\n');
fprintf('5 � Produto cartesiano dos conjuntos\n');
fprintf('6 � Sair do programa\n');
opcao=input('escolher a op��o');
switch opcao
    case{1}
        tamanho=input('entre com o tamanho do conjunto');
         while tamanho <=0 || tamanho >20 || tamanho -fix(tamanho)~=0
         tamanho=input('Erro! Digite um valor entre 1 e 20');
         end
        [A,B]=gerarconj(tamanho);
    case{2}
        mostrarconj(A,B);
        pause
    case{3}
        uniaoconj(A,B);
        pause
    case{4}
        intersecao(A,B);
        pause
    case{5}
        prodcartesiano(A,B);
        pause
    case{6}
        fprintf('\n fechar programa');
end
end
