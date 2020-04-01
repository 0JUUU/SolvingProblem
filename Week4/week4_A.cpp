#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <hash_set>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int T;			// T : 테스트케이스
	cin >> T;
	while (T != 0) {
		int N;		// N : 정수의 개수
		cin >> N;
		unordered_set<int> A;
		vector<int> B_element;

		for (int i = 0; i < N; i++) {
			int a = 0;
			cin >> a;
			A.insert(a);
		}
		for (int i = 0; i < N; i++) {
			int b = 0;
			cin >> b;
			B_element.push_back(b);
		}
/*		for (int i = 0; i < N; i++) {
			int p = B_element.front();
			auto q = A.find(p);
			if (q != A.end()) {
				B_element.erase(remove(B_element.begin(), B_element.end(), p), B_element.end());
			}
	//		if (p == B_element.back()) break;
		}*/
		auto p = B_element.begin();
		while (p != B_element.end()) {
//		auto q = 
			if (A.find(*p) != A.end()) {
				p = B_element.erase(p);
			}
			else {
				++p;
			}
		}
		if (B_element.empty()) cout << "0";
		else {
			for (int i = 0; i < B_element.size(); i++) {
				cout << B_element[i] << " ";
			}
		}
		cout << endl;
		T--;
	}

	return 0;
}