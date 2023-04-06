#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 10e5+10;
vector<int> tree[N];
int subtree_sum[N];
int val[N];

void dfs(int v, int p){
	
	subtree_sum[v] = val[v]; 
	for(int child : tree[v]){
		if(child==p) continue;
		dfs(child, v);
		
		subtree_sum[v] += subtree_sum[child];
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n-1; i++){
		int x, y;
		cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	cout<<"Inter the value for "<<n<<" vertecs ";
	for(int i=1; i<=n; i++){
		cin>>val[i];
	}
	
	cout<<"Tree representation with weights: "<<endl;
	for(int i=0; i<=n; i++){
		cout<<"For vertex: "<<i<<" weight = "<<val[i]<<endl<<"connected with ==> ";
		for(int child: tree[i]){
			cout<<child<<" ";
		}cout<<endl;
	}
	dfs(1, -1);
	for(int i=0; i<=n; i++){
		cout<<"submtree sum of "<<i<<" is: "<<subtree_sum[i]<<endl;
	}
	
	long long max_sum = 1;
	for(int i=2; i<=n; i++){
		int part1 = subtree_sum[i];
		int part2 = subtree_sum[1]-part1;
		cout<<"part1: "<<part1<<endl<<" part2: "<<part2<<endl;
		long long mul = part1 * part2;
		cout<<"Multiplication: "<<mul<<endl;
		max_sum = max(max_sum, mul);
		cout<<"Max sum: "<<max_sum<<endl;
	}
	cout<<"Maximum: "<<max_sum<<endl;
	
	
	return 0;
}