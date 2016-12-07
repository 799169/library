/*
http://hos.ac/slides/20110504_graph.pdf

多重辺は対応してない

関節点
ord[v]: dfs森でのid
low[v]: lowlink, dfs木で子にいく + 一回だけ後退辺で上に上がれる ときにたどりつけるord のmin
vが関節点⇔
 vがdfs木のroot かつ 次数が2以上 or
 vがdfs木のrootでない かつ ある子uが存在し, ord[v]<=low[u]
ord[v]=low[u]でも関節点(自分にサイクルが戻ってきたとしても上にはいけないのでまだ関節点なまま) なことに注意

二重(頂点)連結成分
橋に対する二重辺連結成分のように、二重連結成分が定義される。
辺集合Eが二重連結⇔Eで誘導されるグラフが関節点を持たない


*/
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}

typedef pair<int,int> P;
const int MV=;
vector<int> G[MV];
int ord[MV],low[MV];
int I;
vector<int> arts;

stack<P> st;
typedef vector<P> VP;
vector<VP> biedges;

void dfs(int v,int p){
	ord[v]=++I;
	low[v]=ord[v];
	int c=0;
	bool isart=0;
	for(int u:G[v]) if(u!=p){
		if(ord[u]<ord[v]) st.push(P(v,u));
		if(ord[u]) chmin(low[v],ord[u]);	//back edge
		else{
			dfs(u,v);
			c++;
			chmin(low[v],low[u]);
			if(low[u]>=ord[v]) isart=1;

			if(low[u]>=ord[v]){
				vector<P> vp;
				while(true){
					P p=st.top();st.pop();
					vp.pb(p);
					if(p.fs==v && p.sc==u) break;
				}
				biedges.pb(vp);
			}
		}
	}
	if(p<0) isart=(c>1);
	if(isart) arts.pb(v);
}
void arti(int N){
	rep(i,N) if(ord[i]==0){
		while(!st.empty()) st.pop();
		dfs(i,-1);
	}
}
int main(){
	int N,M;
	cin>>N>>M;
	rep(i,M){
		int a,b;
		cin>>a>>b;
		G[a].pb(b);G[b].pb(a);
	}
	arti(N);
//	sort(all(arts));
//	for(int a:arts) cout<<a<<endl;
	int K=biedges.size();
//	show(K);
//	rep(i,K) show(biedges[i]);
}
