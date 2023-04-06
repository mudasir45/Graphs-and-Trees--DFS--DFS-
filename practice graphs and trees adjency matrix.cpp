#include<iostream>
#include<vector>
using namespace std;
const int N = 10e3+10;
int graph1[N][N];

int main()
{
	int n, m;
	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		int v1, v2;
		cin>>v1>>v2;
		
		graph1[v1][v2] = 1;
		graph1[v2][v1] = 1;
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
			cout<<graph1[i][j]<<" ";
		cout<<endl;
	}
	
	if(graph1[2][3]==1)
		cout<<"connected"<<endl;
	else
		cout<<"not connected"<<endl;
	
	return 0;
}