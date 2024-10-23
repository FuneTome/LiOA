#include <iostream>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	int** G1, ** G, len_1, len_2, t;
	cout << "Введтите размер графа G1: ";
	cin >> len_1;
	G1 = new int* [len_1];
	for (int i = 0; i < len_1; i++) {
		G1[i] = new int[len_1];
	}
	srand(time(0));
	while (1) {
		t = 0;
		for (int i = 0; i < len_1; i++) {
			for (int j = i; j < len_1; j++) {
				if (i == j) { G1[i][i] = 0; continue; }
				G1[i][j] = rand() % 2;
				t += G1[i][j];
				G1[j][i] = G1[i][j];
			}
		}
		if (t >= (len_1 / 2)) break;
	}
	int** G2;
	cout << "Введтите размер графа G2: ";
	cin >> len_2;
	G2 = new int* [len_2];
	for (int i = 0; i < len_2; i++) {
		G2[i] = new int[len_2];
	}
	srand(time(0));
	while (1) {
		t = 0;
		for (int i = 0; i < len_2; i++) {
			for (int j = i; j < len_2; j++) {
				if (i == j) { G2[i][i] = 0; continue; }
				G2[i][j] = rand() % 2;
				t += G2[i][j];
				G2[j][i] = G2[i][j];
			}
		}
		if (t >= (len_2 / 2)) break;
	}
	cout << "Граф 1: \n\n";
	for (int i = 0; i < len_1; i++) {
		for (int j = 0; j < len_1; j++) {
			cout << G1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "Граф 2: \n\n";;
	for (int i = 0; i < len_2; i++) {
		for (int j = 0; j < len_2; j++) {
			cout << G2[i][j] << " ";
		}
		cout << endl;
	}
	int max, min, f;
	if (len_1 > len_2) { max = len_1; min = len_2; f = 1; }
	else { max = len_2; min = len_1; f = 2; }//
	cout << "\nОбъединение графов: \n\n";
	G = new int* [max];
	for (int i = 0; i < max; i++) {
		G[i] = new int[max];
	}
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			if (j < min && i < min) {
				G[i][j] = G1[i][j] | G2[i][j];
			}
			else if (f == 1) G[i][j] = G1[i][j];
			else G[i][j] = G2[i][j];
			cout << G[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < max; i++) delete[]G[i];
	delete[]G;
	G = new int* [min];
	for (int i = 0; i < min; i++) {
		G[i] = new int[min];
	}
	cout << "\nПересечение графов:\n\n";
	for (int i = 0; i < min; i++) {
		for (int j = 0; j < min; j++) {
			G[i][j] = G1[i][j] & G2[i][j];
			cout << G[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\nКольцевая сумма графов:\n\n";
	for (int i = 0; i < min; i++) {
		for (int j = 0; j < min; j++) {
			G[i][j] = G1[i][j] ^ G2[i][j];
			cout << G[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}