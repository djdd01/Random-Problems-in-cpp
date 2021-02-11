// Problem Statement - https://codeforces.com/problemset/problem/630/I


#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(a) a.begin(), a.end()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
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
ull compute(ull a, int b);

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
    int n;
    cin >> n;
    int power1 = n - 3;
    int power2 = n - 4;
    ull ans1 = compute(4,n-3);
    ull ans2 = compute(4,n-4);
    ans1 *= 12;
    ans2 *= 36;
    ans1 *= 2;
    ans2 *= (n - 3);
    cout << ans1+ans2;
    return;
}
ull compute(ull a, int b) {
    ull result = 1;
    while(b > 0) {
        if(b&1)
        result *= a;
        a*=a;
        b >>= 1;
    }
    return result;
}
