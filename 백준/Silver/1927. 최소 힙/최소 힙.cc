#include<iostream>
#include<queue>


int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::priority_queue<long long, std::vector<long long>, std::greater<long long>> q;
	int n;
	std::cin >> n;
	long long command;
	for (int i = 0; i < n; i++) {
		std::cin >> command;
		if (command == 0) {
			if (q.empty()) {
				std::cout << 0 << '\n';
			}
			else {
				std::cout << q.top() << '\n';
				q.pop();
			}
		}
		else {
			q.push(command);
		}
	}
}