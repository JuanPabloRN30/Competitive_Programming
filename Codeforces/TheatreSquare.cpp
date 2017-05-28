#include <bits/stdc++.h>

using namespace std;
int main()
{
  long long n,m,a;
  cin >> n >> m >> a;
  long long filas = ceil(n/(double)a);
  long long columnas = ceil(m/(double)a);
  cout << filas * columnas << endl;
  return 0;
}
