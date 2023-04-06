#include<iostream>
#include<vector>
using namespace std;
const int N = 10e5+10;
vector<int> tree[N];
int subtree_sum[N];
int even_ct[N];

void dfs(int vertex, int par)
{
	if(vertex%2==0)
		even_ct[vertex]++;
	subtree_sum[vertex] = vertex;
	cout<<"vertex: "<<vertex<<endl;
	cout<<"value of subtree_sum+=  "<<subtree_sum[vertex]<<endl;
	
	for(int child: tree[vertex]){
		
		if(child==par) continue;
		dfs(child, vertex);
		
		subtree_sum[vertex] += subtree_sum[child];
		even_ct[vertex] += even_ct[child];
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
	dfs(2, 1);
//	for(int i=1; i<=n; i++){
		cout<<"\nsubtree Sum of 2 is "<<subtree_sum[2]<<endl;
		cout<<"Even Count of 2 is "<<even_ct[2]<<endl;
//	}
	
	
	return 0;
}