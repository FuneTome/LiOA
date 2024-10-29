#include <iostream>
#include <string>
using namespace std;

struct node {
	string n;
	node* next;
	node(string _n) : n(_n), next(nullptr) {}
};

struct list {
	node* first;
	list() : first(nullptr) {}

	bool is_empty() { return first == nullptr; }
	void add(string _n) {
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
	int check_cell(int n) {
		int i = 0;
		node* p = first;
		while (p && i != n) { p = p->next;	i++; }
		if (p == nullptr) return 1;
		return stoi(p->n);
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

void dfs(int v, bool* num, int len, struct list* l) {
	num[v - 1] = true;
	cout << " " << v;
	for (int i = 0; i < len; i++) {
		int n = l[v - 1].check_cell(i);
		if (num[n - 1] == false) {
			dfs(n, num, len, l);
		}
	}
}

int main() {
	setlocale(LC_ALL, "");
	int** G, len;
	cout << "������� ����� �����: ";
	cin >> len;
	bool* num;
	num = new bool[len];
	for (int i = 0; i < len; i++) { num[i] = false; }
	G = creatG(len);
	printG(G, len);
	cout << "\n";
	list* l = new list[len];
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (G[i][j] == 1) l[i].add(to_string(j + 1));
		}
		l[i].print(i + 1);
	}
	cout << "\n";
	dfs(1, num, len, l);
	return 0;
}