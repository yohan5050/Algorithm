#include <cstdio>

int main() {
	char str[101];
	while(scanf("%[^\n]%*c", str)==1) {
		int cnt1=0, cnt2=0, cnt3=0, cnt4=0;
		for(int i=0; str[i]; i++) {
			if('a'<=str[i] && str[i]<='z') cnt1++;
			else if('A'<=str[i] && str[i]<='Z') cnt2++;
			else if('0'<=str[i] && str[i]<='9') cnt3++;
			else cnt4++;
		}
		printf("%d %d %d %d\n", cnt1, cnt2, cnt3, cnt4);
	}
	return 0;
}

