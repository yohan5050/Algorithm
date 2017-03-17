//돌아가는 것보다 직선으로 바로 가는 것이 더 낫다.
//그러니까 k번의 급유를 언제할지는 신경쓰지 않아도 되고 bfs사용 해야됨!
//KOI 풀이 및 코드 참조! // refer to a KOI solution.

#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

int sq(int);
bool bfs(double);

//간선이 v*v개이므로 굳이 인접리스트로 할 필요 없음.
double fuel[1002][1002]; //dist[a][b] a에서 b까지 가는데 필요한 연료량.
int px[1002], py[1002];
int n, k;

int main() {
	scanf("%d %d", &n, &k);
	
	px[0]=py[0]=0;
	px[n+1]=py[n+1]=10000;
	for(int i=1; i<=n; i++)
		scanf("%d %d", &px[i], &py[i]);

	//가능한 모든 조합
	for(int i=0; i<=n; i++) 
		for(int j=1; j<=n+1; j++) 
			fuel[i][j]=fuel[j][i]=sqrt((double)sq(px[i]-px[j])+sq(py[i]-py[j]))/10.0;

	int lo=0, hi=fuel[0][n+1];
	while(lo<=hi) {
		//printf("test : %d %d\n", lo, hi); -> 이거 주석처리 안했었네...
		int mid=(lo+hi)/2;
		if(bfs((double)mid)) hi=mid-1;
		else lo=mid+1;
	}

	printf("%d\n", lo);
	return 0;
}

bool bfs(double limit) {
	queue<int> q;
	int landing[1003]={0, }; //landing[X]-1 : X비행장까지의 급유 횟수를 나타냄,  그리고 X비행장을 방문했는지 안 했는지도 나타냄.

	landing[0]=1;
	q.push(0);
	while(!q.empty()) {
		int here=q.front(); q.pop();
		for(int there=0; there<n+2; there++) {
			if(landing[there]==0 && fuel[here][there]<=limit) {
				//bfs이므로 landing[here]값이 작은 값부터 보게돼있다.
				if(there==n+1 && landing[here]-1<=k)
					return true;

				landing[there]=landing[here]+1;
				q.push(there);
			}
		}
	}
	return false;
}

int sq(int x) {
	return x*x;
}
