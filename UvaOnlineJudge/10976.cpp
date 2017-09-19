#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>

using namespace std;

struct Res
{
	long long k;
	long long x;
	long long y;
	Res(int k, int x, int y)
	{
		this->k = k;
		this->x = x;
		this->y = y;
	}
};

int main()
{
	int k;
	while( scanf("%d",&k) != EOF)
	{
		int cont = 0;
		vector < Res > arr;		
		for( int i = 1 ; i <= (k*2)+1 ; i++)
		{
			double first = 1.0 / (double)k;
			double second = 1.0 / (double)i;
			if( first - second == 0)
				continue;
			long long x = (1.0 / ( first - second )) + 0.5;
			double total = 1.0 / (1.0 / (double)x + second);
 			if( fabs(total-k) < 1e-9 )
			{
				cont++;
				arr.push_back( Res(k,x,i) );
			}
				
		} 
		printf("%d\n",cont);
		for( int i = 0 ; i < cont ; i++)
		{
			printf("1/%lld = 1/%lld + 1/%lld\n",arr[i].k,arr[i].x,arr[i].y);
		}
	} 

	return 0;
}
