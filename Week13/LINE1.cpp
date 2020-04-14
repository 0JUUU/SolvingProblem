#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L;
long long a_dp[100001];
long long b_dp[100001];
pair<int, int> stick[100001];
vector<int> av, bv;

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> stick[i].first >> stick[i].second;
		av.push_back(stick[i].first);
		bv.push_back(stick[i].second);
	}
	sort(stick, stick + N);
	sort(av.begin(), av.end());
	sort(bv.begin(), bv.end());

	av.erase(unique(av.begin(), av.end()), av.end());
	bv.erase(unique(bv.begin(), bv.end()), bv.end());
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		int a_idx = lower_bound(av.begin(), av.end(), stick[i].first) - av.begin();
		int b_idx = lower_bound(bv.begin(), bv.end(), stick[i].second) - bv.begin();
		int len = L + (abs(stick[i].first - stick[i].second));
		long long a = a_dp[a_idx], b = b_dp[b_idx];
		a_dp[a_idx] = max(a, b + len);
		b_dp[b_idx] = max(b, a + len);
		ans = max(a_dp[a_idx], max(ans, b_dp[b_idx]));
	}
	cout << ans << "\n";
}