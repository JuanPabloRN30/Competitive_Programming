#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    while( n-- )
    {
        int stores,positions;
        int menor = 1e6, may = -1;
        scanf("%d",&stores);
        for(int i = 0 ; i < stores ; i++)
        {
            scanf("%d",&positions);
            if(positions > may)
                may = positions;
            if(positions < menor)
                menor = positions;
        }
        printf("%d\n",(may-menor)*2);
    }
    return 0;
}
