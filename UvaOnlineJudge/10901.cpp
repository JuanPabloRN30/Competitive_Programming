#include <bits/stdc++.h>

using namespace std;

typedef pair < int , int > ii;

int main()
{
    int c, n, t, m, time;
    string direct;
    int aux = 0;
    cin >> c;
    while(c--)
    {
        if(aux) cout << '\n';
        aux++;
        queue < ii > left,right;
        cin >> n >> t >> m;
        vector < int > ans(m);
        for(int i = 0 ; i < m ; i++)
        {
            cin >> time >> direct;
            if(direct == "left")
                left.push(ii(time,i));
            else
                right.push(ii(time,i));
        }
        int t_curr = 0, acum = 0, cont = 0;
        bool curr_pos = true;
        while(!left.empty() || !right.empty())
        {
            if(curr_pos)
            {
                cont = 0;
                while(!left.empty() && left.front().first <= t_curr && cont < n)
                {
                    ans[ left.front().second ] = t_curr+t;
                    left.pop();
                    cont++;
                }
                if(cont || (!right.empty() && right.front().first <= t_curr))
                {
                    curr_pos = !curr_pos;
                    t_curr += t;
                }
                else
                    t_curr++;
            }
            else
            {
                cont = 0;
                while(!right.empty() && right.front().first <= t_curr && cont < n)
                {
                     ans[ right.front().second ] = t_curr+t;
                    right.pop();
                    cont++;
                }
                if(cont || (!left.empty() && left.front().first <= t_curr))
                {
                    curr_pos = !curr_pos;
                    t_curr += t;
                }
                else
                    t_curr++;
            }
        }
        for(int i = 0 ; i < ans.size() ; i++)
            cout << ans[i] << '\n';

    }

    return 0;
}
