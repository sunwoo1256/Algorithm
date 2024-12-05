#include<iostream>
#include<vector>
#include<cmath>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<int> v(200001,0);
	std::vector<int> ans(200001, 0);
	
	int num;
	int min = 1000000001;
	int max = 0;

	for (int i = 1; i <= n; i++) {
		std::cin >> num;
		v[i] = num;
		if (i == 1) {
			min = num;
			v[0] = num;
			ans[i] = 0;
		}
		if (num < v[i - 1]) {
			ans[i] = ans[i - 1];
		}
		else {
			if (num - min >= ans[i - 1]) {
				ans[i] = num - min;
			}
			else {
				ans[i] = ans[i - 1];
			}
		}

		if (min > num) {
			min = num;
		}
		std::cout << ans[i] << ' ';
	}
	
}