#include<iostream>
#include<vector>

int main() {
	int n, q;
	std::cin >> n >> q;

	std::vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		std::cin >> a;
		v.push_back(a);
	}

	int gap = 0;
	int id;

	for (int i = 0; i < q; i++) {
		int command;
		std::cin >> command;
		int s;

		if (command == 2) {
			std::cin >> s;
			gap = (gap + s) % n;
		}
		else if (command == 3) {
			std::cin >> s;
			gap = (gap - s + n) % n;
		}
		else if (command == 1) {
			int x, idx;
			
			std::cin >> idx >> x;
			if (idx - 1 - gap < 0) {
				id = (idx - 1 - gap) % n + n;
			}
			else {
				id = (idx - 1 - gap) % n;
			}
			v[id] += x;
		}
		/*for (int i = 0; i < n; i++) {
			if ((i - gap) < 0) {
				id = (i - gap) % n + n;
			}
			else {
				id = (i - gap) % n;
			}
			std::cout << v[id] << ' ';
		}
		std::cout << '\n';*/
	}

	for (int i = 0; i < n; i++) {
		int id = ((i - gap) % n + n) % n;
		std::cout << v[id] << ' ';
	}
}