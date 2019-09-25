function n = disnormal(a,b,n,u,o2)
  sum = 0;
  for i = 1:n
    ti = a + ((b-a)/n) * i;u
    sum = sum + ((1/sqrt(2*pi*o2)) * e^-(((ti-u)^2)/(2 * o2)));
  end
  sumfinal = sum * ((b-a)/n);
n = sumfinal;
