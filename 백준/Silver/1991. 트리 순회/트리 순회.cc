#include<iostream>
#include<vector>
#include<string>

void preorder(char node, std::vector<std::vector<char>> nodes) {
	if (node == '.') {
		return;
	}
	std::cout << node;
	preorder(nodes[node - 'A'][0], nodes);
	preorder(nodes[node - 'A'][1], nodes);
}

void inorder(char node, std::vector<std::vector<char>> nodes) {
	if (node == '.') {
		return;
	}
	inorder(nodes[node - 'A'][0], nodes);
	std::cout << node;
	inorder(nodes[node - 'A'][1], nodes);
}

void postorder(char node, std::vector<std::vector<char>> nodes) {
	if (node == '.') {
		return;
	}
	postorder(nodes[node - 'A'][0], nodes);
	postorder(nodes[node - 'A'][1], nodes);
	std::cout << node;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::vector<std::vector<char>> nodes(27, std::vector<char>(2,'.'));
	int n;
	char node, l, r;

	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> node >> l >> r;
		nodes[node - 'A'][0] = l;
		nodes[node - 'A'][1] = r;
	}

	preorder('A', nodes);
	std::cout << '\n';
	inorder('A', nodes);
	std::cout << '\n';
	postorder('A', nodes);
}