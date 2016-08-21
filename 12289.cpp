#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    while( n-- )
    {
        string linea;
        cin >> linea;
        if(linea.size() == 5)
        {
            printf("3\n");
        }
        else
        {
            int contadorUno = 0;
            vector < char > one(3);
            one[0] = 'o';
            one[1] = 'n';
            one[2] = 'e';
            for(int i = 0 ; i < 3 ; i++)
            {
                if(linea[i] == one[i])
                    contadorUno++;
            }
            if(contadorUno >= 2)
                printf("1\n");
            else
                printf("2\n");
        }
    }
    return 0;
}
