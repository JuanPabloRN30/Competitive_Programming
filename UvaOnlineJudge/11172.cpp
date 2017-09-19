#include <iostream>

using namespace std;

int main()
{
    int x,y,n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> x >> y;
        if(x > y)
            cout << '>' << endl;
        else if(x < y)
            cout << '<' << endl;
        else if( x == y)
            cout << '=' << endl;
    }

    return 0;
}

