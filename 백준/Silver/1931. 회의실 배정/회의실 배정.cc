#include<iostream>
#include<vector>
#include<algorithm>

int main() {
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> v(n,std::pair<int,int> (0,0));

	for (int i = 0; i < n; i++) {
		int start, end;
		std::cin >> start >> end;
		v[i].first = end;
		v[i].second = start;
	}

	std::sort(v.begin(), v.end());

	int now = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		//std::cout << v[i].first << ' ' << v[i].second << '\n';
		if (v[i].second >= now) {
			now = v[i].first;
			cnt++;
		}
	}
	std::cout << cnt;
}