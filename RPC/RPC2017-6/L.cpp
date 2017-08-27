#include <iostream>

using namespace std;

int ans( string number )
{
  int digito = number[ number.size()-1 ] - '0';
  return (digito%5 - 2 + 5)%5;
}

int main()
{
  int t;
  string number;
  int arr[ 5 ];
  arr[ 0 ] = 56;
	arr[ 1 ] = 96;
	arr[ 2 ] = 36;
	arr[ 3 ] = 76;
	arr[ 4 ] = 16;
  cin >> t;
  while( t-- )
  {
    cin >> number;
    if( number == "0" )
      cout << 1;
    else if( number == "1" )
      cout << 66;
    else
      cout << arr[ ans( number ) ];
    cout << '\n';
  }


  return 0;
}
