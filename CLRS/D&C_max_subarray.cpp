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
int INF = 1e9 + 7;
long long INFF = 1e18L + 7;
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
        //cout << "\n";
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
tuple<int,int,int> maxcrosssum(int left,int mid, int right, vi &a){
    
    int i,j,leftmax= 0 ,rightmax = 0,leftbest = -INF,rightbest = -INF;
    for(int k = mid;k>=left;k--){
        leftmax += a[k];
        if(leftmax > leftbest){
            leftbest = leftmax;
            i = k;
        }
    }
    rep(k,mid+1,right){
        rightmax += a[k];
        if(rightmax > rightbest){
            rightbest = rightmax;
            j = k;
        }
    }
    int sum = rightbest + leftbest;
    return tie(i,j,sum);
}
tuple<int, int, int> maxsum(int left, int right, vi &a)
{
    if(left == right){
        return tie(left,right,a[left]);
    }
    int lefti = 0, leftj = 0, leftsum = -INF;
    int righti = 0, rightj = 0, rightsum = -INF;
    int crossi = 0, crossj = 0, crosssum = -INF;

    int mid = (left + right) / 2;
    tie(lefti, leftj, leftsum) = maxsum(left, mid, a);
    tie(righti, rightj, rightsum) = maxsum(mid + 1, right, a);
    tie(crossi, crossj, crosssum) = maxcrosssum(left, mid, right, a);
    if (leftsum > rightsum && leftsum > crosssum)
        return tie(lefti, leftj, leftsum);
    else if (rightsum > leftsum && rightsum > crosssum)
        return tie(righti, rightj, rightsum);

    return tie(crossi, crossj, crosssum);
}
void solve()
{
    cout << setprecision(12);
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    int i, j, sum = 0;
    tie(i, j, sum) = maxsum(0, n, a);
    cout << i+1 << " " << j+1 << " " << sum;
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
