#include <iostream>
#include <string.h>
using namespace std;
int T, N;
struct Pencle {
	int x_coordinate;
	int length;
	int left;
	int right = 1;
};
Pencle P[10010];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		memset(P, 0, sizeof(P));
		cin >> N;
		int result = 0;
		for (int i = 0; i < N; i++) {
			cin >> P[i].x_coordinate >> P[i].length;
			P[i].left = 1;
		}
		for (int i = N - 1; i >= 0; i--) {
			if (i == N - 1) {
				result = P[i].length;
				P[i].left = 0;
			}
			else if (i == N - 2) {
				if (P[i + 1].x_coordinate - P[i].x_coordinate > P[i].length) {
					result += P[i].length;
					P[i].left = 0;
				}
			}
			else {
				if (P[i + 1].left == 1) {
					if (P[i + 1].x_coordinate - P[i].x_coordinate > P[i].length + P[i + 1].length) {
						result += P[i + 1].length;
						result += P[i].length;
						P[i].left = 0;
					}
					else if (P[i + 1].x_coordinate - P[i].x_coordinate > P[i].length || P[i + 1].x_coordinate - P[i].x_coordinate > P[i + 1].length) {
						int tmp1 = 0, tmp2 = 0;
						if (P[i + 1].x_coordinate - P[i].x_coordinate > P[i].length) {
							tmp1 = P[i].length;
						}
						if (P[i + 1].x_coordinate - P[i].x_coordinate > P[i + 1].length) {
							tmp2 = P[i + 1].length;
						}
						if (tmp1 > tmp2) {
							P[i].left = 0;
						}
						result += (tmp1 - tmp2) > 0 ? tmp2 : tmp1;
					}
				}
			}
		//	else if (i == 0) {
	//			if (P[i].left == 0 && P[i + 1].x_coordinate - P[i].x_coordinate > P[i].length) result += P[i].length;
	//		}
				
		}
		cout << result << endl;
		
	}
	return 0;
}