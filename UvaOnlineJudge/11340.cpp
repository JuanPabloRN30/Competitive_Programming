#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k, val;
    double acum;
    char carac;
    string linea;
    cin >> n;
    while(n--)
    {
        map < char , int > mapa;
        cin >> k;
        while(k--)
        {
            cin >> carac >> val;
            mapa[ carac ] = val;
        }
        cin >> k;
        cin.ignore();
        acum = 0.0;
        for(int i = 0 ; i < k ; i++)
        {
            getline(cin, linea);
            for(int j = 0 ; j < linea.size() ; j++)
                acum += mapa[ linea[j] ];
        }
        acum /= 100.0;
        cout << fixed << setprecision(2) << acum << "$\n";
    }
    return 0;
}
