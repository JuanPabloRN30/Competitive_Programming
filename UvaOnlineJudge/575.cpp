#include <bits/stdc++.h>

using namespace std;

int skewBinary( string number )
{
    int ans = 0;
    for( int i = number.size()-1, cont = 1 ; i >= 0 ; i--, cont++ )
    {
        int numero = number[ i ] - '0';
        ans += (( 1 << cont ) - 1) * numero;
    }
    return ans;
}


int main()
{
    string number;
    while( cin >> number && number != "0" )
    {
        cout << skewBinary( number ) << endl;
    }
    return 0;
}
