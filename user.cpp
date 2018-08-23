#define N 4

typedef struct {
	int strike;
	int ball;
} Result;

// API
extern Result query(int guess[]);

Result baseballGame(int arr1[], int arr2[]) {
	bool check[10] = {false, };
	for(int i = 0; i < 4; i++) check[arr1[i]] = true;

	Result result;
	result.strike = 0;
	result.ball = 0;

	for(int i = 0; i < 4; i++) {
		if(arr1[i] == arr2[i]) result.strike++;
		else if(check[arr2[i]]) result.ball++;
	}

	return result;
}

int c_arr[6000][4];

void doUserImplementation(int guess[]) {
	// Implement a user's implementation function
	//
	// The array of guess[] is a return array that
	// is your guess for what digits[] would be.
	//
	// 중복되지 않는 숫자들로 구성된 4자리 수의 모든 경우(10 * 9 * 8 * 7 = 5040)
	// 에 대해서 차례로 query를 해본다. 
	// 어떤 수a의 query결과가 나오면 q1이라고 하고,
	// a와 나머지 다른 수b와의 야구게임 결과가 q2라고 할 때, q1과 q2가 다르면
	// b는 절대 정답이 될 수 없으므로 제거한다. 
	// 이런 식으로 제거해 나가면 결국 정답이 남게 된다.
	
	int cnt = 0;
	bool candCheck[6000] = {false, };
	// 5040가지의 모든 경우의 수를 구한다.
	int tmp[4];
	for(int i = 0; i < 10; i++) {
		tmp[0] = i;	
		for(int j = 0; j < 10; j++) {
			if(j == i) continue;
			tmp[1] = j;
			for(int k = 0; k < 10; k++) {
				if(k == i || k == j) continue;
				tmp[2] = k;
				for(int l = 0; l < 10; l++) {
					if(l == i || l == j || l == k) continue;
					tmp[3] = l;

					for(int x = 0; x < 4; x++) c_arr[cnt][x] = tmp[x];
					candCheck[cnt++] = true;
				}
			}
		}
	}

	for(int i = 0; i < cnt; i++) {
		if(candCheck[i]) {
			Result qRes = query(c_arr[i]);
			if(qRes.strike == 4) {
				for(int x = 0; x < 4; x++) guess[x] = c_arr[i][x];
				return;
			}

			candCheck[i] = false;
			for(int j = i + 1; j < cnt; j++) {
				if(candCheck[j]) {
					Result cRes = baseballGame(c_arr[i], c_arr[j]);
					if(cRes.strike != qRes.strike || cRes.ball != qRes.ball) {
						candCheck[j] = false;	
					}
				}
			}
		}
	}
}
