#include<iostream>
#include<vector>
#include<queue>

std::vector<int> visited(100001, 0);
std::queue<int> q;

void bfs(int n, int k) {
	q.push(n);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		//std::cout << x << ": ";
		if (x == k) {
			//std::cout << "x == k\n";
			break;
		}

		int minus = x - 1;
		int plus = x + 1;
		int multi = x * 2;

		
		if (minus >= 0 && visited[minus] == 0) {
			q.push(minus);
			visited[minus] = visited[x] + 1;
			//std::cout << minus << ' ';
		}
		if (plus < 100001 && visited[plus] == 0) {
			q.push(plus);
			visited[plus] = visited[x] + 1;
			//std::cout << plus << ' ';
		}
		if (multi < 100001 && visited[multi] == 0) {
			q.push(multi);
			visited[multi] = visited[x] + 1;
			//std::cout << multi << ' ';
		}
		//std::cout << '\n';
	}
	std::cout << visited[k];
}

int main() {
	int n, k;
	std::cin >> n >> k;

	bfs(n, k);
}