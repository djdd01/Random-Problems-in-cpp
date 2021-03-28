//https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d12d7

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
void recursion(int n, int k, int &score);
void nonrecursion(int n, int d, int &notscore);

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
    int cases = t;
    while (t--)
    {
        cout << "Case #" << cases - t << ':' << " ";
        solve();
        cout << "\n";
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
void solve()
{
    cout << setprecision(12);
    int n,c;
    cin >> n >> c;
    if(c < n-1 || c > n*(n+1)/2 - 1){
        cout << "IMPOSSIBLE";
        return;
    }
    vi a(n);
    rep(i,0,n){
        a[i] = i+1;
    }
    c -= n-1;
    rep(i,0,n){
        int j = min(c,n-i-1);
        int temp = 0;
        int k = 0;
        if(i%2 == 0){
            k = i/2;
            temp = k + j;
        }
        else{
            temp = n - 1 - (i+1)/2;
            k = temp - j;
        }
        while(temp > k){
            swap(a[k],a[temp]);
            temp--;
            k++;
        }
        c -= j;
        if(c == 0){
            break;
        }
    }
    rep(i,0,n){
        cout << a[i] << " ";
    }
    return;
}
vector<bool> sieve()
{
    vector<bool> primes(1000001, 1);
    primes[0] = 0;
    primes[1] = 0;
    for (ll i = 4; i < 1000001; i += 2)
    {
        primes[i] = 0;
    }
    for (int i = 3; i * i < 1000001; i += 2)
    {
        for (ll j = i * i; j < 1000001; j += i)
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
