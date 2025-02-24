#include<iostream>
#include<vector>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	std::vector<int> v;
	std::vector<int> fruit(10, 0);
	
	for (int i = 0; i < n; i++) {
		int f;
		std::cin >> f;
		v.push_back(f);
	}

	int start = 0;
	int end = 0;
	int max = 0;
	int kind = 0;

	while (end < n) {
		if (fruit[v[end]] == 0) {
			kind++;
		}
		fruit[v[end]]++;
		end++;
		//std::cout << start << ", " << end << '\n';
		while (kind > 2) {
			fruit[v[start]]--;
			if (fruit[v[start]] == 0) {
				kind--;
			}
			start++;
			//std::cout << start << ", " << end << '\n';
		}

		if (max < end - start) {
			max = end - start;
		}
	}
	//std::cout << start << ", " << end << '\n';
	std::cout << max;
}