#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	std::ios::sync_with_stdio;

	string word1, word2;
	int T;
	cin >> T;
	while (T--) {
		cin >> word1;
		word2 = word1;
		next_permutation(word1.begin(), word1.begin() + word1.length());
		if (word1 > word2) cout << word1 << endl;
		else cout << word2 << endl;
	}
	return 0;
}