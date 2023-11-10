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
stack<int> s;

struct spisok_soed {
	int vershina;
	struct spisok_soed* next;
};

struct spisok_soed* creation_element(int nomber) {

	struct spisok_soed* p = NULL;

	if ((p = (spisok_soed*)malloc(sizeof(struct spisok_soed))) == NULL) // выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}

	p->vershina = nomber;
	p->next = NULL;

	return p;


}

struct spisok_soed* spis;

void creation_spisok(int** M, int size) {
	struct spisok_soed* q, * save = NULL;
	for (int i = 0; i < size; i++) {
		spis[i].next = NULL;
		spis[i].vershina = i;
		for (int j = 0; j < size; j++) {
			if (M[i][j] == 1) {
				q = creation_element(j);

				if (spis[i].next == NULL) {
					spis[i].next = q;
					save = q;
				}
				else {
					save->next = q;
					save = q;
				}
			}
		}
	}
}

void review(int size) {
	struct spisok_soed* save;
	cout << "\n";
	for (int i = 0; i < size; i++) {
		save = spis[i].next;
		cout << "[" << spis[i].vershina << "]";
		while (save != NULL) {
			cout << " -> " << save->vershina;
			save = save->next;
		}
		cout << "\n";
	}
	cout << "\n";

}




void BFSD(int** G, int v, int* DIST, int size) {
	Q.push(v);
	DIST[v] = 0;
	while (!Q.empty()) {
		v = Q.front();
		Q.pop();
		for (int i = 0; i < size; i++) {
			if (G[v][i] == 1 && DIST[i] == -1) {
				Q.push(i);
				DIST[i] = DIST[v] + 1;
			}

		}
	}
}

void DFSD(int** G, int v, int* DIST, int size) {

	DIST[v] = 0;
	s.push(v);
	while (!s.empty()) {
		v = s.top();
		s.pop();
		for (int i = size; i > 0; i--) {
			if (G[v][i] == 1 && DIST[i] == -1) {
				s.push(i);
				DIST[i] = DIST[v] + 1;
			}
		}

	}

}

void BFSD_spisok(int v, int* DIST, int size) {
	struct spisok_soed* save;
	Q.push(v);
	DIST[v] = 0;
	while (!Q.empty()) {
		v = Q.front();
		Q.pop();
		save = spis[v].next;
		for (; save != NULL; save = save->next) {
			if (DIST[save->vershina] == -1) {
				Q.push(save->vershina);
				DIST[save->vershina] = DIST[v] + 1;
			}

		}
	}
}

void DFSD_spisok(int v, int* DIST, int size) {
	struct spisok_soed* save;
	DIST[v] = 0;
	s.push(v);
	while (!s.empty()) {
		v = s.top();
		s.pop();
		save = spis[v].next;
		for (; save != NULL; save = save->next) {
			if (DIST[save->vershina] == -1) {
				s.push(save->vershina);
				DIST[save->vershina] = DIST[v] + 1;
			}
		}
	}
}


void POSH(int* DIST, int size, int** G, int v, int vibor) {
	cout << "\n";
	for (int i = 0; i < size; i++) {
		DIST[i] = -1;
	}
	switch (vibor) {
	case(0):
		cout << " Поиск расстояний в графе:\n \n Обход в ширину: \n Матрица смежности: ";
		BFSD(G, v, DIST, size);
		break;
	case(1):
		cout << " Список смежности:  ";
		BFSD_spisok(v, DIST, size);
		break;
	case(2):
		cout << " \n Обход в глубину: \n Матрица смежности: ";
		DFSD(G, v, DIST, size);
		break;
	case(3):
		cout << " Список смежности:  ";
		DFSD_spisok(v, DIST, size);
		break;

	default:
		cout << "!ОШИБКА!";
	}

	for (int i = 0; i < size; i++) {
		cout << DIST[i] << " ";
	}

}

void POSH_time(int* DIST, int size, int** G, int v, int vibor) {
	clock_t start, end;

	for (int i = 0; i < size; i++) {
		DIST[i] = -1;
	}
	switch (vibor) {
	case(0):
		start = clock();
		BFSD(G, v, DIST, size);
		end = clock();
		printf("|%5d|%.3f", size, (double)(end - start) / CLOCKS_PER_SEC);
		break;
	case(1):
		start = clock();
		BFSD_spisok(v, DIST, size);
		end = clock();
		printf("|%.3f|", (double)(end - start) / CLOCKS_PER_SEC);
		break;
	case(2):
		start = clock();
		DFSD(G, v, DIST, size);
		end = clock();
		printf("%.3f|", (double)(end - start) / CLOCKS_PER_SEC);
		break;
	case(3):
		start = clock();
		DFSD_spisok(v, DIST, size);
		end = clock();
		printf("%.3f|", (double)(end - start) / CLOCKS_PER_SEC);
		break;

	default:
		cout << "!ОШИБКА!";
	}
}



int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int** G, size, vershina, * DIST, v;

	cout << " \n Введите количество вершин графа: ";
	cin >> size;

	spis = new struct spisok_soed[size];
	G = new int* [size]; // создаём двумерный массив 
	DIST = new int[size];
	for (int i = 0; i < size; i++) {
		G[i] = new int[size];
	}


	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if (i == j) { G[i][j] = 0; }
			else {
				G[i][j] = rand() % 2;
				G[j][i] = G[i][j];
			}
		}

	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << G[i][j] << " ";
		}
		cout << "\n";
	}

	creation_spisok(G, size);
	review(size);

	cout << "Введите исходную вершину: ";
	cin >> v;
	POSH(DIST, size, G, v, 0);
	POSH(DIST, size, G, v, 1);
	POSH(DIST, size, G, v, 2);
	POSH(DIST, size, G, v, 3);

	cout << "\n\n";
	cout << "| size| BFSD|BFSDs|DFSD| DFSDs|\n-------------------------------\n";
	for (size = 10; size < 10001; size = size * 10) {
		spis = new struct spisok_soed[size];
		G = new int* [size]; // создаём двумерный массив 
		DIST = new int[size];
		for (int i = 0; i < size; i++) {
			G[i] = new int[size];
		}


		for (int i = 0; i < size; i++) {
			for (int j = i; j < size; j++) {
				if (i == j) { G[i][j] = 0; }
				else {
					G[i][j] = rand() % 2;
					G[j][i] = G[i][j];
				}
			}

		}

		creation_spisok(G, size);

		POSH_time(DIST, size, G, 0, 0);
		POSH_time(DIST, size, G, 0, 1);
		POSH_time(DIST, size, G, 0, 2);
		POSH_time(DIST, size, G, 0, 3);
		cout << "\n";
	}


	system("pause");
	return 0;
}
