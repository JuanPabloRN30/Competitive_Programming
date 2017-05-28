#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int v1[] = {1,2,3,3,4,10};
    int v2[] = {1,2,2,2,3,5,10};
    int n,value;
    long long good, bad;
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ )
    {

        good = bad = 0;
        for( int a = 0 ; a < 6 ; a++ )
        {
            scanf("%d",&value);
            good += value*v1[ a ];
        }
        for( int a = 0 ; a < 7 ; a++ )
        {
            scanf("%d",&value);
            bad += value*v2[ a ];
        }
        printf("Battle %d: ",i+1);
        if( good > bad )
        {
            printf("Good triumphs over Evil\n");
        }
        else if( bad > good )
        {
            printf("Evil eradicates all trace of Good\n");
        }
        else
        {
            printf("No victor on this battle field\n");
        }
    }

    return 0;
}
