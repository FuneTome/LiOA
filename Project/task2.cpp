#include <iostream>
#include <stack>
using namespace std;

int **creatG(int len) {
	int** G;
	srand(time(0));
	G = new int* [len];
	for (int i = 0; i < len; i++) {
		G[i] = new int[len];
	}
	for (int i = 0; i < len; i++) {
		for (int j = i; j < len; j++) {
			if (i == j) G[i][i] = 0;
			else {
				G[i][j] = rand() % 2;
				G[j][i] = G[i][j];
			}
		}
	}
	return G;
}

void printG(int ** G, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			cout << G[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

bool num_empty(bool *num, int len) {
	for (int i = 0; i < len; i++) {	if (num[i] == false) return false; } return true;
}

int main() {
	setlocale(LC_ALL, "");
	int** G, len;
	cout << "Введите длину графа: ";
	cin >> len;
	bool *num;
	num = new bool[len];
	for (int i = 0; i < len; i++) { num[i] = false; }
	G = creatG(len);
	printG(G, len);
	stack<int> stack;
	int s = 0;
	while (1) {
		for (int i = len - 1; i >= 0; i--) { if (G[s][i] == 1 && num[i] == false) stack.push(i); }
		cout << s + 1 << " ";
		num[s] = true;
		if (num_empty(num, len)) break;
		for (int i = 0; i < len; i++) {
			if (num[stack.top()] == false) {
				s = stack.top();
				stack.pop();
				break;
			}
		}
	}
	return 0;
}