#include <iostream>
#include <algorithm>
using namespace std;

int T, N, x_min, x_max, y_min, y_max, x, y, result;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N;
		x_min = 10001, y_min = 10001;
		x_max = -10001, y_max = -10001;
		for (int i = 1; i <= N; i++) {
			cin >> x >> y;
			x_min = min(x_min, x);
			x_max = max(x_max, x);
			y_min = min(y_min, y);
			y_max = max(y_max, y);
		}
		if (N == 1) cout << "0\n";
		else {
			result = (x_max - x_min) * (y_max - y_min);
			cout << result << "\n";
		}
	}
	return 0;
}