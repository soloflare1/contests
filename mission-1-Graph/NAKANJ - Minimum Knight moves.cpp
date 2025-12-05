#include <bits/stdc++.h>
using namespace std;
#define Naba ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

// vis track
bool vis[8][8];

// grid
char grid[8][8];

// Minimum dist
int level[8][8];


// Knight moves
vector<pair<int,int>> d ={
    {-2,1}, {-2,-1}, {-1,2}, {-1,-2}, 
    {1,2}, {1,-2}, {2,1}, {2,-1}
};

// valid index
// si -> 0 to 7 (a to h)
// sj -> 0 to 8
bool valid(int i, int j)
{
    if( i < 0 || i >= 8 || j < 0 || j >= 8)  return false;
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
        
        for(int i=0; i< 8; i++)
        {
            int ci = par_i + d[i].first;  
            int cj = par_j + d[i].second;
            
            if( valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
    
}

int main() 
{
    Naba;
   
    int t; cin >> t;
    
    while(t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        memset(grid, '.', sizeof(grid));
        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));
    
        int si = s1[0]-'a', sj = s1[1]-'1';
        int di = s2[0]-'a', dj = s2[1]-'1';
      
        bfs(si, sj, di, dj);
    
        cout << level[di][dj] << endl;
    }
    
 
    
	return 0;

}
