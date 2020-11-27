#include <bits/stdc++.h>
using namespace std;

int T, p, n;
int coin[501];
int dp[10001];
int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> p >> n;
		fill(dp, dp + 10001, 100000);
		for (int i = 0; i < n; i++)
		{
			cin >> coin[i];
			dp[coin[i]] = 1;
		}
		for (int i = coin[0] + 1; i <= 10000-p; i++)
		{
			if (i % coin[0] == 0)
			{
				for (int j = 0; j < n; j++)
				{
					if (i - coin[j] >= 0)
					{
						if (dp[i] > dp[i - coin[j]]) dp[i] = dp[i - coin[j]];
					}
					else break;
				}
				dp[i] += 1;
			}

		}
		if (dp[10000 - p] == 100000) cout << "0\n";
		else cout << dp[10000 - p] << "\n";
	}
}