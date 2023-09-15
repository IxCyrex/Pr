#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#include<iostream>
#include<string>

using namespace std;

struct student {
	string name, famil, facult, Nomstud;
}stud[5];

int main() {

	srand(time(NULL));

	setlocale(LC_ALL, "Rus");
	string namepoisk, familpoisk, facultpoisk, Nomstudpoisk;

	int v = 0;
	while (v != 1 && v != 2) {
		cout << "Выберите:\n1 - работа с массивом\n2 - работа со структурой\n";
		cin >> v;
	}
	if (v == 1) { // Задание 1-4
		int size1 = 0, size2 = 0;
		float** mas;
		while (size1 < 1) {
			cout << "Введите число столбцов: ";
			cin >> size1;
		}
		while (size2 < 1) {
			cout << "Введите число строк: ";
			cin >> size2;
		}
		mas = new float* [size1]; // создаём двумерный массив 
		for (int i = 0; i < size1; i++) {
			mas[i] = new float[size2];
		}

		float max, min;
		cout << "Выберите, как вводить массив:\n1 - заполнить массив рандомными числами \n2 - заполнить вручную \n";
		int vibor;
		cin >> vibor;
		if (vibor == 1) { // заполняем массив случайными числами 
			for (int i = 0; i < size1; i++) {
				for (int o = 0; o < size2; o++) {
					mas[i][o] = (rand() % 100 - 50) * 0.1;
					cout << mas[i][o] << " ";
				}
				cout << "\n";
			}

		}
		else if (vibor == 2) { // заполняем массив в ручную 
			for (int i = 0; i < size1; i++) {
				for (int o = 0; o < size2; o++) {
					cout << "Введите число : ";
					cin >> mas[i][o];
				}
				cout << "\n";
			}
			for (int i = 0; i < size1; i++) { // выводим заполненный массив
				for (int o = 0; o < size2; o++) {
					cout << mas[i][o] << " ";
				}
				cout << "\n";
			}
		}

		max = mas[0][0];
		min = mas[0][0];
		float sum;

		float di1 = 0, di2 = 0;
		if (size1 == size2) {
			for (int i = 0; i < size1; i++) {
				di1 += mas[i][i];
				di2 += mas[i][size1 - i - 1];
			}
			cout << "Первая диагональ: " << di1 << "\n";
			cout << "Вторая диагональ: " << di2 << "\n";
		}
		else { cout << "Матрица не квадратная"; }

		for (int i = 0; i < size1; i++) {
			sum = 0;
			for (int o = 0; o < size2; o++) {
				sum = sum + mas[i][o]; // считаем сумму чисел в строке 
				if (max < mas[i][o]) max = mas[i][o]; // ищём макс и мин число 
				if (min > mas[i][o]) min = mas[i][o];
			}
			cout << "\n Сумма чисел " << i + 1 << " строки: " << sum << "\n";
		}
		cout << "min = " << min << "\nmax = " << max << "\nРазность = " << max - min << "\n";
	}
	else { // задание 5
		v = 0;
		while (v != 1 && v != 2) {
			cout << "Выберите:\n1 - заполнить самому\n2 - заполнить програмно\n";
			cin >> v;
		}
		if (v == 1) { // заполнение элементов структуры вручную 
			for (int i = 0; i < 5; i++) {
				cout << "Введите имя " << i + 1 << " студента : ";
				cin >> stud[i].name;
				cout << "Введите фамилию " << i + 1 << " студента : ";
				cin >> stud[i].famil;
				cout << "Введите факультет " << i + 1 << " студента : ";
				cin >> stud[i].facult;
				cout << "Введите номер " << i + 1 << " студента : ";
				cin >> stud[i].Nomstud;
				cout << "\n";
			}
		}
		else { //  заполнение элементов структуры в программе 
			stud[0].name = "Ярослав";
			stud[0].famil = "Китаев";
			stud[0].facult = "Фвт";
			stud[0].Nomstud = "7734";

			stud[1].name = "Иван";
			stud[1].famil = "Петрович";
			stud[1].facult = "Фите";
			stud[1].Nomstud = "7389";

			stud[2].name = "Иван";
			stud[2].famil = "Колокольчиков";
			stud[2].facult = "Фвт";
			stud[2].Nomstud = "0654";

			stud[3].name = "Алексей";
			stud[3].famil = "Аргаткин";
			stud[3].facult = "Фвт";
			stud[3].Nomstud = "23";

			stud[4].name = "Дмитрий";
			stud[4].famil = "Новгородцев";
			stud[4].facult = "ВППСН";
			stud[4].Nomstud = "666";

		}
		for (int i = 0; i < 5; i++) { // выводим заполненные данные 
			cout << i + 1 << " студент : \n";
			cout << "Имя :" << stud[i].name << "\n";
			cout << "Фамилия :" << stud[i].famil << "\n";
			cout << "Факульет :" << stud[i].facult << "\n";
			cout << "Номер :" << stud[i].Nomstud << "\n";
			cout << "\n";
		}
		// вводим параметры для поиска студента 
		cout << " Поиск студента (если параметр не нужен введите '-') : \n Введите имя : ";
		cin >> namepoisk;
		cout << " Введите фамилию : ";
		cin >> familpoisk;
		cout << " Введите факультет : ";
		cin >> facultpoisk;
		cout << " Введите номер студента : ";
		cin >> Nomstudpoisk;
		int shet = 0;
		string none = "-";

		for (int i = 0; i < 5; i++) { // осуществляем поиск студента по введённым выше параметрам 
			shet = 0;
			if (stud[i].name == namepoisk || namepoisk == none) {
				shet++;
			}
			if (stud[i].famil == familpoisk || familpoisk == none) {
				shet++;
			}
			if (stud[i].facult == facultpoisk || facultpoisk == none) {
				shet++;
			}
			if (stud[i].Nomstud == Nomstudpoisk || Nomstudpoisk == none) {
				shet++;
			}
			if (shet == 4) {
				cout << "\nИмя :" << stud[i].name << "\n";
				cout << "Фамилия :" << stud[i].famil << "\n";
				cout << "Факульет :" << stud[i].facult << "\n";
				cout << "Номер :" << stud[i].Nomstud << "\n";

			}


		}

	}
	system("pause");
	return 0;
}