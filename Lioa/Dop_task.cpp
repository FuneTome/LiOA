#include <iostream>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	int len, count = 0;
	cout << "������� ���������� ������ �����: ";
	cin >> len;
	int** G, **g;
	G = new int* [len];
	for (int i = 0; i < len; i++) {
		G[i] = new int[len];
	}
	cout << "������� ���������: \n";
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
	int size = 0;
	for (int i = 0; i < len; i++) {
		for (int j = i; j < len; j++) {
			size += G[i][j];
		}
	}
	cout << "\n������ ����� �����: " << size << endl;
	for (int i = 0; i < len; i++) {
		int sum = 0;
		for (int j = 0; j < len; j++) {
			sum += G[i][j];
		}
		if ((sum == (len - 1) && G[i][i] == 0) || (sum == len)) cout << "������� " << i + 1 << " �������� ������������\n";
		else if (sum == 1 && G[i][i] == 0) cout << "������� " << i + 1 << " �������� ��������\n";
		else if ((sum == 1 && G[i][i] == 1) || (sum == 0)) cout << "������� " << i + 1 << " �������� �������������\n";
	}
	cout << '\n';
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
			if (G[i][j] == 1 && i == j) {
				g[i][sum] = 2;
				sum++;
			}
			else if (G[i][j] == 1) {
				g[i][sum] = 1;
				g[j][sum] = 1;
				sum++;
			}
		}
	}
	cout << "������� ��������������: \n\n";
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < size; j++) {
			cout << g[i][j] << " ";
		}
		cout << '\n';
	}
	cout << "\n������ ����� �����: " << size << endl;
	for (int i = 0; i < len; i++) {
		int sum = 0;
		for (int j = 0; j < size; j++) {
			sum += g[i][j];
			if (g[i][j] == 2) sum-=2;
		}
		if (sum >= (len - 1)) cout << "������� " << i + 1 << " �������� ������������\n";
		else if (sum == 1) cout << "������� " << i + 1 << " �������� ��������\n";
		else if (sum == 0) cout << "������� " << i + 1 << " �������� �������������\n";
	}
	return 0;
}