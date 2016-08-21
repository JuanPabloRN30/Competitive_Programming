#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    while( n-- )
    {
        int numero;
        scanf("%d",&numero);
        printf("%d\n",abs((((((((numero*567)/9)+7492)*235)/47)-498)/10)%10));
    }

    return 0;
}
