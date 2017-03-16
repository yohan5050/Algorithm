#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int sq(int);
bool check(int, double, int, double);

vector<vector<pair<int, double> > > adj(1002);
pair<int, int> point[1002];
bool visited[1002];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	point[0]=make_pair(0, 0);
	point[1]=make_pair(10000, 10000);
	for(int i=2; i<n+2; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		point[i]=make_pair(x, y);
	}

	for(int i=0; i<n+2; i++) {
		for(int j=0; j<n+2; j++) {
			if(i==j) continue;
			double dist=sqrt((double)sq(point[i].first-point[j].first)+sq(point[i].second-point[j].second));
			adj[i].push_back(make_pair(j, dist));
		}
	}

	int lo=0, hi=14143;
	while(lo<=hi) {
		int mid=(lo+hi)/2;
		memset(visited, false, sizeof(visited));
		if(check(0, (double)mid*10, k, (double)mid*10)) hi=mid-1;
		else lo=mid+1;
	}

	printf("%d\n", lo);
	return 0;
}

bool check(int node, double fuel, int k, double tfuel) {
	visited[node]=true;
	if(node==1) return true;

	bool ret=false;
	for(int i=0; i<adj[node].size(); i++) {
		int next=adj[node][i].first;
		double dist=adj[node][i].second;
		if(visited[next]) continue;
				
		if(fuel>=dist) 
			ret=ret||check(next, fuel-dist, k, tfuel);
		else {
			if(tfuel>=dist && k>0) 
				ret=ret||check(next, tfuel, k-1, tfuel);		
		}
	}
	return ret;
}

int sq(int x) {
	return x*x;
}
