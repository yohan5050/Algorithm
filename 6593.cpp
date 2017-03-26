#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;

char building[30][30][31];
int dl[]={0, 0, 0, 0, -1, 1};
int dr[]={-1, 1, 0, 0, 0, 0};
int dc[]={0, 0, -1, 1, 0, 0};
int dist[30][30][31];

int main() {
	int l, r, c;
	while(true) {
		scanf("%d %d %d", &l, &r, &c);
		if(l==0) break;

		for(int i=0; i<l; i++) {
			for(int j=0; j<r; j++) {
				scanf("%s", building[i][j]);				
				//printf("tests : %s\n", building[i][j]);
			}
			scanf("%*c");
		}

		int sl, sr, sc, el, er, ec;
		for(int i=0; i<l; i++) {
			for(int j=0; j<r; j++) {
				for(int k=0; k<c; k++) {
					if(building[i][j][k]=='S') {
						sl=i; sr=j; sc=k;
					}
					if(building[i][j][k]=='E') {
						el=i; er=j; ec=k;
					}
				}
			}
		}

		memset(dist, -1, sizeof(dist));					
		dist[sl][sr][sc]=0;
		queue<pair<int, pair<int, int> > > q;
		q.push(make_pair(sl, make_pair(sr, sc)));
		while(!q.empty()) {
			int hl=q.front().first;
			int hr=q.front().second.first;
			int hc=q.front().second.second;
			q.pop();
			
			for(int i=0; i<6; i++) {
				int nl=hl+dl[i];
				int nr=hr+dr[i];
				int nc=hc+dc[i];
				if(nl<0 || l<=nl || nr<0 || r<=nr || nc<0 || c<=nc) continue;

				if(dist[nl][nr][nc]==-1 && building[nl][nr][nc]!='#') {
					dist[nl][nr][nc]=dist[hl][hr][hc]+1;
					q.push(make_pair(nl, make_pair(nr, nc)));
				}
			}
		}

		//printf("test E : %d %d %d\n", el, er, ec);
		int ans=dist[el][er][ec];
		if(ans==-1)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n", ans);
	}
	return 0;
}
