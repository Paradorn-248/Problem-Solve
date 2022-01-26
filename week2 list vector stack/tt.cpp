#include <bits/stdc++.h>
using namespace std;
int color[100005];
int par[100005];
int group[100005];
vector<int> g[100005];

int findPar(int u){
    return par[u] = u == par[u] ? u : findPar(par[u]);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
    int N,M,ans=0,ch=0,run=0;
    cin >> N >> M;

    for(int i=1;i<=M;++i)
        par[i]=i;

    for(int i=1;i<=M;++i){
        int a,b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
        int parA = findPar(a);
        int parB = findPar(b);

        //printf(" be par -- %d %d  color %d %d\n",parA,parB,color[a],color[b]);
        if(color[a])
            swap(a,b);
        if(color[a]){
            if(parA==parB){
                if(color[a]==color[b]){//same par same col
                    ch=1;
                }
            }
            else if(color[a]==color[b]){//not par same col
                ++run;
                color[b] = 3-color[a];
                queue<int> q;
                q.push(b);
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    group[u] = run;
                    for(int i=0;i<g[u].size();++i){
                        color[g[u][i]] = 3-color[u];
                        if(group[g[u][i]]==run)
                            q.push(g[u][i]);
                    }
                }
            }

        }
        else if(color[b]){ //col only b
            color[a]=3-color[b];
        }
        else{//no color
            color[a]=1;
            color[b]=2;
        }
        if(!ch)
            ++ans;
        par[parB]=parA;
        parA = findPar(a);
        parB = findPar(b);
        //printf(" a = %d b = %d af par -- %d %d  color %d %d\n",a,b,parA,parB,color[a],color[b]);
    }

    cout << ans;
}
