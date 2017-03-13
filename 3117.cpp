#include <cstdio>
#include <cstring>

//video[i][x] = i번 video의 2의 x제곱번째 부모
//
int video[100001][30]; // 2의 30제곱 = 1073741824
int fwatching[100000];
bool gap[30];

int main() {
	memset(video, -1, sizeof(video));

	int n, k, m;
	scanf("%d %d %d", &n, &k, &m);

	for(int i=0; i<n; i++) 
		scanf("%d", &fwatching[i]);

	for(int i=1; i<=k; i++)
		scanf("%d", &video[i][0]);

	//preprocessing
	//video[i][x+1] = video[video[i][x]][x]
	for(int x=0; x<29; x++) {
		for(int i=1; i<=k; i++) {
			if(video[i][x]==-1) continue;
			video[i][x+1]=video[video[i][x]][x];
		}
	}

	int cnt;
	for(cnt=0, m-=1; m; m/=2) {
		gap[cnt++]=m%2;
	}

	for(int i=0; i<n; i++) {
		int ans=fwatching[i];
		for(int j=0; j<cnt; j++) {
			if(gap[j]) 
				ans=video[ans][j];
		}
		printf("%d ", ans);
	}

	return 0;
}
