function [ ] = intersecao( A,B )
t=length(A);
cont=0;
for i=1:t
    intersec(i)=A(i);
    intersec(i+t)=B(i);
end
for i=1:t*2
    for j=1:t*2
        if intersec(i)==intersec(j) && i~=j
            cont=cont+1;
        end
    end
    if cont>0
        fprintf('%i\t',intersec(i));
    end
    cont=0;
end


