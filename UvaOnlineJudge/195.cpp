#include<bits/stdc++.h>

using namespace std;

bool cmp( char var1, char var2 )
{
    if( var1 >= 'A' && var1 <= 'Z' )
    {
        if( var2 >= 'A' && var2 <= 'Z' )
            return var1 < var2;
        else
        {
            char aux = var1+32;
            if( var2 == aux )
                return true;
            else
                return aux < var2;
        }
    }
    else
    {
        if( var2 >= 'A' && var2 <= 'Z' )
        {
            char aux = var2+32;
            if( var1 == aux )
                return false;
            else
                return var1 < aux;
        }
        else
        {
            return var1 < var2;
        }
    }

}

int main()
{
    int cases;
    scanf("%d",&cases);
    while( cases-- )
    {
        string linea;
        cin >> linea;
        sort(linea.begin(),linea.end(),cmp);
        do
        {
            cout << linea << endl;
        }
        while( next_permutation(linea.begin(),linea.end(),cmp) );
    }

    return 0;
}
