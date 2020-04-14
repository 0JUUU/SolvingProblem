#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N, c, d, y_length;
int a_dp[100001], b_dp[100001];
vector<int> a, b;
pair<int, int> x_coor[100001];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	cin >> c >> d;
	y_length = abs(c - d);
	for (int i = 0; i < N; i++) {
		cin >> x_coor[i].first >> x_coor[i].second;
		a.push_back(x_coor[i]. first);
		b.push_back(x_coor[i].second);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(x_coor, x_coor + N);

	a.erase(unique(a.begin(), a.end()), a.end());
	b.erase(unique(b.begin(), b.end()), b.end());

	int result = 0;

	for (int i = 0; i < N; i++) {
		int a_index = lower_bound(a.begin(), a.end(), x_coor[i].first) - a.begin();
		int b_index = lower_bound(b.begin(), b.end(), x_coor[i].second) - b.begin();
		int length = y_length + abs(x_coor[i].first - x_coor[i].second);
		int a_now = a_dp[a_index], b_now = b_dp[b_index];
		a_dp[a_index] = max(a_now, b_now + length);
		b_dp[b_index] = max(b_now, a_now + length);
		result = max(a_dp[a_index], max(result, b_dp[b_index]));
	}
	cout << result << "\n";
	return 0;
}