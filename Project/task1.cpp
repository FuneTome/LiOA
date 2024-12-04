//#include <iostream>
//#include <queue>
//using namespace std;
//
//int** creatG(int len) {
//	int** G;
//	srand(time(0));
//	G = new int* [len];
//	for (int i = 0; i < len; i++) {
//		G[i] = new int[len];
//	}
//	for (int i = 0; i < len; i++) {
//		for (int j = i; j < len; j++) {
//			if (i == j) G[i][i] = 0;
//			else {
//				G[i][j] = rand() % 10;
//				G[j][i] = G[i][j];
//			}
//		}
//	}
//	return G;
//}
//
//int** creatG_orint(int len) {
//	int** G;
//	srand(time(0));
//	G = new int* [len];
//	for (int i = 0; i < len; i++) {
//		G[i] = new int[len];
//	}
//	for (int i = 0; i < len; i++) {
//		for (int j = i; j < len; j++) {
//			if (i == j) G[i][i] = 0;
//			else {
//				G[i][j] = rand() % 10;
//				if (rand() % 10 > 5) G[j][i] = G[i][j];
//				else G[j][i] = 0;
//			}
//		}
//	}
//	return G;
//}
//
//void printG(int** G, int len) {
//	for (int i = 0; i < len; i++) {
//		for (int j = 0; j < len; j++) {
//			cout << G[i][j] << " ";
//		}
//		cout << "\n";
//	}
//	cout << "\n";
//}
//
//void BFSD(int v, int len, int* dist, int** G) {
//	queue<int> q;
//	q.push(v);
//	dist[v] = 0;
//	while (!q.empty()) {
//		v = q.front();
//		q.pop();
//		cout << v + 1 << " ";
//		for (int i = 0; i < len; i++) {
//			if (G[v][i] != 0 && dist[i] == -1) {
//				q.push(i);
//				dist[i] = dist[v] + G[v][i];
//			}
//		}
//	}
//}
//
//void BFSD_orint(int v, int len, int* dist, int** G) {
//	queue<int> q;
//	q.push(v);
//	dist[v] = 0;
//	while (!q.empty()) {
//		v = q.front();
//		q.pop();
//		cout << v + 1 << " ";
//		for (int i = 0; i < len; i++) {
//			if (G[v][i] != 0 && dist[i] == -1) {
//				q.push(i);
//				dist[i] = dist[v] + G[v][i];
//			}
//		}
//	}
//}
//
//int main() {
//	setlocale(LC_ALL, "");
//	int** G, ** G_, len, * dist, start;
//	cout << "Введите длину графа: ";
//	cin >> len;
//	G = creatG(len);
//	printG(G, len);
//	dist = new int[len];
//	for (int i = 0; i < len; i++) dist[i] = -1;
//	cout << "Введите вершину с которой начать обход: ";
//	cin >> start;
//	BFSD(start - 1, len, dist, G);
//	cout << "\n";
//	for (int i = 0; i < len; i++) {
//		cout << dist[i] << " ";
//		dist[i] = -1;
//	}
//	cout << "\n\nОриентированный граф: \n";
//	G_ = creatG_orint(len);
//	printG(G_, len);
//	BFSD(start - 1, len, dist, G_);
//	cout << "\n";
//	for (int i = 0; i < len; i++) {
//		cout << dist[i] << " ";
//		dist[i] = -1;
//	}
//	return 0;
//}