#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair < int , int > ii;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int m;
    cin >> m;
    vector < ii > a(m),b(m);
    vector < ii > a_(m),b_(m);
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
        a_[i] = a[i];
    }
    for(int i = 0 ; i < m ; i++)
    {
        cin >> b[i].first;
        b[i].second = i;
        b_[i] = b[i];
    }
    sort(a_.rbegin(), a_.rend());
    sort(b_.begin(), b_.end());
    for(int i = 0 ; i < m ; i++)
        a[ b_[i].second ] = a_[i];
    for(int i = 0 ; i < m ; i++)
    {
        if(i) cout << ' ';
        cout << a[i].first;
    }
    cout << '\n';
    return 0;
}
