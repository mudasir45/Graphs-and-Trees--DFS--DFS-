#include<iostream>
using namespace std;
int main()
{
	int n, m, p;
	cout<<"Enter the number of rows and colums for your metrix 1: ";
	cin>>m>>n;
	cout<<"Enter the number of culums for 2nd metrix: ";
	cin>>p;
	int A[m][n], B[n][p], C[m][p];
	
	cout<<"Enter values for 1st metrix "<<m<<" * "<<n<<endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>>A[i][j];
		}
	}
	
	cout<<"Enter values for 2nd metrix "<<n<<" * "<<p<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<p; j++){
			cin>>B[i][j];
		}
	}
	
	for(int i=0; i<m; i++){
		for(int j=0; j<p; j++){
			C[i][j]=0;
		}
	}
	

	for(int i=0; i<p; i++){
		for(int j=0; j<m; j++){
			for(int k=0; k<n; k++){
				C[i][j] += A[i][k] * B[k][j]; 
			}
		}
	}
	
	cout<<"Resultant Metrix: "<<endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<p; j++){
			cout<<C[i][j]<<" ";
			
		}
		cout<<endl;
	}
	
	
	return 0;
}