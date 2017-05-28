#include <bits/stdc++.h>

using namespace std;

int matriz[ 1010 ][ 1010 ];
int n;
int menor;
string ans_path;

bool in( int i , int j)
{
  return i >= 0 && i < n && j >= 0 && j < n;
}

int countZero( unsigned long long n )
{
  unsigned long long ten = 10;
  int cont = 0;
  while( n )
  {
    if( n%ten == 0 ) cont++;
    else break;
    n/=ten;
  }
  return cont;
}

void solve( int i , int j, unsigned long long multi, string path )
{
  if( i == n - 1 && j == n - 1 )
  {
    int aux = countZero( multi );
    if( aux < menor )
    {
      menor = aux;
      ans_path = path;
    }
  }

  if( in( i+1,j ) )
    solve( i+1, j, multi * matriz[ i + 1 ][ j ], path + 'D' );
  if( in( i,j + 1 ) )
    solve( i, j + 1, multi * matriz[ i ][ j+ 1], path + 'R' );
}

int main()
{
  memset( matriz, 0 , sizeof matriz );
  menor = 1e9;
  cin >> n;
  for( int i = 0 ; i < n ; i++ )
  {
    for( int j = 0 ; j < n ; j++ )
      cin >> matriz[ i ][ j ];
  }
  unsigned long long multi = 1;
  string path = "";
  solve(0,0, multi, path);
  cout << menor << '\n';
  cout << ans_path << '\n';

  return 0;
}
