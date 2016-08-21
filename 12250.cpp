#include<bits/stdc++.h>

using namespace std;

int main()
{
    string linea;
    map < string , string > idiomas;
    idiomas["HELLO"] = "ENGLISH";
    idiomas["HOLA"] = "SPANISH";
    idiomas["HALLO"] = "GERMAN";
    idiomas["BONJOUR"] = "FRENCH";
    idiomas["CIAO"] = "ITALIAN";
    idiomas["ZDRAVSTVUJTE"] = "RUSSIAN";
    int cont = 1;
    while(cin >> linea && linea != "#")
    {
        if(idiomas.find(linea) == idiomas.end())
            printf("Case %d: UNKNOWN\n",cont++);
        else
            printf("Case %d: %s\n",cont++,idiomas[linea].c_str());
    }

    return 0;
}
