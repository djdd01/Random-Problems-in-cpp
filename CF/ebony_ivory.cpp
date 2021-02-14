//https://codeforces.com/contest/633/problem/A

#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(a) a.begin(), a.end()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

double EPS = 1e-9;
int INF = 1000000007;
long long INFF = 1000000000000000007LL;
double PI = acos(-1);
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};

#define SQR(x) ((ll)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back

void solve();
int gcd(int a, int b, int &x, int &y);

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
    cout << setprecision(10);
    int a, b, c, g, x, y;
    cin >> a >> b >> c;
    g = gcd(a, b, x, y);
    int c0 = c / g;
    x = x * c0;
    y = y * c0;
    if (c % g != 0)
        cout << "No";
    else if (x < 0)
    {
        int constant = ((0 - x) * g) / b;
        x = x + (constant * b) / g;
        y = y - (constant * a) / g;
        if (x >= 0 && y >= 0)
            cout << "Yes";
        else if (y >= a/g)
        {
            x = x + b / g;
            y = y - a / g;
            if (x >= 0 && y >= 0)
                cout << "Yes";
            else
                cout << "No";
        }
        else
            cout << "No";
    }
    else if (y < 0)
    {
        int constant = ((0 - y) * g) / a;
        x = x - (constant * b) / g;
        y = y + (constant * a) / g;
        if (x >= 0 && y >= 0)
            cout << "Yes";
        else if (x >= b/g)
        {
            x = x - b / g;
            y = y + a / g;
            if (x >= 0 && y >= 0)
                cout << "Yes";
            else
                cout << "No";
        }
        else
            cout << "No";
    }
    else
        cout << "Yes";
    return;
}
int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
