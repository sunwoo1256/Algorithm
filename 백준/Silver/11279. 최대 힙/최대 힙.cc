#include<iostream>
#include<queue>

int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::priority_queue<int> q;
	int n;
	std::cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		std::cin >> x;
		if (x == 0) {
			if (q.empty()) {
				std::cout << 0 << '\n';
			}
			else {
				std::cout << q.top() << '\n';
				q.pop();
			}
		}
		else {
			q.push(x);
		}
	}
	
}