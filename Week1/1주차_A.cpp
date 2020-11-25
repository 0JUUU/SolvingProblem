#include <bits/stdc++.h>
using namespace std;

int T, p, n;
int coin[15];
int cnt = 0;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while (T--)
	{
		cnt = 0;
		cin >> p >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> coin[i];
		}
		int money = 10000 - p;
		for (int i = n - 1; i >= 0; i--)
		{
			cnt += money / coin[i];
			money -= (money / coin[i]) * coin[i];
			if (money < 0) break;
		}
		if (money != 0) cout << 0<<"\n";
		else cout << cnt << "\n";
	}
}