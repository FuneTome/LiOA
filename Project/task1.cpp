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

void BFSD(int v, int len, int* dist, int** G) {
	queue<int> q;
	q.push(v);
	dist[v] = 0;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		cout << v + 1 << " ";
		for (int i = 0; i < len; i++) {
			if (G[v][i] == 1 && dist[i] == -1) {
				q.push(i);
				dist[i] = dist[v] + 1;
			}
		}
	}
}

void BFSD_list(int v, int len, int* dist, struct list * l) {
	queue<int> q;
	q.push(v);
	dist[v] = 0;
	while (!q.empty()) {
		node* p = l[v].first;
		v = q.front();
		q.pop();
		cout << v + 1 << " ";
		while(p){
			if (dist[p->n - 1] == -1) {
				q.push(p->n - 1);
				dist[p->n - 1] = dist[v] + 1;
			}
			p = p->next;
		}
	}
}

int main() {
	setlocale(LC_ALL, "");
	int** G, len, *dist, start;
	cout << "������� ����� �����: ";
	cin >> len;
	G = creatG(len);
	printG(G, len);
	dist = new int[len];
	for (int i = 0; i < len; i++) dist[i] = -1;
	cout << "������� ������� � ������� ������ �����: ";
	cin >> start;
	BFSD(start - 1, len, dist, G);
	cout << "\n";
	for (int i = 0; i < len; i++) {
		cout << dist[i] << " ";
		dist[i] = -1;
	}
	list* l = new list[len];
	cout << "\n\n";
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (G[i][j] == 1) l[i].add(j + 1);
		}
		l[i].print(i + 1);
	}
	cout << "\n";
	BFSD_list(start - 1, len, dist, l);
	cout << "\n";
	for (int i = 0; i < len; i++) {
		cout << dist[i] << " ";
		dist[i] = -1;
	}
	return 0;
}