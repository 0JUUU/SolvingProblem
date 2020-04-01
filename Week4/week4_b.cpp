#include <cstdio>
#include <queue>

unsigned int T, fruit[8], M, i, j, tmp, sum, order;
unsigned char N;
bool bl;
std::queue<int> Q[256];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%s%d", &N, &M);
		if (N == 'D') fruit[M]++;
		else {
			tmp = 0;
			for (i = 0; i < M; i++) {
				scanf("%d", &N);
				tmp |= 1 << N;
			}
			Q[tmp].push(sum++);
		}
		order = -1;
		for (i = 0; i < 256; i++) {
			if (!Q[i].empty()) {
				bl = true;
				for ( j = 0; j < 8; j++) {
					if ((i&(1 << j)) && !fruit[j]) {
						bl = false;
						break;
					}
				}
				if (bl && (order == -1 || order > Q[i].front())) {
					tmp = i;
					order = Q[i].front();
				}
			}
		}
		if (~order) {
			Q[tmp].pop();
			for (unsigned int i = 0; i < 8; i++) {
				if (tmp & 1 << i) fruit[i]--;
			}
			printf("%d\n", order);
		}
	}
	return 0;
}