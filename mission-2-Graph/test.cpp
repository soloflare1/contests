#include <bits/stdc++.h>
using namespace std;
#define Naba ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
int n,m,cnt;
// vis track
bool vis[1005][1005];

// grid
char grid[1005][1005];

// Minimum dist
int level[1005][1005];

// 
// vertically or horizontally adjacent moves
// free moves
vector<pair<int,int>> d =
{
    {-1,0}, {1,0},
    {0,-1}, {0,1}
};

bool valid(int i, int j)
{
    if( i < 0 || i >= n || j < 0 || j >= m)  return false;
    return true;
}

// bfs
void bfs(int si, int sj,int di,int dj)
{
    queue<pair<int, int>>q;
    
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;
    
    while(!q.empty())
    {
        pair<int,int>par;
        par = q.front();
        q.pop();
        
        int par_i = par.first;
        int par_j = par.second;
        
        // 
        
        for(int i=0; i< 4; i++)
        {
            int ci = par_i + d[i].first;  
            int cj = par_j + d[i].second;
            
            if(!vis[ci][cj] && valid(ci, cj) && grid[ci][cj] == '.')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                
                level[ci][cj] = level[par_i][par_j] + 1;
            }
            else 
              cnt++;
        }
    }
    
}

int main() 
{
    Naba;
   
    cin >> n >> m;
    int si, sj;  cin >> si >> sj;
    int di, dj;  cin >> di >> dj;
    
    
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
         cin >> grid[i][j];
         
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    
   
    bfs(si, sj, di, dj);
    
    // 
    cout << level[di][dj] << endl;
     cout << cnt << endl;
    
	return 0;

}
