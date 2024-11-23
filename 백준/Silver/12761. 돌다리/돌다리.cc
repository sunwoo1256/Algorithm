#include<iostream>
#include<vector>
#include<queue>

int a, b;
int n, m;
std::vector<int> visited(100001, 0);

void bfs(int x) {
	std::queue<int> q;
	q.push(x);
	visited[x] = 1;

	while (!q.empty()) {
		int k = q.front();
		q.pop();
		int plus1 = k + 1;
		int minus1 = k - 1;
		int plusA = k + a;
		int minusA = k - a;
		int plusB = k + b;
		int minusB = k - b;
		int multiA = k * a;
		int multiB = k * b;

		if (visited[m] != 0) {
			std::cout << visited[m] - 1;
			break;
		}
		if (plus1 <= 100000 && visited[plus1] == 0) {
			visited[plus1] += visited[k] + 1;
			q.push(plus1);
		}
		if (plusA <= 100000 && visited[plusA] == 0) {
			visited[plusA] += visited[k] + 1;
			q.push(plusA);
		}
		if (plusB <= 100000 && visited[plusB] == 0) {
			visited[plusB] += visited[k] + 1;
			q.push(plusB);
		}
		if (multiA <= 100000 && visited[multiA] == 0) {
			visited[multiA] += visited[k] + 1;
			q.push(multiA);
		}
		if (multiB <= 100000 && visited[multiB] == 0) {
			visited[multiB] += visited[k] + 1;
			q.push(multiB);
		}
		if (minus1 >= 0 && visited[minus1] == 0) {
			visited[minus1] += visited[k] + 1;
			q.push(minus1);
		}
		if (minusA >= 0 && visited[minusA] == 0) {
			visited[minusA] += visited[k] + 1;
			q.push(minusA);
		}
		if (minusB >= 0 && visited[minusB] == 0) {
			visited[minusB] += visited[k] + 1;
			q.push(minusB);
		}
		/*for (int i = 0; i <= m; i++) {
			std::cout << visited[i] << ' ';
		}
		std::cout << '\n';*/
	}
}


int main() {
	std::cin >> a >> b >> n >> m;
	bfs(n);
}