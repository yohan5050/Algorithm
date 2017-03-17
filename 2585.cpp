//���ư��� �ͺ��� �������� �ٷ� ���� ���� �� ����.
//�׷��ϱ� k���� ������ ���������� �Ű澲�� �ʾƵ� �ǰ� bfs��� �ؾߵ�!
//KOI Ǯ�� �� �ڵ� ����! // refer to a KOI solution.

#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

int sq(int);
bool bfs(double);

//������ v*v���̹Ƿ� ���� ��������Ʈ�� �� �ʿ� ����.
double fuel[1002][1002]; //dist[a][b] a���� b���� ���µ� �ʿ��� ���ᷮ.
int px[1002], py[1002];
int n, k;

int main() {
	scanf("%d %d", &n, &k);
	
	px[0]=py[0]=0;
	px[n+1]=py[n+1]=10000;
	for(int i=1; i<=n; i++)
		scanf("%d %d", &px[i], &py[i]);

	//������ ��� ����
	for(int i=0; i<=n; i++) 
		for(int j=1; j<=n+1; j++) 
			fuel[i][j]=fuel[j][i]=sqrt((double)sq(px[i]-px[j])+sq(py[i]-py[j]))/10.0;

	int lo=0, hi=fuel[0][n+1];
	while(lo<=hi) {
		//printf("test : %d %d\n", lo, hi); -> �̰� �ּ�ó�� ���߾���...
		int mid=(lo+hi)/2;
		if(bfs((double)mid)) hi=mid-1;
		else lo=mid+1;
	}

	printf("%d\n", lo);
	return 0;
}

bool bfs(double limit) {
	queue<int> q;
	int landing[1003]={0, }; //landing[X]-1 : X����������� ���� Ƚ���� ��Ÿ��,  �׸��� X�������� �湮�ߴ��� �� �ߴ����� ��Ÿ��.

	landing[0]=1;
	q.push(0);
	while(!q.empty()) {
		int here=q.front(); q.pop();
		for(int there=0; there<n+2; there++) {
			if(landing[there]==0 && fuel[here][there]<=limit) {
				//bfs�̹Ƿ� landing[here]���� ���� ������ ���Ե��ִ�.
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
