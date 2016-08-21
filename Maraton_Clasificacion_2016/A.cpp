#include <bits/stdc++.h>

using namespace std;

#define ii pair < long long , pair < int , int > >

const long long INF = 1e10;
long long minimo;

long long dijkstra(vector < vector < pair < int , long long > > > &graph, int origen, int destino)
{
  priority_queue< ii , vector < ii > , greater < ii > > cola;
  priority_queue< int , vector < int > , greater < int > > result;
  vector < long long > distancias(graph.size(),INF);
  cola.push(ii(0,make_pair(origen,0)));
  distancias[ origen ] = 0;
  while(!cola.empty())
  {
    ii actual = cola.top() ;
    cola.pop();
    int o = actual.second.first;
    long long costo = actual.first;
    int pasos = actual.second.second;
    if(costo <= distancias[ o ])
    {
      for(int i = 0 ; i < (int)graph[o].size() ; i++)
      {
        int first_son = graph[o][i].first;
        long long costo_arista_first = graph[o][i].second;
        for(int j = 0 ; j < (int)graph[first_son].size() ; j++)
        {
          int second_son = graph[ first_son ][j].first;
          long long costo_arista_second = graph[ first_son ][ j ].second;
          if(distancias[o]+costo_arista_first+costo_arista_second < distancias[ second_son ])
          {
            distancias[ second_son ] = distancias[o]+costo_arista_first+costo_arista_second;
            cola.push(ii(distancias[ second_son ],make_pair( second_son ,pasos+2)));
          }
        }
      }
    }
  }
  return distancias[destino];
}


int main()
{
  int v,e;
  //ofstream cout("out");
  while(scanf("%d%d",&v,&e) != EOF)
  {
    vector < vector < pair < int , long long > > > grafo(v, vector < pair < int , long long > > ());
    minimo = -1;
    for(int i = 0 ; i < e ; i++)
    {
      int o , d , c;
      scanf("%d%d%d",&o,&d,&c);
      grafo[o-1].push_back(make_pair(d-1,c));
      grafo[d-1].push_back(make_pair(o-1,c));
    }
    long long respuesta = dijkstra(grafo,0,v-1);
    //    printf("%lld\n",(respuesta == INF ? -1 : respuesta));
    cout << (respuesta == INF ? -1 : respuesta) << endl;
  }
  return 0;
}
