#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int T;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		string word1, word2;
		cin >> word1;
		word2 = word1;
		next_permutation(word1.begin(), word1.begin() + word1.length());
		if (word1 > word2) cout << word1 << endl;
		else cout << word2 << endl;
	}
	return 0;
}