//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//	setlocale(LC_ALL, "");
//	int** G1, ** G2, ** G, len;
//	cout << "�������� ������� ������: ";
//	cin >> len;
//	G1 = new int* [len];
//	G2 = new int* [len];
//	for (int i = 0; i < len; i++) {
//		G1[i] = new int[len];
//		G2[i] = new int[len];
//	}
//	srand(time(0));
//	for (int i = 0; i < len; i++) {
//		for (int j = i; j < len; j++) {
//			if (i == j) { G1[i][i] = 0; G2[i][i] = 0; continue; }
//			G1[i][j] = rand() % 2;
//			G1[j][i] = G1[i][j];
//			G2[i][j] = rand() % 2;
//			G2[j][i] = G2[i][j];
//		}
//	}
//	cout << "���� 1: \n\n";
//	for (int i = 0; i < len; i++) {
//		for (int j = 0; j < len; j++) {
//			cout << G1[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl << "���� 2: \n\n";;
//	for (int i = 0; i < len; i++) {
//		for (int j = 0; j < len; j++) {
//			cout << G2[i][j] << " ";
//
//		}
//		cout << endl;
//	}
//	cout << "\n";
//	int n, m, ** _G, count;
//	cout << "�������������� ������\n\n������� �������: ";
//	cin >> n >> m;
//	len--;
//	_G = new int* [len];
//	for (int i = 0; i < len; i++) {
//		_G[i] = new int[len];
//	}
//	int r, c = 0;
//	for (int i = 0; i <= len; i++) {
//		r = 0;
//		for (int j = 0; j <= len; j++) {
//			if (i == (n - 1) || i == (m - 1)) { c--; break; }
//			if (j == (n - 1) || j == (m - 1)) continue;
//			_G[c][r] = G1[i][j];
//			r++;
//		}
//		c++;
//	}
//	for (int i = 0; i < len; i++) {
//		_G[len - 1][i] = G1[n - 1][i] + G1[m - 1][i];
//		if (_G[len - 1][i] == 2) _G[len - 1][i]--;
//		_G[i][len - 1] = _G[len - 1][i];
//	}
//	_G[len - 1][len - 1] = 0;
//	for (int i = 0; i < len; i++) {
//		for (int j = 0; j < len; j++) {
//			cout << _G[i][j] << " ";
//		}
//		cout << "\n";
//	}
//	for (int i = 0; i < len; i++) {
//		delete _G[i];
//	}
//	delete _G;
//	cout << "\n���������� �����";
//	while (1) {
//		cout << "\n������� ������� : ";
//		cin >> n >> m;
//		if (G1[n - 1][m - 1] != 1) {
//			cout << "\n������� ����� �� ����������, ���������� �����\n";
//			continue;
//		}
//		break;
//	}
//	_G = new int* [len];
//	for (int i = 0; i < len; i++) {
//		_G[i] = new int[len];
//	}
//	c = 0;
//	for (int i = 0; i <= len; i++) {
//		r = 0;
//		for (int j = 0; j <= len; j++) {
//			if (i == (n - 1) || i == (m - 1)) { c--; break; }
//			if (j == (n - 1) || j == (m - 1)) continue;
//			_G[c][r] = G1[i][j];
//			r++;
//		}
//		c++;
//	}
//	for (int i = 0; i < len; i++) {
//		_G[len - 1][i] = G1[n - 1][i] + G1[m - 1][i];
//		if (_G[len - 1][i] == 2) _G[len - 1][i]--;
//		_G[i][len - 1] = _G[len - 1][i];
//	}
//	_G[len - 1][len - 1] = 0;
//	for (int i = 0; i < len; i++) {
//		for (int j = 0; j < len; j++) {
//			cout << _G[i][j] << " ";
//		}
//		cout << "\n";
//	}
//	for (int i = 0; i < len; i++) {
//		delete _G[i];
//	}
//	delete _G;
//	cout << "\n�������� �������\n\n������� �������: ";
//	cin >> n;
//	_G = new int* [len];
//	for (int i = 0; i < len; i++) {
//		_G[i] = new int[len];
//	}
//	c = 0;
//	for (int i = 0; i <= len; i++) {
//		r = 0;
//		for (int j = 0; j <= len; j++) {
//			if (i == (n - 1)) { c--; break; }
//			if (j == (n - 1)) continue;
//			_G[c][r] = G1[i][j];
//			r++;
//		}
//		c++;
//	}
//	for (int i = 0; i < len; i++) {
//		for (int j = 0; j < len; j++) {
//			cout << _G[i][j] << " ";
//		}
//		cout << "\n";
//	}
//	return 0;
//}