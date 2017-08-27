#include <iostream>
#include <sstream>

using namespace std;

int countCapital(string &aux)
{
    int c=0;
    for(int i = 0 ; i < (int)aux.size() ; i++)
    {
        if(aux[i] >= 'A' && aux[i] <='Z')
            c++;
    }
    return c;
}

int main()
{
    int n,may = 0;
    string text, aux;
    cin >> n;
    cin.ignore();
    getline(cin, text);
    stringstream ss(text);
    while(ss >> aux)
        may = max(may, countCapital(aux));
    cout << may << '\n';
    return 0;
}
