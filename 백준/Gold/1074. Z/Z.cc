#include<iostream>
#include<vector>
#include<cmath>
int r, c;
int cnt = 0;
void Z(int x, int y, int n) {
	int dx[5] = {0, 1, 0, 1};
	int dy[5] = { 0, 0, 1, 1 };

	if (x == c && y == r) {
		std::cout << cnt;
	}
	//if (n == 2) {
	//	for (int i = 0; i < 4; i++) {
	//		int xx = x + dx[i];
	//		int yy = y + dy[i];
	//		cnt++;
	//		//std::cout << "x: " << xx << " y: " << yy << " cnt:" << cnt << '\n';
	//		if (xx == c && yy == r) {
	//			std::cout << cnt - 1;
	//		}
	//	}
	//}
	else if(c<x+n && c>=x && r<y+n && r>=y){
		Z(x, y, n / 2);
		Z(x + n / 2, y, n / 2);
		Z(x, y + n / 2, n / 2);
		Z(x + n / 2, y + n / 2, n / 2);
	}
	else {
		cnt += n * n;
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	std::cin >> n >> r >> c;

	Z(0, 0, pow(2,n));
}