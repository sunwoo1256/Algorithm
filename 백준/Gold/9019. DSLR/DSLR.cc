#include<iostream>
#include<vector>
#include<queue>
#include<string>

void bfs(int a, int b) {
	std::vector<std::string> visited(10000, "NO");
	std::queue<int> q;
	q.push(a);
	visited[a] = "";

	while (!q.empty()) {
		if (visited[b] != "NO") {
			std::cout << visited[b] << '\n';
			break;
		}
		int k = q.front();
		q.pop();
		int d = (2 * k) % 10000;
		int s = k - 1;
		if (s < 0) {
			s = 9999;
		}
		int l = (k % 1000) * 10 + k / 1000;
		int r = (k % 10) * 1000 + k / 10;

		if (visited[d] == "NO") {
			q.push(d);
			visited[d] = visited[k] + "D";
		}
		if (visited[s] == "NO") {
			q.push(s);
			visited[s] = visited[k] + "S";
		}
		if (visited[l] == "NO") {
			q.push(l);
			visited[l] = visited[k] + "L";
		}
		if (visited[r] == "NO") {
			q.push(r);
			visited[r] = visited[k] + "R";
		}
	}

}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int t;
	std::cin >> t;

	int a, b;
	for (int i = 0; i < t; i++) {
		std::cin >> a >> b;
		bfs(a,b);
	}
}