#include <iostream>
#include <stdio.h>

using namespace std;

bool isVocal( char letra )
{
    return letra == 'a' || letra == 'i' || letra == 'y' || letra == 'e' || letra == 'o' || letra == 'u';
}
char vocales[] = {'a','i','y','e','o','u'};
char consonantes[] = {'b','k','x','z','n','h','d','c','w','g','p','v','j','q','t','s','r','l','m','f'};

char decodeV( char letra )
{
    for( int i = 0 ; i < 6 ; i++ )
    {
        if( letra == vocales[ i ] )
        {
            return vocales[((i+3)%6)];
        }
    }
}

char decodeC( char letra )
{
    for( int i = 0 ; i < 20 ; i++ )
    {
        if( letra == consonantes[ i ] )
        {
            return consonantes[(i+10)%20];
        }
    }
}

char minusc( char letra )
{
    if( letra >='A' && letra <= 'Z' )
    {
        return letra += 32;
    }
    return letra;

}

bool isInTheArray( char letra )
{
    for( int i = 0 ; i < 6 ; i++ )
    {
        if( letra == vocales[ i ] )
        {
            return true;
        }
    }
    for( int i = 0 ; i < 20 ; i++ )
    {
        if( letra == consonantes[ i ] )
        {
            return true;
        }
    }
    return false;
}


int main()
{
    string linea;
    while( getline(cin,linea) )
    {
        for( int i = 0 ; i < linea.size() ; i++ )
        {
            if( !isInTheArray( minusc(linea[ i ]) ))
            {
                cout << linea[i];
            }
            else
            {
                if( isVocal( minusc(linea[ i ]) )  )
                {
                    if( linea[ i ] >= 'A' && linea[ i ] <= 'Z' )
                        cout << (char)(decodeV( minusc(linea[ i ]) )-32);
                    else
                        cout << decodeV( minusc(linea[ i ]) );
                }
                else
                {
                    if( linea[ i ] >= 'A' && linea[ i ] <= 'Z' )
                        cout << (char)(decodeC( minusc(linea[ i ]) )-32);
                    else
                        cout << decodeC( minusc(linea[ i ]) );
                }
            }
        }
        cout << endl;
    }

    return 0;
}
