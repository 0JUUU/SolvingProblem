#include <iostream>
#include <algorithm>
using namespace std;
int N;		// 사원 수
int K;		// 작업 수
int dn , M;
int *parent;
int *file;
int *doc; //document 횟수
int sorting[101] = { 0 };
int parnum = 0;

struct Query {
	int r, a, b, c;
} q[300001];

int find(int X) {
	int L = 1, R = dn;
	while (L <= R) {
		M = (L + R) / 2;
		if (doc[M] == X)
			break;
		if (doc[M] > X)
			R = M - 1;
		else L = M + 1;
	}

	return M;
}

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
		if (sorting[file[a]] == 0) {
			sorting[file[a]] = 1;
			count++;
		}
		a = parent[a];
	}
	while (1) {
		if (b == parnum) break;
		if (sorting[file[b]] == 0) {
			sorting[file[b]] = 1;
			count++;
		}
		b = parent[b];
	}
	for (int i = 0; i < 101; i++) {
		sorting[i] = 0;
	}
	cout << count << endl;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N >> K;
	parent = new int[N + 1];
	file = new int[N + 1];
	sorting[0] = 0;
	sorting[1] = 0;
	//	for (int i = 0; i <= 1; i++) {
	//		parent[i] = 0;
	//		file[i] = 0;
	//	}
	for (int i = 2; i < N + 1; i++) {
		parent[i] = 1;
		file[i] = 1;
	}

	for (int i = 1; i <= K; i++) {
		cin >> q[i].r;
		switch (q[i].r) {
		case 1:
			cin >> q[i].a >> q[i].b >> q[i].c;
	//		doc[++dn] = q[i].c;
			break;
		case 2:
			cin >> q[i].a >> q[i].b;
			break;
		case 3:
			cin >> q[i].a >> q[i].b;
			break;

		}

	}
	cout << endl;
	//1명령어 배열 doc 정렬 dn:1번 갯수
	sort(doc + 1, doc + dn + 1);

	for (int i = 1; i <= K; i++) {
		switch (q[i].r) {
		case 1:
			document(q[i].a, q[i].b, q[i].c);
			break;
		case 2:
			under(q[i].a, q[i].b);
			break;
		case 3:
			kind(q[i].a, q[i].b);
			break;

		}

	}
	cout << endl;
	return 0;
}