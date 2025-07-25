#include<iostream>
#include<vector>
#include<algorithm>

int MAX = 10000000001;

int main() {
	int T;
	int n, m;
	std::cin >> T;
	for (int i = 0; i < T; i++) {
		std::cin >> n >> m;
		std::vector<long long> a(n+1,MAX);
		std::vector<long long> b(m+1,MAX);
		long long cnt = 0;
		for (int j = 0; j < n; j++) {
			std::cin >> a[j];
		}
		for (int k = 0; k < m; k++) {
			std::cin >> b[k];
		}

		std::sort(a.begin(), a.end());
		std::sort(b.begin(), b.end());

		for (int l = 0; l < n; l++) {
			int lower = std::lower_bound(b.begin(), b.end(), a[l]) - b.begin();
			if (lower == 0) {
				cnt += b[lower];
			}
			else if (lower >= m) {
				cnt += b[lower - 1];
			}
			else if (b[lower] - a[l] >= a[l] - b[lower - 1]) {
				cnt += b[lower - 1];
			}
			else {
				cnt += b[lower];
			}
			//std::cout << cnt << '\n';
		}
		std::cout << cnt << '\n';
		
	}
}