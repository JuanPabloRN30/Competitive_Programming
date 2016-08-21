#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-15

int main()
{
  for(long long i = 1 ; i <= 2000 ; i++)
  {
    for(long long j = i ; j <= 2000-i ; j++)
    {
      for(long long k = j ; k <= 2000-(j+i) ; k++)
      {
        long long denominador = (i*j*k)-1000000;
        long long numerador = (i+j+k)*1000000;
        if(denominador != 0)
        {
          if(numerador%denominador == 0)
          {
            long long resultado = (numerador / denominador);
            long long suma = i+j+k+resultado;
            long long multi = (i*j*k*resultado);
            if(suma*1000000 == multi && resultado > 0 && k <= resultado && suma <= 2000)
            {
              printf("%.2lf %.2lf %.2lf %.2lf\n",i/100.0,j/100.0,k/100.0,resultado/100.0);
            }
          }
        }
      }
    }
  }
  return 0;
}
