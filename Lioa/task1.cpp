#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "");
	int G[6][6];
	srand(time(0));
	cout << "Матрица смежности: \n\n";
	for (int i = 0; i < 6; i++) {
		for (int j = i; j < 6; j++) {
			G[i][j] = rand() % 2;
			G[j][i] = G[i][j];
		}
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cout << G[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
	int sum = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = i; j < 6; j++) {
			if (i == j) sum += G[i][j];
			sum += G[i][j];
		}
	}
	cout << "Размер графа: " << sum << "\n";
	for (int i = 0; i < 6; i++) {
		sum = 0;
		for (int j = 0; j < 6; j++) {
			sum += G[i][j];
		}
		if ((sum == 5 && G[i][i] == 0) || (sum == 6)) cout << "Вершина " << i + 1 << " является доминирующей\n";
		else if (sum == 1 && G[i][i] == 0) cout << "Вершина " << i + 1 << " является концевой\n";
		else if ((sum == 1 && G[i][i] == 1) || (sum == 0)) cout << "Вершина " << i + 1 << " является изолированной\n";
	}
	return 0;
}