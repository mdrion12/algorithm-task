#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
const int N = 1009;
vector<int> parent1(N), parent2(N);
int dsu_find(int x, vector<int> &arr)
{
    if (arr[x] == -1)
    {
        return x;
    }
    else
    {
        int leader = dsu_find(arr[x], arr);
        arr[x] = leader;
        return leader;
        }
}
void dsu_union(int x, int y, vector<int> &arr)
{
    int a = dsu_find(x, arr);
    int b = dsu_find(y, arr);
    if (a != b)
    {
        arr[b] = a;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        parent1[i] = -1;
        parent2[i] = -1;
    }
    for (int i = 1; i <= a; i++)
    {
        int u, v;
        cin >> u >> v;
        dsu_union(u, v, parent1);
    }
    for (int i = 1; i <= b; i++)
    {
        int u, v;
        cin >> u >> v;
        dsu_union(u, v, parent2);
    }
    vector<pair<int, int>> res;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if ((dsu_find(i, parent1) != dsu_find(j, parent1)) && (dsu_find(i, parent2) != dsu_find(j, parent2)))
            {
                dsu_union(i, j, parent1);
                dsu_union(i, j, parent2);
                res.push_back({i, j});
            }
        }
    }
    cout << res.size() << "\n";
    for (auto it : res)
    {
        cout << it.first << " " << it.second << "\n";
    }

    return 0;
}