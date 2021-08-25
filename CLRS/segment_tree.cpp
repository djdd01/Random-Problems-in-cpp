/* Ad-hoc/Implementation
Sort and Search
Hashing
Math
Greedy
DP
Graphs
DSU
Min Spanning Tree
Segment Trees
Strings Algo 
Tries, Suffix Tree, Suffix Array
Heavy light decomposition
Graph colouring, Network flow
Sqrt decomposition */

#include <bits/stdc++.h>

using namespace std;

#define YES "Yes"
#define NO "No"
#define ull unsigned long long
#define ll long long
#define ld long double
#define vin(a)        \
    for (auto &i : a) \
    cin >> i
#define vvin(a)       \
    for (auto &i : a) \
    vin(i)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define negrep(i, n, b) for (int i = n - 1; i >= b; i--)
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
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ld> vld;
typedef vector<vld> vvld;

double EPS = 1e-9;
int INF = 1000000007;
long long INFF = 1000000000000000007LL;
double PI = acos(-1);
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};

#define SQR(x) ((ll)(x) * (x))
#define SQRd(x) ((ld)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back

void solve();
ll power(ll a, ll b, bool yes);
vector<bool> sieve();
bool sortcol(const vector<int> &v1, const vector<int> &v2);
ll lcm(ll a, ll b);

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
    // int cases = t;
    while (t--)
    {
        // cout << "Case #" << cases - t << ':' << " ";
        solve();
        cout << "\n";
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
int root(int x, vi &set)
{
    while (set[x] != x)
    {
        set[x] = set[set[x]];
        x = set[x];
    }
    return x;
}
void build(vi &segtree, vi &a, int node, int start, int end)
{
    if (start == end)
    {
        segtree[node - 1] = a[start];
        return;
    }
    int mid = (start + end) / 2;    
    build(segtree, a, 2 * node, start, mid);
    build(segtree, a, 2 * node + 1, mid + 1, end);
    segtree[node - 1] = segtree[2 * node - 1] + segtree[2 * node];
}
void update(vi &segtree,int node, int ind, int val,int start, int end){
    if(end < ind){
        return;
    }
    if(start > ind){
        return;
    }
    if (start == end)
    {
        segtree[node - 1] = val;
        return;
    }
    int mid = (start + end) / 2;    
    update(segtree, 2 * node,ind,val, start, mid);
    update(segtree, 2 * node + 1,ind,val, mid + 1, end);
    segtree[node - 1] = segtree[2 * node - 1] + segtree[2 * node];
}
int givesum(vi &segtree, int node, int start, int end, pii range)
{
    if(end < range.fi || start > range.se){
        return 0;
    }
    if (start >= range.first && end <= range.second)
    {
        return segtree[node - 1];
    }
    int mid = (start + end) / 2;
    return givesum(segtree, 2 * node, start, mid, range) +
        givesum(segtree, 2 * node + 1, mid + 1, end, range);
}
void solve()
{
    cout << setprecision(12);
    int n;
    cin >> n;
    vi a(n);
    vin(a);
    vi segtree(4 * n);
    build(segtree, a, 1, 0, n - 1);
    update(segtree,1,2,3,0,n-1);
    int sum = givesum(segtree, 1, 0, n - 1, {0, 4});
    cout << sum;
    return;
}
vector<bool> sieve()
{
    int n = 10000001;
    vector<bool> primes(n, 1);
    primes[0] = 0;
    primes[1] = 0;
    for (ll i = 4; i < n; i += 2)
    {
        primes[i] = 0;
    }
    for (int i = 3; i * i < n; i += 2)
    {
        for (ll j = i * i; j < n; j += i)
        {
            primes[j] = 0;
        }
    }
    return primes;
}
ll power(ll a, ll b, bool yes)
{
    ll result = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            result = result * a;
            if (yes)
                result %= INF;
        }
        a = a * a;
        if (yes)
            a %= INF;
        b >>= 1;
    }
    return result;
}
bool sortcol(const vector<int> &v1, const vector<int> &v2)
{
    return v1[2] < v2[2];
}
ll lcm(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}
