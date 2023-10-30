#include <bits/stdc++.h>

using namespace std;

template<typename T>
using vt = vector<T>;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
using vi = vt<int>;
using vii = vt<ii>;
using vll = vt<ll>;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
ll fgcd(ll a, ll b) { while(b) swap(b, a %= b); return a; }
ll fpow(ll a, ll b, const ll c) { ll ans = 1; a %= c; for(; b; b >>= 1, a = a * a % c) if(b & 1) ans = ans * a % c; return ans; }
ll fpow(ll a, ll b) { ll ans = 1; for(; b; b >>= 1, a *= a) if(b & 1) ans *= a; return ans; }
int flog(int x) { return 31 - __builtin_clz(x); }
int flog(ll x) {return 63 - __builtin_clzll(x);}
template<typename T> using minpq = priority_queue<T, vt<T>,greater<T>>;
#define debug(x) { cout << #x << " = "; cout << (x) << endl; }
template<class U, class V> std::ostream& operator << (std::ostream& out, const std::pair<U, V>& p) {return out << '(' << p.first << ", " << p.second << ')';}   //cout pair type
void setIO(string name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    if (!name.size()) return;

    #ifndef ONLINE_JUDGE
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    #endif
}

int a[505][505], vis[505][505];
int ans1[505][505];
int n;

bool check_bound(int i,int j){
    return (i>=1 && i<=n && j>=1 && j<=n);
}

void solve1(int g){
    for (int i=1;i<=n;i++)  for (int j=1;j<=n;j++)  {cin>>a[i][j];   ans1[i][j]= INT_MAX;}
    for (int i=1;i<=n;i++)  for (int j=1;j<=n;j++)  if (a[i][j] < g)    a[i][j] = 1;    else a[i][j] = 0;
    minpq<pair<int,ii>> pq;
    ans1[1][1] = a[1][1];
    pq.push({ans1[1][1],{1,1}});
    while (pq.size()){
        iii u = pq.top();
        ii uu = u.second;
        pq.pop();
        for (int i = 0; i< 4; i++){
            int xx = uu.first + d4i[i];
            int yy = uu.second + d4j[i];
            if (!check_bound(xx,yy))    continue;
            if (ans1[xx][yy] > ans1[uu.first][uu.second] + a[xx][yy]){
                ans1[xx][yy] =  ans1[uu.first][uu.second] + a[xx][yy];
                pq.push({ans1[xx][yy],{xx,yy}});
            }
        }
    }
    //for (int i=1;i<=n;i++)  {for (int j=1;j<=n;j++)  cout<<ans1[i][j]<<' ';    cout<<'\n';}
    cout<<ans1[n][n];
}

bool check(int g){
    if (g > a[1][1])    return 0;
    memset(vis , 0 ,sizeof vis);
    vis[1][1] = 1;
    queue<ii> q;
    q.push({1,1});
    while (q.size()){
        ii uu = q.front();
        q.pop();
        int x = uu.first;
        int y = uu.second;
        for (int i=0;i<4;i++){
            int xx = x + d4i[i];
            int yy = y + d4j[i];
            if (!check_bound(xx,yy) ) continue;
            if (a[xx][yy] < g)  continue;
            if (!vis[xx][yy])  {vis[xx][yy] = 1;    q.push({xx,yy});}
        }
    }
    return vis[n][n] == 1;
}

void solve2(){
    int l = 1, r = 5000;
    int ans = 0;
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) cin>>a[i][j];
//    for (int i=1;i<=n;i++)  {for (int j=1;j<=n;j++)  cout<<a[i][j]<<' ';    cout<<'\n';}
    while (l<=r){
        int mid = (l+r) /2 ;
        //debug(mid);
        if (check(mid)) {l = mid +1;    ans = mid;}
        else r = mid - 1;
    }
    cout<<ans;
}

int main()
{
    setIO("");
    int typ;    cin>>typ;
    cin>>n;
    if (typ == 1){
        int g;  cin>>g;
        solve1(g);
    }
    else solve2();
    // OUR CODE LIES HERE

    return 0;
}

//   _                          _
//  | |__   ___ _ __ ___  _   _| |_
//  | '_ \ / __| '_ ` _ \| | | | __|
//  | | | | (__| | | | | | |_| | |_
//  |_| |_|\___|_| |_| |_|\__,_|\__|

