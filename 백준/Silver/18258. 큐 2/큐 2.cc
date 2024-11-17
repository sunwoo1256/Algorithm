#include<iostream>
#include<queue>
#include<string>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::queue<int> q;
	std::string command;
	int n;

	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> command;
		if (command == "push") {
			int x;
			std::cin >> x;
			q.push(x);
		}
		if (command == "pop") {
			if (q.empty()) {
				std::cout << -1 << '\n';
			}
			else {
				std::cout << q.front() << '\n';
				q.pop();
			}
		}
		if (command == "size") {
			std::cout << q.size() << '\n';
		}
		if (command == "empty") {
			if (q.empty()) {
				std::cout << 1 << '\n';
			}
			else {
				std::cout << 0 << '\n';
			}
		}
		if (command == "front") {
			if (q.empty()) {
				std::cout << -1 << '\n';
			}
			else {
				std::cout << q.front() << '\n';
			}
		}
		if (command == "back") {
			if (q.empty()) {
				std::cout << -1 << '\n';
			}
			else {
				std::cout << q.back() << '\n';
			}
		}
	}
}