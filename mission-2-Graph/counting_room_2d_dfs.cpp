#include <bits/stdc++.h>
using namespace std;
#define Naba ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int n,m;
// vis track
bool vis[1005][1005];

// grid
char grid[1005][1005];


// moves
vector<pair<int,int>> d ={
    {-1,0}, {1,0}, {0,1}, {0,-1}
};


bool valid(int i, int j)
{
    if( i < 0 || i >= n || j < 0 || j >= m)  return false;
    return true;
}


void dfs(int si, int sj)
{
    vis[si][sj] = true;

    for(int i=0; i< 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if( valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
            dfs(ci,cj);
    }

}

int main()
{

    Naba;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin  >> grid[i][j];

    memset(vis, false, sizeof(vis));

    int cnt = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == '.' && vis[i][j] == false)
            {
                cnt ++;
                dfs(i, j);
            }
        }
    }

    cout << cnt << endl;


	return 0;

}
