#include <bits/stdc++.h>
using namespace std;
#define Naba ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int>adj_list[10005];
bool vis[10005];

void dfs(int src)
{
    vis[src] = true;
    for(int child : adj_list[src])
    {
        if(!vis[child])
            dfs(child);
    }
}
int main() 
{
    Naba;
	
	int n,des;
	cin >> n >> des;
	
	int ar[n+5];
	for(int i = 0; i < n-1; i++)
	    cin >> ar[i];
	   
	for(int i = 1; i <= n; i++)
	{
	    int a,b;
	    a = i;
	    b = a + ar[i-1];
	    
	    if(b <= n)
	       adj_list[a].push_back(b);
	}
	
// 	for(int i = 1; i <= n; i++)
// 	{
// 	    cout << i << " : ";
 
// 	    for(int x : adj_list[i])
// 	       cout << x << " ";
// 	    cout << endl;
// 	}

    memset(vis, false,sizeof(vis));
    dfs(1);
    
    if(vis[des])
       cout << "Yes" << endl;
    else 
       cout << "No" << endl;
 
	
	return 0;

}
