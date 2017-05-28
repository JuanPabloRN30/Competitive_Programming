#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n,puntaje;
  string nombre;
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  map < string , int > mapa;
  vector < pair < string , int > > ronda;
  while( n-- )
  {
    cin >> nombre >> puntaje;
    ronda.push_back( make_pair(nombre,puntaje) );
    if( mapa.find( nombre ) == mapa.end() )
      mapa[ nombre ] = puntaje;
    else
      mapa[ nombre ] += puntaje;
  }
  map < string , int >::iterator it;
  set < string > winners;
  int mayor_puntaje = 0;
  for( it = mapa.begin() ; it != mapa.end() ; it++ )
  {
    if( mayor_puntaje < it->second )
      mayor_puntaje = it->second;
  }
  for( it = mapa.begin() ; it != mapa.end() ; it++ )
  {
    if( it->second == mayor_puntaje )
      winners.insert( it->first );
  }
  mapa.clear();
  if( winners.size() == 1 )
    cout << *winners.begin() << endl;
  else
  {
    for( int i = 0 ; i < ronda.size() ; i++ )
    {
      if( mapa.find( ronda[ i ].first ) == mapa.end() )
        mapa[ ronda[ i ].first ] = ronda[ i ].second;
      else
        mapa[ ronda[ i ].first ] += ronda[ i ].second;
      if( mapa[ ronda[ i ].first ] >= mayor_puntaje && winners.find( ronda[ i ].first ) != winners.end() )
      {
        cout << ronda[ i ].first << endl;
        break;
      }
    }
  }


  return 0;
}
