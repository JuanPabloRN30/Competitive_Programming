#include <iostream>
#include <vector>

using namespace std;

struct Range
{
    int minimo,maximo,actual;
};

int main()
{
    int d, sumTime;
    cin >> d >> sumTime;
    vector < Range > ranges(d);
    for(int i = 0 ; i < d ; i++)
    {
        cin >> ranges[i].minimo >> ranges[i].maximo;
        ranges[i].actual = ranges[i].minimo;
    }
    int acum = 0, ind_i = 0;
    for(int i = 0 ; i < d ; i++)
        acum += ranges[i].actual;
    while(acum != sumTime && ind_i < d)
    {
        if(ranges[ind_i].actual + 1 <= ranges[ind_i].maximo)
        {
            ranges[ind_i].actual++;
            acum++;
        }
        else
            ind_i++;
    }
    if(acum == sumTime)
    {
        cout << "YES\n";
        for(int i = 0 ; i < d ; i++)
        {
            if(i) cout << ' ';
            cout << ranges[i].actual;
        }
        cout << '\n';
    }
    else
        cout << "NO\n";
    return 0;
}
