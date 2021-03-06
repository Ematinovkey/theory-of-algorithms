#include <cstdio>
#include <iostream>
#include <queue>
#include <numeric>
const int MAX_LCM = 2520;

struct State
{
	int island;
	int time;
	State(int i, int t) :island(i), time(t)
	{
	}
	State() :island(-1), time(0)
	{
	}
};


int gcd(int a, int b)
{
	for (;;)
	{
		if (a == 0) return b;
		b %= a;
		if (b == 0) return a;
		a %= b;
	}
}

int lcm(int a, int b)
{
	int temp = gcd(a, b);

	return temp ? (a / temp * b) : 0;
}

int main()
{
	int n, current_lcm = 1, result_time = 1;
	bool is_exist = false;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	std::cin >> n;
	int *a = new int[n];
	int *b = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i] >> b[i];
		if (current_lcm < MAX_LCM)
			current_lcm = lcm(current_lcm,a[i]+b[i]);
	}
	std::queue<State> states;
	states.push(State());
	bool *used = new bool[n];
	for (int i = 0; i<n; i++)
		used[i] = false;
	while (!states.empty() && !is_exist)
	{
		State current = states.front();
		states.pop();
		if (result_time < current.time + 1)
		for (int i = current.island - 5; i <= (current.island + 5); i++)
		{
			if ((i > -1) && (i < n) && (used[i] == false) && (current.time + 1 < current_lcm) && (((current.time) % (a[i]+b[i])) < a[i]))
			{
				states.push(State(i, current.time + 1));
				used[i] = true;
			}

			else
			{
				if ((i == -1) && ((current.time + 1) < current_lcm))
					states.push(State(-1, current.time + 1));
				else
					if ((i == n) && ((current.time + 1) <= current_lcm + 1))
					{
						result_time = current.time + 1;
						is_exist = true;
					}
			}

		}
	}
	delete[] a;
	delete[] b;
	if (is_exist)
		std::cout << result_time;
	else
		std::cout << "No";
}