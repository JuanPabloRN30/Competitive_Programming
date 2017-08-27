#include <iostream>
#include <vector>

using namespace std;

int count_(vector < bool > &total)
{
    for(int i = 0 ; i < (int)total.size() ; i++)
        if(total[i]) return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,value;
    long long suma = 0;
    cin >> n;
    vector < bool > total(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> value;
        suma += value;
        total[i] = (value&1);
    }
    if(suma&1LL)
        cout << "First\n";
    else
    {
        if(count_(total))
            cout << "First\n";
        else
            cout << "Second\n";
    }

    return 0;
}
