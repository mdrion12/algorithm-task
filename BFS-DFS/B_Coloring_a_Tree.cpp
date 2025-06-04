#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const int N = 1e4 + 9;
vector<int> clr(N);
vector<int> adj[N];
int cn = 0;
void dfs(int x, int p)
{
    for (auto it : adj[x])
    {
        if (it != p)
        {
            if (clr[it] != clr[x])
            {
                cn++;
            }
            dfs(it, x);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        int v;
        cin >> v;
        adj[v].push_back(i);
        adj[i].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> clr[i];
    }
    dfs(1, 0);
    cout << cn + 1 << "\n";
    return 0;
}