#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int cont = 1;
    scanf("%d",&n);
    while( n-- )
    {
        int L,W,H;
        scanf("%d%d%d",&L,&W,&H);
        if(L <= 20 && W <= 20 && H<=20)
            printf("Case %d: good\n",cont++);
        else
            printf("Case %d: bad\n",cont++);

    }
    return 0;
}
