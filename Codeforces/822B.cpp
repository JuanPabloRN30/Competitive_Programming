#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m,c,men = 1e9;
    string s,t;
    vector < int > ans;
    cin >> n >> m;
    cin >> s >> t;
    for(int i  = 0 ; i < m ; i++)
    {
        int copia = i;
        bool flag = false;
        c = 0;
        vector < int > aux;
        for(int j = 0 ; j < n && copia < m ; j++, copia++)
        {
            if(j == n-1) flag = true;
            if(t[copia] != s[j])
            {
                aux.push_back(j+1);
                c++;
            }
        }
        if(flag && c < men)
        {
            ans = aux;
            men = c;
        }
    }
    cout << men << '\n';
    for(int i = 0 ; i < men ; i++)
    {
        if(i != 0) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}
