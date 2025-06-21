#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const int N = 1e3 + 5;
int n,t;
vector<int>vis(N);
vector<int>v(N);
void dfs(int i)
{
    if(i<=n)
    {
      if(vis[i]==0)
      {
       vis[i]=1;
       dfs(i+v[i]);
      }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>t;
     for(int i=0;i<N;i++)
     {
      vis[i]=0;
      }
    for(int i=1; i<=n-1; i++)
    {
        cin>>v[i];
    }

    dfs(1);
    if(vis[t]==1)
    {
        yes
    }
    else{
        no
    }

    return 0;
}
