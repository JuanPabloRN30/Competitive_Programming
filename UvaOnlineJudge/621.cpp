#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  while( n-- )
  {
    string linea;
    cin >> linea;
    if( linea.size() <= 2)
      printf("+\n");
    else if( linea[linea.size()-1] == '5' && linea[linea.size()-2] == '3')
      printf("-\n");
    else if( linea[linea.size()-1] == '8' && linea[linea.size()-2] == '7')
      printf("?\n");
    else if(linea[0] == '9' && linea[linea.size()-1] == '4')
      printf("*\n");
    else if( linea.size() == 4 && (linea[linea.size()-1] == '1' || linea[linea.size()-1] == '4'))
      printf("?\n");
  }
  return 0;
}
