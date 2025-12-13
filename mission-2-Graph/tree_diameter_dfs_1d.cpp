

#include <bits/stdc++.h>
using namespace std;
#define Naba ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int>adj_list[200005];
bool vis[200005];
int d[200005];

void dfs(int src)
{
    vis[src] = true;

    for(int child : adj_list[src])
    {
        if(!vis[child])
        {
            d[child] = d[src] + 1;
            dfs(child);
        }
    }
}

int main()
{
    Naba;
    int n; cin >> n;

    int e = n-1;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(d, 0, sizeof(d));

    dfs(1);

    int mx_d = -1,  mx_node = 0;

    for(int i = 1; i <= n; i++)
    {
        if(mx_d < d[i])
        {
            mx_d = d[i];
            mx_node = i;
        }

    }
    
    memset(d, 0, sizeof(d));
    memset(vis, false, sizeof(vis));


    dfs(mx_node);
    for(int i = 1; i <= n; i++)
    {
        if(mx_d < d[i])
            mx_d = d[i];
    }

    cout << mx_d << endl;

	return 0;

}
