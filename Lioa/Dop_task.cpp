#include <iostream>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	int len, count = 0;
	cout << "Введите количество вершин графа: ";
	cin >> len;
	int** G, **g;
	G = new int* [len];
	for (int i = 0; i < len; i++) {
		G[i] = new int[len];
	}
	cout << "Матрица смежности: \n";
	srand(time(0));
	for (int i = 0; i < len; i++) {
		for (int j = i; j < len; j++) {
			G[i][j] = rand() % 2;
			G[j][i] = G[i][j];
			count++;
		}
	}
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			cout << G[i][j] << " ";
			}
		cout << '\n';
	}

	cout << '\n';
	int size = 0;
	for (int i = 0; i < len; i++) {
		for (int j = i; j < len; j++) {
			size += G[i][j];
			if (G[i][i] == 0 && G[i][j] == 1) size--;
		}
	}
	g = new int*[len];
	for (int i = 0; i < len; i++) {
		g[i] = new int[size];
	}
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < size; j++) {
			g[i][j] = 0;
		}
	}
	int sum = 0;
	for (int i = 0; i < len; i++) {
		for (int j = i; j < len; j++) {
			if (G[i][i] == 0) { continue; }
			else if (G[i][j] == 1) {
				g[i][sum] = 1;
				g[j][sum] = 1;
				sum++;
			}

		}
	}
	cout << "Матрица инцидентвности: \n\n";
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < size; j++) {
			cout << g[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}