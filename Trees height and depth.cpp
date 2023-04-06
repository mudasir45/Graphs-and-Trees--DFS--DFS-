#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 10e3*10;
vector<int> tree[N];
int depth[N];
int height[N];

void dfs_depth_height(int vertex, int par=0)
{
	cout<<"Vertex: "<<vertex<<endl;
	for(int child : tree[vertex])
	{
		if(child==par) continue;
		depth[child] = depth[vertex] + 1;
		cout<<"child: "<<child<<" depth: "<<depth[child]<<endl;
		
		dfs_depth_height(child, vertex);
		
		height[vertex] = max(height[vertex], height[child]+1);
		cout<<child<<" Child of: "<<vertex<<" height: "<<height[vertex]<<endl;
		
	}
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
	dfs_depth_height(1);
	cout<<"\n Height of this tree is: "<<height[1]<<endl;
	cout<<"\n Depth of this tree is: "<<depth[6]<<endl;
	
	
	
	return 0;
}