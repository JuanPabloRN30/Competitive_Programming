#include <bits/stdc++.h>

using namespace std;

set < pair < int , int > > pareja;
map < char , pair < int , int > > operaciones;

bool verify( pair < int , int > current_pos, pair < int , int > limit )
{
  return current_pos.first >= 0 && current_pos.first <= limit.first && current_pos.second >= 0 && current_pos.second <= limit.second;
}

void simulation(pair < int , int > pos_inicio, char direccion, string pasos, pair < int , int > limite)
{
  bool lost = false;
  for(int i = 0 ; i < (int)pasos.size() ; i++)
  {
  //  cout << pos_inicio.first << " " << pos_inicio.second << " " << direccion<< endl;
    switch (pasos[ i ]) {
      case 'R':
        if( direccion == 'N' )
          direccion = 'E';
        else if(direccion == 'E')
          direccion = 'S';
        else if(direccion == 'S')
          direccion = 'W';
        else if(direccion == 'W')
          direccion = 'N';
      break;
      case 'L':
      if( direccion == 'N' )
        direccion = 'W';
      else if(direccion == 'W')
        direccion = 'S';
      else if(direccion == 'S')
        direccion = 'E';
      else if(direccion == 'E')
        direccion = 'N';
      break;
      case 'F':
      if( verify( make_pair( pos_inicio.first + operaciones[ direccion ].first,pos_inicio.second + operaciones[ direccion ].second ), limite ) )
      {
        pos_inicio.first += operaciones[ direccion ].first;
        pos_inicio.second += operaciones[ direccion ].second;
      }
      else
      {
        if( pareja.find( pos_inicio ) == pareja.end() )
        {
          lost = true;
          pareja.insert( pos_inicio );
          printf("%d %d %c LOST\n",pos_inicio.first,pos_inicio.second,direccion);
          return;
          pos_inicio.first += operaciones[ direccion ].first;
          pos_inicio.second += operaciones[ direccion ].second;

        }
      }
      break;
    }
  }
  if( !lost )
    printf("%d %d %c\n",pos_inicio.first,pos_inicio.second,direccion);
}


int main()
{
  operaciones[ 'N' ] = make_pair(0,1);
  operaciones[ 'S' ] = make_pair(0,-1);
  operaciones[ 'E' ] = make_pair(1,0);
  operaciones[ 'W' ] = make_pair(-1,0);
  pair < int , int > limite;
  pair < int , int > pos_inicio;
  char direccion;
  scanf("%d%d",&limite.first,&limite.second);
  while( cin >> pos_inicio.first >> pos_inicio.second >> direccion )
  {
    string pasos;
    cin >> pasos;
    simulation( pos_inicio, direccion, pasos, limite );
  }
  return 0;
}
