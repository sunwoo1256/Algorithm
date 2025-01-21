#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int t;
	std::cin >> t;

	std::string command;
	int n;
	std::string arr;
	for (int i = 0; i < t; i++) {
		std::cin >> command;
		std::cin >> n;
		std::cin >> arr;
		std::vector<int> v;
		int idx = 1;
		for (int a = 0; a < n; a++) {
			int comma = arr.find(",", idx);
			if (comma == std::string::npos) {
				comma = arr.size() - 1;
			}
			std::string s1 = arr.substr(idx, comma - idx);
			int num = std::stoi(s1);
			v.push_back(num);
			idx = comma + 1;
		}
		bool error = false;
		bool reverse = false;
		for (int a = 0; a < command.size(); a++) {
			if (command[a] == 'R') {
				//std::reverse(v.begin(), v.end());
				if (reverse) {
					reverse = false;
				}
				else {
					reverse = true;
				}
			}
			else if (command[a] == 'D') {
				if (v.empty()) {
					error = true;
					break;
				}
				if(reverse) {
					v.erase(v.end() - 1);
				}
				else {
					v.erase(v.begin());
				}
			}
		}
		if (error) {
			std::cout << "error" << '\n';
		}
		else {
			std::cout << "[";
			if (!v.empty()) {
				if (reverse) {
					for (int a = v.size() - 1; a > 0; a--) {
						std::cout << v[a] << ",";
					}
					std::cout << v[0];
				}
				else {
					for (int a = 0; a < v.size() - 1; a++) {
						std::cout << v[a] << ",";
					}
					std::cout << v[v.size() - 1];
				}
				
			}
			std::cout << "]\n";
		}
	}
}