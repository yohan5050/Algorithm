#define N 4

typedef struct {
	int strike;
	int ball;
} Result;

// API
extern Result query(int guess[]);

// input: 테스트 배열, output: 스트라이크의 개수
// 이 함수는 스트라이크와 볼이 나오는 테스트 배열을
// 스트라이크만 나오도록 만들어준다.
int onlyStrikes(int t_arr[]) {
	for(int i = 0; i < 4; i++) {
		int candidate[4];
		candidate[0] = t_arr[i];
		for(int j = 0; j < 4; j++) {
			if(j == i) continue;
			candidate[1]= t_arr[j];
			for(int k = 0; k < 4; k++) {
				if(k == i || k == j) continue;
				candidate[2] = t_arr[k];
				for(int l = 0; l < 4; l++) {
					if(l == i || l == j || l == k) continue;
					candidate[3] = t_arr[l];
					Result cRes = query(candidate);
					if(cRes.ball == 0) {
						for(int x = 0; x < 4; x++) t_arr[x] = candidate[x];
						return cRes.strike;
					}
				}
			}
		}
	}
}

void swapIdx2(int t_arr[], int idx1, int idx2) {
	int tmp = t_arr[idx1];
	t_arr[idx1] = t_arr[idx2];
	t_arr[idx2] = tmp;
}

void swapIdx3(int t_arr[], int exc) {
	int sn[3], cnt = 0;
	for(int i = 0; i < 4; i++) {
		if(i == exc) continue;
		sn[cnt++] = i;
	}

	int tmp = t_arr[sn[0]];	
	t_arr[sn[0]] = t_arr[sn[1]];
	t_arr[sn[1]] = t_arr[sn[2]];
	t_arr[sn[2]] = tmp;
}

void swapIdx3Rev(int t_arr[], int exc) {
	int sn[3], cnt = 0;
	for(int i = 3; i >= 0; i--) {
		if(i == exc) continue;
		sn[cnt++] = i;
	}

	int tmp = t_arr[sn[0]];	
	t_arr[sn[0]] = t_arr[sn[1]];
	t_arr[sn[1]] = t_arr[sn[2]];
	t_arr[sn[2]] = tmp;
}

void doUserImplementation(int guess[]) {
	// Implement a user's implementation function
	//
	// The array of guess[] is a return array that
	// is your guess for what digits[] would be.
	
	bool used[10] = {false, };

	int test[3][4] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 0, 1}
	};

	for(int t = 0; t < 3; t++) {
		Result tRes = query(test[t]);
		if(tRes.strike == 4) {
			for(int i = 0; i < 4; i++) guess[i] = test[t][i];
			return;
		}
		if(tRes.strike + tRes.ball > 0) {
			int sNum = onlyStrikes(test[t]);
			if(sNum == 1) {
				for(int i = 0; i < 4; i++) {
					swapIdx3(test[t], i);
					Result tRes2 = query(test[t]);
					if(tRes2.strike == 1) {
						used[test[t][i]] = true;
					}
					swapIdx3Rev(test[t], i);
				}
			}
			else if(sNum == 2) {
				for(int i = 0; i < 4; i++) {
					for(int j = i + 1; j < 4; j++) {
						swapIdx2(test[t], i, j);	
						Result tRes2 = query(test[t]);
						if(tRes2.strike == 0) {
							used[test[t][i]] = used[test[t][j]] = true;
						}
						swapIdx2(test[t], i, j);
					}
				}
			}
			else if(sNum == 3) { //sNum == 3
				for(int i = 0; i < 4; i++) {
					swapIdx3(test[t], i);
					Result tRes2 = query(test[t]);
					if(tRes2.strike == 0) {
						for(int j = 0; j < 4; j++) {
							if(j == i) continue;
							used[test[t][j]] = true;
						}
					}
					swapIdx3Rev(test[t], i);
				}
			}
			else { //sNum == 4
				for(int i = 0; i < 4; i++) guess[i] = test[t][i];
				return;	
			}
		}
	}

	int usedNum[4], cnt = 0;
	for(int i = 0; i < 10; i++) {
		if(used[i]) usedNum[cnt++] = i; 
	}

	for(int i = 0; i < 4; i++) {
		int candidate[4];
		candidate[0] = usedNum[i];
		for(int j = 0; j < 4; j++) {
			if(j == i) continue;
			candidate[1]= usedNum[j];
			for(int k = 0; k < 4; k++) {
				if(k == i || k == j) continue;
				candidate[2] = usedNum[k];
				for(int l = 0; l < 4; l++) {
					if(l == i || l == j || l == k) continue;
					candidate[3] = usedNum[l];
					Result cRes = query(candidate);
					if(cRes.strike == 4) {
						for(int x = 0; x < 4; x++) guess[x] = candidate[x];
						return;
					}
				}
			}
		}
	}
}
