// https://codeforces.com/problemset/problem/246/B

#include <bits/stdc++.h>

using namespace std;

#define YES "YES"
#define NO "NO"
#define ull unsigned long long
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(a) a.begin(), a.end()
typedef map<int, int> mii;
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
    while (t--)
    {
        solve();
        //cout << "\n";
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
void solve()
{
    cout << setprecision(12);
    int n =0;
    cin >> n;
    vi a(n);
    int total = 0;
    rep(i,0,n){
        cin >> a[i];
        total += a[i];
    }
    if(total%n == 0)
    cout << n;
    else
    cout << n-1;
    return;
}
vector<bool> sieve(){
    vector<bool> primes(10000001,1);
    for(ll i=4;i<10000001;i+=2){
        primes[i] = 0;
    }
    for(int i =3;i*i<10000001;i+=2){
        for(ll j =i*i;j<10000001;j+=i){
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
        result = result * result;
        if (b % 2 != 0)
        {
            result = result * a;
        }
        a = a * a;
        b >>= 1;
    }
    return result;
}
