#include<iostream>
#include<vector>
using namespace std;
const int N = 10e5 + 10;
vector<int> g[N];
bool vis[N];

bool isSycle(int vertex, int par){
	
	
	vis[vertex] = true;
	bool isLoopExist = false;
	for(int child : g[vertex])
	{
		if(vis[child] && child==par) continue;
		if(vis[child]) return true;
		isLoopExist |= isSycle(child, par);
	}
	return isLoopExist;
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
	bool isSycleExist = false;
	for(int i=1; i<=n; i++)
	{
		if(vis[i]) continue;
		if(isSycle(i, 0))
			isSycleExist = true;
	}
	cout<<isSycleExist<<endl;
		
	return 0;
}