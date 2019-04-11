#include "algo.h"

int minCoins(int amount, const std::vector<int> &coins)
{
	int dp[amount + 1];
	memset(dp, INT_MAX, sizeof(dp));

	for (int i = 1; i < amount + 1; i++)
	{
		for (int j = 0; j < coins.size(); j++)
		{
			if (i - coins[j] >= 0)
			{
				dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
			}
		}
	}
	return dp[amount];
}

int main()
{
	int amount = 11;
	std::vector<int> coins{2, 3, 5};
	int c = minCoins(amount, coins);
	std::cout << c << "\n";
}