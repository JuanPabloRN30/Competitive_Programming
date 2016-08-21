#include <bits/stdc++.h>

using namespace std;


int main()
{
  string linea1,linea2;
  while(cin >> linea1 >> linea2)
  {
    vector < vector < char > > respuestas;
    map < char,int> mapa;
    for(int i = 0 ; i < linea1.size() ; i++)
    {
      mapa[linea1[i]]++;
    }
    stack < char > s;
    deque < char > res;
    int pos = 0,pos1=1;
    s.push(linea1[0]);
    res.push_back('i');
    while (!s.empty()) {
      if ( s.top() == linea2[pos]) {
        s.pop();
        pos++;
        res.push_back('o');
      }
      else
      {
        s.push(linea1[pos1]);
        pos1++;
        res.push_back('i');
      }
      if(s.empty() && pos < linea2.size())
      {
        s.push(linea1[pos1]);
        res.push_back('i');
        pos1++;
      }
    }
    printf("[\n");
    while(!res.empty())
    {
      printf("%c ",res.front());
      res.pop_front();
    }
    printf("\n]\n");
  }
  return 0;
}
