#include <iostream>
#include <cstring>


using namespace std;

typedef pair < int ,int > ii;

int n;

int f( int number )
{
  number *= 10;
  return number %n;
}

ii encontreCiclo( int x0 )
{
  int tortoise = f(x0), hare = f(f(x0));
  while( tortoise != hare ) { tortoise = f( tortoise ); hare = f(f(hare)); }
  int mu = 0; hare = x0;
  while( tortoise != hare ) { tortoise = f( tortoise ); hare = f( hare ); mu++; }
  int lambda = 1; hare = f( tortoise );
  while( tortoise != hare ) { hare = f(hare) ; lambda++;}
  return ii( mu,lambda );
}

int main()
{
  int number;
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n;
    number = 1;
    ii ans = encontreCiclo( number );
    cout << "0.";
    if( ans.first ) ans.second+= ans.first;
    while( ans.second-- )
    {
      number *= 10;
      cout << number/n;
      number = number%n;
    }
    cout << '\n';
  }
  return 0;
}
