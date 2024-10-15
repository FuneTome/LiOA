#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	int** G1, ** G2, ** G, len, * sum1, * sum2, sm1, sm2;
	cout << "Введтите размеры графов: ";
	cin >> len;
	G1 = new int* [len];
	G2 = new int* [len];
	for (int i = 0; i < len; i++) {
		G1[i] = new int[len];
		G2[i] = new int[len];
	}
	srand(time(0));
	sum1 = new int[len];
	sum2 = new int[len];
	for (int i = 0; i < len; i++) {
		sm1 = 0;
		sm2 = 0;
		for (int j = i; j < len; j++) {
			if (i == j) { G1[i][i] = 0; G2[i][i] = 0; continue; }
			G1[i][j] = rand() % 2;
			sm1 += G1[i][j];
			G1[j][i] = G1[i][j];
			G2[i][j] = rand() % 2;
			sm2 += G2[i][j];
			G2[j][i] = G2[i][j];
		}
		sum1[i] = sm1;
		sum2[i] = sm2;
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
	cout << "\n";
	int** g1, ** g2, sum;
	g1 = new int* [len];
	g2 = new int* [len];
	for (int i = 0; i < len; i++) {
		g1[i] = new int[sum1[i]];
		g2[i] = new int[sum2[i]];
	}
	for (int i = 0; i < len; i++) {
		sum = 0;
		for (int j = i + 1; j < len; j++) {
			if (G1[i][j] == 1) {
				g1[i][sum] = j + 1;
				sum++;
			}
		}
	}
	for (int i = 0; i < len; i++) {
		sum = 0;
		for (int j = i + 1; j < len; j++) {
			if (G2[i][j] == 1) {
				g2[i][sum] = j + 1;
				sum++;
			}
		}
	}
	cout << "Список смежности для 1 графа: \n\n";
	for (int i = 0; i < len; i++) {
		cout << i + 1 << ": ";
		if (sum1[i] == 0) { cout << "null \n"; continue; }
		for (int j = 0; j < sum1[i]; j++) {
			cout << g1[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;
	cout << "Список смежности для 2 графа: \n\n";
	for (int i = 0; i < len; i++) {
		cout << i + 1 << ": ";
		if (sum2[i] == 0) { cout << "null \n"; continue; }
		for (int j = 0; j < sum2[i]; j++) {
			cout << g2[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;
	return 0;
}