#include <iostream>
using namespace std;

int T, N;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N;
		int origin = N;
		int reverse = 0;
		while (N) {
			int temp = N % 10;
			N /= 10;
			reverse = reverse * 10 + temp;
		}
		int sum = origin + reverse;
		int sum_origin = sum;
		int sum_reverse = 0;
		while (sum) {
			int sum_temp = sum % 10;
			sum /= 10;
			sum_reverse = sum_reverse * 10 + sum_temp;
		}
		if (sum_origin == sum_reverse) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}