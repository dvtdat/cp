#include <bits/stdc++.h>
using namespace std;

const int N=30;
vector<int> adj[N],topo,tmp;
string a[N];
int in[N],vao[N],ra[N],root[N],pos[N];
bool mark[N][N],ok[N],vis[N];
int n,t=0;

void dfs(int u,int s){
    vis[u]=1;
    vao[u]=t++;
    root[u]=s;
    for(int v:adj[u]){
        if(!vis[v])dfs(v,s);
    }
    tmp.push_back(u);
    ra[u]=t;
}

signed main()
{
    freopen("ORDER.INP","r",stdin);
    freopen("ORDER.OUT","w",stdout);

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
        for(char j:a[i])ok[j-'A']=1;
    }

    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            for(int k=0;k<min(a[i].size(),a[j].size());++k){
                if(a[i][k]!=a[j][k]){
                    adj[a[i][k]-'A'].push_back(a[j][k]-'A');
                    mark[a[i][k]-'A'][a[j][k]-'A']=1;
                    in[a[j][k]-'A']++;
                    break;
                }
            }
        }
    }

    for(int i=0;i<26;++i){
        if(ok[i]){
            if(in[i]==0){
                tmp.clear();
                // cout<<i<<endl;
                dfs(i,i);
                reverse(tmp.begin(),tmp.end());
                for(int j:tmp)topo.push_back(j);
            }
        }
    }

    for(int i=0;i<topo.size();++i)pos[topo[i]]=i;
    for(int i=0;i<topo.size();++i){
        for(int j=i+1;j<topo.size();++j){
            if((vao[topo[j]]>ra[topo[i]]||ra[topo[j]]<vao[topo[i]])&&topo[j]<topo[i]&&pos[root[topo[j]]]<pos[topo[i]]){
                swap(pos[topo[i]],pos[topo[j]]);
                swap(topo[i],topo[j]);
            }
        }
    }
    for(int i:topo)cout<<(char)('A'+i);
    cout<<endl;
}
