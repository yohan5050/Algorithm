//BOJ 10835
//1. L�� �����ų�(�׻� ����, ���� ����)
//2. L, R �Ѵ� ���� �����ų�(�׻� ����, ���� ����)
//R�� ���� �� ����(L>R�� ��츶, ������ R��)
//�ִ� ������ ȹ���ϱ� ���ؼ�...
//L>R�� ���� ������ R�� ������ ���� �̵�.
//�ؿ� � ī�尡 �ִ��� �𸣴�.. ��쿡 ���� ���ʸ� �����ų�
//�� �� ������ ��쵵 �ʿ���.
//�ᱹ �� �غ��� �ҵ�... dp?!
//d[l][r] = ������ l��° ī��, �������� r��° ī�带 �� ��, ���� �� �ִ� 
//�ִ� ����.
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
