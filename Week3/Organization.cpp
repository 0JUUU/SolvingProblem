#include <iostream>
using namespace std;
int N;		// 사원 수
int K;		// 작업 수
int *parent;
int *file;
int sort[101] = { 0 };
int parnum = 0;

int LCA(int a, int b) {
	int lca = 0;
	int *IcaArr = new int[N + 1];
	for (int i = 0; i < N + 1; i++) {
		IcaArr[i] = 0;
	}
	while (1) {
		IcaArr[a] = 1;
		if (a == 1) break;
		a = parent[a];
	}
	while (1) {
		if (IcaArr[b] == 1) {
			lca = b;
			break;
		}
		IcaArr[b] = 1;
		b = parent[b];
	}
	return lca;
}

void document(int a, int b, int x) {
	parnum = LCA(a, b);

	while (a != parnum) {
		file[a] = x;
		a = parent[a];
	}
	while (b != parnum) {
		file[b] = x;
		b = parent[b];
	}
}
void under(int a, int b) {
	parent[a] = b;
}
void kind(int a, int b) {
	int count = 0;
	parnum = LCA(a, b);

	while (1) {
		if (a == parnum) break;
		if (sort[file[a]] == 0) {
			sort[file[a]] = 1;
			count++;
		}
		a = parent[a];
	}
	while (1) {
		if (b == parnum) break;
		if (sort[file[b]] == 0) {
			sort[file[b]] = 1;
			count++;
		}
		b = parent[b];
	}
	for (int i = 0; i < 101; i++) {
		sort[i] = 0;
	}
	cout << count << endl;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N >> K;
	parent = new int[N + 1];
	file = new int[N + 1];
	sort[0] = 0;
	sort[1] = 0;
//	for (int i = 0; i <= 1; i++) {
//		parent[i] = 0;
//		file[i] = 0;
//	}
	for (int i = 2; i < N + 1; i++) {
		parent[i] = 1;
		file[i] = 1;
	}

	while (K != 0) {
		int r;
		int a, b, x;
		cin >> r;
		switch (r) {
		case 1:
			cin >> a >> b >> x;
			document(a, b, x);
			break;
		case 2:
			cin >> a >> b;
			under(a, b);
			break;
		case 3:
			cin >> a >> b;
			kind(a, b);
			break;
		}
		K--;
	}
	delete[] file;
	delete[] parent;
	cout << endl;
	return 0;
}