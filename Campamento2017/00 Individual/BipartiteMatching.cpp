#include <bits/stdc++.h>

using namespace std;

#define MAX 600

int flow[ MAX ][ MAX ];
vector < vector < int > > graph;
vector < int > p;
int maxFlow;

bool bfs( int source, int sink )
{
    p.assign( graph.size(), -1 );
    queue < int > q;
    q.push( source );
    while( !q.empty() )
    {
        int curr = q.front();
        q.pop();
        if( curr == sink )
            return true;
        for( int i = 0 ; i < graph[ curr ].size() ; ++i )
        {
            int curr2 = graph[ curr ][ i ];
            if( p[ curr2 ] == -1 && flow[ curr ][ curr2 ] > 0)
            {
                p[ curr2 ] = curr;
                q.push( curr2 );
            }
        }
    }
    return p[ sink ] != -1;
}

void go( int u )
{
    if( p[ u ] == -1 )
        return;
    maxFlow = max( maxFlow, flow[ p[ u ] ][ u ] );
    go( p[ u ] );
    flow[ p[ u ] ][ u ] -= maxFlow;
    flow[ u ][ p[ u ] ] += maxFlow;
}

int edmons()
{
    int f = 0;
    while( bfs( 0, 530 ) )
    {
        maxFlow = -1;
        go( 530 );
        f += maxFlow;
    }
    return f;
}

void reconstruir(  )
{
    for( int i = 1 ; i <= 250 ; i++ )
    {
        for( int j = 0 ; j < graph [ i ].size() ; j++ )
        {
            if( flow[ i ][ graph[ i ][ j ] ] == 0 )
                printf("%d %d\n",i,graph[ i ][ j ] - 251);
        }
    }
}

int main()
{
    int n,m,nodo;
    memset( flow, 0, sizeof flow );
    scanf("%d%d",&n,&m);
    graph.assign( MAX, vector < int >() );
    for( int i = 1 ; i <= n ; i++ )
    {
        while( scanf("%d",&nodo) && nodo )
        {
            graph[ i ].push_back( nodo+251 );
            graph[ nodo + 251 ].push_back( i );
            flow[ i ][ nodo + 251 ] = 1;
        }
    }
    for( int i = 1 ; i<= 250 ; i++ )
    {
        graph[ 0 ].push_back( i );
        flow[ 0 ][ i ] = 1;
    }
    for( int i = 251 ; i<= 510 ; i++ )
    {
        graph[ i ].push_back( 530 );
        flow[ i ][ 530 ] = 1;
    }
    printf("%d\n", edmons());
    reconstruir();
    return 0;
}
