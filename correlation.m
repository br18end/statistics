function [r,p] = correlation(x,y)
  n = length(x);
  #pearson calc
  r = ((n.*sum(x.*y))-(sum(x).*sum(y)))/(sqrt((n*sum(x.^2)-(sum(x))^2)*(n*sum(y.^2)-(sum(y))^2)))
  #get order
  x2 = zeros(1,n);
  y2 = zeros(1,n);
  D2 = zeros(1,n);
  for j = 1:n
    for i = 2:n
      if(x(i-1)>x(i))
        aux=i-1;
        x2(i-1)=i;
        x2(i)=aux;
      elseif(x(i-1)==x(i))
        aux=((i-1)+i)/2;
        x2(i-1)=aux;
        x2(i)=aux;
      else
        x2(i-1)=i-1;
        x2(i)=i;
      end
      if(y(i-1)>y(i))
        aux=i-1;
        y2(i-1)=i;
        y2(i)=aux;
      elseif(y(i-1sstata)==y(i))
        aux=(i-1+(i))/2;
        y2(i-1)=aux;
        y2(i)=aux;
      else
        y2(i-1)=i-1;
        y2(i)=i;
      end
    end
  end
  x2
  y2
  for i = 1:n
    D2(i) = (x2(i) - y2(i)).^2;
  end
  #spearman calc
  p = 1 - ((6.*sum(D2))/(n.^3-n))
