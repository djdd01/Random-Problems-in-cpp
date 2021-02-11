//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3671

// Many well-known cryptographic operations require modular exponentiation. That is, given integers x,
// y and n, compute x
// y mod n. In this question, you are tasked to program an efficient way to execute
// this calculation.

// Input
// The input consists of a line containing the number c of datasets, followed by c datasets, followed by a
// line containing the number ‘0’.
// Each dataset consists of a single line containing three positive integers, x, y, and n, separated by
// blanks. You can assume that 1 < x, n < 2
// 15 = 32768, and 0 < y < 2
// 31 = 2147483648.

// Output
// The output consists of one line for each dataset. The i-th line contains a single positive integer z such
// that
// z = x
// y mod n
// for the numbers x, y, z given in the i-th input dataset.

// Sample Input
// 2
// 2 3 5
// 2 2147483647 13
// 0
// Sample Output
// 3
// 11

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
int compute(int x, int y, int n);

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
    cout << setprecision(10);
    int x,y,n;
    cin >> x>>y>>n;
    int ans = compute(x,y,n);
    cout << ans;
    return;
}
int compute(int x, int y, int n){
    ull res = 0;
    if(y == 0) {
        return 1;
    }
    res = compute(x, y/2, n);
    if(y%2)
    return (res*res*x)%n;
    else
    return (res*res)%n;
}
