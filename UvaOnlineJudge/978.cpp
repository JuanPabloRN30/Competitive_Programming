#include <iostream>
#include <set>
#include <queue>
#include <stdio.h>

using namespace std;

int main()
{
    int n,b,sg,sb,value,cont;
    int casos = 0;
    scanf("%d",&n);
    while( n-- )
    {
        if( casos ) printf("\n");
        casos++;
        scanf("%d%d%d",&b,&sg,&sb);
        multiset < int > green,blue;
        multiset < int >::iterator it,it2;
        for( int i = 0 ; i < sg ; i++ )
        {
            scanf("%d",&value);
            green.insert( value * -1 );
        }
        for( int i = 0 ; i < sb ; i++ )
        {
            scanf("%d",&value);
            blue.insert(value * -1);
        }
        while( !green.empty() && !blue.empty() )
        {
            cont = 0;
            queue < int > qg,qb;
            while( cont < b && !green.empty() && !blue.empty() )
            {
                int current_green = *(green.begin()) * -1;
                int current_blue = *(blue.begin()) * -1;
                green.erase( green.begin() );
                blue.erase( blue.begin() );
                if( current_green < current_blue )
                {
                    qb.push( current_blue - current_green );
                }
                else if( current_blue < current_green )
                {
                    qg.push( current_green - current_blue );
                }
                ++cont;
              /*  cout << "El set azul: " << endl;
                for( it = blue.begin() ; it != blue.end() ; ++it )
                    printf("%d\n",(*it));
                cout << "El set green: " << endl;
                for( it = green.begin() ; it != green.end() ; ++it )
                    printf("%d\n",(*it));*/
            }
            while( !qg.empty() )
            {
                green.insert( qg.front()*-1 );
                qg.pop();
            }
            while( !qb.empty() )
            {
                blue.insert( qb.front()*-1 );
                qb.pop();
            }
        }
        if( green.empty() && blue.empty() )
        {
            printf("green and blue died\n");
        }
        else if( green.empty() && !blue.empty() )
        {
            printf("blue wins\n");
            for( it = blue.begin() ; it != blue.end() ; ++it )
                printf("%d\n",(*it)*-1);
        }
        else
        {
            printf("green wins\n");
            for( it = green.begin() ; it != green.end() ; ++it )
                printf("%d\n",(*it)*-1);
        }
    }

    return 0;
}
