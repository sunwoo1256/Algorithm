#include<iostream>
#include<string>

int main() {
	int n;
	std::cin >> n;
	std::string ioi;
	std::string oi = "OI";
	ioi = "I";
	int m;
	std::cin >> m;
	std::string s;
	std::cin >> s;
	int idx = 0;

	for (int i = 0; i < n; i++) {
		ioi += "OI";
	}
	int cnt = 0;
	while (idx < m) {
		int fi = s.find(ioi, idx);
		if (fi != std::string::npos) {
			idx = fi + 1;
			cnt++;
			//std::cout << "idx: " << idx << '\n';
		}
		else {
			break;
		}
	}
	std::cout << cnt;
}