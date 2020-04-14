#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int T, N, M, a[501], b[501],t, result;
vector<pair<int, int>> adj[102];

int dijkstra(int x, int y) {
	priority_queue<pair<int, int> > ab;
	int check[102] = {};
	ab.push({ 0,1 });
	while (!ab.empty()) {
		int distance = -ab.top().first;
		int node = ab.top().second;
		ab.pop();
		if (node == N) {
			return distance;
		}
		if (check[node]) {
			continue;
		}
		check[node] = 1;
		for (auto it : adj[node]) {
			if (x + y^node + it.first || x * y^node * it.first) {
				ab.push({ -it.second - distance,it.first });
			}
		}
	}
	return 1000000000;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		result = 0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> a[i] >> b[i] >> t;
			adj[a[i]].push_back({ b[i],t });
			adj[b[i]].push_back({ a[i],t });
		}
		for (int i = 0; i < M; i++) {
			result = max(result, dijkstra(a[i], b[i]));
		}
		if (result < 1000000000) {
			result -= dijkstra(0, 0);
		}
		else {
			result = -1;
		}
		cout << result << "\n";
		for (int i = 0; i < 102; i++) {
			adj[i].clear();
		}
	}
	return 0;
}
