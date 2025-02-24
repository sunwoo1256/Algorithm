#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
long long a;
long long b;
int ans = -1;

std::unordered_map<long long, int> visited;

void bfs() {
	std::queue<long long> q;
	q.push(a);
	visited[a] = 1;
	
	while (!q.empty()) {
		long long k = q.front();
		//std::cout << k << '\n';
		q.pop();
		long long multi = k * 2;
		long long plus = k * 10 + 1;
		if (multi == b || plus == b) {
			ans = visited[k] + 1;
			return;
		}
		if (multi < b && visited.find(multi) == visited.end()) {
			visited[multi] = visited[k] + 1;
			q.push(multi);
			//std::cout << "multi: " << multi << '\n';
		}
		if (plus < b && visited.find(plus)==visited.end()) {
			visited[plus] = visited[k] + 1;
			q.push(plus);
			//std::cout << "plus: " << plus << '\n';
		}

	}

}
int main() {
	std::cin >> a >> b;
	bfs();
	std::cout << ans;
}