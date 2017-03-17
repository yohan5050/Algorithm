#include <cstdio>

int main() {
	int n;
	bool isFirst=true;
	while(scanf("%1d", &n)==1) {
		if(isFirst && n==0) {
			printf("0");
			break;
		}
		
		if(isFirst) {
			for(int div=4; div!=0; n%=div, div/=2) {
				if(isFirst) {
					if(n/div!=0) {
						printf("%d", n/div);
						isFirst=false;
					}
				}
				else
					printf("%d", n/div);
			}
			isFirst=false;
			continue;
		}
		
		for(int div=4; div!=0; n%=div, div/=2) {
			printf("%d", n/div);
		}
	}
	return 0;
}
