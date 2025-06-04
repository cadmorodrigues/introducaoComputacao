function [ ] = prodcartesiano( A,B )
t=length(A);
k=1;
for i=1:t
    for j=1:t
        produtocart(k)=A(i)*B(j);
        k=k+1;
    end
end
disp(produtocart)

