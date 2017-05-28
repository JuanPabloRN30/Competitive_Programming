#include <bits/stdc++.h>

using namespace std;

long long power(long long x, unsigned long long y, long long p)
{
    long long res = 1;
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

bool miillerTest(long long d, int n)
{
    long long a = 2 + rand() % (n - 4);

    long long x = power(a, d, n);

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

bool isPrime(long long n, int k)
{
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;

    long long d = n - 1;
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
  long long l,u;
  int k = 4;
  while( scanf("%lld%lld",&l,&u) != EOF )
  {
    vector < long long > primes;
    for(long long i = l ; i<= u ; i++)
    {
      if( isPrime( i,k ) )
        primes.push_back( i );
    }
    int cercanos = 1e9;
    int lejanos = 0;
    pair < long long , long long > ans1,ans2;
    for(int i = 0 ; i+1 < (int)primes.size() ; i++)
    {
      // cout << primes[ i+1 ] << " " << primes[ i ] << endl;
      int diferencia = primes[ i+1 ] - primes[ i ];
      if( diferencia < cercanos )
      {
        cercanos = diferencia;
        ans1.first = primes[ i ];
        ans1.second = primes[ i+1 ];
      }
      if( diferencia > lejanos )
      {
        lejanos = diferencia;
        ans2.first = primes[ i ];
        ans2.second = primes[ i+1 ];
      }
    }
    if( cercanos == 1e9 )
      printf("There are no adjacent primes.\n");
    else
      printf("%lld,%lld are closest, %lld,%lld are most distant.\n",ans1.first,ans1.second,ans2.first,ans2.second);
  }


  return 0;
}
