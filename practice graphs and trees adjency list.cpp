#include<iostream>
#include<vector>
using namespace std;

const int N = 10e3+10;
vector<int> graph[N];
vector<pair<int, int> > graph1[N];

int main()
{
	int n, m;
	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		int v1, v2, wt;
		cin>>v1>>v2>>wt;
		
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
		
		graph1[v1].push_back({v2, wt});
		graph1[v2].push_back({v1, wt});
	}
	// Display the graph
	for (int i = 1; i <= n; i++) {
	    cout << "Adjacent vertices of vertex " << i << ": ";
	    for (int j = 0; j < graph[i].size(); j++) {
	        cout << graph[i][j] << " ";
	    }
	    cout << endl;
	}
	
	cout<<"\nDisplay the weighted graph"<<endl;
	// Display the weighted graph
	for (int i = 1; i <= n; i++) {
	    cout << "Adjacent vertices of vertex " << i << ": ";
	    for (int j = 0; j < graph1[i].size(); j++) {
	         cout << graph1[i][j].first << " (wt=" << graph1[i][j].second << ") ";
	    }
	    cout << endl;
	}
	
	// to find the sepcific connection and find weights
	for(int child : graph[4])
	{
		if(child==1)
			cout<<"connected!"<<endl;
	}
	
	for(pair<int, int> child: graph1[4])
	{
		if(child.first == 1)
		{
			cout<<"connected!"<<endl;
			cout<<"Weight: "<<child.second<<endl;
		}
	}
	

	
	
	return 0;
}