#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

//wiki is pretty usefull btw https://en.wikipedia.org/wiki/Maxima_of_a_point_set

std::vector<int> segment_tree;
int size=1;

struct  Score
{
	int place1, place2, place3;
	Score(int p1, int p2, int p3) :place1(p1), place2(p2), place3(p3)
	{	
	}

};

bool operator < (const Score& s1, const Score& s2) 
{
	return s1.place1 < s2.place1;
}

//segment_tree operations
void update(int key, int value) 
{
	key += size - 1;
	segment_tree[key] = value;
	while (key /= 2)
		segment_tree[key] = std::min(segment_tree[2 * key], segment_tree[2 * key+ 1]);
}

int minimal_query(int r)
{
	int ans = INT_MAX;
	int l = size;
	r += size - 1;
	while (l <= r)
	{
		if (l & 1)
			ans = std::min(ans, segment_tree[l]);
		if (!(r & 1))
			ans = std::min(ans, segment_tree[r]);
		l = (l + 1) / 2, r = (r - 1) / 2;
	}
	return ans;
}


int main()
{
	int n, x, y, z, counter=0;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	std::cin >> n;
	std::set<Score> scores;


	for (int i = 0; i < n; i++) 
	{
		std::cin >> x >> y >> z;
		scores.insert(Score(x, y, z));
	}

	//int size = n;
	//size = (1 << ((int)log(size - 1) + 1));
	while (size < n) 
		size <<= 1;
	segment_tree.resize(2 * size, INT_MAX);

	for (auto s: scores) {
		update(s.place2, s.place3);
		if (s.place3 < minimal_query(s.place2 - 1))
			counter++; 
	}
	std::cout << counter;
}
