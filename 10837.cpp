#include <cstdio>

int main() {
	int k, c;
	scanf("%d %d", &k, &c);
	while(c--) {
		int m, n;
		scanf("%d %d", &m, &n);
		
		if(m<n) {
			if(n-1>=m+k-(n-1)) printf("0\n");
			else printf("1\n");
		}
		else if(m==n) {
			printf("1\n");
		}
		else { //m>n
			if(m-1>=n+k-(m-2)) printf("0\n");
			else printf("1\n");
		}
	}
	return 0;
}
