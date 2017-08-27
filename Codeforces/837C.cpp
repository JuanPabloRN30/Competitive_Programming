#include <iostream>

using namespace std;

typedef pair < int , int > ii;
int n,a,b;
ii seals[200];

int area(int i)
{
    return seals[i].first * seals[i].second;
}

bool fit(int x, int x1, int y, int y1)
{
    int aux_x = x;
    int aux_x1 = x1;
    int aux_y = y;
    int aux_y1 = y1;

    int x_real = max(aux_x, aux_x1);
    int y_real = aux_y + aux_y1;
    if( x_real <= a && y_real <= b)
        return true;
    if( x_real <= b && y_real <= a)
        return true;
    x_real = aux_x+aux_x1;
    y_real = max(aux_y,aux_y1);
    if( x_real <= a && y_real <= b)
        return true;
    if( x_real <= b && y_real <= a)
        return true;

    aux_x1 = y1;
    aux_y1 = x1;
    x_real = max(aux_x, aux_x1);
    y_real = aux_y + aux_y1;
    if( x_real <= a && y_real <= b)
        return true;
    if( x_real <= b && y_real <= a)
        return true;
    x_real = aux_x+aux_x1;
    y_real = max(aux_y,aux_y1);
    if( x_real <= a && y_real <= b)
        return true;
    if( x_real <= b && y_real <= a)
        return true;

    aux_x = y;
    aux_y = x;
    aux_x1 = x1;
    aux_y1 = y1;
    x_real = max(aux_x, aux_x1);
    y_real = aux_y + aux_y1;
    if( x_real <= a && y_real <= b)
        return true;
    if( x_real <= b && y_real <= a)
        return true;
    x_real = aux_x+aux_x1;
    y_real = max(aux_y,aux_y1);
    if( x_real <= a && y_real <= b)
        return true;
    if( x_real <= b && y_real <= a)
        return true;

    aux_x1 = y1;
    aux_y1 = x1;
    x_real = max(aux_x, aux_x1);
    y_real = aux_y + aux_y1;
    if( x_real <= a && y_real <= b)
        return true;
    if( x_real <= b && y_real <= a)
        return true;
    x_real = aux_x+aux_x1;
    y_real = max(aux_y,aux_y1);
    if( x_real <= a && y_real <= b)
        return true;
    if( x_real <= b && y_real <= a)
        return true;
    return false;
}

int main()
{
    cin >> n >> a >> b;
    for(int i = 0 ; i < n ; i++)
        cin >> seals[i].first >> seals[i].second;
    int mayor = 0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            int x1 = seals[i].first, y1 = seals[i].second;
            int x2 = seals[j].first, y2 = seals[j].second;
            if((area(i) + area(j) <= a*b) && fit(x1,x2,y1,y2))
                mayor = max(mayor, area(i) + area(j));
        }
    }
    cout << mayor << '\n';
    return 0;
}
