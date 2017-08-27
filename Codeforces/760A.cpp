#include <iostream>

using namespace std;

int main()
{
    int m,d;
    int days[ 12 ];
    days[ 0 ] = 31;
    days[ 1 ] = 28;
    days[ 2 ] = 31;
    days[ 3 ] = 30;
    days[ 4 ] = 31;
    days[ 5 ] = 30;
    days[ 6 ] = 31;
    days[ 7 ] = 31;
    days[ 8 ] = 30;
    days[ 9 ] = 31;
    days[ 10 ] = 30;
    days[ 11 ] = 31;
    scanf("%d%d",&m,&d);
    int menos = days[ m - 1 ] - ((7 - d) + 1);
    int tot = 0;
    if( menos% 7 != 0 )
        tot++;
    menos -= menos % 7;
    tot += menos / 7 + 1;
    cout << tot << endl;
    return 0;
}
