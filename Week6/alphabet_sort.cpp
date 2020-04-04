#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <list>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	string word1;
	string word2;
	list<string> result;
	int T;
	cin >> T;
	while (T--) {
		cin >> word1;
		word2 = word1;
		next_permutation(word1.begin(), word1.begin() + word1.length());		// ������������ ����, �� ���� �������� word1�� ����
		if (word1 > word2) {
			result.push_back(word1);
		}
		else {
			result.push_back(word2);
		}
	}
	cout << endl;
	while (!result.empty()) {
		cout << result.front() << endl;
		result.pop_front();
	}
	cout << endl;
	return 0;
}