#include <iostream>

using namespace std;

int main()
{
  int w;
  bool can = false;
  cin >> w;
  for(int i = 1 ; i<= 100 && !can ; i++)
  {
    for(int j = 1; j <= 100 && !can ; j++)
    {
      if(!(i&1) && !(j&1) && i+j == w)
      {
        cout << "YES\n";
        can = true;
      }
    }
  }
  if(!can) cout << "NO\n";
  return 0;
}
