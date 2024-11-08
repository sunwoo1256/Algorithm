#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

std::vector<int> graph[10002];
std::vector<int> dvisited(1001, 0);
std::vector<int> bvisited(1001, 0);

void dfs(int x) {
	dvisited[x] = 1;
	std::cout << x << ' ';
	for (int i = 0; i < graph[x].size(); i++) {
		int k = graph[x][i];

		if (dvisited[k] == 0) {
			dfs(k);
		}
	}
}

void bfs(int x) {
	std::queue<int> q;
	q.push(x);

	while (!q.empty()) {
		int k = q.front();
		bvisited[k] = 1;
		std::cout << k << ' ';
		q.pop();

		for (int i = 0; i < graph[k].size(); i++) {
			if (bvisited[graph[k][i]] == 0) {
				bvisited[graph[k][i]] = 1;	//방문처리 안해줄시 q에 여러번 들어갈 가능성 있음
				q.push(graph[k][i]);
			}
		}
	}
}

int main() {
	int n, m, v;
	std::cin >> n >> m >> v;
	
	int a, b;
	for (int i = 0; i < m; i++) {
		std::cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(v);
	std::cout << '\n';
	bfs(v);
}