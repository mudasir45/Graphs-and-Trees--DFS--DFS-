#include<iostream>
#include<vector>
using namespace std;
const int N = 10e3+10;


void dfs(int i, int j, int initialColor, int newColor, vector<vector<int>>& image)
{
	int n, m;
	n = image.size();
	m = image[0].size();
	if(i < 0 || j < 0) return;
	if(i >= n || j >= m) return;
	if(image[i][j] != initialColor) return;
	
	image[i][j] = newColor;
	
	dfs(i-1, j, initialColor, newColor, image);
	dfs(i+1, j, initialColor, newColor, image);
	dfs(i, j-1, initialColor, newColor, image);
	dfs(i, j+1, initialColor, newColor, image);
}

int main()
{
	vector<vector<int>> image;
	int n, m;
	cin>>n>>m;
	for(int i=0; i<n; i++)
	{
		vector<int> row;
		row.clear();
		for(int j=0; j<m; j++)
		{
			int num;
			cin>>num;
			row.push_back(num);
		}
		image.push_back(row);
	}
	
	dfs(1, 2, 1, 5, image);
	cout<<"Displaying the image: "<<endl;
	for(auto child: image)
	{
		for(int n : child)
			cout<<n<<" ";
		cout<<endl;
	}
	
	
	return 0;
}