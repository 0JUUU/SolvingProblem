#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

vector < vector<pair<int, int > > > graph;
vector < vector<bool > > check;
vector<int> parent;
int T, N, M;

int dijkstra(int a, int b) {
	priority_queue<pair<int, int > > pq;
	pq.push(make_pair(0, 1));
	vector<int> dis(N + 1, 100000000);
	dis[1] = 0;
	while (!pq.empty()) {
		int distance = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dis[here] < distance)
			continue;

		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i].first;
			int nextdis = graph[here][i].second + distance;
			if ((here == a && next == b) || (here == b && next == a))
				continue;
			if (dis[next] > nextdis) {
				pq.push(make_pair(nextdis, next));
				dis[next] = nextdis;
				parent[next] = here;
			}
		}
	}
	return dis[N];
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		graph.assign(N + 1, vector<pair<int, int > >());
		check.assign(N + 1, vector<bool>());
		parent.assign(N + 1, -1);
		for (int i = 0; i < M; i++) {
			int a, b, t;
			cin >> a >> b >> t;
			graph[a].push_back(make_pair(b, t));
			graph[b].push_back(make_pair(a, t));
		}
		int min = dijkstra(0, 0);
		int result = -100000000;
		int node = N;
		while (parent[node] != -1) {
			int a = node;
			int b = parent[node];
			result = max(result, dijkstra(a, b));
			node = b;
		}
		if (result == 100000000)
			cout << "-1" << endl;
		else
			cout << result - min << endl;
	}
	return 0;
}