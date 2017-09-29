#include <iostream>
#include <bitset>
#include <cstring>

using namespace std;

int main()
{
    string linea;
    int pos;
    cin >> linea;
    bitset < 26 > bs;
    int cant[ 26 ];
    memset(cant, 0, sizeof cant);
    for(int i = 0 ; i < (int)linea.size() ; i++)
    {
        pos = linea[i] - 'a';
        bs[pos] = 1;
        cant[pos]++;
    }
    int complexi = bs.count();
    int ans = 0;
    int menor;
    while( complexi > 2)
    {
        menor = 1e9;
        for(int i = 0 ; i < 26 ; i++)
        {
            if(bs[i])
            {
                if(cant[i] < menor)
                {
                    menor = cant[i];
                    pos = i;
                }
            }
        }
        bs[pos]=0;
        ans += cant[pos];
        cant[pos] = 0;
        complexi = bs.count();
    }
    cout << ans << '\n';
  return 0;
}
