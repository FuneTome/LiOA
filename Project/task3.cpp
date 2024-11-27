#include <iostream>
#include <queue>
#include <string>
#include <Windows.h>
using namespace std;

int** creatG(int len, int p1, int p2) {
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
				if (p1 == 1) G[i][j] = rand() % 10;
				else G[i][j] = rand() % 2;
				if(p2 == 1)	G[j][i] = G[i][j];
				else {
					if (rand() % 10 > 5) G[j][i] = G[i][j];
					else G[j][i] = 0;
				}
			}
		}
	}
	return G;
}

void printG(int** G, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			cout << G[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void print_info() {
	cout << "Первый параметр - взвешеность\n1 - Взвешенный\n0 - Не взвешенный\n";
	cout << "Второй параметр - ориентированность\n1 - Ориентированный\n0 - Не ориентированный";
	exit(0);
}

void BFSD(int v, int len, int* dist, int** G) {
	queue<int> q;
	q.push(v);
	dist[v] = 0;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		//cout << v + 1 << " ";
		for (int i = 0; i < len; i++) {
			if (G[v][i] != 0 && dist[i] == -1) {
				q.push(i);
				dist[i] = dist[v] + G[v][i];
			}
		}
	}
}

void dist_print(int* e, int len) {
	int min = 2000, max = -2, * perif = new int[len], * centre = new int[len], size_min = 0, size_max = 0;
	for (int i = 0; i < len; i++) {
		if (e[i] > max) max = e[i];
		if (e[i] < min) min = e[i];
		cout << e[i] << " ";
	}
	for (int i = 0; i < len; i++) {
		if (e[i] == max) {
			perif[size_max] = i + 1;
			size_max++;
		}
		if (e[i] == min) {
			centre[size_min] = i + 1;
			size_min++;
		}
	}
	cout << "\nРадиус графа равер: " << min << "\nДиаметр графа равен: " << max << "\n";
	cout << "\nПодмножество центральных вершин равно: ";
	if (size_min == 0) cout << "null";
	for (int i = 0; i < size_min; i++) { cout << centre[i] << " "; }
	cout << "\nПодмножество периферийных вершин равно: ";
	if (size_max == 0) cout << "null";
	for (int i = 0; i < size_max; i++) { cout << perif[i] << " "; }
}

int main(int argc, char* argv[]){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (argc == 1) print_info();
	int p1 = stoi(argv[1]), p2 = stoi(argv[2]);
	int** G, ** G_, len, * dist, *e;
	cout << "Введите длину графа: ";
	cin >> len;
	G = creatG(len, p1, p2);
	printG(G, len);
	dist = new int[len];
	for (int i = 0; i < len; i++) dist[i] = -1;
	BFSD(0, len, dist, G);
	cout << "\n";
	for (int i = 0; i < len; i++) dist[i] = -1;
	e = new int[len];
	for (int i = 0; i < len; i++) {
		BFSD(i, len, dist, G);
		int max = -2;
		for (int j = 0; j < len; j++) {
			if (dist[j] > max) max = dist[j];
		}
		e[i] = max;
		for (int i = 0; i < len; i++) dist[i] = -1;
	}
	cout << "\n";
	dist_print(e, len);
	return 0;
}
