#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair < int , pair < int , int > > ii;
typedef pair < string , string > ss;

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

bool inside(int i , int j)
{
  return i>= 1 && i <= 8 && j >= 1 && j <= 8;
}

void printPath(int fila, int columna, int tfila, int tcolumna, vector < vector < ss > > &path)
{
  if(tfila == fila && tcolumna == columna)
    return;
  if(path[tfila][tcolumna].first == "RD")
    printPath(fila,columna,tfila+1,tcolumna+1,path);
  if(path[tfila][tcolumna].first == "D")
    printPath(fila,columna,tfila+1,tcolumna,path);
  if(path[tfila][tcolumna].first == "LD")
    printPath(fila,columna,tfila+1,tcolumna-1,path);
  if(path[tfila][tcolumna].first == "R")
    printPath(fila,columna,tfila,tcolumna+1,path);
  if(path[tfila][tcolumna].first == "L")
    printPath(fila,columna,tfila,tcolumna-1,path);
  if(path[tfila][tcolumna].first == "UR")
    printPath(fila,columna,tfila-1,tcolumna+1,path);
  if(path[tfila][tcolumna].first == "U")
    printPath(fila,columna,tfila-1,tcolumna,path);
  if(path[tfila][tcolumna].first == "LU")
    printPath(fila,columna,tfila-1,tcolumna-1,path);
  cout << path[tfila][tcolumna].second << '\n';
}

void bfs(int fila, int columna, int tfila, int tcolumna)
{
  queue < ii > q;
  q.push(ii(fila,make_pair(columna,0)));
  vector < vector < bool > > mark(9, vector < bool > (9, false));
  vector < vector < ss > > path(9, vector < ss > (9, ss("-","-")));
  mark[fila][columna]=1;
  while(!q.empty())
  {
    ii current = q.front(); q.pop();
    int level = current.second.second;
    if(current.first == tfila && current.second.first == tcolumna)
    {
      cout << level << '\n';
      break;
    }
    for(int i = 0 ; i < 8 ; i++)
    {
      int curr_f = current.first + dx[i];
      int curr_c = current.second.first + dy[i];
      if(inside(curr_c, curr_f))
      {
        if(!mark[curr_f][curr_c])
        {
          q.push(ii(curr_f,make_pair(curr_c,level+1)));
          mark[curr_f][curr_c] = 1;
          int copy = i+1;
          switch(copy)
          {
            case 1:
              path[curr_f][curr_c]=ss("RD","LU");
            break;
            case 2:
              path[curr_f][curr_c]=ss("D","U");
            break;
            case 3:
              path[curr_f][curr_c]=ss("LD","RU");
            break;
            case 4:
              path[curr_f][curr_c]=ss("R","L");
            break;
            case 5:
              path[curr_f][curr_c]=ss("L","R");
            break;
            case 6:
              path[curr_f][curr_c]=ss("UR","LD");
            break;
            case 7:
              path[curr_f][curr_c]=ss("U","D");
            break;
            case 8:
              path[curr_f][curr_c]=ss("LU","RD");
            break;
          }
        }
      }
    }
  }
  printPath(fila,columna,tfila,tcolumna,path);
}

int getColumns(char a)
{
  if(a == 'a') return 1;
  if(a == 'b') return 2;
  if(a == 'c') return 3;
  if(a == 'd') return 4;
  if(a == 'e') return 5;
  if(a == 'f') return 6;
  if(a == 'g') return 7;
  if(a == 'h') return 8;
}

int main()
{
  char fs,ft;
  int fis, fit;
  int cs,ct;
  cin >> fs >> cs >> ft >> ct;
  fis = getColumns(fs);
  fit = getColumns(ft);
  cs = abs(8-cs)+1;
  ct = abs(8-ct)+1;
  bfs(cs,fis,ct,fit);
  return 0;
}
