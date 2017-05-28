// TALLER NO 4
// TALLER NO 5
// TALLER NO 6
#include <bits/stdc++.h>

using namespace std;

struct Ticket
{
  int start;
  int destiny;
  int number_pass;
  Ticket(int start, int destiny, int number_pass)
  {
    this->start = start;
    this->destiny = destiny;
    this->number_pass = number_pass;
  }
};

bool comp( Ticket t1 , Ticket t2 )
{
  if( t1.start != t2.start )
    return t1.start < t2.start;
  return t1.destiny < t2.destiny;
}

vector < Ticket > tickets;
int capacity;
int destino;

int sum_pasajeros( vector < int > &bajadas, int destino  )
{
  int acum = 0;
  for(int i = 0 ; i <= destino;  i++)
  {
    acum += bajadas[ i ];
  }
  return acum;
}

void delete_pasajeros( vector < int > &bajadas, int origen )
{
  for(int i = 0 ; i <= origen ; i++)
    bajadas[ i ] = 0;
}

int total(int posicion, int costo_actual, vector < int > bajadas)
{
  if( posicion == (int)tickets.size() )
    return costo_actual;

  delete_pasajeros( bajadas, tickets[ posicion ].start );
  int pasajeros = sum_pasajeros( bajadas, tickets[ posicion ].destiny );
  if( pasajeros + tickets[ posicion ].number_pass <= capacity )
  {
      int value_second = total( posicion+1, costo_actual, bajadas );
      int costo_aux = (tickets[ posicion ].destiny - tickets[ posicion ].start) * tickets[ posicion ].number_pass;
      bajadas[ tickets[ posicion ].destiny ] += tickets[ posicion ].number_pass;
      int value_first = total( posicion+1, costo_actual+costo_aux, bajadas  );
      return max(value_first,value_second);
  }
  else
    return total( posicion+1, costo_actual, bajadas );
}

int main()
{
  int number_tickets;
  while( scanf("%d%d%d",&capacity,&destino,&number_tickets ) && (capacity+destino+number_tickets) )
  {
    int a,b,c;
    tickets.clear();
    vector < int > bajadas( destino+1,0 );
    for(int i = 0 ; i < number_tickets ; i++)
    {
      scanf("%d%d%d",&a,&b,&c);
      tickets.push_back(Ticket( a, b, c ));
    }
    sort(tickets.begin(),tickets.end(),comp);
    printf("%d\n",total( 0,0, bajadas ) );
  }

  return 0;
}
