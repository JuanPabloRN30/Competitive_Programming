#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
	ll n,k;
	cin >> n >> k;
		if((n/k)&1)
			puts("YES");
		else
			puts("NO");
	return 0;
}
