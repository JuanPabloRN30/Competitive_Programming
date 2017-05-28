#include <bits/stdc++.h>

using namespace std;

struct Estacion
{
  double distancia;
  double precio;
};

const double SNACKS = 200;
const double INF = 1e9;
Estacion estaciones[ 60 ];
double capacidad,millxgalon,costo_inicial;
double distancia,mitad;
int numero_estaciones;

double minimum(double distancia_recorrida, double costo_total, int posicion)
{
  if( posicion == numero_estaciones )
    return costo_total;
  double gasolina_perdida = (estaciones[ posicion ].distancia-distancia_recorrida) / millxgalon;
  double costo_actual = gasolina_perdida * estaciones[ posicion ].precio;
  if( gasolina_perdida > capacidad )
    return INF;

  if( gasolina_perdida >= mitad )
  {
    return min(minimum(estaciones[ posicion ].distancia, costo_total+SNACKS+floor(costo_actual+0.5), posicion+1 ),minimum(distancia_recorrida, costo_total, posicion+1 ));
  }
  else
  {
    if( posicion+1 < numero_estaciones )
    {
      double gasolina_perdida_next = (estaciones[ posicion + 1 ].distancia-distancia_recorrida) / millxgalon;
      if( gasolina_perdida_next > capacidad)
        return minimum( estaciones[ posicion ].distancia, costo_total+SNACKS+floor(costo_actual+0.5), posicion+1 );
      else
        return minimum(distancia_recorrida, costo_total, posicion+1 );
    }
    else
      return minimum(distancia_recorrida, costo_total, posicion+1 );
  }
}

int main()
{
  int contador = 1;
  while( scanf("%lf",&distancia) && distancia > -1 )
  {

    scanf("%lf%lf%lf%d",&capacidad,&millxgalon,&costo_inicial,&numero_estaciones);
    double precio;
    for(int i = 0 ; i < numero_estaciones ; i++)
    {
      scanf("%lf%lf",&estaciones[ i ].distancia,&precio);
      estaciones[ i ].precio = precio;
    }
    estaciones[ numero_estaciones ].distancia = distancia;
    estaciones[ numero_estaciones ].precio = 0.0;
    mitad = capacidad/2.0;
    numero_estaciones++;
    printf("Data Set #%d\n",contador++);
    printf("minimum cost = $%.2lf\n",costo_inicial+ minimum(0.0, 0.0, 0 )/100.0);
  }
  return 0;
}
