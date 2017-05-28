#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,m;
        char auxletra;
        double auxprecio;
        double total=0.0;
        int valor;
        string aux;
        double precio[1000] ={0.0};
        cin>>l;
        while(l--)
        {
            cin>>auxletra;
            cin>>auxprecio;
            valor= auxletra+128;
            precio[valor]=auxprecio;
        }
        cin>>m;
        cin.ignore();
        while(m--)
        {
            getline(cin,aux);
            for(int h=0; h<aux.size();h++){
                int letra =aux[h]+128;
                total=total+precio[letra];
            }
        }
        total /= 100;
        printf("%.2lf$\n",total);
    }
    return 0;
}
