#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool isNecessary(int);

int a[5001];
bool d[5001][5000]={false, };
int n, k;

int main() {
	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; i++) 
		scanf("%d", &a[i]);		
	
	sort(a+1, a+n+1); //**
	
	int lo=1, hi=n;
	while(lo<=hi) {
		int mid=(lo+hi)/2;
		if(isNecessary(mid)) hi=mid-1;
		else lo=mid+1;
	}

	printf("%d\n", lo-1);
	return 0;
}

bool isNecessary(int idx) {
	int tmp=a[idx];
	a[idx]=0;
	memset(d, false, sizeof(d));
	d[0][0]=true;
	for(int	i=1; i<=n; i++) {
		for(int j=0; j<k; j++) {
			bool res=d[i-1][j];
			if(j-a[i]>=0) 
				res=res||d[i-1][j-a[i]];

			d[i][j]=res;
			if(k-tmp<=j && j<k && d[i][j]) {
				a[idx]=tmp;
				return true;
			}
		}
	}

	a[idx]=tmp;
	return false;
}
