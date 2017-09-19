#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,b,h,w,p,a, menor;
    while(cin >> n >> b >> h >> w)
    {
        menor = 1e9;
        for(int i = 0 ; i < h ; i++)
        {
            cin >> p;
            for(int j = 0 ; j < w ; j++)
            {
                cin >> a;
                if( p * n <= b && n <= a )
                    menor = min(menor, p*n);
            }
        }
        if(menor != 1e9) cout << menor << '\n';
        else cout << "stay home\n";
    }
    return 0;
}
