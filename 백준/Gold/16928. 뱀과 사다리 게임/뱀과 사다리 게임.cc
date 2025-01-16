#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
std::vector<int> graph(101, 0);
std::vector<int> visited(101, 100);

void bfs() {
	int dice[7] = { 6,5,4,3,2,1 };
	std::deque<int> q;
	q.push_back(1);
	visited[1] = 0;

	while (!q.empty()) {
		if (visited[100] != 100) {
			break;
		}
		int k = q.front();
		q.pop_front();
		
		//std::cout <<"k: "<< k << '\n';
		for (int i = 0; i < 6; i++) {
			int xx = k + dice[i];
			if (xx <= 100 && visited[xx] == 100) {
				q.push_back(xx);
				visited[xx] = visited[k] + 1;
				//std::cout << xx << " " << visited[xx]<<'\n';
				if (graph[xx]) {
					q.pop_back();
					visited[xx] = 100;
					if (visited[graph[xx]] == 100) {
						q.push_back(graph[xx]);
						visited[graph[xx]] = visited[k] + 1;
						//std::cout << graph[xx] << ' ' << visited[graph[xx]] << '\n';
					}
					
				}
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;

	int num1, num2;
	for (int i = 0; i < n + m; i++) {
		std::cin >> num1 >> num2;
		graph[num1] = num2;
	}

	bfs();
	std::cout << visited[100];
}