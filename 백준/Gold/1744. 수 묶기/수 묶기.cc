#include<iostream>
#include<vector>
#include<algorithm>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<int> plus;
	std::vector<int> minus;
	int num;

	for (int i = 0; i < n; i++) {
		std::cin >> num;
		if (num > 0) {
			plus.push_back(num);
		}
		else {
			minus.push_back(num);
		}
	}
	std::sort(plus.rbegin(), plus.rend());
	std::sort(minus.begin(), minus.end());

	long long sum = 0;
	for (int i = 1; i < plus.size(); i+=2) {
		if (plus[i] == 1 || plus[i - 1] == 1) {
			sum += plus[i] + plus[i - 1];
		}
		else {
			sum += plus[i] * plus[i - 1];
		}
		
		//std::cout << sum << '\n';
	}
	if (!plus.empty() && plus.size() % 2 != 0) {
		sum += plus[plus.size() - 1];
		//std::cout << "ifplus";
	}
	for (int i = 1; i < minus.size(); i += 2) {
		sum += minus[i] * minus[i - 1];
		//std::cout << sum << '\n';
	}
	if (!minus.empty() && minus.size() % 2 != 0) {
		sum += minus[minus.size() - 1];
		//std::cout << "ifminus";
	}
	std::cout << sum;

}