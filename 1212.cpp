#include <cstdio>

char str[333335];
char ans[1000006];

int main() {
	scanf("%s", str);
	if(str[0]=='0') {
		printf("0");
		return 0;
	}

	int idx=0;
	bool isFirst=true;
	for(int i=0; str[i]; i++) {
		int num=str[i]-'0', div;
		if(i==0) {
			for(div=4; div!=0; num%=div, div/=2) {
				if(isFirst) {
					if(num/div!=0) {
						ans[idx++]=num/div+'0';
						isFirst=false;
					}
				}
				else
					ans[idx++]=num/div+'0';
			}
			continue;
		}

		for(div=4; div!=0; num%=div, div/=2) {
			ans[idx++]=num/div+'0';
		}
	}
	ans[idx]='\0';
	printf("%s", ans);
	return 0;
}
