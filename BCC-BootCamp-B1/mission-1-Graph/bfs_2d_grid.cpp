#include <bits/stdc++.h>
using namespace std;
#define Naba ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int n,m;  
char grid[105][105];
bool vis[105][105];
int level[105][105];

vector<pair<int, int>> mv{{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=m)
       return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    
    vis[si][sj] = true;
    level[si][sj] = 0;
    
    while(!q.empty())
    {
        pair<int,int> par = q.front();
        q.pop();
        
        int par_i = par.first;
        int par_j = par.second;
        
        for(int i = 0; i < 4; i++)
        {
            int ci = par_i + mv[i].first;
            int cj = par_j + mv[i].second;
            
            if(valid(ci, cj) && !vis[ci][cj])
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
	
	
	cin >> n >> m;
	
	for(int i=0; i<n;i++)
	   for(int j=0;j<m;j++)
	      cin >> grid[i][j];
	
	for(int i=0; i<n;i++)
	{
	   for(int j=0;j<m;j++)
	      cout << grid[i][j] << " ";
	   cout << endl;
	}
	
	int si,sj;
	cin >> si >> sj;
	
	int di,dj;
	cin >> di >> dj;
	
	memset(vis, false, sizeof(vis));
	memset(level, -1, sizeof(level));
	
	bfs(si,sj);
	
	
	cout << level[di][dj] << endl;
	
	return 0;
	  
}
