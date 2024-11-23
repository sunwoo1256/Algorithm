#include<iostream>
#include<vector>
#include<algorithm>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> v(n + 1, 0);
	std::vector<int> v1(n + 1, 0);
	std::vector<int> left;
	std::vector<int> right;

	for (int i = 1; i <= n; i++) {
		std::cin >> v[i];
	}
	std::sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) {
		v1[i] = v[i] - v[i - 1];
	}
	/*for (int i = 0; i < v1.size(); i++) {
		std::cout << v1[i] << ' ';
	}
	std::cout << '\n';*/
	for (int i = 2; i <= n; i+=2) {
		if (i == 2) {
			right.push_back(v1[i]);
		}
		else {
			right.push_back(v1[i] + right.back());
		}
	}
	for (int i = n; i > 2; i -= 2) {
		if (i == n) {
			left.push_back(v1[i]);
		}
		else {
			left.push_back(v1[i] + left.back());
		}
	}

	/*for (int i = 0; i < right.size(); i++) {
		std::cout << right[i] << ' ';
	}
	std::cout << '\n';
	for (int i = 0; i < right.size(); i++) {
		std::cout << left[i] << ' ';
	}*/

	int min = left.back() + right[0];
	for (int i = 0; i < right.size(); i++) {
		int temp = left[left.size() - i -1] + right[i];
		if (temp < min) {
			min = temp;
		}
	}
	std::cout << min;
}