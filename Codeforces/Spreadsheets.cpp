#include <bits/stdc++.h>

using namespace std;

int toNum( char letra )
{
    return (letra - 'A')+1;
}

int toNum1( char letra )
{
    return (letra - '0');
}

char toChar( int num )
{
    --num;
    return 'A'+num;
}

int buscarLetra( string linea )
{

    for( int i = (int)linea.size()-1 ; i >= 0 ; i-- )
        if( linea[ i ] >= 'A' && linea[ i ] <= 'Z' ) return i;
    return -1;
}

void ans( string linea )
{
    int pos = buscarLetra( linea );
    long long base = 1;
    long long acum = 0;
    for( int i = pos ; i >= 0 ; i-- )
    {
        acum += toNum(linea[ i ])*base;
        base *= 26LL;
    }
    cout << 'R';
    for( int i = pos + 1 ; i < (int)linea.size() ; i++ )
        cout << linea[ i ];
    cout << 'C' << acum << endl;
}

bool regexx( string linea )
{
    if( linea[ 0 ] == 'R' )
    {
        int i = 1;
        while( i < (int)linea.size() && linea[ i ] >= '0' && linea[ i ] <= '9' )
            i++;
        if( i == 1 ) return false;
        if( linea[ i ] == 'C' )
            return true;
    }
    return false;
}

int toNumm( string linea, int inicio)
{
    long long pot = 1;
    long long numero = 0;
    for( int i = linea.size()-1 ; i >= inicio ; i-- )
    {
        numero+= toNum1( linea[ i ] ) * pot;
        pot*=10;
    }
    return numero;
}

void ans1( string linea )
{
    int ini = 1, fin;
    int i = 1;
    while( i < (int)linea.size() && linea[ i ] >= '0' && linea[ i ] <= '9' )
        i++;
    fin = i;
    stack < char > ans;
    int numero = toNumm( linea, i+1 );
    while( numero )
    {
      if( numero%26 == 0 )
      {
        ans.push( 'Z' );
        numero--;
      }
      else
        ans.push( toChar(numero%26) );
      numero /= 26;
    }
    while( !ans.empty() )
    {
        cout << ans.top();
        ans.pop();
    }
    for( int i = ini ; i < fin ; i++ )
        cout << linea[ i ];
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    while( n-- )
    {
        string linea;
        cin >> linea;
        if( regexx( linea ) )
            ans1( linea );
        else
            ans( linea );
    }
    return 0;
}
