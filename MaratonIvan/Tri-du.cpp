#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    while( scanf("%d%d",&a,&b) != EOF )
    {
        if( a != b )
            printf("%d\n",max(a,b));
        else
            printf("%d\n",a);
    }
    return 0;
}

