#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main() {
	int n;
	std::cin >> n;

	std::string name;
	std::cin >> name;

	std::vector<char> v = {'y', 'u','i','o', 'p', 'h', 'j', 'k', 'l', 'b', 'n', 'm'};
	char last = name[n - 1];

	if (std::find(v.begin(), v.end(), last) != v.end()) {
		std::cout << 0;
	}
	else {
		std::cout << 1;
	}
}