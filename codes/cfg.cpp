// #include<bits/stdc++.h>
// using namespace std;
// #define fi first
// #define se second
// #define ek long long 
// #define dow pair<ek,ek>
// #define teen pair<ek,dow> 
// #define pb push_back
// #define mp make_pair
// const double pi=3.14159265358979323846;
// ek yes=998244353;
 
// long long gcd(long long a,long long b)
// { long long temp;  
//   if(a<b)
//   {temp=b;
//     b=a;
//     a=temp;
//   }
//   if(a%b==0)
//   {return b;}
//    return gcd(b,a%b);
// }
// ek modu(ek a,ek b)
// {
//     if(a<0)
//     {a=-1*a;
//     return (b-a%b)%b;
//     }
//     else
//     {return a%b;}
 
// }
// long long lcm(long long a,long long b,long long c,long long d)
// {
//   long long temp;  
//   if(a<b)
//   {temp=b;
//     b=a;
//     a=temp;
//   }
 
// if(a%b==0)
//   {return (c*d)/b;}
   
//    return lcm(b,a%b,c,d);
 
// }
// ek powers(ek a,ek b,ek c)
// {
//    ek ans=1;
//    while(b>0)
//    {
//        if(b%2==1)
//          {ans=((ans%c)*(a%c))%c;}
//          b=b/2;
//         a=((a%c)*(a%c))%c;
 
//    }
// return ans;
 
// }
 
// ek modi=1e9+7;
// ek vis[200005]={0};
// vector<ek> adj1[200005];
// vector<ek> adj2[200005];
// vector<ek> adj3[200005];
// ek sze[200005];
// ek vis1[200005];
// ek vis2[200005];
// ek vis3[200005];
// ek vis4[200005];
// vector<ek>ke;
// ek par[200005]={0};
// ek calc[200005]={0};
// stack<ek>s;
// ek answ[200005]={0};
// ek dp[200005]={0};
// vector<ek>value1(200005,0);
// vector<ek>value2(200005,0);
// vector<ek>answe;
// vector<ek>vert1(200005,0);
// vector<ek>vert2(200005,0);
 
// void dfs(ek a)
// { 
 
//     while(adj1[a].size())
//     {
//         ek b=adj1[a].back();
//         adj1[a].pop_back();
//         if(vis[b])
//         {
//             continue;
//         }
//         vis[b]=1;
//         dfs(vert2[b]);
//         answe.pb(vert1[b]);
 
 
 
 
 
//     }
 
// }
 
// void dfs2(ek a)
// {   vis3[a]=1;
//     for(int i=0;i<adj2[a].size();i++){
//         if(vis3[adj2[a][i]]==0)
//            {dfs2(adj2[a][i]);}
 
 
//     }
// }
// void dfs3(ek a){
//     vis4[a]=1;
 
//     for(int i=0;i<adj3[a].size();i++){
//         if(vis4[adj3[a][i]]==0)
//           {dfs3(adj3[a][i]);}
 
//     }
// }
 
// ek ver[20][20]={0}; 
// ek dpi[1000000][20]; 
// int main()
// {
//  ek i,j,k,z,t,f,ans,ma,mi,a,b,c,d,y,mid,m,g,x,h,x1,y1,x2,y2,o,p,l,r,q,n;
//      cin>>n>>m;
//      for(i=0;i<m;i++){
//          cin>>a>>b;
//          ver[a-1][b-1]+=1;
//      }
//     dpi[1][0]=1;
//    for(i=2;i<1<<n;i++){
//        if(i>>(n-1)&1&&i!=(1<<n)-1)
//        {continue;}
//        for(j=0;j<n;j++){
//            if(i>>j&1){
//                a=i^1<<j;
//                for(k=0;k<n;k++){
//                    if(a>>k&1&&ver[k][j]){
//                        dpi[i][j]=(dpi[i][j]+ver[k][j]*dpi[a][k])%modi;

//                    }
//                }
//            }
//        }
//    }

//  cout<<dpi[(1<<n)-1][n-1]<<endl;
             
 
 
          
// return 0;
// }

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

int n, m;
ll adj[501][501], oadj[501][501];

ll flow[501];
bool V[501];
int pa[501];
using pii = pair<int, int>;
vector<pii> ans;

bool reachable() {
	memset(V, false, sizeof(V));
	queue<int> Q; Q.push(1); V[1]=1;
	while(!Q.empty()) {
		int i=Q.front(); Q.pop();
		FOR(j,1,n) if (adj[i][j] && !V[j])
			V[j]=1, pa[j]=i, Q.push(j);
	}
	return V[n];
}

int main() {
	cin >> n >> m;
	FOR(i,1,n) FOR(j,1,n) adj[i][j]=oadj[i][j]=0;
	F0R(i,m) {
		ll a,b; cin >> a >> b;
		adj[a][b]++, adj[b][a]++;
		oadj[a][b]++, oadj[b][a]++;
	}
	int v, u;
	while(reachable()) {
		ll flow = 1e18;
		for (v=n; v!=1; v=pa[v]) {
			u = pa[v];
			flow = min(flow, adj[u][v]);
		}
		for (v=n; v!=1; v=pa[v]) {
			u = pa[v];
			adj[u][v] -= flow;
			adj[v][u] += flow;
		}
	}
	reachable();
	FOR(i,1,n) FOR(j,1,n)
	if (V[i] && !V[j] && oadj[i][j]) ans.pb({i,j});
	cout << ans.size() << '\n';
	trav(a, ans) cout << a.f << " " << a.s << '\n';
}