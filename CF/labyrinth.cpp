//Problem - https://codeforces.com/problemset/problem/1666/L

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

#define YES "YES"
#define NO "NO"
#define IMPOSSIBLE "Impossible"
#define POSSIBLE "Possible"
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
ll power(ll a, ll b, bool yes = 0);
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
    // /*is Single Test case?*/ cin >> t;
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
int dfs(vvi &graph, int curr, vb &visited, vvi &anc)
{
    int ans = -1;
    visited[curr] = 1;
    // this is the check for direct connection to s
    if (anc[curr].size() >= 2)
    {
        ans = curr;
        return ans;
    }
    rep(i, 0, graph[curr].size())
    {
        if (visited[graph[curr][i]] == 0)
        {
            if (anc[graph[curr][i]].size() != 0)
            {
                anc[graph[curr][i]].pb(curr);
                return graph[curr][i];
            }
            anc[graph[curr][i]].pb(curr);
            ans = dfs(graph, graph[curr][i], visited, anc);
        }
        if (ans != -1)
            break;
    }
    return ans;
}
void solve()
{
    cout << setprecision(12);
    /* create a graph. If there is only 1 way from s then ans is not possible (min 2 required).
    it is possible that ans('t') is directly connected to s becoz of which there is a check.
    simply do dfs and set ancestor for each node. if a node already has ancestor means its been visited from another branch,
    and we have the ans. */
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    vvi graph(n);
    int x, y;
    rep(i, 0, m)
    {
        cin >> x >> y;
        graph[x - 1].pb(y - 1);
    }
    if (graph[s].size() < 2)
    {
        cout << IMPOSSIBLE;
        return;
    }
    vvi anc(n);
    anc[s].pb(s);
    int ans = -1;
    rep(i, 0, graph[s].size())
    {
        vb visited(n);
        visited[s] = 1;
        anc[graph[s][i]].pb(s);
        ans = dfs(graph, graph[s][i], visited, anc);
        if (ans != -1)
            break;
    }
    if (ans == -1)
    {
        cout << IMPOSSIBLE;
        return;
    }
    vi ans1;
    vi ans2;
    ans1.pb(ans);
    ans2.pb(ans);
    ans1.pb(anc[ans][0]);
    ans2.pb(anc[ans][1]);
    x = ans1[1];
    while (anc[x][0] != s)
    {
        ans1.pb(anc[x][0]);
        x = anc[x][0];
    }
    if (ans1.back() != s)
        ans1.pb(s);
    x = ans2[1];
    while (anc[x][0] != s)
    {
        ans2.pb(anc[x][0]);
        x = anc[x][0];
    }
    if (ans2.back() != s)
        ans2.pb(s);
    reverse(all(ans1));
    reverse(all(ans2));
    cout << POSSIBLE << "\n";
    cout << ans1.size() << "\n";
    rep(i, 0, ans1.size())
    {
        cout << ans1[i] + 1 << " ";
    }
    cout << "\n"
         << ans2.size() << "\n";
    rep(i, 0, ans2.size())
    {
        cout << ans2[i] + 1 << " ";
    }
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
    return v1[0] > v2[0];
}
ll lcm(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}
