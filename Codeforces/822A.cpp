#include <iostream>

using namespace std;

typedef long long ll;

ll factorial( ll n )
{
  ll fact = 1;
  for( ll i = 2 ; i <= n ; i++ )
  {
    fact *= i;
  }
  return fact;
}

int main()
{
  ll n, m;
  cin >> n >> m;
  cout << factorial(min(n,m)) << '\n';
  return 0;
}
