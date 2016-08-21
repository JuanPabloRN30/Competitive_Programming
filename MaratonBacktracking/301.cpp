#include <bits/stdc++.h>

using namespace std;

int total_pasajeros;
int ciudad_fin;

struct Ticket
{
  int starting;
  int destination;
  int number_pass;
  Ticket( int starting, int destination, int number_pass)
  {
    this->starting = starting;
    this->destination = destination;
    this->number_pass = number_pass;
  };

  bool operator < ( Ticket other) const
  {
    if(this->starting < other.starting)
    return true;
    else if(this->starting == other.starting)
    return this->destination < other.destination;
    return false;
  }
};

long long backtrack(vector < Ticket > &information, int n, int pasajeros, vector < int > total)
{

  if( n >= (int)information.size() )
  {
    return 0;
  }
  long long maximo = 0;
  long long value = 0;
  if(pasajeros+information[ n ].number_pass <= total_pasajeros)
  {
    value = information[ n ].number_pass * ( information[ n ].destination - information[ n ].starting );
    pasajeros += information[ n ].number_pass;
    total [ information[ n ].destination ] += information[ n ].number_pass;
    maximo = value;
  }
  for(int x = n+1 ; x < (int)information.size() ; x++)
  {
    for(int j = 0 ; j < (int)total.size() ; j++)
    {
      if( j == information[ x ].starting )
      {
        pasajeros -= total[ j ];
      }
    }
    if(pasajeros+information[ x ].number_pass <= total_pasajeros && information[ x ].starting <= ciudad_fin && information[ x ].destination <= ciudad_fin)
    {
      maximo = max(maximo,value + backtrack( information, x, pasajeros, total));
    }
  }
  return maximo;
}

void imprimir(vector < Ticket > information)
{
  for(int i = 0 ; i < (int)information.size() ; i++)
  {
    printf("%d %d %d\n",information[i].starting,information[i].destination,information[i].number_pass );
  }
  printf("\n");
  printf("\n");
}

int main()
{
  int b,tickets;
  while(scanf("%d%d%d",&total_pasajeros,&b,&tickets) && (total_pasajeros+b+tickets))
  {
    ciudad_fin = b;
    vector < Ticket > information;
    int s,d,number;
    for(int i = 0 ; i < tickets ; i++)
    {
      scanf("%d%d%d",&s,&d,&number );
      information.push_back(Ticket(s,d,number));
    }
    sort(information.begin(),information.end());
    long long maxi = 0;
    //for(int i = 0 ; i < tickets ; i++)
    //{
    vector < int > pasajeros(b+1,0);
    maxi = max(maxi,backtrack(information,0,0,pasajeros));
    //}
    printf("%lld\n",maxi);

  }
  return 0;
}
