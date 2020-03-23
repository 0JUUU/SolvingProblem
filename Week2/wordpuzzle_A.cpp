#include <iostream>
#include <string>
using namespace std;

int  main() {
	std::ios::sync_with_stdio(false);

	int T;
	string first;
	string second;

	cin >> T;
	if (1 <= T && T <= 100000) {
		for (int i = 0; i < T; i++) {
			cin >> first;
			cin >> second;
			int count[80] = { 0 };
			int s_length = 0;
			int first_size = first.length();
			int second_size = second.length();
			int answer = -1;

			for (int i = 0; i < first_size; i++) {
				for (int j = 0; j < second_size; j++) {
					if (first[i] == second[j]) {
						s_length++;
					}
				}
				if (s_length == second_size) answer = 1;
				else answer = 0;
			}
			for (int i = 0; i < first_size; i++) {
				for (int j = i + 1; j < first_size; j++) {
					if (first[i] == first[j]) answer = 0;
				}
			}

			if (answer == 1) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}