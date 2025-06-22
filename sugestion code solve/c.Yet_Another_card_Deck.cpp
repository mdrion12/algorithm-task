#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << "NO" << "\n";
#define yes cout << "YES" << "\n";
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;

    vector<int> deck(n);
    map<int, int> color_pos;

    for (int i = 0; i < n; ++i) {
        cin >> deck[i];
        if (color_pos.count(deck[i]) == 0) {
            color_pos[deck[i]] = i;
        }
    }

    while (q--) {
        int t;
        cin >> t;

        int idx = color_pos[t];
        cout << idx + 1 << " ";

        for (auto &x : color_pos) {
            if (x.second < idx) {
                x.second += 1;
            }
        }
        color_pos[t] = 0;
    }

    cout << "\n";
    return 0;
}
