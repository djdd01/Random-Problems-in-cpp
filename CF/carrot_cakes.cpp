//Problem - https://codeforces.com/contest/799/problem/A

#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve();
vector<int> bestSum(vector<int> &query, int target, map<int, vector<int>> &possible);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    /*is Single Test case?*/ //cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
void solve()
{
    int n, t, k, d;
    cin >> n >> t >> k >> d;
    if (d < t)
    {
        if ((n - k) <= 0)
            cout << "NO";
        else
            cout << "YES";
    }
    else if (d == t)
    {
        if ((n - k) <= k)
            cout << "NO";
        else
            cout << "YES";
    }
    else
    {
        if (n-((d / t) * k) <= k)
            cout << "NO";
        else
            cout << "YES";
    }
    return;
}
