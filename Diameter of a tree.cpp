#include<iostream>
#include<vector>
using namespace std;
const int N = 10e5*10;
vector<int> tree[N];
int depth[N];
void dfs(int vertex, int par=-1){
	
	for(int child: tree[vertex]){
		if(child==par) continue;
		depth[child] += depth[vertex]+1;
		dfs(child, vertex);
		
	}
}

int main()
{
	int n;
	cin>>n;
	for(int i=0; i<n-1; i++){
		int x, y;
		cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	dfs(9);
	int max_depth = -1, depth_index = -1;
	for(int i=1; i<=n; i++){
		cout<<depth[i]<<" ";
		if(max_depth < depth[i]){
			max_depth = depth[i];
			depth_index = i;
		}
		depth[i] = 0;
	}
	for(int i=1; i<=n; i++){
		cout<<depth[i]<<" ";
	}
	cout<<"Max Depth = "<<max_depth<<" at index of "<<depth_index<<endl;
	dfs(depth_index);
	max_depth = -1;
	depth_index = -1;
	for(int i=1; i<=1; i++){
		cout<<depth[i]<<" ";
		if(max_depth < depth[i]){
			max_depth = depth[i];
			
		}
	}
	cout<<"Diameter of the tree = "<<max_depth<<endl;
	
	return 0;
}