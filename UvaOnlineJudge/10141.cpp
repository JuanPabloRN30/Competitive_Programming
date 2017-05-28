#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,p,r,caso = 1;
    string requirement;
    string proposal;
    double d;
    while( cin >> n >> p && ( n+p ) )
    {
        if( caso != 1 )
            cout << endl;
        cin.ignore();
        double may = 0.0;
        double price_m = 0.0;
        string ans;
        for( int i = 0 ; i < n ; ++i )
        {
            getline( cin, requirement );
        }

        for( int i = 0 ; i < p ; ++i )
        {
            getline( cin, proposal );
            cin >> d >> r;
            cin.ignore();
            for( int j = 0 ; j < r ; ++j )
            {
                getline( cin, requirement );
            }
            double compliance = (double)r / (double)n;
            if( compliance > may )
            {
                may = compliance;
                price_m = d;
                ans = proposal;
            }
            else if( compliance == may )
            {
                if( d < price_m )
                {
                    ans = proposal;
                    price_m = d;
                }
            }
        }
        printf("RFP #%d\n",caso++);
        cout << ans << endl;
    }

    return 0;
}
