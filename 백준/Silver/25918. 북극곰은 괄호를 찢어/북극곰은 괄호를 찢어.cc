#include<iostream>
#include<stack>
#include<string>

int main() {
	int n;
	std::string s;
	std::cin >> n;
	std::cin >> s;

	std::stack<char> st;
	int max = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			if (!st.empty() && st.top() == ')') {
				st.pop();
			}
			else {
				st.push(s[i]);
				if (max < st.size()) {
					max = st.size();
				}
			}
		}
		else if (s[i] == ')') {
			if (!st.empty() && st.top() == '(') {
				st.pop();
			}
			else {
				st.push(s[i]);
				if (max < st.size()) {
					max = st.size();
				}
			}
		}
	}
	if (!st.empty()) {
		std::cout << -1;
	}
	else {
		std::cout << max;
	}

}