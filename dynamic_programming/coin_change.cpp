#include <iostream>
#include <vector>
#include <limits>

std::vector<int> coins{10,6,1};

int makeChange(int c) {
	if (c == 0) {
		return 0;
	}
	int minCoins = INT_MAX;
	for (int coin : coins) {
		if (c - coin >= 0) {
			int currMinCoins = makeChange(c-coin);
			minCoins = std::min(currMinCoins, minCoins);
		} 
	}
	return minCoins+1; // add back the coin removed recursively
}

int main()
{
	int change = 20;
	std::cout << makeChange(change);
}
