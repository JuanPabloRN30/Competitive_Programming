#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  scanf("%d",&t);
  for(int i = 0 ; i < t ; i++)
  {
    string linea;
    cin >> linea;
    deque < char > cola;
    string min = "";
    for(int j = 0 ; j < (int)linea.size() ; j++)
    {
      string aux = min + linea[j];
      string aux1 = linea[j] + min;
      if(aux < aux1)
      {
        min = aux1;
      }
      else
      {
        min = aux;
      }
    }
    cout << "Case #" << i+1 << ": " << min << endl;
  }


  return 0;
}
