#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    while( n-- )
    {
        int numero1,numero2;
        scanf("%d%d",&numero1,&numero2);
        printf("%d\n",(numero1/3)*(numero2/3));
    }
    return 0;
}
