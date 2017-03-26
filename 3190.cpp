#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

bool board[100][100]; 
bool apple[100][100]; 
int dr[]={-1, 0, 1, 0};
int dc[]={0, 1, 0, -1};
int dir=1; //╩С, ©Л, го, аб : 0, 1, 2, 3

int main() {
	int n, k, l;
	scanf("%d %d", &n, &k);
	while(k--) {
		int r, c;
		scanf("%d %d", &r, &c);
		apple[r-1][c-1]=true;
	}

	scanf("%d", &l);
	int sr=0, sc=0, ans=0;
	bool isFinished=false;	
	queue<pair<int, int> > q;
	q.push(make_pair(sr, sc));
	while(l--) {
		int x;
		char c;
		scanf("%d %c", &x, &c);
		x-=ans;
		for(int i=0; i<x; i++) {
			ans++;
			sr+=dr[dir];
			sc+=dc[dir];
			//check.
			if(sr<0 || n<=sr || sc<0 || n<=sc) { //range check
				isFinished=true;
				break;
			}
			//check whether itself is already in the position.
			if(board[sr][sc]) {
				isFinished=true;
				break;
			}
			
			board[sr][sc]=true;
			q.push(make_pair(sr, sc));
			if(apple[sr][sc]) {
				apple[sr][sc]=false;
			}
			else {
				int er=q.front().first;
				int ec=q.front().second;
				q.pop();
				board[er][ec]=false;
			}
		}

		if(isFinished) break;

		//change direction.
		if(c=='L') dir=(dir-1+4)%4;
		else dir=(dir+1)%4;
	}
	
	if(isFinished) printf("%d\n", ans);
	else {
		while(true) {
			sr+=dr[dir]; sc+=dc[dir];
			q.push(make_pair(sr, sc));
			ans++;	

			if(sr<0 || n<=sr || sc<0 || n<=sc) break;
			if(board[sr][sc]) break;

			board[sr][sc]=true;
			q.push(make_pair(sr, sc));
			if(apple[sr][sc]) {
				apple[sr][sc]=false;
			}
			else {
				int er=q.front().first;
				int ec=q.front().second;
				q.pop();
				board[er][ec]=false;
			}
		} 
		printf("%d\n", ans);
	}

	return 0;
}
