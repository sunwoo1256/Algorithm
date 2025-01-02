#include<iostream>
#include<queue>
#include<cmath>

struct compare
{
	bool operator()(int a, int b) {
		if (abs(a) != abs(b)) {
			return abs(a) > abs(b);
		}
		else if (a != b) {
			return a > b;
		}
		return a > b;
	}

};

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	std::cin >> n;

	std::priority_queue<int, std::vector<int>, compare> pq;

	for (int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		if (x != 0) {
			pq.push(x);
		}
		else {
			if (pq.empty()) {
				std::cout << 0 << '\n';
			}
			else {
				std::cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}
}