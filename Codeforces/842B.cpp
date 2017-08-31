#include <iostream>
#include <cmath>

using namespace std;

struct Sausage
{
    int x,y,r;

    double operator~ ()
    {
        return sqrt(x*x + y*y);
    }
};

int main()
{
    Sausage s[100010];
    int r,d,n;
    cin >> r >> d >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> s[i].x >> s[i].y >> s[i].r;
    int cont = 0;
    for(int i = 0 ; i < n ; i++)
    {
        double dist_c = ~s[i];
        if(dist_c >= (r-d) && dist_c <= r)
        {
            if(dist_c+s[i].r <= r && dist_c-s[i].r >= (r-d))
            {
                cont++;
            }
        }
    }
    cout << cont << '\n';
    return 0;
}
