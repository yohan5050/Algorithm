#include <cstdio>

void Union(int, int);
int Find(int);

struct Query {
	int x;
	int b, c, d;
};

Query qys[400000]; //** 200000 -> runtime error
bool ans[200000];
int par[200001], p[200001];

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	
	for(int i=2; i<=n; i++) 
		scanf("%d", &par[i]);	

	for(int i=0; i<n-1+q; i++) {
		scanf("%d", &qys[i].x);
		if(qys[i].x==0) 
			scanf("%d", &qys[i].b);
		else
			scanf("%d %d", &qys[i].c, &qys[i].d);
	}

	for(int i=1; i<=n; i++) p[i]=i;

	int cnt=0;
	for(int i=n-2+q; i>=0; i--) {
		if(qys[i].x==0) 
			Union(qys[i].b, par[qys[i].b]);
		else {
			if(Find(qys[i].c)==Find(qys[i].d))
				ans[cnt++]=true;
			else
				ans[cnt++]=false;
		}
	}

	for(int i=cnt-1; i>=0; i--) 
		printf("%s\n", ans[i] ? "YES" : "NO");

	return 0;
}

void Union(int x, int y) {
	x=Find(x);
	y=Find(y);
	p[x]=y;
}

int Find(int x) {
	if(p[x]==x) return p[x];
	return p[x]=Find(p[x]);
}
