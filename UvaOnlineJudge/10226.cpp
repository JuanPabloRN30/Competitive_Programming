#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cases, conta = 0;
    string tree;
    cin >> cases;
    cin.ignore();
    cin.ignore();
    while( cases-- )
    {
        if( conta ) cout << endl;
        map < string , double > list_tree;
        map < string , double >::iterator it;
        double cont = 0.0;
        while( getline( cin, tree ) && tree != "" )
        {
            list_tree[ tree ]++;
            cont++;
        }
        for( it = list_tree.begin() ; it != list_tree.end() ; ++it )
        {
            double result = (it->second / cont) * 100.0;
            cout << fixed << setprecision(4) <<it->first << " " << result << endl;
        }
        ++conta;

    }
    return 0;
}
