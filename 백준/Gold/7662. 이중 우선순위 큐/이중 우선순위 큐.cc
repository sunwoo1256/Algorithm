#include<iostream>
#include<vector>
#include<queue>
#include<map>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	
	while (t--) {
		int k;
		std::cin >> k;
		std::priority_queue<int, std::vector<int>, std::greater<int>> q1;
		std::priority_queue<int, std::vector<int>, std::less<int>> q2;
		std::map<int, int> m;

		while (k--) {
			std::string command;
			int n;
			std::cin >> command;
			if (command == "I") {
				std::cin >> n;
				q1.push(n);
				q2.push(n);
				m[n] += 1;
			}
			else if (command == "D") {
				std::cin >> n;
				if (n == -1) {
					while (!q1.empty()) {
						if (m[q1.top()] != 0) {
							m[q1.top()]--;
							q1.pop();
							break;
						}
						q1.pop();
					}
				}
				else if (n == 1) {
					while (!q2.empty()) {
						if (m[q2.top()] != 0) {
							m[q2.top()]--;
							q2.pop();
							break;
						}
						q2.pop();
					}
				}
			}
		}
		
		while (!q2.empty()) {
			if (m[q2.top()] != 0) {
				break;
			}
			q2.pop();
		}
		while (!q1.empty()) {
			if (m[q1.top()] != 0) {
				break;
			}
			q1.pop();
		}
		if (q2.empty() || q1.empty()) {
			std::cout << "EMPTY" << '\n';
		}
		else {
			std::cout << q2.top() << " ";
			std::cout << q1.top() << "\n";
		}
	}
}