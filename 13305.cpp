//KOI 풀이 보고 풀었음
//refer to a KOI solution
//https://www.digitalculture.or.kr/koi/showOlymPiadDissentDetail.do
//
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long llint;

int dist[100000];
int price[100000];

int main() {
	int n;
	scanf("%d", &n);

	for(int i=0; i<n-1; i++) 
		scanf("%d", &dist[i]);

	for(int i=0; i<n; i++)
		scanf("%d", &price[i]);

	int mini=2e9;
	llint ans=0;
	for(int i=0; i<n-1; i++) {
		mini=min(mini, price[i]);
		ans+=(llint)mini*dist[i];
	}

	printf("%lld\n", ans);
	return 0;
}
