#include<iostream>
#include<string>

int main() {
	std::string s;
	int n;

	std::cin >> n;
	std::cin >> s;

	int chicken = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'C') {
			chicken++;
		}
	}

	int nochicken = n - chicken + 1;
	if (chicken % nochicken) {
		std::cout << chicken / nochicken + 1;
	}
	else {
		std::cout << chicken / nochicken;
	}
}