function [ ] = uniaoconj( A,B )
t=length(A);
cont=0;
for i=1:t
    uniao(i)=A(i);
    uniao(i+t)=B(i);
end
for i=1:t*2
    for j=1:t*2
        if uniao(i)== uniao(j) && i~=j
            cont=cont+1;
        end
    end
    if cont==0
            fprintf('%i\t',uniao(i));
        end
        if cont>0
            uniao(i)=0;
        end
        cont=0;
end
