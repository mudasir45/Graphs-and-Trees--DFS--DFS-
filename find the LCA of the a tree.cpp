#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 10e5+10;
vector<int> tree[N];
int par[N];
void dfs(int vertex, int p = -1){
	par[vertex] = p;
	for(int child : tree[vertex]){
		if(child==p) continue;
		dfs(child, vertex);
	}
}

vector<int> path(int v){
	vector<int> ans;
	while(v != -1){
		ans.push_back(v);
		v = par[v];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	int n; 
	cin>>n;
	for(int i=0; i<n-1; i++)
	{
		int x, y;
		cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	// Run DFS to store the parent of all vertecs
	dfs(1);
	cout<<"DFS runing: "<<endl;
	for(int i=1; i<=n; i++){
		cout<<par[i]<<" ";
	}cout<<endl;
	
	cout<<"Enter the two vetrices to find the LCA: "<<endl;
	int x, y;
	cin>>x>>y;
		// get out the path of x
	vector<int> x_path = path(x);
	for(int i=0; i<=x_path.size(); i++)
		cout<<x_path[i]<<" ";
	cout<<endl;
	
		// get out the path of x
	vector<int> y_path = path(y);
	for(int i=0; i<=y_path.size(); i++)
		cout<<y_path[i]<<" ";
	cout<<endl;
	
	int min_len, LCA = -1;
	
	// Get the minimum length
	min_len = min(x_path.size(), y_path.size());
	
	for(int i=0; i<=min_len; i++){
		
		if(x_path[i] == y_path[i]){
			LCA = x_path[i];
		}
		else{
			break;
		}
	}
	cout<<"The LCA of the both number is: "<<LCA<<endl;
	
	return 0;
}