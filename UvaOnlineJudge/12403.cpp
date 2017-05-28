#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int acum = 0;
    scanf("%d",&n);
    while( n-- )
    {
        string tipo;
        int cantidad;
        cin >> tipo;
        if(tipo == "donate")
        {
            cin >> cantidad;
            acum += cantidad;
        }
        else
            cout << acum << endl;
    }
    return 0;
}
