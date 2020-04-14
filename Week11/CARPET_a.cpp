#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

int m, n, k, arr[501][501];

int rect(int a[], int col) {
	int l = 0, r = 0;
	for (int i = col - 1; i >= 0; i--) {
		if (a[i] < a[col])
			break;
		l++;
	}
	for (int i = col + 1; i < k; i++) {
		if (a[i] < a[col])
			break;
		r++;
	}

	return (l + r + 1) * a[col];
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m;  
	string input;

	while (m--) {
		memset(arr, 0, sizeof(arr));
		cin >> n >> k;
		int str_sum = 0;
		int tmp = -1;
		int input_sum = 0;
		for (int i = 0; i < n; i++) {
			str_sum = 0;
			input_sum = 0;
			while (str_sum != k) {
				cin >> input;
				if (input == "e" || input == "f") {
					if (input == "e") {
						for (int j = input_sum; j < input_sum + tmp; j++) {
							arr[i][j] = 0;
						}
					}
					else {
						for (int j = input_sum; j < input_sum + tmp; j++) {
							arr[i][j] = 1;
						}
					}
					input_sum = str_sum;
				}
				else {
					tmp = atoi(input.c_str());
					str_sum += atoi(input.c_str());
				}
			}
			cin >> input;
			if (input == "e" || input == "f") {
				if (input == "e") {
					for (int j = input_sum; j < input_sum + tmp; j++) {
						arr[i][j] = 0;
					}
				}
				else {
					for (int j = input_sum; j < input_sum + tmp; j++) {
						arr[i][j] = 1;
					}
				}
			}
		}

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < k; j++) {
				if (arr[i][j] == 1) {
					arr[i][j] += arr[i - 1][j];
				}
			}
		}

		int result = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				result = max(result, rect(arr[i], j));
			}
		}

		cout << result << '\n';

	}
	return 0;
}