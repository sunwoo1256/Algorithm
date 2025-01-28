#include<iostream>
#include<vector>
int n, m;
int max = 0;
std::vector<std::vector<int>> v(501, std::vector<int>(501, 0));

void three1() {
	int sum;
	int dx[8] = { 0,1,2,3,2,1,0 };
	int dy[8] = { -1,-1,-1,0,1,1,1 };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j + 2 <= m; j++) {
			std::pair<int, int> k = { i,j };
			sum = v[i][j] + v[i][j + 1] + v[i][j + 2];
			for (int a = 0; a < 7; a++) {
				int xx = j + dx[a];
				int yy = i + dy[a];
				if (xx <= m && yy <= n && yy > 0) {
					sum += v[yy][xx];
					if (sum > max) {
						max = sum;
						/*std::cout << "t1max: " << max << '\n';
						std::cout << i << ' ' << j << ' ' << yy << ' ' << xx << '\n';*/
					}
					sum -= v[yy][xx];
				}
			}
		}
	}
}

void three2() {
	int sum;
	int dx[8] = { -1,-1,-1,0,1,1,1};
	int dy[8] = { 0,1,2,3,2,1,0 };
	for (int i = 1; i + 2 <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::pair<int, int> k = { i,j };
			sum = v[i][j] + v[i + 1][j] + v[i + 2][j];
			for (int a = 0; a < 7; a++) {
				int xx = j + dx[a];
				int yy = i + dy[a];
				if (xx>0 && xx <= m && yy <= n && yy > 0) {
					sum += v[yy][xx];
					if (sum > max) {
						max = sum;
						/*std::cout << "t2max: " << max << '\n';
						std::cout << i << ' ' << j << ' ' << yy << ' ' << xx << '\n';*/
					}
					sum -= v[yy][xx];
				}
			}
		}
	}
}

void two1() {
	int sum;
	int dx[4] = { -1,0,1 };
	int dy[4] = { 1,1,1 };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j + 1 <= m; j++) {
			std::pair<int, int> k = { i,j };
			sum = v[i][j] + v[i][j + 1];
			for (int a = 0; a < 3; a++) {
				int xx = j + dx[a];
				int yy = i + dy[a];
				if (xx >0 && xx + 1 <= m && yy <= n && yy > 0) {
					sum += v[yy][xx] + v[yy][xx+1];
					if (sum > max) {
						max = sum;
						//std::cout << "w1max: " << max << '\n';
						//std::cout << i << ' ' << j << ' ' << yy << ' ' << xx << '\n';
					}
					sum -= (v[yy][xx] + v[yy][xx + 1]);
				}
			}
		}
	}
}

void two2() {
	int sum;
	int dx[4] = { 1,1 };
	int dy[4] = { -1,1 };
	for (int i = 1; i + 1 <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::pair<int, int> k = { i,j };
			sum = v[i + 1][j] + v[i][j];
			for (int a = 0; a < 2; a++) {
				int xx = j + dx[a];
				int yy = i + dy[a];
				if (xx > 0 && xx <= m && yy + 1 <= n && yy > 0) {
					sum += v[yy][xx] + v[yy + 1][xx];
					if (sum > max) {
						max = sum;
						//std::cout << "w2max: " << max << '\n';
						//std::cout << i << ' ' << j << ' ' << yy << ' ' << xx << '\n';
					}
					sum -= (v[yy][xx] + v[yy + 1][xx]);
				}
			}
		}
	}
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cin >> n >> m;

	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> v[i][j];
		}
	}
	three1();
	three2();
	two1();
	two2();
	std::cout << max;
}