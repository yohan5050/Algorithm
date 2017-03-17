#include <cstdio>

char str[333335];

int main() {
	scanf("%s", str);
	if(str[0]=='0') {
		printf("0");
		return 0;
	}

	bool isFirst=true;
	for(int i=0; str[i]; i++) {
		int num=str[i]-'0', div;
		if(i==0) {
			for(div=4; div!=0; num%=div, div/=2) {
				if(isFirst) {
					if(num/div!=0) {
						printf("%d", num/div);
						isFirst=false;
					}
				}
				else
					printf("%d", num/div);
			}
			continue;
		}

		for(div=4; div!=0; num%=div, div/=2) {
			printf("%d", num/div);
		}
	}
	return 0;
}
