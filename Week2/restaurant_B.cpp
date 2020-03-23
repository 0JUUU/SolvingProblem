#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	int T;
	int N;		// ½Ä´ç
	int M;		// ÀÏ

	cin >> T;
		for (int i = 0; i < T; i++) {
			cin >> N;
			cin >> M;

			int result = 800001;
			int price[100][101] = { 0 };
			int price_min[100][101] = { 0 };
			
			for (int i = 0; i < N; i++) {
				for (int j = 1; j <= M; j++) {
					cin >> price[i][j];
				}
			}
			for (int i = 0; i < N; i++) {
				for (int j = 1; j <= M; j++) {
					price_min[i][j] = 800001;
				}
			}
			
			for (int j = 1; j <= M; j++) {
				for (int i = 0; i < N; i++) {
					for (int k = 0; k < N; k++) {
						if (i != k) price_min[i][j] = min(price_min[k][j - 1], price_min[i][j]);
					}
					price_min[i][j] += price[i][j];
				}
			}

			for (int i = 0; i < N; i++) {
				result = min(result, price_min[i][M]);
			}
			cout << result << endl;
		}
	return 0;
}	
