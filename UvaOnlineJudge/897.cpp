#include <bits/stdc++.h>

using namespace std;

int power(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;

    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;

        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

bool miillerTest(int d, int n)
{
    int a = 2 + rand() % (n - 4);

    int x = power(a, d, n);

    if (x == 1  || x == n-1)
       return true;

    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false;
        if (x == n-1)    return true;
    }

    return false;
}

bool isPrime(int n, int k)
{
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;

    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
         if (miillerTest(d, n) == false)
              return false;

    return true;
}

long long potencia(int base, int exponente)
{
  if( exponente == 0 )
    return 1;
  long long resultado = 1;
  for(int i = 1 ; i<= exponente ; i++)
    resultado *= base;
  return resultado;
}

int main()
{
  long long n;
  int k = 4;
  while( scanf("%lld",&n) && n )
  {
    if( n >= 1e6 )
    {
      printf("0\n");
      continue;
    }
    bool bandera = true;
    long long i = n+1;
    long long limite = potencia(10,log10( n )+1);
    while( bandera && i <= limite )
    {
      if( isPrime( i,k ) )
      {
        string numero = to_string( i );
        sort( numero.begin(), numero.end() );
        bool bandera1 = true;
        do{
          if( !isPrime( stoi( numero ),k ) )
            bandera1 = false;
        }while( next_permutation(numero.begin(),numero.end()) && bandera1);
        if( bandera1 )
        {
          printf("%lld\n",i );
          bandera = false;
        }
      }
      i++;
    }
    if( bandera )
      printf("0\n");
  }


  return 0;
}
