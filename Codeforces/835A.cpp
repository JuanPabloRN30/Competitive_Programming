#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ll s,v1,v2,t1,t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    ll total_1 = t1 * 2 + v1 * s;
    ll total_2 = t2 * 2 + v2 * s;
    if(total_1 < total_2)
        cout << "First\n";
    else if(total_1 > total_2)
        cout << "Second\n";
    else
        cout << "Friendship\n";
    return 0;
}
