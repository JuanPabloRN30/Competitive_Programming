#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k,minimo,maximo,value;
    string state;
    cin >> n >> k;
    minimo = 1;
    maximo = k;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> value >> state;
        if(state == "BROKEN") maximo = min(value, maximo);
        else minimo = max(minimo, value);
    }
    cout << minimo+1 << " " << maximo-1 << '\n';
    return 0;
}
