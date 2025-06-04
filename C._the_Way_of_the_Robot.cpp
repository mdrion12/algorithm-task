#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
int n, m;
char arr[101][101];
int parent[101][101];
int vis[101][101];
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool valid(int i, int j)
{
    if ((i >= 1 && i <= n) && (j >= 1 && j <= m))
    {
        if ((arr[i][j] == '*' || arr[i][j] == 'S') && vis[i][j] == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
void dfs(int x, int y, int px, int py)
{
    for (int i = 0; i < 4; i++)
    {
        int cx = dir[i].first + x;
        int cy = dir[i].second + y;
        if (valid(cx, cy) && (cx != px || cy != py))
        {
            parent[cx][cy] = i;
            vis[cx][cy] = 1;
            dfs(cx, cy, x, y);
        }
    }
}
string s = "";
void getpath(int x, int y)
{
    if (arr[x][y] == 'S')
    {
        return;
    }
    if (parent[x][y] == 0)
    {
        s += "R";
        getpath(x, y - 1);
    }
    if (parent[x][y] == 1)
    {
        s += "L";
        getpath(x, y + 1);
    }
    if (parent[x][y] == 2)
    {
        s += "D";
        getpath(x - 1, y);
    }
    if (parent[x][y] == 3)
    {
        s += "U";
        getpath(x + 1, y);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'S')
            {
                x = i;
                y = j;
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    dfs(x, y, 0, 0);
    cout << x << " " << y << "\n";
    int a1, z1;

    if (parent[x][y] == 0)
    {
        s += "R";
        a1 = x, z1 = y - 1;
    }
    if (parent[x][y] == 1)
    {
        s += "L";
        a1 = x, z1 = y + 1;
    }
    if (parent[x][y] == 2)
    {
        s += "D";
        a1 = x - 1, z1 = y;
    }
    if (parent[x][y] == 3)
    {
        s += "U";
        a1 = x + 1, z1 = y;
    }
    parent[x][y] = -1;
    getpath(a1, z1);
    reverse(s.begin(), s.end());
    cout << s << "\n";
    return 0;
}
