#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<string>
#include<Windows.h>


using namespace std;

struct priority_queue
{
	string data[10];  // полезная информация
	int den, mauns, colvo_elem_str;
	struct priority_queue* next; // ссылка на следующий элемент 
};

struct struck_ochered
{
	char data[256];  // полезная информация
	struct struck_ochered* next; // ссылка на следующий элемент 
};

struct priority_queue* head = NULL, * last = NULL; // указатели на первый и последний элементы списка
struct struck_ochered* head_ochered = NULL, * last_ochered = NULL;
int dlinna_ochered_stek = 0;

struct struck_ochered* get_ochered(void)
{
	struct struck_ochered* p = NULL;
	char s[256];
	if ((p = (struck_ochered*)malloc(sizeof(struct struck_ochered))) == NULL)  // выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}

	printf("Введите название объекта: \n");   // вводим данные
	scanf("%s", &s);
	if (s == 0)
	{
		printf("Запись не была произведена\n");
		return NULL;
	}
	strcpy(p->data, s);


	p->next = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

void  review_stek(int razmer)
{
	struct struck_ochered* head_struc = head_ochered, * last_struc = head_ochered;
	if (head_ochered == NULL)
	{
		printf("Список пуст\n");
	}
	for (int i = 0; i < razmer; i++) {
		head_struc = head_ochered;
		printf("Имя - %s \n", head_ochered->data);
		head_ochered = head_ochered->next;
		delete head_struc;
	}
	return;
}
+


struct priority_queue* get_struct(void); // функция создания элемента
void review(void);

void input_po_priority() {
	int prior;
	struct priority_queue* q, * f = NULL;
	q = get_struct();


	if (head == NULL || (head->mauns > q->mauns && head->den > q->den)) {
		q->next = head;
		head = q;
	}
	else {
		f = head;
		while (f->next != NULL && (f->next->mauns < q->mauns || (f->next->mauns != q->mauns && f->next->den < q->den))) {
			f = f->next;
		}

		if (f->next == NULL) {
			f->next = q;
		}
		else {
			q->next = f->next;
			f->next = q;
		}
	}

}

void ochered_stek(void) {
	struct struck_ochered* q, * f = NULL;
	q = get_ochered();
	if (head_ochered == NULL) {
		head_ochered = q;
		last_ochered = q;
	}
	else {
		q->next = head_ochered;
		head_ochered = q;
	}
}

void review_ochered(int razmer)
{
	struct struck_ochered* head_struc = head_ochered, * last_struc = last_ochered;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	for (int i = 0; i < razmer; i++) {

		printf("Имя - %s \n", last_struc->data);
		if (head_struc != last_struc) {
			while (head_struc->next != last_struc) {
				head_struc = head_struc->next;
			}
			delete last_struc;
			last_struc = head_struc;
			head_struc = head_ochered;
		}

	}
	last_ochered = last_struc;

	return;

}

int main() {
	setlocale(LC_ALL, "Rus");

	int colvo_elem, vibor, vibor1 = 0;

	printf("1. Список с приоритетом \n2. Очередь \n3. Стек\n");
	printf("Выберите действие: ");
	scanf("%d", &vibor);

	// Обработка выбора пользователя
	switch (vibor) {
	case 1:
		cout << "Введите количество елементов в очереди: ";
		cin >> colvo_elem;
		for (int i = 0; i < colvo_elem; i++) {
			input_po_priority();
		}
		review();
		break;
	case 2:
		while (vibor1 >= 0) {
			printf("1. Добавить элемент \n2. Вывести и удалить элемент\n3. Закончить программу\n");
			printf("Выберите действие: ");
			scanf("%d", &vibor1);
			while (dlinna_ochered_stek == 0 && vibor1 == 2)
			{
				cout << "Список пуст! Удалять нечего\n1. Добавить элемент \n3. Закончить программу\nВыберите действие: ";
				cin >> vibor1;
			}
			switch (vibor1) {
			case 1:
				cout << "Сколько элементов вы хотите добавить: ";
				cin >> colvo_elem;
				while (colvo_elem <= 0)
				{
					cout << "Список не может существовать\n Попробуйте ещё раз: ";
					cin >> colvo_elem;
				}
				dlinna_ochered_stek += colvo_elem;
				for (int i = 0; i < colvo_elem; i++) {
					ochered_stek();
				}
				break;
			case 2:
				cout << "Сколько элементов вы хотите вывести на экран и удалить: ";
				cin >> colvo_elem;
				while (colvo_elem > dlinna_ochered_stek)
				{
					cout << "В очереди нет столько элементов.\n Попробуйте ещё раз : ";
					cin >> colvo_elem;
				}
				dlinna_ochered_stek -= colvo_elem;
				review_ochered(colvo_elem);

				break;
			case 3:
				vibor1 = -1;
				break;
			default:
				printf("Ошибка. Попробуйте снова.\n");
			}
		}
		break;
	case 3:
		while (vibor1 >= 0) {
			printf("1. Добавить элемент \n2. Вывести и удалить элемент\n3. Закончить программу\n");
			printf("Выберите действие: ");
			scanf("%d", &vibor1);
			while (dlinna_ochered_stek == 0 && vibor1 == 2)
			{
				cout << "Список пуст! Удалять нечего\n1. Добавить элемент \n3. Закончить программу\nВыберите действие: ";
				cin >> vibor1;
			}
			switch (vibor1) {
			case 1:
				cout << "Сколько элементов вы хотите добавить: ";
				cin >> colvo_elem;
				while (colvo_elem <= 0)
				{
					cout << "Список не может существовать\n Попробуйте ещё раз: ";
					cin >> colvo_elem;
				}
				dlinna_ochered_stek += colvo_elem;
				for (int i = 0; i < colvo_elem; i++) {
					ochered_stek();
				}
				break;
			case 2:
				cout << "Сколько элементов вы хотите вывести на экран и удалить: ";
				cin >> colvo_elem;
				while (colvo_elem > dlinna_ochered_stek)
				{
					cout << "В очереди нет столько элементов.\n Попробуйте ещё раз : ";
					cin >> colvo_elem;
				}
				dlinna_ochered_stek -= colvo_elem;
				review_stek(colvo_elem);

				break;
			case 3:
				vibor1 = -1;
				break;
			default:
				printf("Ошибка. Попробуйте снова.\n");
			}
		}

		break;
	default:
		printf("Ошибка. Попробуйте снова.\n");
	}
	system("pause");
}

struct priority_queue* get_struct(void)
{
	struct priority_queue* p = NULL;
	float dat;
	int colvo_predmetov;
	if ((p = (priority_queue*)malloc(sizeof(struct priority_queue))) == NULL)  // выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}
	printf("Введите дату (формат 31.12): ");   // вводим данные
	scanf("%f", &dat);
	p->den = dat;
	p->mauns = (dat - p->den) * 10;
	while (p->den > 31 || p->mauns > 12) {
		printf("Такой даты существовать не может\n Введите другую дату: ");   // вводим данные
		scanf("%f", &dat);
		p->den = dat;
		p->mauns = (dat - p->den) * 10;
	}

	printf("Сколько предметов вы хотите добавить в расписание: \n");   // вводим данные
	cin >> colvo_predmetov;
	p->colvo_elem_str = colvo_predmetov;
	for (int i = 0; i < colvo_predmetov; i++) {
		cin >> p->data[i];
	}

	p->next = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

void review(void)
{
	int size;
	struct priority_queue* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	cout << " Расписание на сколько дней вы хотите узнать? :";
	cin >> size;
	for (int i = 0; i < size; i++) {
		struc = head;
		cout << struc->den << "." << struc->mauns << "\n";
		for (int j = 0; j < struc->colvo_elem_str; j++) {
			cout << j + 1 << struc->data[j] << "\n";
		}
		head = head->next;
		delete struc;
	}
	return;

}
