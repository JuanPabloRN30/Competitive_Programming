#include <iostream>

using namespace std;

int main()
{
    int letters[26];
    string linea;
    int k,c = 0;
    for(int i = 0  ; i < 26 ; i++)
        letters[i] = 0;
    cin >> linea >> k;
    for(int i = 0 ; i < (int)linea.size() ; i++)
    {
        letters[ (linea[i]-'a') ]++;
        if(letters[ (linea[i]-'a') ] == 1) c++;
    }
    if((int)linea.size() < k) cout << "impossible\n";
    else
    {
        if(c >= k) cout << "0\n";
        else cout << k - c << '\n';
    }
    return 0;
}
