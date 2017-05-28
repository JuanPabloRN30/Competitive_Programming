#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    int contG,contB;
    string name;
    cin >> n;
    cin.ignore();
    while( n-- )
    {
        contG = contB = 0;
        getline(cin, name);
        for( int i = 0 ; i < name.size() ; i++ )
        {
            if( name[ i ] == 'g' || name[ i ] == 'G' )
                contG++;
            if( name[ i ] == 'b' || name[ i ] == 'B' )
                contB++;
        }
        cout << name << " is ";
        if( contG > contB )
        {
            cout << "GOOD\n";
        }
        else if( contB > contG )
        {
            cout << "A BADDY\n";
        }
        else
        {
            cout << "NEUTRAL\n";
        }
    }

    return 0;
}
