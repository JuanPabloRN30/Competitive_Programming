#include <bits/stdc++.h>

using namespace std;

bool verificar(string linea, int ini, int fin)
{
  int cont,cont1;
  cont = cont1 = 0;
  for(int i = ini ; i <= fin ; i++)
  {
      if(linea[i] == '0')
        cont++;
      if(linea[i] == '1')
        cont1++;
  }
  if(cont == 0 && cont1 > 0)
    return true;
  else if(cont1 == 0 && cont > 0)
    return true;
  else if(cont1 > 0 && cont > 0)
    return false;

}

int main()
{
  string linea;
  int cont = 1;
  while(cin >> linea)
  {
    int numero;
    cin >> numero;
    int ini,fin;
    printf("Case %d:\n",cont++);
    for(int i = 0 ; i < numero ; i++)
    {
      cin >> ini >> fin;

      if(verificar(linea,min(ini,fin),max(fin,ini)))
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }


  return 0;
}
