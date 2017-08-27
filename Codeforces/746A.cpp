#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int minimo = min(a,min(b/2,c/4));
    printf("%d\n",minimo*7);
    return 0;
}
