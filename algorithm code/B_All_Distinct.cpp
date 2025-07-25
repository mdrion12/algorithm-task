#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            s.insert(value);
        }
        int sum = n - s.size();
        if (sum % 2 == 0)
        {
            cout << s.size() << "\n";
        }
        else
        {
            cout << s.size() - 1 << "\n";
        }
    }
    return 0;
}