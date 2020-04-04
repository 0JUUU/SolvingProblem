#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N; 
		int origin = N;
		int reverse = 0;
		while (N) { 
			int temp = N % 10;
			N = N / 10; 
			reverse = reverse * 10 + temp;
		}
		int sum = origin + reverse;
		int sum_test = sum;
		int sum_check = 0;
		while (sum_test) {
			int temp = sum_test % 10;
			sum_test = sum_test / 10;
			sum_check = sum_check * 10 + temp;
		}
		if (sum_check == sum) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	return 0;
}