#include <bits/stdc++.h>

using namespace std;

unsigned long long res;

deque < long long > mergesort( deque < long long > arr )
{
    if(arr.size() == 1 )    return arr;
    deque < long long > lv = mergesort(deque < long long > (arr.begin(), arr.begin() + ( arr.size() >> 1) )) , rv = mergesort(deque < long long > (arr.begin() + ( arr.size() >> 1 ) , arr.end()));
    deque < long long > ans;
    while(lv.size() && rv.size())
    {
        if( lv.front() < rv.front() )
        {
            ans.push_back(rv.front());
            rv.pop_front();
        }
        else if( lv.front() > rv.front() )
        {
            res += rv.size();
            ans.push_back(lv.front());
            lv.pop_front();
        }
        else
        {
            ans.push_back(rv.front());
            rv.pop_front();
        }
    }
    while( lv.size() )
    {
        ans.push_back(lv.front());
        lv.pop_front();
    }
    while( rv.size() )
    {
        ans.push_back(rv.front());
        rv.pop_front();
    }
    return ans;
}

int main()
{
    int l , n;
    long long aux;
    scanf("%d%d" ,&n,&l);
    deque < long long > arr;
    for( int i = 0 ; i < n ; ++i )
    {
        scanf("%ld",&aux);
        aux *= (long long)l;
        aux += (long long)i;
        arr.push_back( aux );
    }
    mergesort( arr );
    printf("%llu\n", res);
    return 0;
}
