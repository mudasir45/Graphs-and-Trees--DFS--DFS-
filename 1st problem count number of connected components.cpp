#include<iostream>
#include<vector>
using namespace std;
const int N = 10e5+10;
vector<int> g[N];
bool vis[N];
vector<int> saved_cc;
vector<vector<int>> number_cc;

void dfs(int vertex){
	if(vis[vertex]) return;
	vis[vertex] = true;
	saved_cc.push_back(vertex);
	for(int child : g[vertex]){
		
		dfs(child);
	}
}
int main()
{
	int n, e;
	cin>>n>>e;
	for(int i=0; i<e; i++)
	{
		int x, y;
		cin>>x>>y;
		
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	int cc = 0;
	for(int i=1; i<=n; i++)
	{
		if(vis[i]) continue;
		saved_cc.clear();
		dfs(i);
		number_cc.push_back(saved_cc);
		cc++;
	}
	cout<<"Number of connected components! "<<number_cc.size()<<endl;
	for(auto m : number_cc){
		for(int j : m){                                    
			cout<<j<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}