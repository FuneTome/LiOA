#include <iostream>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	int** G1, ** G2, ** G, len;
	cout << "Введтите размеры графов: ";
	cin >> len;
	G1 = new int* [len];
	G2 = new int* [len];
	for (int i = 0; i < len; i++) {
		G1[i] = new int[len];
		G2[i] = new int[len];
	}
	srand(time(0));
	for (int i = 0; i < len; i++) {
		for (int j = i; j < len; j++) {
			if (i == j) { G1[i][i] = 0; G2[i][i] = 0; continue; }
			G1[i][j] = rand() % 2;
			G1[j][i] = G1[i][j];
			G2[i][j] = rand() % 2;
			G2[j][i] = G2[i][j];
		}
	}
	cout << "Граф 1: \n\n";
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			cout << G1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "Граф 2: \n\n";;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			cout << G2[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\nОбъединение графов: \n\n";
	G = new int* [len];
	for (int i = 0; i < len; i++) {
		G[i] = new int[len];
	}
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			G[i][j] = G1[i][j] | G2[i][j];
			cout << G[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\nПересечение графов:\n\n";
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			G[i][j] = G1[i][j] & G2[i][j];
			cout << G[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\nКольцевая сумма графов:\n\n";
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			G[i][j] = !(G1[i][j] & G2[i][j]);
			if (i == j) G[i][i] = 0;
			cout << G[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}