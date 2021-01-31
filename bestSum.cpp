// Problem statement: given an array and a targetsum, 
// return the smallest possible array to create that target sum.
// Numbers are allowed to be reused.
// Sample inputs and output : 
// number of test cases : 4
// format - array length(n), targetsum, array elements.
// 1. 4 7
//  5 3 4 7  output: 7
// 2. 3 8
//  2 3 5  output: 5,3
// 3. 4 8
//  1 4 5 8 output: 4,4
// 4. 4 100
//  1 2 5 25 output: 25,25


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
    /*is Single Test case?*/ cin >> t;
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
    int n, target;
    cin >> n >> target;
    vector<int> query(n);
    for (int i = 0; i < n; i++)
    {
        cin >> query[i];
    }
    map<int, vector<int>> possible;
    bestSum(query, target, possible);
    for (int i = 0; i < possible[target].size(); i++)
    {
        cout << possible[target][i] << " ";
    }
    return;
}
vector<int> bestSum(vector<int> &query, int target, map<int, vector<int>> &possible)
{
    vector<int> curr;
    if (!possible[target].empty())
        return possible[target];
    if (target == 0)
    {
        return {};
    }
    else
    {
        for (int i = 0; i < query.size(); i++)
        {
            if (query[i] <= target)
            {
                curr = bestSum(query, target - query[i], possible);
                if (curr.empty() || curr[0] != -1)
                {
                    curr.push_back(query[i]);
                    if (possible[target].empty() || (possible[target].size() > curr.size()))
                    {
                        possible[target] = curr;
                    }
                }
            }
        }
    }
    if (possible[target].empty())
        possible[target] = {-1};
    return possible[target];
}