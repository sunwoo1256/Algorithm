#include<iostream>
#include<stack>
#include<string>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	int command;
	std::stack<int> s;

	for (int i = 0; i < n; i++) {
		std::cin >> command;
		if (command == 1) {
			int x;
			std::cin >> x;
			s.push(x);
		}
		if (command == 2) {
			if (!s.empty()) {
				std::cout << s.top() << '\n';
				s.pop();
			}
			else {
				std::cout << -1 << '\n';
			}
		}
		if (command == 3) {
			std::cout << s.size() << '\n';
		}
		if (command == 4) {
			if (s.empty()) {
				std::cout << 1 << '\n';
			}
			else {
				std::cout << 0 << '\n';
			}
		}
		if (command == 5) {
			if (!s.empty()) {
				std::cout << s.top() << '\n';
			}
			else {
				std::cout << -1 << '\n';
			}
		}
	}
}