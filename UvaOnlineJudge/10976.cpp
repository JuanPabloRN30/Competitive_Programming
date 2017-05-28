#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num,cont;
    double k,x,t_result;
    int result;
    while( scanf("%d",&num) != EOF )
    {
        k = 1.0 / num;
        cont = 0;
        for( int i = 10000 ; i>= num * 2 ; --i )
        {
            x = (1.0 / i);
            if( k - x > 0 )
                result = (int)((1.0 / ( k - x )) + 0.5);
            t_result = (1.0 / result) + x;
            if( t_result == k )
                cont++;

        }
        printf("%d\n",cont);
        for( int i = 10000 ; i>= num * 2 ; --i )
        {
            x = (1.0 / i);
            if( k - x > 0 )
                result = (int)((1.0 / ( k - x )) + 0.5) ;
            t_result = (1.0 / result) + x;
            if( t_result == k )
                printf("1/%d = 1/%d + 1/%d\n",num,i,result);

        }
    }
    return 0;
}
