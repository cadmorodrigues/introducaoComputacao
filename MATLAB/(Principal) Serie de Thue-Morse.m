clear
clc
n=input('Entre com a quantidade de negações: '); 
j=[0];
while n>0
    j=[j not(j)];
    n=n-1;
end
tamanho=length(j);

for i=1:1:tamanho
fprintf('%i\t',j(i));
end