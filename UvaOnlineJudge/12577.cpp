#include<bits/stdc++.h>

using namespace std;

int main()
{
    string linea;
    int cont = 1;
    while( cin >> linea && linea != "*")
    {
        if(linea == "Hajj")
            printf("Case %d: Hajj-e-Akbar\n",cont++);
        else
            printf("Case %d: Hajj-e-Asghar\n",cont++);

    }
    return 0;
}
