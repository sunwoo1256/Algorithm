#include<iostream>
#include<string>

int main() {
	std::string s;
	std::cin >> s;
	int check = -1;
	int n;
	bool minus = false;
	int ans = 0;
	int temp;
	std::string str;
	//std::cout << s[s.size()] << '\n';
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '+' || s[i] == '-' || i == s.size()) {
			n = i - check - 1;
			str = s.substr(check + 1, n);
			check = i;
			temp = -1 * stoi(str);
			if (!minus) {
				temp = stoi(str);
			}
			if (s[i] == '-') {
				minus = true;
			}
			ans += temp;
			//std::cout << ans << '\n';
		}
	}
	std::cout << ans;
}