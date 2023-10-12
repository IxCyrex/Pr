#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<string>
#include<Windows.h>


using namespace std;

struct priority_queue
{
	string data[10];  // �������� ����������
	int den, mauns, colvo_elem_str;
	struct priority_queue* next; // ������ �� ��������� ������� 
};

struct struck_ochered
{
	char data[256];  // �������� ����������
	struct struck_ochered* next; // ������ �� ��������� ������� 
};

struct priority_queue* head = NULL, * last = NULL; // ��������� �� ������ � ��������� �������� ������
struct struck_ochered* head_ochered = NULL, * last_ochered = NULL;
int dlinna_ochered_stek = 0;

struct struck_ochered* get_ochered(void)
{
	struct struck_ochered* p = NULL;
	char s[256];
	if ((p = (struck_ochered*)malloc(sizeof(struct struck_ochered))) == NULL)  // �������� ������ ��� ����� ������� ������
	{
		printf("������ ��� ������������� ������\n");
		exit(1);
	}

	printf("������� �������� �������: \n");   // ������ ������
	scanf("%s", &s);
	if (s == 0)
	{
		printf("������ �� ���� �����������\n");
		return NULL;
	}
	strcpy(p->data, s);


	p->next = NULL;

	return p;		// ���������� ��������� �� ��������� �������
}

void  review_stek(int razmer)
{
	struct struck_ochered* head_struc = head_ochered, * last_struc = head_ochered;
	if (head_ochered == NULL)
	{
		printf("������ ����\n");
	}
	for (int i = 0; i < razmer; i++) {
		head_struc = head_ochered;
		printf("��� - %s \n", head_ochered->data);
		head_ochered = head_ochered->next;
		delete head_struc;
	}
	return;
}
+


struct priority_queue* get_struct(void); // ������� �������� ��������
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
		printf("������ ����\n");
	}
	for (int i = 0; i < razmer; i++) {

		printf("��� - %s \n", last_struc->data);
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

	printf("1. ������ � ����������� \n2. ������� \n3. ����\n");
	printf("�������� ��������: ");
	scanf("%d", &vibor);

	// ��������� ������ ������������
	switch (vibor) {
	case 1:
		cout << "������� ���������� ��������� � �������: ";
		cin >> colvo_elem;
		for (int i = 0; i < colvo_elem; i++) {
			input_po_priority();
		}
		review();
		break;
	case 2:
		while (vibor1 >= 0) {
			printf("1. �������� ������� \n2. ������� � ������� �������\n3. ��������� ���������\n");
			printf("�������� ��������: ");
			scanf("%d", &vibor1);
			while (dlinna_ochered_stek == 0 && vibor1 == 2)
			{
				cout << "������ ����! ������� ������\n1. �������� ������� \n3. ��������� ���������\n�������� ��������: ";
				cin >> vibor1;
			}
			switch (vibor1) {
			case 1:
				cout << "������� ��������� �� ������ ��������: ";
				cin >> colvo_elem;
				while (colvo_elem <= 0)
				{
					cout << "������ �� ����� ������������\n ���������� ��� ���: ";
					cin >> colvo_elem;
				}
				dlinna_ochered_stek += colvo_elem;
				for (int i = 0; i < colvo_elem; i++) {
					ochered_stek();
				}
				break;
			case 2:
				cout << "������� ��������� �� ������ ������� �� ����� � �������: ";
				cin >> colvo_elem;
				while (colvo_elem > dlinna_ochered_stek)
				{
					cout << "� ������� ��� ������� ���������.\n ���������� ��� ��� : ";
					cin >> colvo_elem;
				}
				dlinna_ochered_stek -= colvo_elem;
				review_ochered(colvo_elem);

				break;
			case 3:
				vibor1 = -1;
				break;
			default:
				printf("������. ���������� �����.\n");
			}
		}
		break;
	case 3:
		while (vibor1 >= 0) {
			printf("1. �������� ������� \n2. ������� � ������� �������\n3. ��������� ���������\n");
			printf("�������� ��������: ");
			scanf("%d", &vibor1);
			while (dlinna_ochered_stek == 0 && vibor1 == 2)
			{
				cout << "������ ����! ������� ������\n1. �������� ������� \n3. ��������� ���������\n�������� ��������: ";
				cin >> vibor1;
			}
			switch (vibor1) {
			case 1:
				cout << "������� ��������� �� ������ ��������: ";
				cin >> colvo_elem;
				while (colvo_elem <= 0)
				{
					cout << "������ �� ����� ������������\n ���������� ��� ���: ";
					cin >> colvo_elem;
				}
				dlinna_ochered_stek += colvo_elem;
				for (int i = 0; i < colvo_elem; i++) {
					ochered_stek();
				}
				break;
			case 2:
				cout << "������� ��������� �� ������ ������� �� ����� � �������: ";
				cin >> colvo_elem;
				while (colvo_elem > dlinna_ochered_stek)
				{
					cout << "� ������� ��� ������� ���������.\n ���������� ��� ��� : ";
					cin >> colvo_elem;
				}
				dlinna_ochered_stek -= colvo_elem;
				review_stek(colvo_elem);

				break;
			case 3:
				vibor1 = -1;
				break;
			default:
				printf("������. ���������� �����.\n");
			}
		}

		break;
	default:
		printf("������. ���������� �����.\n");
	}
	system("pause");
}

struct priority_queue* get_struct(void)
{
	struct priority_queue* p = NULL;
	float dat;
	int colvo_predmetov;
	if ((p = (priority_queue*)malloc(sizeof(struct priority_queue))) == NULL)  // �������� ������ ��� ����� ������� ������
	{
		printf("������ ��� ������������� ������\n");
		exit(1);
	}
	printf("������� ���� (������ 31.12): ");   // ������ ������
	scanf("%f", &dat);
	p->den = dat;
	p->mauns = (dat - p->den) * 10;
	while (p->den > 31 || p->mauns > 12) {
		printf("����� ���� ������������ �� �����\n ������� ������ ����: ");   // ������ ������
		scanf("%f", &dat);
		p->den = dat;
		p->mauns = (dat - p->den) * 10;
	}

	printf("������� ��������� �� ������ �������� � ����������: \n");   // ������ ������
	cin >> colvo_predmetov;
	p->colvo_elem_str = colvo_predmetov;
	for (int i = 0; i < colvo_predmetov; i++) {
		cin >> p->data[i];
	}

	p->next = NULL;

	return p;		// ���������� ��������� �� ��������� �������
}

void review(void)
{
	int size;
	struct priority_queue* struc = head;
	if (head == NULL)
	{
		printf("������ ����\n");
	}
	cout << " ���������� �� ������� ���� �� ������ ������? :";
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
