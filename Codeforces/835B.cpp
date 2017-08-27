#include <iostream>

using namespace std;

typedef long long ll;

ll sum(string &number)
{
    ll acum = 0LL;
    for(ll i = 0 ; i < (int)number.size(); i++)
        acum += (number[i])-'0';
    return acum;
}

int ans,k;

bool replace_n(string &number, int n, ll &prev)
{
    for(ll i = 0 ; i < (int)number.size() ; i++)
    {
        int digit = (number[i])-'0';
        if(digit == n)
        {
            prev -= digit;
            prev += 9LL;
            ans++;
            if(prev >= k)
                return true;
            number[i]='9';
        }
    }
    return false;
}

int main()
{
    string number;
    cin >> k >> number;
    ll suma = sum(number);
    if(suma >= k)
        cout << 0 << '\n';
    else
    {
        int cont = 0;
        while(suma < k && cont < 10)
        {
            replace_n(number, cont, suma);
            cont++;
        }
        cout << ans << '\n';
    }
    return 0;
}
