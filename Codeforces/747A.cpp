#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n,num;
    int diff = 1e9,rows,columns;
    scanf("%d",&n);
    for( long long i = 1 ; i <= n ; ++i )
    {
        num = n/i;
        if( num * i == n )
        {
            if( abs(num - i) < diff )
            {
                diff = abs(num - i);
                rows = i;
                columns = num;
            }

        }
    }
    printf("%d %d\n",rows,columns);
    return 0;
}
