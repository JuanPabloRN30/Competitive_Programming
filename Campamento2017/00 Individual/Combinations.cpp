#include <bits/stdc++.h>

using namespace std;

int n,k;
vector < int > solutionss;

bool check( int num, int num1 )
{
    int pos = 0;
    map < int , int > mapa;
    while( num )
    {
        if( num&1 )
        {
            mapa[ pos ]++;
        }
        num >>=1;
        pos++;
    }
    pos = 0;
    while( num1 )
    {
        if( num1&1 )
        {
            mapa[ pos ]++;
        }
        num1 >>=1;
        pos++;
    }
    map< int , int >::iterator it;
    int cont = 0;
    for( it = mapa.begin() ; it != mapa.end() ; ++it )
    {
        if( it->second == 1 )
            cont++;
    }
    if( cont == 2 )
        return true;
    return false;
}

void print( int num )
{
    int pos = 0;
    int sum = 0;
    int cont = 0;
    while( num )
    {
        if( num&1 )
        {
            if( cont ) cout << " ";
            cout << pos;
            cont++;
        }
        num >>=1;
        pos++;
    }
    cout << '\n';
}

void recurr( int pos, int cogi, int mascara )
{
    if( cogi == k )
    {
        solutionss.push_back( mascara );
        return;
    }
    if( pos > n )
        return;
    recurr( pos + 1, cogi + 1, (1<<pos)|mascara );
    recurr( pos + 1, cogi, mascara );
}

int main()
{
    int valor,suma1,suma2,suma3,valor1;
    scanf("%d%d",&n,&k);
    recurr( 1,0,0 );
    for( int i = 0 ; i < solutionss.size()-1  ; ++i )
    {
        if( check( solutionss[ i ], solutionss[ i + 1 ] ))
        {
            print( solutionss[ i ] );
            if( i == solutionss.size()-2 )
                print( solutionss[ i + 1 ] );
        }
    }
    if( n == k )
        print( solutionss[ solutionss.size()-1 ] );
    return 0;
}
