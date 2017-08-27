#include <iostream>

using namespace std;

typedef long long ll;

bool good_letters[27];

int to_pos(char a)
{
	return a - 'a';
}

int find_(string &pattern)
{
	for(int i = 0 ; i < (int)pattern.size() ; i++)
		if(pattern[i] == '*') return i;
	return -1;
}

bool match_good(string &query, string &pattern, int pos)
{
  int tam_query = query.size();
  int tam_pattern = pattern.size();
  for(int i = 0 ;  i< pos ; i++)
		if((pattern[i] == '?' && !good_letters[to_pos(query[i])]) || ((pattern[i] != '?' && query[i] != pattern[i]))) return false;
  int cont = 0;
  for(int i = tam_pattern-1, j = tam_query-1 ;  i> pos; i--, j--)
  {
		if(j < pos) return false;
  	if((pattern[i] == '?' && !good_letters[to_pos(query[j])]) || ((pattern[i] != '?' && query[j] != pattern[i]))) return false;
    cont++;
  }
  for(int i = pos ; i < abs(cont-tam_query) ; i++)
  {
  	if(i >= tam_query) return false;
  	if(good_letters[to_pos(query[i])]) return false;
  }
  return true;
}

bool match_good_not(string &query, string &pattern)
{
	int tam_query = query.size();
	int tam_pattern = pattern.size();
	if(tam_query != tam_pattern)  return false;
	for(int i = 0 ;  i< tam_query ; i++)
		if((pattern[i] == '?' && !good_letters[to_pos(query[i])]) || ((pattern[i] != '?' && query[i] != pattern[i]))) return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	for(int i = 0 ; i < 27 ; i++)
		good_letters[i] = 0;
	string good, pattern, query;
	int n;
	cin >> good >> pattern >> n;
	for(int i = 0 ; i < (int)good.size() ; i++)
		good_letters[to_pos(good[i])] = 1;
	int pos = find_(pattern);
	cin.ignore();
	while( n-- )
	{
		getline(cin,query);
		if(pos == -1)
			cout << (match_good_not(query, pattern) ? "YES" : "NO") << '\n';
		else
			cout << (match_good(query, pattern, pos) ? "YES" : "NO") << '\n';
	}
	return 0;
}
