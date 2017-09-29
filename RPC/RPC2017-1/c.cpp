#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    string name, last_name;
    cin >> n;
    vector < pair < string , string > > persons;
    while(n--)
    {
        cin >> name >> last_name;
        persons.push_back(make_pair(last_name,name));
    }
    sort(persons.begin(),persons.end());
    for(int i = 0 ; i < (int)persons.size() ; i++)
        cout << persons[i].second << " " << persons[i].first << '\n';
    return 0;
}
