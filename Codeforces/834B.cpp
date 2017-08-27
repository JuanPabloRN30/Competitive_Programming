#include <iostream>

using namespace std;

int cant[26];
bool open[26];
bool first_time[26];
int cant_c[26];

int to_num(char a)
{
    return a - 'A';
}

int main()
{
    int n,k;
    string line;
    cin >> n >> k >> line;
    for(int i = 0 ; i < (int)line.size() ; i++)
        cant[to_num(line[i])]++;
    for(int i = 0 ; i < (int)line.size() ; i++)
    {
        int pos = to_num(line[i]);
        cant_c[pos]++;
        if(cant_c[pos] != cant[pos])
        {
            if(!first_time[pos])
            {
                first_time[pos]=1;
                k--;
            }
            open[pos]=1;
        }
        else
        {
            if(first_time[pos])
                k++;
            else
            {
                if(k-1 < 0)
                {
                    cout << "YES\n";
                    return 0;
                }

            }
            open[pos]=0;
        }
        if(k < 0)
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
