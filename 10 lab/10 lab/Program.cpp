#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<time.h>
#include<stack>
#include <queue>
#include<Windows.h>
using namespace std;

queue<int> Q;
/*
1 - взыешенный ориентированный
2 - взыешенный неориентированный
3 - невзыешенный ориентированный
4 - невзыешенный неориентированный
*/

void BFSD(int** G, int v, int* DIST, int size) {
	Q.push(v);
	DIST[v] = 0;
	while (!Q.empty()) {
		v = Q.front();
		Q.pop();
		for (int i = 0; i < size; i++) {
			if (G[v][i] > 0 && DIST[i] == -1) {
				Q.push(i);
				DIST[i] = DIST[v] + G[v][i];
			}
		}
	}
}
void POSH2(int* DIST, int size, int** G, int v) {
	for (int i = 0; i < size; i++) {
		DIST[i] = -1;
	}
	BFSD(G, v, DIST, size);
}
void POSH(int* DIST, int size, int** G, int v) {
	cout << "\n";
	for (int i = 0; i < size; i++) {
		DIST[i] = -1;
	}

	cout << " Поиск расстояний в графе:\n \n Обход в ширину: \n Матрица смежности: ";
	BFSD(G, v, DIST, size);


	for (int i = 0; i < size; i++) {
		cout << DIST[i] << " ";
	}




}



int main(int argc) {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int** G,size= 5, vershina, * DIST, * RAD, v, who;

	//cout << " \n Введите количество вершин графа: ";
	//cin >> size;


	G = new int* [size]; // создаём двумерный массив 
	DIST = new int[size];
	RAD = new int[size];
	for (int i = 0; i < size; i++) {
		DIST[i] = -1;
		G[i] = new int[size];
	}
	/*cout << "Выберите какой граф вы хотите:\n1) Ориентированный\n2) Неориентированный\n";
	cin >> who;*/
	switch (argc) {
	case(1):
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i == j) { G[i][j] = 0; }
				else {
					G[i][j] = rand() % 2;
					if (G[i][j] == 1) {
						G[i][j] = rand() % 9;
					}
				}
			}
		}
		break;
	case(2):
		for (int i = 0; i < size; i++) {
			for (int j = i; j < size; j++) {
				if (i == j) { G[i][j] = 0; }
				else {
					G[i][j] = rand() % 2;
					if (G[i][j] == 1) {
						G[i][j] = rand() % 9;
					}
					G[j][i] = G[i][j];
				}
			}
		}
		break;
	case(3):
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i == j) { G[i][j] = 0; }
				else {
					G[i][j] = rand() % 2;
				}
			}
		}
		break;
	case(4):
		for (int i = 0; i < size; i++) {
			for (int j = i; j < size; j++) {
				if (i == j) { G[i][j] = 0; }
				else {
					G[i][j] = rand() % 2;
					G[j][i] = G[i][j];
				}
			}
		}
		break;
	default:
		cout << "!ОШИБКА!";
	}




	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << G[i][j] << " ";
		}
		cout << "\n";
	}
	/*cout << "Выберите с какой вершины хотите начать\n";
	cin >> v;
	POSH(DIST, size, G, v);*/

	int rad = 0, diam = 0, mid, per;
	for (int i = 0; i < size; i++) {
		POSH(DIST, size, G, i);
		for (int j = 0; j < size; j++) {
			if (DIST[j] > RAD[i]) {
				RAD[i] = DIST[j];
			}
		}
		if (rad == 0) {
			rad = RAD[i];
		}
		if (rad > RAD[i]) {
			rad = RAD[i];
		}
		if (diam < RAD[i]) {
			diam = RAD[i];
		}
	}

	for (int i = 0; i < size; i++) {
		POSH2(DIST, size, G, i);
		for (int j = 0; j < size; j++) {
			if (DIST[j] == rad) {
				cout << "\n" << j + 1 << " вершина центральная";
			}
			if (DIST[j] == diam) {
				cout << "\n" << j + 1 << " вершина переферийная";
			}
		}
	}

	cout << "\nРадиус = " << rad << "\nДеаметр = " << diam << "\n";

	system("pause");
	return 0;
}
