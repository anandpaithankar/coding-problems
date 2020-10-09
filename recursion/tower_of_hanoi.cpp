#include "algo.h"

const int N = 3;

void moveDisks(std::array<std::stack<int>, N> &tower, int from, int to, int aux, int diskNum)
{
	if (diskNum < 0)
	{
		return;
	}

	moveDisks(tower, from, aux, to, diskNum - 1);
	tower[to].push(tower[from].top());
	tower[from].pop();
	moveDisks(tower, aux, to, from, diskNum - 1);
}

void moveDisks(std::array<std::stack<int>, N> &tower)
{
	moveDisks(tower, 0, 1, 2, N);
}

int main()
{
	std::array<std::stack<int>, N> tower;

	for (int i = N; i > 0; --i)
	{
		tower[0].push(i);
	}

	moveDisks(tower);
}
