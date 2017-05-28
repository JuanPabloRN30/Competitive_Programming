#include <bits/stdc++.h>

using namespace std;

struct elf
{
    string name;
    int weight;
    int age;
    double height;
    elf(){}

    bool operator < ( elf other ) const{
        if( this->weight == other.weight )
        {
            if( this->age == other.age )
            {
                if( this->height == other.height )
                {
                    return this->name < other.name;
                }
                else
                    return this->height < other.height;
            }
            else
                return this->age < other.age;
        }
        else
            return this->weight > other.weight;
    }
};

int main()
{
    int cases,n,k,casess=0;
    scanf("%d",&cases);
    while( cases--)
    {
        scanf("%d%d",&n,&k);
        vector < elf > elfos(n);
        for( int i = 0 ; i < n ; i++ )
        {
            cin >> elfos[ i ].name >> elfos[ i ].weight >> elfos[ i ].age >> elfos[ i ].height;
        }
        sort( elfos.begin(), elfos.end() );
        printf("CENARIO {%d}\n",++casess);
        for( int i = 0 ; i < k ; i++ )
        {
            printf("%d - ",i+1);
            cout << elfos[ i ].name << endl;
        }
    }


    return 0;
}
