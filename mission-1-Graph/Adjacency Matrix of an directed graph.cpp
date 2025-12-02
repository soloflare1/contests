#include <bits/stdc++.h>
using namespace std;
#define Naba ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() 
{
    Naba;
	
	int n,e; cin >> n >> e;
	int ad_mat[n][n];
	
	memset(ad_mat, 0, sizeof(ad_mat));
	
	
	for(int i = 0; i < e; i++)
	{
	    int a,b; 
	    cin >> a >> b;
	  
	    ad_mat[a][b] = 1;
	    ad_mat[b][a] = 1;
	}
	
	for(int i = 0; i < n; i++)
    {   
        for(int j = 0; j < n; j++)
            cout << ad_mat[i][j] << " ";
	    cout << endl;
    }
	
	
	return 0;

}
