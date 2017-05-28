#include <bits/stdc++.h>

using namespace std;

char board[ 30 ][ 30 ];
short dp[ 30 ][ 30 ];
int n;
int dx[] = { -1, -1,  1, 1 };
int dy[] = { -1,  1, -1, 1 };

bool isGood( int x, int y )
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

void printBoard()
{
    for( int i = 0 ; i < n ; i++ )
    {
        for( int j = 0 ; j < n ; j++ )
        {
            cout << board[ i ][ j ] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int backtrack( int x, int y)
{
   /* printBoard();
   system("pause");*/
    if( dp[ x ][ y ] != -1 )
        return dp[ x ][ y ];
    int acum = 0;
    for( int i = 0 ; i < 4 ; i++ )
    {
        int currenti = dx[ i ] + x;
        int currentj = dy[ i ] + y;
        if( isGood( currenti, currentj ) && board[ currenti ][ currentj ] == 'W' )
        {
            int currentii = dx[ i ] + currenti;
            int currentjj = dy[ i ] + currentj;
            if( isGood( currentii, currentjj ) && board[ currentii ][ currentjj ] == '_' )
            {
                board[ x ][ y ] = '_';
                board[ currenti ][ currentj ] = '_';
                board[ currentii ][ currentjj ] = 'B';
                acum = max(backtrack( currentii, currentjj) + 1, acum);
                board[ x ][ y ] = 'B';
                board[ currenti ][ currentj ] = 'W';
                board[ currentii ][ currentjj ] = '_';
            }
        }
    }
    return dp[ x ][ y ] = acum;
}

int main()
{
    scanf("%d",&n);
    queue < pair < int , int > > q;
    int totalBlancas = 0;
    for( int i = 0 ; i < n ; i++ )
    {
        for( int j = 0 ; j < n ; j++ )
        {
            cin >> board[ i ][ j ];
            if( board[ i ][ j ] == 'B' )
                q.push( make_pair( i,j ) );
            else if( board[ i ][ j ] == 'W' )
                totalBlancas++;
        }
    }
    int cont = 0;
    pair < int , int > res;
    memset( dp, -1, sizeof dp );
    while( !q.empty() )
    {
        if( backtrack( q.front().first, q.front().second) == totalBlancas )
        {
            cont ++;
            res = q.front();
        }
        q.pop();
    }
    if( cont == 1 )
    {
        cout << (char)('a'+res.second) << n-res.first << endl;
    }
    else if( cont > 1 )
        cout << "Multiple" << endl;
    else
        cout << "None" << endl;

    return 0;
}
