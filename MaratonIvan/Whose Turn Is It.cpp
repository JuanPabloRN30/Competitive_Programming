#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    while( n-- )
    {
        string name1,name2,choice1,choice2;
        int val1,val2;
        cin >> name1 >> choice1 >> name2 >> choice2 >> val1 >> val2;
        if( (val1 + val2) & 1 )
        {
            if( choice1 == "IMPAR" )
                cout << name1 << endl;
            else
                cout << name2 << endl;
        }
        else
        {
            if( choice1 == "PAR" )
                cout << name1 << endl;
            else
                cout << name2 << endl;
        }
    }
    return 0;
}

