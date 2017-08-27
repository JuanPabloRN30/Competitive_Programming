#include <iostream>
#include <set>

using namespace std;

int main()
{
    string linea;
    int acum = 0;
    set < string > online;
    while(getline(cin,linea))
    {
        if(linea[0] == '+')
            online.insert(linea);
        else if(linea[0] == '-')
        {
            linea[0] = '+';
            online.erase(linea);
        }
        else
        {
            int i;
            for(i = 0 ; i < (int)linea.size() ; i++)
                if(linea[i] == ':') break;
            i++;
            acum += (linea.size()-i) * online.size();
        }
    }
    cout << acum << '\n';

    return 0;
}
