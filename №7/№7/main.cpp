#include <iostream>
#include <stack>
#include <conio.h>
#include <Windows.h>

#include "Data.h"
#include "Input.h"
#include "Algorithm.h"

using namespace std;

int startMenu();

void show(iterable_stack<Student> stack);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	iterable_stack<Student> stack;
	Student obj;
	Algorithm<Student> alg;
	bool flag = true;
	while (flag) {
		switch (startMenu())
		{
		case 0:
			cin >> obj;
			stack.push(obj);
			break;
		case 1:
			if (stack.empty()) {
				cout << "Стек пуст!" << endl;
				break;
			}
			
			show(stack);
			break;
		case 2:
			if (stack.empty()) {
				cout << "Стек пуст!" << endl;
				break;
			}

			alg.sortFIO(stack);
			show(stack);
			break;
		case 3:
			if (stack.empty()) {
				cout << "Стек пуст!" << endl;
				break;
			}

			alg.clear(stack);
			cout << "Стек очищен!" << endl;
			break;
		case 4:
			if (stack.empty()) {
				cout << "Стек пуст!" << endl;
				break;
			}

			alg.checkGroup(stack);
			break;
		case 5:
			if (stack.empty()) {
				cout << "Стек пуст!" << endl;
				break;
			}

			alg.checkBal(stack);
			break;
		case 6:
			if (stack.empty()) {
				cout << "Стек пуст!" << endl;
				break;
			}

			alg.copyGroup(stack);
			break;
		case 7:
			if (stack.empty()) {
			cout << "Стек пуст!" << endl;
			break;
			}

			alg.copyBal(stack);
			break;
		case 8:
			if (stack.empty()) {
				cout << "Стек пуст!" << endl;
				break;
			}
			alg.edit(stack);
			break;
		case 9:
			if (stack.empty()) {
				cout << "Стек пуст!" << endl;
				break;
			}
			alg.del(stack);
			break;
		case 10:
			alg.searchGroup(stack);
			break;
		case 11:
			alg.searchFIO(stack);
			break;
		case 12:
			alg.task1(stack);
			break;
		case 13:
			alg.task2(stack);
			break;
		case 14:
			flag = false;
			break;
		}
		system("pause");
		system("cls");
	}
	return 1;
}

void show(iterable_stack<Student> stack) {
	int num = 1;
	for (iterable_stack<Student>::iterator it = stack.begin(); it != stack.end(); ++it) {
		cout<< "№" << num <<": " << *it << endl;
		num++;
	}
}

int startMenu()
{
	int ViborPunkta = 0, strelka = 0;
	while (true) {
		cout << "ВЫБЕРИТЕ ПУНКТ МЕНЮ" << endl;
		ViborPunkta = (ViborPunkta + 15) % 15;
		if (ViborPunkta == 0) cout << "->Добавить запись" << endl;
		else cout << " Добавить запись" << endl;

		if (ViborPunkta == 1) cout << "->Просмотр" << endl;
		else cout << " Просмотр" << endl;

		if (ViborPunkta == 2) cout << "->Сортировка" << endl;
		else cout << " Сортировка" << endl;

		if (ViborPunkta == 3) cout << "->Очистить стек" << endl;
		else cout << " Очистить стек" << endl;
		
		if (ViborPunkta == 4) cout << "->Проверка условия(группа)" << endl;
		else cout << " Проверка условия(группа)" << endl;

		if (ViborPunkta == 5) cout << "->Проверка условия(ср.балл)" << endl;
		else cout << " Проверка условия(ср.балл)" << endl;
	
		if (ViborPunkta == 6) cout << "->Копирование множества(группа)" << endl;
		else cout << " Копирование множества(группа)" << endl;

		if (ViborPunkta == 7) cout << "->Копирование множества(ср.балл)" << endl;
		else cout << " Копирование множества(ср.балл)" << endl;

		if (ViborPunkta == 8) cout << "->Редактирование" << endl;
		else cout << " Редактирование" << endl;

		if (ViborPunkta == 9) cout << "->Удаление элемента" << endl;
		else cout << " Удаление элемента" << endl;

		if (ViborPunkta == 10) cout << "->Поиск по группе" << endl;
		else cout << " Поиск по группе" << endl;

		if (ViborPunkta == 11) cout << "->Поиск по ФИО" << endl;
		else cout << " Поиск по ФИО" << endl;

		if (ViborPunkta == 12) cout << "->Запрос 1" << endl;
		else cout << " Запрос 1" << endl;

		if (ViborPunkta == 13) cout << "->Запрос 2" << endl;
		else cout << " Запрос 2" << endl;

		if (ViborPunkta == 14) cout << "->Закрыть программу" << endl;
		else cout << " Закрыть программу" << endl;

		

		strelka = _getch();
		if (strelka == 119) {
			ViborPunkta--;
		}
		if (strelka == 115) {
			ViborPunkta++;
		}
		if (strelka == 224)
		{
			strelka = _getch();
			if (strelka == 72) ViborPunkta--;
			if (strelka == 80) ViborPunkta++;
		}
		if (strelka == 13)
		{
			system("cls");
			return ViborPunkta;
		}
		system("cls");
	}
}

int menuUpdateData(iterable_stack<Student>::iterator it)
{
	int ViborPunkta = 0, strelka = 0;
	while (true) {
		ViborPunkta = (ViborPunkta + 5) % 5;
		cout << "ВЫБЕРИТЕ ЧТО ИЗМЕНИТЬ" << endl;
		if (ViborPunkta == 0)
			cout << "->ФИО: " << (*it).getFIO() << endl;
		else
			cout << " ФИО: " << (*it).getFIO() << endl;

		if (ViborPunkta == 1)
			cout << "->Группа: " << (*it).getGroup() << endl;
		else
			cout << " Группа: " << (*it).getGroup() << endl;

		if (ViborPunkta == 2) {
			cout << "->Оценки за экзамены: ";
			(*it).showExam();
			cout << endl;
		}
		else
		{
			cout << " Оценки за экзамены: ";
			(*it).showExam();
			cout << endl;
		}

		if (ViborPunkta == 3) {
			cout << "->Результаты зачетов: ";
			(*it).showCredit();
			cout << endl;
		}
		else
		{
			cout << " Результаты зачетов: ";
			(*it).showCredit();
			cout << endl;
		}

		if (ViborPunkta == 4)
			cout << "->Выход" << endl;
		else
			cout << " Выход" << endl;

		strelka = _getch();

		if (strelka == 224 )
		{
			strelka = _getch();
			if (strelka == 72) ViborPunkta--;
			if (strelka == 80) ViborPunkta++;
		}
		if (strelka == 13)
		{
			system("cls");
			return ViborPunkta;
		}
		system("cls");
	}
}