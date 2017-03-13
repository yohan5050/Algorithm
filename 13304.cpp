#include <cstdio>

int main() {
	int n, k;
	int stu12=0, stu34w=0, stu34m=0, stu56w=0, stu56m=0;

	scanf("%d %d", &n, &k);
	while(n--) {
		int s, y;
		scanf("%d %d", &s, &y);
		if(y==1 || y==2) stu12++;
		else if(y==3 || y==4) {
			if(s==0) stu34w++;
			else stu34m++;
		}
		else {
			if(s==0) stu56w++;
			else stu56m++;
		}
	}

	int ans=0;
	ans+=(stu12+k-1)/k;
	ans+=(stu34w+k-1)/k+(stu34m+k-1)/k;
	ans+=(stu56w+k-1)/k+(stu56m+k-1)/k;

	printf("%d\n", ans);
	return 0;
}
