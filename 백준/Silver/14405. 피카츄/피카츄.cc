#include<iostream>
#include<string>

int main() {
	std::string s;
	std::cin >> s;
	int k = 0;
	
	
	while (k < s.size()) {
		if (s.find("pi", k) == k) {
			k += 2;
		}
		else if (s.find("ka", k) == k) {
			k += 2;
		}
		else if (s.find("chu", k) == k) {
			k += 3;
		}
		else {
			break;
		}
	}
	if (k == s.size()) {
		std::cout << "YES";
	}
	else {
		std::cout << "NO";
	}
	
	
}