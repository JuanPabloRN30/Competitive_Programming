#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int cont = 0;
    vector < int > ans;
    for(int i = s.size()-1 ; i>= 0 ; i--)
    {
        if(s[i] == '1')
            cont++;
        else
        {
            if(s[i] == '0' && cont == 0)
                ans.push_back(0);
            else
            {
                if(cont != 0)
                    ans.push_back(cont);
                cont = 0;
            }
        }
    }
    if(cont)
        ans.push_back(cont);
    for(int i = ans.size()-1 ; i >= 0 ; i--)
        cout << ans[i];
    cout << '\n';
    return 0;
}
