#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int cont = 1;
    while(scanf("%d",&n) && n)
    {
        int numero;
        int acum = 0;
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d",&numero);
            if(!numero)
                acum--;
            else
                acum++;
        }
        printf("Case %d: %d\n",cont++,acum);
    }
    return 0;
}
