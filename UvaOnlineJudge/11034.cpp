#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t,l,m,largo,acum;
    string dir;
    cin >> t;
    while(t--)
    {
        queue < int > left,right;
        cin >> l >> m;
        l*=100;
        for(int i = 0 ; i < m ; i++)
        {
            cin >> largo >> dir;
            if(dir == "left") left.push(largo);
            else right.push(largo);
        }
        bool curr_pos = true;
        int contador = 0;
        while(!left.empty() || !right.empty())
        {
            acum = 0;
            if(curr_pos)
            {
                while(!left.empty() && left.front() + acum <= l)
                {
                    acum += left.front();
                    left.pop();
                }
            }
            else
            {
                while(!right.empty() && right.front() + acum <= l)
                {
                    acum += right.front();
                    right.pop();
                }
            }
            contador++;
            curr_pos = !curr_pos;
        }
        cout << contador << '\n';
    }
    return 0;
}
