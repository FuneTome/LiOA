#include <iostream>
#include <queue>
#include <stack>
#include <time.h>
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

void DFSD_ver(int v, int len, int* dist, int** G) {
	stack<int> stack;
	queue<int> q;
	int** ver = new int* [len - 1], j = 0, k = 0;
	for(int i = 0; i < len; i ++){ ver[i] = new int[len]; }
	stack.push(v);
	dist[v] = 0;
	while (!stack.empty()) {
		v = stack.top();
		stack.pop();
		q.push(v + 1);
		for (int i = 0; i < len; i++) {
			if (G[v][i] == 1 && dist[i] == INT_MAX) {
				stack.push(i);
				dist[i] = dist[v] + 1;
				q.push(i + 1);
				cout << "\n";
				j = 0;
				while (!q.empty()) {
					k = q.back();
					//cout << q.front() << " "; 
					ver[k - 2][j] = q.front();
					q.pop(); 
					j++;
				}
				q.push(1);
			}
		}
	}
	for (int i = 0; i < len - 1; i++) {
		cout << i + 2 << ": ";
		for (int j = 0; j < len; j++) {
			if (ver[i][j] < 0) break;
			cout << ver[i][j] << " ";
		}
		cout << "\n";
	}
}

void DFSD(int v, int len, int* dist, int** G) {
	stack<int> stack;
	stack.push(v);
	dist[v] = 0;
	while (!stack.empty()) {
		v = stack.top();
		stack.pop();
		cout << v + 1 << " ";
		for (int i = 0; i < len; i++) {
			if (G[v][i] == 1 && dist[i] == INT_MAX) {
				stack.push(i);
				dist[i] = dist[v] + 1;
			}
		}
	}
}

void DFSD_list(int v, int len, int* dist, struct list* l) {
	stack<int> stack;
	stack.push(v);
	dist[v] = 0;
	while (!stack.empty()) {
		node* p = l[v].first;
		v = stack.top();
		stack.pop();
		cout << v + 1 << " ";
		while (p) {
			if (dist[p->n - 1] == INT_MAX) {
				stack.push(p->n - 1);
				dist[p->n - 1] = dist[v] + 1;
			}
			p = p->next;
		}
	}
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
			if (G[v][i] == 1 && dist[i] == INT_MAX) {
				q.push(i);
				dist[i] = dist[v] + 1;
			}
		}
	}
}


int main() {
	setlocale(LC_ALL, "");
	int** G, len, * dist, start;
	cout << "������� ����� �����: ";
	cin >> len;
	G = creatG(len);
	printG(G, len);
	dist = new int[len];
	for (int i = 0; i < len; i++) dist[i] = INT_MAX;
	cout << "������� ������� � ������� ������ �����: ";
	cin >> start;
	time_t st1 = clock();
	cout << "�����: ";
	DFSD(start - 1, len, dist, G);
	time_t end1 = clock();
	cout << "\n";
	cout << "\n��������� �� ������:\n";
	for (int i = 0; i < len; i++) {
		cout << i + 1 << ": ";
		if (dist[i] == INT_MAX) cout << "���� ���\n";
		else cout << dist[i] << "\n";
		dist[i] = INT_MAX;
	}
	DFSD_ver(start - 1, len, dist, G);
	list* l = new list[len];
	cout << "\n\n������ ���������:\n";
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (G[i][j] == 1) l[i].add(j + 1);
		}
		l[i].print(i + 1);
	}
	cout << "\n�����: ";
	DFSD_list(start - 1, len, dist, l);
	cout << "\n";
	cout << "\n��������� �� ������:\n";
	for (int i = 0; i < len; i++) {
		cout << i + 1 << ": ";
		if (dist[i] == INT_MAX) cout << "���� ���\n";
		else cout << dist[i] << "\n";
		dist[i] = INT_MAX;
	}
	cout << "\n\n";
	time_t st2 = clock();
	BFSD(start - 1, len, dist, G);
	time_t end2 = clock();
	cout << "����� ���������� �� ������ ������ � �������: " << (end1 - st1) / 1000.0;
	cout << "\n����� ���������� �� ������ ������ � ������: " << (end2 - st2) / 1000.0 << "\n";
	return 0;
}