#include <iostream>
using namespace std;
int N;
int white_p = 0;
int black_p = 0;

void recursion(int start_i, int start_j, int length, int arr1[][256]) {

	int white_c = 0;
	int black_c = 0;
	if (length == 2) {
		for (int i = start_i; i < (start_i + length); i++) {
			for (int j = start_j; j < (start_j + length); j++) {
				if (arr1[i][j] == 1) black_c++;
				else if (arr1[i][j] == 0) white_c++;
				arr1[i][j] = -1;
			}
		}
		if (white_c == length*length) {
			white_p++;
		}
		else if (black_c == length*length) {
			black_p++;
		}
		else {
			black_p += black_c;
			white_p += white_c;
		}
	}
	else if (length == 1) {

	}
	else {
		for (int i = start_i; i < (start_i + length); i++) {
			for (int j = start_j; j < (start_j + length); j++) {
				if (arr1[i][j] == 0) white_c += 1;
				else if (arr1[i][j] == 1) black_c += 1;
			}
		}
		if (white_c == length*length) {
			for (int i = start_i; i < (start_i + length); i++) {
				for (int j = start_j; j < (start_j + length); j++) {
					arr1[i][j] = -1;
				}
			}
			white_p++;
		}
		else if (black_c == length*length) {
			for (int i = start_i; i < (start_i + length); i++) {
				for (int j = start_j; j < (start_j + length); j++) {
					arr1[i][j] = -1;
				}
			}
			black_p++;
		}
		else {
				recursion(start_i, start_j, (length / 2), arr1);
				recursion(start_i, start_j + (length / 2), (length / 2), arr1);
				recursion(start_i + (length / 2), start_j, (length / 2), arr1);
				recursion(start_i + (length / 2), start_j + (length / 2), (length / 2), arr1);
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T != 0) {
		cin >> N;

		int arr[256][256];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}

		int length = N;
		recursion(0, 0, length, arr);
		cout << white_p << " " << black_p << endl;
		white_p = 0;
		black_p = 0;
		T--;
	}
	return 0;
}