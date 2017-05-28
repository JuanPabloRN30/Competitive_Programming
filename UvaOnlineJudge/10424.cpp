#include <bits/stdc++.h>

using namespace std;

int sumDigits(int num)
{
  int sum = 0;
  while(num != 0)
  {
    sum += num%10;
    num/= 10;
  }
  return sum;
}

int main()
{
  string name1, name2;
  map < char , int > mapa;
  int cont = 1;
  char j = 'A';
  for(char i = 'a' ; i<= 'z' ; i++,j++)
  {
    mapa[i] = cont;
    mapa[j] = cont;
    cont++;
  }
  while(getline(cin,name1))
  {
    getline(cin,name2);
    int sum,sum1;
    sum = sum1 = 0;
    for(int i = 0 ; i < name1.size() ; i++)
    {
      if(name1[i] != ' ')
      {
        sum += mapa[name1[i]];
      }
    }
    for(int i = 0 ; i < name2.size() ; i++)
    {
      if(name2[i] != ' ')
      {
        sum1 += mapa[name2[i]];
      }
    }
    while(sum > 9)
    {
      sum = sumDigits(sum);
    }
    while(sum1 > 9)
    {
      sum1 = sumDigits(sum1);
    }
    double value = (min((double)sum1,(double)sum)*100)/max((double)sum1,(double)sum);
    printf("%.2lf %%\n",value);
  }


  return 0;
}
