#include<bits/stdc++.h>

using namespace std;

int n,m,sl,b[1000005],d[1000005],bac[1000005],vi[1000005];
char a[1000005];
void dfs(int i)
{
    sl++;

    vi[i]=1;
    if (!vi[d[i]]) dfs(d[i]);
}
int main(){
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int tc;
    cin>>tc;
    while (tc--){
        int kt=0,s=0;
        cin>>n>>m;
        for(int i=1;i<=n*m;++i) cin>>a[i],vi[i]=0,d[i]=0;
        for(int i=1;i<=n*m;++i) cin>>b[i];
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                int x=b[m*(i-1)+j];
                int u=i,v=j;
                if (a[m*(i-1)+j]=='u') u-=x; else
                if (a[m*(i-1)+j]=='d') u+=x; else
                if (a[m*(i-1)+j]=='l') v-=x; else
                if (a[m*(i-1)+j]=='r') v+=x;
                if (u<1||u>n||v<1||v>m) {kt=1; break;}
                bac[m*(u-1)+v]++;
                d[m*(i-1)+j]=m*(u-1)+v;
            }
            if (kt) break;
        }
        if (kt) {cout<<"No\n"; continue;}
        sl=0; int i;
        for(i=1;i<=n*m;++i) if (bac[i]==0) break;
        if (i>n*m) dfs(1); else dfs(i);
        if (sl<n*m) cout<<"No\n"; else cout<<"Yes\n";
    }
}
