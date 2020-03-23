#include <iostream>
#include <string.h>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	int T = 0;
	int p = 0;
	int change = 0;
	int n = 0;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> p;
		change = 10000 - p;
		cin >> n;
		int *sort = new int[n + 1];
		sort[0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> sort[i];
		}
		
		int **num = new int*[n + 1];
		for (int i = 0; i < n + 1; ++i) {
			num[i] = new int[change + 1];					//num[n][change] »ý¼º
			memset(num[i], 10001, sizeof(int)*(change + 1));
		}

//		for (int i = 0; i <= n; i++) num[i][0] = 0;
		for (int i = 1; i <= n; i++) {
			num[0][0] = 0;
			num[i][0] = 0;
			for (int j = 1; j <= change; j++) {
				if (sort[i] > j) {
					num[i][j] = num[i - 1][j];
				}
				else if (num[i - 1][j] > num[i][j - sort[i]] + 1) num[i][j] = num[i][j - sort[i]] + 1;
				else num[i][j] = num[i - 1][j];
			}
		}
		if (num[n][change] >= 10001) cout << "0" << endl;
		else cout << num[n][change] << endl;
		for (int i = 0; i <= n; i++) {
			delete[] num[i];
		}
	}
	cout << endl;

	return 0;
}