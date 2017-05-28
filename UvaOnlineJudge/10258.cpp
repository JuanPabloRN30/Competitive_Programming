#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <string>
#include <set>

using namespace std;

struct Team
{
  int id;
  int solve;
  int penalty;
  bool sub;
  set < int > p_solve;
  Team(  )
  {
    id = solve = penalty = sub = 0;
  }

  bool operator <( Team other ) const{
    if( this->solve > other.solve )
      return this->solve > other.solve;
    else if( this->solve == other.solve )
    {
      if( this->penalty < other.penalty )
        return this->penalty < other.penalty;
      else if( this->penalty == other.penalty )
        return this->id < other.id;
      return false;
    }
    return false;
  }

  void toString()
  {
    printf("%d %d %d\n",id,solve,penalty);
  }
};

struct Problem
{
  int id_team;
  int id;
  Problem( ){}
  Problem( int _a, int _b ) : id_team(_a), id(_b) {}
};

int search_penalty( vector < Problem > p, int id_team, int id_problem )
{
  int penalty = 0;
  for( int i = 0 ; i < (int)p.size() ; ++i )
  {
    if( id_team == p[ i ].id_team && id_problem == p[ i ].id )
      penalty += 20;
  }
  return penalty;
}

int main()
{
  int cases,id,problem,penalty, tot;
  char op;
  string linea;
  scanf("%d",&cases);
  cin.ignore();
  cin.ignore();
  int c = 0;
  while( cases-- )
  {
    if( c ) printf("\n");
    c++;
    vector < Team > teams(110);
    for( int i = 0 ; i < 110 ; i++ )
      teams[ i ].id = i;
    vector < bool > sub( 110 , false);
    vector < Problem > p;
    while( getline( cin, linea ) && linea != "" )
    {
      stringstream ss( linea );
      ss >> id >> problem >> penalty >> op;
      if( op == 'C' )
      {
        if( teams[ id ].p_solve.find( problem ) == teams[ id ].p_solve.end() )
        {
          tot = search_penalty( p, id, problem );
          teams[ id ].solve++;
          teams[ id ].p_solve.insert( problem );
          teams[ id ].penalty += tot + penalty;
        }
      }
      else if( op == 'I' )
        p.push_back( Problem( id, problem ) );
      teams[ id ].sub = true;
    }
    sort( teams.begin(), teams.end() );
    for( int i = 0 ; i < (int)teams.size() ; i++ )
      if( teams[ i ].sub )
        teams[ i ].toString();
  }
  return 0;
}
