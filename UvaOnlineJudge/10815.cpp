#include <bits/stdc++.h>

using namespace std;

int main()
{
  char c;
  string aux = "";
  set < string > palabras;
  while( (c = getchar()) != EOF )
  {
    if( c >= 'A' && c <= 'Z' )
      c += 32;
    if( c >= 'a' && c <= 'z')
      aux += c;
    else
    {
      if( aux != "" )
        palabras.insert( aux );
      aux = "";
    }
  }
  set < string >::iterator it;
  for(it = palabras.begin(); it != palabras.end() ; it++)
    cout << (*it) << endl;


  return 0;
}
