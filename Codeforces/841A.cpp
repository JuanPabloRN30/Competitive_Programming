#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,k;
    string line;
    cin >> n >> k;
    vector < vector < int > > ball(n, vector < int >(26,0));
    cin >> line;
    sort(line.begin(),line.end());
    int friend_i = 0;
    for(int i = 0 ; i < (int)line.size() ; i++)
    {
        if(friend_i == k)
            friend_i = 0;
        ball[friend_i][(line[i]-'a')]++;
        friend_i++;
    }
    bool flag = true;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < 26 ; j++)
        {
            if(ball[i][j] > 1)
                flag = false;
        }
    }
    cout << (flag ? "YES": "NO") << '\n';

    return 0;
}
