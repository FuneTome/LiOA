#include <iostream>
#include <queue>
using namespace std;

struct node {
	int n;
	node* next;
	node(int _n) : n(_n), next(nullptr) {}
};

struct list {
	node* first;
	node* last;
	list() : first(nullptr), last(nullptr) {}

	bool is_empty() { return first == nullptr; }
	void add_back(int _n) {
		node* p = new node(_n);
		if (is_empty()) {
			first = p;
			last = p;
			return;
		}
		last->next = p;
		last = p;
	}
	void dlt() {
		if (is_empty()) return;
		node* p = first;
		first = p->next;
		delete p;
	}
};

int** creatG(int len, double ver) {
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
				if (rand() % 11 <= 10 * ver)	G[i][j] = 1;
				else G[i][j] = 0;
				G[j][i] = G[i][j];
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

void BFS(int v, int len, bool* num, int** G) {
	queue<int> q;
	q.push(v);
	num[v] = true;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		cout << v + 1 << " ";
		for (int i = 0; i < len; i++) {
			if (G[v][i] == 1 && num[i] == false) { q.push(i); num[i] = true; }
		}
	}
	cout << "\n";
}

void BFS_queue(int v, int len, bool* num, int** G) {
	list q;
	q.add_back(v);
	num[v] = true;
	while (!q.is_empty()) {
		v = q.first->n;
		q.dlt();
		cout << v + 1 << " ";
		for (int i = 0; i < len; i++) {
			if (G[v][i] == 1 && num[i] == false) { q.add_back(i); num[i] = true; }
		}
	}
}



int main() {
	setlocale(LC_ALL, "");
	int** G, len, start;
	double ver;
	cout << "Введите длину графа: ";
	cin >> len;
	cout << "Введите вероятность появления 1: ";
	cin >> ver;
	bool* num;
	num = new bool[len];
	for (int i = 0; i < len; i++) num[i] = false;
	G = creatG(len, ver);
	printG(G, len);
	cout << "Введите вершину с которой начнется обход: ";
	cin >> start;
	time_t start1 = clock();
	BFS(start - 1, len, num, G);
	for (int i = 1; i < len; i++) {
		if(num[i] == false)	BFS(i, len, num, G);
	}
	time_t end1 = clock();
	delete[]num;
	cout << "\n";
	num = new bool[len];
	for (int i = 0; i < len; i++) num[i] = false;
	time_t start2 = clock();
	BFS_queue(start - 1, len, num, G);
	time_t end2 = clock();
	cout << "\nВремя выполнение с помощью встроенного класса: " << (end1 - start1)/1000.0; 
	cout << "\nВремя выполнения с использованием самостоятельно реализованного метода: " << (end2 - start2) / 1000.0;
	return 0;
}