#include <iostream>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	int G[6][6] = { 0 };
	string mass[6];
	srand(time(0));
	cout << "Матрица инцидентности: \n\n";
	for (int i = 0; i < 6; i++) {
		int sum = 0;
		for (int j = 0; j < 6; j++) {
			if (sum < 2)	G[j][i] = rand() % 2;
			else G[j][i] = 0;
			sum += G[j][i];
		}
	}

	/*for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			mass[i] += to_string(G[j][i]);
		}
	}

	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (mass[i] == mass[j]) {
				for (int k = 0; k < 6; k++) {
					G[j][k] = 0;
				}
			}
		}
	}*/
	int count = 0;
	for (int i = 0; i < 6; i++) {
		int sum = 0;
		for (int j = 0; j < 6; j++) {
			sum += G[j][i];
			cout << G[i][j] << " ";
		}
		if (sum == 2) count++;
		else if (sum == 1) count += 2; 
		cout << '\n';
	}
	cout << '\n' << "Размер графа: " << count << "\n\n";
	
	for (int i = 0; i < 6; i++) {
		int sum = 0;
		for (int j = 0; j < 6; j++) {
			sum += G[i][j];
		}
		if (sum >= 5) cout << "Вершина" << i + 1 << " является доминирующей\n";
		else if (sum == 1) cout << "Вершина " << i + 1 << " является концевой\n";
		else if (sum == 0) cout << "Вершина " << i + 1 << " является изолированной\n";
	}
	return 0;
}