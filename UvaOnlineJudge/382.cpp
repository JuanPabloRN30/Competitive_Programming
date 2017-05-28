#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cases,n,age;
    printf("PERFECTION OUTPUT\n");
    while( scanf("%d",&cases) && cases)
    {
        int acum = 0;
        int div = 1;
        while( div < cases )
        {
            if( cases%div == 0 )
                acum += div;
            div++;
        }
        if( acum == cases )
        {
            printf("%5d  PERFECT\n",cases);
        }
        else if( acum > cases )
        {
            printf("%5d  ABUNDANT\n",cases);
        }
        else
        {
            printf("%5d  DEFICIENT\n",cases);
        }
    }
    printf("END OF OUTPUT\n");

    return 0;
}
