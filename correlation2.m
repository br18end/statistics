function [r,p] = correlacion2(x,y)
  n = length(x);
  #pearson calc
  r = ((n.*sum(x.*y))-(sum(x).*sum(y)))/(sqrt((n*sum(x.^2)-(sum(x))^2)*(n*sum(y.^2)-(sum(y))^2)))
  #get orden
  x2 = zeros(1,n);
  y2 = zeros(1,n);
  D2 = zeros(1,n);
  #orden x
  for i = 1:n
    r = 1;
    s = 1;
    for j = 1:i
      if (x(j) < x(i))
        r++;
      elseif (x(j) == x(i))
        s++;
      endif
    end
    for k = i+1:n
      if (x(k) < x(i))
        r++;
      elseif (x(k) == x(i))
        s++;
      endif
    end
    #Fractional Rank formula >> fractional_rank = r + (n-1)/2
    x2(i) = r + (s-1) * 0.5;
  end
  #range y
  for i = 1:n
    r = 1;
    s = 1;
    for j = 1:i
      if (y(j) < y(i))
        r++;
      elseif (y(j) == y(i))
        s++;
      endif
    end
    for k = i+1:n
      if (y(k) < y(i))
        r++;
      elseif (y(k) == y(i))
        s++;
      endif
    end 
    #Fractional Rank formula >> fractional_rank = r + (n-1)/2
    y2(i) = r + (s-1) * 0.5;
  end
  for i = 1:n
    D2(i) = (x2(i) - y2(i)).^2;
  end
  #spearman calc
  p = 1 - ((6.*sum(D2))/(n.^3-n))
