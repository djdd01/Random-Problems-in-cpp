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
bool sortcol(const vector<ll> &v1, const vector<ll> &v2);
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
    /*is Single Test case?*/ cin >> t;
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
void solve()
{
    cout << setprecision(12);
    int n, k;
    cin >> n >> k;
    vi a(n);
    vin(a);
    k--;

    //Random-Select
    //Randomized Quicksort-like algorithm (the partition part using pivot and dividing the array is similar). So EXPECTED O(2n).
    int lo = 0;
    int hi = n - 1;
    std::mt19937 rng(time(NULL));
    while (lo <= hi)
    {
        std::uniform_int_distribution<int> gen(lo, hi); // uniform, unbiased
        int s = gen(rng);
        swap(a[lo], a[s]);
        int q = lo;
        int r = lo + 1;
        while (r <= hi)
        {
            if (a[r] >= a[lo])
            {
                swap(a[q + 1], a[r]);
                q++;
            }
            r++;
        }
        swap(a[q],a[lo]);
        if(q == k){
            cout << a[q];
            return;
        }
        else if(q > k){
            hi = q - 1;
        }
        else{
            lo = q+ 1;
        }
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
ll power(ll a, ll b, bool yes = 0)
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
bool sortcol(const vector<ll> &v1, const vector<ll> &v2)
{
    return v1[2] < v2[2];
}
ll lcm(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}
