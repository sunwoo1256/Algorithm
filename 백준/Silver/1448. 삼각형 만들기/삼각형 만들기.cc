#include<iostream>
#include<vector>
#include<algorithm>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	std::cin >> n;

	std::vector<int> v;
	int num;

	for (int i = 0; i < n; i++) {
		std::cin >> num;
		v.push_back(num);
	}

	std::sort(v.rbegin(), v.rend());
	int sum = -1;
	bool tri = false;
	for (int i = 0; i < n - 2; i++) {
		if (v[i] < v[i + 1] + v[i + 2]) {
			sum = v[i] + v[i + 1] + v[i + 2];
			tri = true;
			break;
		}

	}
	std::cout << sum;
}