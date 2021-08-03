//Problem Statement - https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/puchi-and-luggage/
#include <bits/stdc++.h>

using namespace std;

#define YES "YES"
#define NO "NO"
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
bool sortcol(const vector<ll> &v1, const vector<ll> &v2, int col);
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
vi ans;
map<int,int> hah;
void merge(vi &a, int l, int mid, int r)
{
    vi temp;
    int i = l;
    int j = mid + 1;
    int w = 0;
    while(i <=mid && j <=r){
        if(a[i] > a[j]){
            w++;
            temp.push_back(a[j]);
            j++;
        }
        else{
            ans[hah[a[i]]] += w;
            temp.push_back(a[i]);
            i++;
        }
    }
    while(i <= mid){
        ans[hah[a[i]]] += w;
        temp.push_back(a[i]);
        i++;
    }
    while(j <= r){
        temp.push_back(a[j]);
        j++;
    }
    i = 0;
    rep(k,l,r+1){
        a[k] = temp[i++];
    }
}
void mergesort(vi &a, int l, int r)
{
    if(r <= l){
        return;
    }
    int mid = (l + r) / 2;
    mergesort(a,l,mid);
    mergesort(a,mid+1,r);
    merge(a,l,mid,r);
}
void solve()
{
    cout << setprecision(12);
    hah.clear();
    fill(all(ans),0);
    int n;
    cin >> n;
    vi a(n);
    vin(a);
    rep(i,0,n){
        hah[a[i]] = i;
    }
    ans.resize(n);
    mergesort(a, 0, n - 1);
    rep(i,0,n){
        cout << ans[i] << " ";  
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
bool sortcol(const vector<ll> &v1, const vector<ll> &v2, int col)
{
    return v1[col] < v2[col];
}
ll lcm(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}
