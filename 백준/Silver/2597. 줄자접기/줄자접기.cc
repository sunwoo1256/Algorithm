#include<iostream>
#include<algorithm>
#include<vector>

int main() {
	float n;
	std::vector<float> v(6, 0);
	int ra, rb;
	int ba, bb;
	int ya, yb;

	std::cin >> n;
	std::cin >> v[0] >> v[1];
	std::cin >> v[2] >> v[3];
	std::cin >> v[4] >> v[5];

	float start = 0, end = n;
	float mid = (v[0] + v[1]) / 2;

	if (mid - start < end - mid) {
		start = mid;
		for (int i = 2; i < 6; i++) {
			if (v[i] < start) {
				v[i] = start * 2 - v[i];
			}
		}
	}
	else {
		end = mid;
		for (int i = 2; i < 6; i++) {
			if (v[i] > end) {
				v[i] = end - (v[i] - end);
			}
		}
	}
	

	if (v[2] != v[3]) {
		mid = (v[2] + v[3]) / 2;
	}
	if (mid - start < end - mid) {
		start = mid;
		for (int i = 4; i < 6; i++) {
			if (v[i] < start) {
				v[i] = start * 2 - v[i];
			}
		}
	}
	else {
		end = mid;
		for (int i = 4; i < 6; i++) {
			if (v[i] > end) {
				v[i] = end - (v[i] - end);
			}
		}
	}
	

	if (v[4] != v[5]) {
		mid = (v[4] + v[5]) / 2;
	}
	if (mid - start < end - mid) {
		start = mid;
	}
	else {
		end = mid;
	}
	


	std::cout << std::fixed;
	std::cout.precision(1);

	std::cout << end - start;
}