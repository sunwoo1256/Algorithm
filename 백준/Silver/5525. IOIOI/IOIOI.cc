#include<iostream>
#include<string>

int main() {
	int n;
	std::cin >> n;
	int m;
	std::cin >> m;
	std::string s;
	std::cin >> s;

	int ans = 0;

	for (int i = 0; i < m; i++) {
		if (s[i] == 'I') {
			int k = 0;
			while (s[i + 1] == 'O' && s[i + 2] == 'I') {
				k++;
				if (k == n) {
					ans++;
					k--;
				}
				i += 2;
			}
		}
	}
	std::cout << ans;
}