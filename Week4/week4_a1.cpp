#include <iostream>
#include <unordered_map>
using namespace std;
//using namespace stdext;

struct A {
	unordered_map<int, int> aelement;
	int element : 26;
} a[1000001];

struct B {
	unordered_map<int, int> belement;
	int element : 26;
} b[1000001];


int main() {
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T != 0) {
		int N;
		cin >> N;
//		hash_map<unsigned int, int> A;
//		hash_map<int, int> B;
		for (int i = 0; i < N; i++) {
			int element;
			cin >> element;
			a[i].element = element;
			a[i].aelement.insert(a[i].element,1);
		}
		for (int i = 0; i < N; i++) {
			int element;
			cin >> element;
			b[i].element = element;
			b[i].belement.insert(b[i].element, 1);
		}
	
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (a[i].aelement.find(1)->first == b[j].belement.find(1)->first) {
					b[j].belement.find(1)->second = 0;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			auto p = b[i].belement.find(1);
			if (p != b[i].belement.end()) {
				cout << b[i].element << " ";
			}
			else cout << "0";
		}
		cout << endl;
		T--;
	}
	return 0;
}