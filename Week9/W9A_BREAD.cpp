#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int T, N, M, arr[10010];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		memset(arr, 0, sizeof(arr));
		int sum = 0;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		if (sum <= M) {
			cout << sum << endl;
		}
		else {
			int tmp = M / N;
			int remain = N;
			sort(arr, arr + N);
			for (int i = 0; i < N; i++) {
				if (arr[i] <= tmp) {
					M -= arr[i];
				}
				else {
					remain = N - i;
					tmp = M / remain;
					if (arr[i] > tmp) {
						break;
					}
					i--;
				}
			}
			int B = M / remain;
			sum = 0;
			for (int i = 0; i < N; i++) {
				if (B <= arr[i]) {
					arr[i] = B;
				}
				sum += arr[i];
			}
			cout << sum << endl;
		}
	}
	cout << "\n";
	return 0;
}