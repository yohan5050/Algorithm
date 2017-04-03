//BOJ 10835
//1. L만 버리거나(항상 가능, 점수 없음)
//2. L, R 둘다 같이 버리거나(항상 가능, 점수 없음)
//R만 버릴 수 있음(L>R인 경우마, 점수는 R점)
//최대 점수를 획득하기 위해선...
//L>R인 경우는 무조건 R만 버리는 것이 이득.
//밑에 어떤 카드가 있는지 모르니.. 경우에 따라 왼쪽만 버리거나
//둘 다 버리는 경우도 필요함.
//결국 다 해봐야 할듯... dp?!
//d[l][r] = 왼쪽의 l번째 카드, 오른쪽의 r번째 카드를 볼 때, 얻을 수 있는 
//최대 점수.
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int solve(int, int);

int d[2000][2000], l[2000], r[2000];
int n;

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) 
		scanf("%d", &l[i]);
	for(int i=0; i<n; i++)
		scanf("%d", &r[i]);

	memset(d, -1, sizeof(d));
	printf("%d\n", solve(0, 0));
	return 0;
}

int solve(int lIdx, int rIdx) {
	if(lIdx==n || rIdx==n) return 0;
	int& ret=d[lIdx][rIdx];
	if(ret!=-1) return ret;

	if(l[lIdx]>r[rIdx]) 
		ret=solve(lIdx, rIdx+1)+r[rIdx];
	else 
		ret=max(solve(lIdx+1, rIdx), solve(lIdx+1, rIdx+1));

	return ret;
}
