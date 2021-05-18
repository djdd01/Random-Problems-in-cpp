#include <bits/stdc++.h>

using namespace std;

#define YES "YES"
#define NO "NO"
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
typedef map<int, int> mii;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<double> vd;
typedef vector<vd> vvd;

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
ll power(ll a, ll b);
vector<bool> sieve();

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
    //int cases = t;
    while (t--)
    {
        //cout << "Case #" << cases - t << ':' << " ";
        solve();
        cout << "\n";
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
int partition(vi &a, int p, int r){
    int i = p-1;
    rep(j,p,r){
        if(a[j] <= a[r])
            swap(a[++i],a[j]);
    }
    swap(a[++i],a[r]);
    return i;
}
void quicksort(vi &a, int p, int r){
    if(p>=r)
    return;
    int q = partition(a,p,r);
    quicksort(a,p,q-1);
    quicksort(a,q+1,r);
}
void solve()
{
    cout << setprecision(12);
    int n;
    cin >> n;
    vi a(n);
    rep(i,0,n){
        cin >> a[i];
    }
    quicksort(a,0,n-1);
    for(auto x: a)
    {
        cout << x << " ";
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
ll power(ll a, ll b)
{
    ll result = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            result = result * a;
        }
        a = a * a;
        b >>= 1;
    }
    return result;
}
