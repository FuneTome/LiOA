#include <iostream>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	int G[6][6], g[6][21] = { 0 };
	srand(time(0));
	cout << "Матрица инцидентности: \n\n";
	for (int i = 0; i < 6; i++) {
		for (int j = i; j < 6; j++) {
			G[i][j] = rand() % 2;
			G[j][i] = G[i][j];
		}
	}
	int sum = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = i; j < 6; j++) {
			if (G[i][i] == 0) { sum++; continue; }
			else if (G[i][j] == 1) {
				g[i][sum] = 1;
				g[j][sum] = 1;
			}
			sum++;
		}
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 21; j++) {
			cout << g[i][j] << " ";
		}
		cout << '\n';
	}
	
	int count = 0;
	for (int i = 0; i < 21; i++) {
		int sum = 0;
		for (int j = 0; j < 6; j++) {
			sum += g[j][i];
		}
		if (sum == 2) count++;
		else if (sum == 1) count += 2;
	}
	cout << '\n' << "Размер графа: " << count << "\n\n";
	
	for (int i = 0; i < 6; i++) {
		int sum = 0;
		for (int j = 0; j < 21; j++) {
			sum += g[i][j];
		}
		if (sum >= 5) cout << "Вершина " << i + 1 << " является доминирующей\n";
		else if (sum == 1) cout << "Вершина " << i + 1 << " является концевой\n";
		else if (sum == 0) cout << "Вершина " << i + 1 << " является изолированной\n";
	}
	return 0;
}