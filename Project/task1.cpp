#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct node {
	int n;
	node* next;
	node(int _n) : n(_n), next(nullptr) {}
};

struct list {
	node* first;
	list() : first(nullptr) {}

	bool is_empty() { return first == nullptr; }
	void add(int _n) {
		node* p = new node(_n);
		if (is_empty()) {
			first = p;
			return;
		}
		node* t1 = first;
		while (t1->next != nullptr) {
			t1 = t1->next;
		}
		t1->next = p;
	}
	void print(int i) {
		if (is_empty()) { cout << i << ": " << "null\n"; return; }
		node* p = first;
		cout << i << ": ";
		while (p) {
			cout << p->n << " ";
			p = p->next;
		}
		cout << "\n";
	}
};

int** creatG(int len) {
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
				G[i][j] = rand() % 2;
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
}

void BFS_list(int v, int len, bool* num, int** G, struct list* l) {
	queue<int> q;
	q.push(v);
	num[v] = true;
	while (!q.empty()) {
		v = q.front();
		node* p = l[v].first;
		q.pop();
		cout << v + 1 << " ";
		while (p) {
			if (num[p->n - 1] == false) { q.push(p->n - 1); num[p->n - 1] = true; }
			p = p->next;
		}
	}
}

int main() {
	setlocale(LC_ALL, "");
	int** G, len;
	cout << "Введите длину графа: ";
	cin >> len;
	bool* num;
	num = new bool[len];
	for (int i = 0; i < len; i++) num[i] = false;
	G = creatG(len);
	printG(G, len);
	list* l = new list[len];
	BFS(0, len, num, G);
	cout << "\n\n";
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (G[i][j] == 1) l[i].add(j + 1);
		}
		l[i].print(i + 1);
	}
	cout << "\n";
	bool* nm;
	nm = new bool[len];
	for (int i = 0; i < len; i++) nm[i] = false;
	BFS_list(0, len, nm, G, l);
	return 0;
}