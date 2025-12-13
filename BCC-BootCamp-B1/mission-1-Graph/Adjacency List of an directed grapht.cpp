#include <bits/stdc++.h>
using namespace std;
#define Naba ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() 
{
    Naba;
	
	int n,e; cin >> n >> e;
	vector<int>adj_list[n+5];
	
	while(e--)
	{
	    int a,b;
	    cin >> a >> b;
	    
	    adj_list[a].push_back(b);
	    adj_list[b].push_back(a);
	}
	
	for(int i = 0; i < n; i++)
	{
	    cout << i << " : ";
	    
	    for(int x : adj_list[i])
	       cout << x << " ";
	    cout << endl;
	}
	
	return 0;

}
