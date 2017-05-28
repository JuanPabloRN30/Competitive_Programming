#include <bits/stdc++.h>

using namespace std;

pair < string , int > bitsOn( int n )
{
    int cont = 0;
    string numBinary = "";
    while( n != 0 )
    {
        if( n & 1 )
        {
            cont++;
            numBinary = '1'+numBinary;
        }
        else
            numBinary = '0'+numBinary;
        n >>= 1;
    }
    return make_pair( numBinary, cont );
}

int main()
{
    int n;
    while( scanf("%d",&n) && n )
    {
        pair < string , int > res = bitsOn( n );
        printf("The parity of %s is %d (mod 2).\n",res.first.c_str(),res.second);
    }
    return 0;
}
