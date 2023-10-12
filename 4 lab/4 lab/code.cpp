#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<time.h>
#include<Windows.h>

using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};


struct Node* CreateTree(struct Node* root, struct Node* r, int data)
{
	if (r == NULL)
	{
		r = (struct Node*)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			printf("Ошибка выделения памяти");
			exit(0);
		}

		r->left = NULL;
		r->right = NULL;
		r->data = data;
		if (root == NULL) return r;

		if (data > root->data)	root->left = r;
		else root->right = r;
		return r;
	}

	if (data > r->data)
		CreateTree(r, r->left, data);
	else
		CreateTree(r, r->right, data);

	return root;
}
struct Node* CreateTree2(struct Node* root, struct Node* r, int data)
{
	if (r == NULL)
	{
		r = (struct Node*)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			printf("Ошибка выделения памяти");
			exit(0);
		}

		r->left = NULL;
		r->right = NULL;
		r->data = data;
		if (root == NULL) return r;

		if (data > root->data)	root->left = r;
		else root->right = r;
		return r;
	}
	if (data == r->data) {
		cout << "Число не может быть введено\n";
		return root;
	}
	if (data > r->data)
		CreateTree2(r, r->left, data);
	else
		CreateTree2(r, r->right, data);

	return root;
}



void print_tree(struct Node* r, int l)
{

	if (r == NULL)
	{
		return;
	}

	print_tree(r->right, l + 1);
	for (int i = 0; i < l; i++)
	{
		printf(" ");
	}

	printf("%d\n", r->data);
	print_tree(r->left, l + 1);
}

int search(struct Node* r, int l,int c) {

	if (r==NULL){
		return c;
	}
	if (l == r->data) {
		c++;
		search(r->right, l,c);
	}
	else if (r->data > l) {
		search(r->right, l,c);
	}
	else if (r->data < l) {
		search(r->left, l,c);
	}
	
}

void search2(struct Node* r, int l) {
	if (r == NULL) {
		cout << "Число не найдено\n";
		return;
	}
	if (l == r->data) {
		cout << "Число найдено\n";
		return;
	}
	else if (r->data > l) {
		search2(r->right, l);
	}
	else if (r->data < l) {
		search2(r->left, l);
	}

}


	int main()
	{
		setlocale(LC_ALL, "RUS");
		int D, start = 1, poisk;
		struct Node* root;
		int vv;
		root = NULL;
		int vibor;
		cout << "Здравствуйте, выберите, как ходите заполнить бинарное дерево:\n1)C повторениями\n2)Без повторений\n";
		cin >> vibor;
		printf("Введите -1 для окончания построения дерева\n");
		switch (vibor) {
		case 1:
			while (start)
			{
				printf("Введите число: ");
				scanf_s("%d", &D);
				if (D == -1)
				{
					printf("Построение дерева окончено\n\n");
					start = 0;
				}
				else
					root = CreateTree(root, root, D);

			}
			cout << "Какое число вы хотите найти: \n";
			cin >> poisk;
			vv = search(root, poisk, 0);
			cout << "Число " << poisk << " входит в дерево " << vv << " раз.\n";
			print_tree(root, 0);

			
			break;
			
		case 2:
			while (start)
			{
				printf("Введите число: ");
				scanf_s("%d", &D);
				if (D == -1)
				{
					printf("Построение дерева окончено\n\n");
					start = 0;
				}
				else
					root = CreateTree2(root, root, D);

			}
			cout << "Какое число вы хотите найти: \n";
			cin >> poisk;
			search2(root, poisk);
			
			print_tree(root, 0);

			break;
		default:
			cout << "Неверный вариант.";
		}
		return 0;
	}
