#include <iostream>

using namespace std;

int main()
{
    string text;
    cin >> text;
    int ans = 0;
    for( int i = 0 ; i < (int)text.size() ; i++ )
    {
        if(i < (int)text.size()-1 && text[ i ] == 'V' && text[ i + 1 ] == 'K' )
        {
            ans++;
            text[ i ] = text[ i + 1 ] = '-';
            i++;
        }
    }
    for( int i = 0 ; i < (int)text.size()-1 ; i++ )
    {
        if(text[ i ] != '-' && text[ i + 1 ] != '-')
        {
            if( text[ i ] == 'V')
            {
                    ans++;
                    break;
            }
            else
            {
                if( text[ i + 1 ] == 'K' )
                {
                    ans++;
                    break;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
