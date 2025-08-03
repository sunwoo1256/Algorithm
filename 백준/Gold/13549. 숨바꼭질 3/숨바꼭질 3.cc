#include<iostream>
#include<vector>
#include<queue>

int bfs(int n, int k, std::vector<int>& v) {
	v[n] = 1;
	std::queue<int> q;
	q.push(n);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == k) {
			return v[k];
		}
		if (v[2 * x] == 0 && 2 * x <= 100000) {
			v[2 * x] = v[x];
			q.push(2 * x);
		}
		if (v[x - 1] == 0 && x - 1 >= 0) {
			v[x - 1] = v[x] + 1;
			q.push(x - 1);
		}
		if (v[x + 1] == 0 && x + 1 <= 100000) {
			v[x + 1] = v[x] + 1;
			q.push(x + 1);
		}
		
	}
}

int main() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> v(200002, 0);
	int ans = bfs(n, k, v);
	std::cout << ans - 1;
}