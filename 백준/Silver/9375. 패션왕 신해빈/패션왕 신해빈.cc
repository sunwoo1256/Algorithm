#include<iostream>
#include<map>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	std::string clothes;
	std::string wear;
	int num;
	for (int i = 0; i < t; i++) {
		
		std::cin >> num;
		std::map<std::string, int> m;
		int res = 1;
		for (int j = 0; j < num; j++) {
			std::cin >> clothes >> wear;
			if (m.find(wear) == m.end()) {
				m[wear] = 1;
			}
			else {
				m[wear] += 1;
			}
		}
		for (auto iter = m.begin(); iter != m.end(); iter++) {
			res *= (iter->second + 1);
		}
		std::cout << res - 1 << '\n';
	}
}