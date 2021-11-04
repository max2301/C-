#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "Container.h"
#include "Data.h"
#include "Input.h"
#include "Algorithm.h"
//
using namespace std;

int startMenu();
int MenuDel(string fio);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Ring<Student> ring;
	Student obj;
	Algorithm<Student> alg;
	Iterator<Student> it(ring);
	bool flag = true;
	int i;
	while (flag) {
		i = 1;
		switch (startMenu()) {
		case 0:
			cin >> obj;
			ring.push_front(obj);
			break;
		case 1: {
			cin >> obj;
			ring.push_back(obj);
			break;
		}
		case 2:
		{
			if (ring.isEmpty()) {
				cout << "Кольцо пустое!" << endl;
				break;
			}	
			Iterator<Student> End = it.End();
			do {		
				cout << *it << endl;	
				++it;
			} while (it != End);
			break;
		}
		case 3:
		{
			if (ring.isEmpty()) {
				cout << "Кольцо пустое!" << endl;
				break;
			}
			Iterator<Student> Begin = it.Begin();
		    do {			
				cout << *it << endl;
				--it;
			} while (it != Begin);
			break;
			break; 
		}
		case 4: {
			if (ring.isEmpty()) {
				cout << "Кольцо пустое!" << endl;
				break;
			}
			Iterator<Student> End = it.End();
			do {
				cout << *it << endl;
				++it;
			} while (it != End);

			cout << "Введите ФИО для удаления"<<endl;
			string fio;
			fio = inputFIO();
			system("cls");
			if (ring.search(fio) == NULL) {
				cout << "Данных по ФИО: " << fio << " нет!" << endl;
				break;
			}
			if (MenuDel(fio) == 1) {
				ring.DellEl(fio);
				system("cls");
				cout << "Данные удалены!" << endl;
			}
			else {
				break;
			}
			break;
		}
		case 5: 
		{
			if (ring.isEmpty()) {
				cout << "Кольцо пустое!" << endl;
				break;
			}
			Iterator<Student> Begin = it.Begin();
			Iterator<Student> End = it.End();
			alg.sortFIO(ring, Begin, End);
			cout << "Кольцо отсортировано!" << endl;
			break;
		}
		case 6:
			if (ring.isEmpty()) {
				cout << "Кольцо пустое!" << endl;
				break;
			}
			alg.sortGr(ring);
			cout << "Кольцо отсортировано!" << endl;
			break;
		/*case 7: {
			if (ring.isEmpty()) {
				cout << "Кольцо пустое!" << endl;
				break;
			}

			auto it = Ring<Student>::Iterator(ring.end());
			do {
				cout << *it << endl;
				++it;
			} while (it != ring.end());

			cout << "Введите ФИО для редактирования" << endl;
			string fio;
			fio = inputFIO();
			system("cls");
			if (ring.search(fio) == NULL) {
				cout << "Данных по ФИО: " << fio << " нет!" << endl;
				break;
			}
			Node<Student>* temp = ring.search(fio);
			int index = 3;
			switch (menuUpdateData(temp))
			{
			case 0:
				temp->value.changeFIO(inputFIO());
				break;
			case 1:
				temp->value.changeGroup(inputGroup());
				break;
			case 2:
				cout << "Оценки за экзамены:";
				temp->value.showExam();
				cout << endl;
				index = inputNum(5);
				temp->value.changeExam(index, inputExam(index - 1));
				break;
			case 3:
				cout << "Результаты зачетов:";
				temp->value.showCredit();
				cout << endl;
				index = inputNum(5);
				temp->value.changeCredit(index, inputCredit(index - 1));
				break;
			case 4:
				break;
			}
			break;
		}*/
		case 7:
			if (ring.isEmpty()) {
				cout << "Кольцо пустое!" << endl;
				break;
			}
			alg.checkGr(ring, it.Begin());
			break;
		case 8:
			if (ring.isEmpty()) {
				cout << "Кольцо пустое!" << endl;
				break;
			}
			alg.checkBal(ring, it.Begin());
			break;
		case 9:
			if (ring.isEmpty()) {
				cout << "Кольцо пустое!" << endl;
				break;
			}
			alg.copyGr(ring,it.Begin(), it.End());
			break;
		case 10:
			if (ring.isEmpty()) {
				cout << "Кольцо пустое!" << endl;
				break;
			}
			alg.copyBal(ring,it.Begin(), it.End());
			break;
		case 11: {
			if (ring.isEmpty()) {
				cout << "Кольцо пустое!" << endl;
				break;
			}
			int i = 1, num;
			Iterator<Student> End = it.End();
			do {
				cout << "№" << i << ": " << *it << endl;
				++it;
				++i;
			} while (it != End);

			cout << "Введите номер для редактирования" << endl;
			num = inputNum(ring.getSize());
			Node<Student>* temp = ring.getBegin();
			for (int i = 0; i < num; i++) {
					temp = temp->next;
			}
			
			system("cls");

			int index = 3;
			switch (menuUpdateData(temp))
			{
			case 0:
				temp->value.changeFIO(inputFIO());
				break;
			case 1:
				temp->value.changeGroup(inputGroup());
				break;
			case 2:
				cout << "Оценки за экзамены:";
				temp->value.showExam();
				cout << endl;
				index = inputNum(5);
				temp->value.changeExam(index, inputExam(index - 1));
				break;
			case 3:
				cout << "Результаты зачетов:";
				temp->value.showCredit();
				cout << endl;
				index = inputNum(5);
				temp->value.changeCredit(index, inputCredit(index - 1));
				break;
			case 4:
				break;
			}
			break;
		}
		case 12: {
			if (ring.isEmpty()) {
				cout << "Кольцо пустое!" << endl;
				break;
			}
			string gr;
			gr = inputGroup();
			Iterator<Student> temp = it.Begin();
			Ring<Student> data;
			int count = 0;
			do
			{
				Student tempdata = *temp;
				if (tempdata.getGroup() == gr) {
					data.push_back(tempdata);
					count++;
				}

				--temp;
			} while (temp != it.Begin());

			if (count == 0) {
				cout << "Данные не найденны!" << endl;
				break;
			}

			int col = inputNumCr(5);
			Iterator<Student> temp1(data);
			Iterator<Student> temp2 = temp1.Begin();
			int count1 = 0;
			do
			{
				Student tempdata = *temp1;
				if (tempdata.colCred() >= col) {
					cout << tempdata;
					count1++;
				}

				--temp1;
			} while (temp1 != temp2);

			if (count1 == 0) {
				cout << "Данные не найденны!" << endl;
				break;
			}

			break;
		}
		case 13:
			flag = false;
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}

int startMenu()
{
	int ViborPunkta = 0, strelka = 0;
	while (true) {
		cout << "ВЫБЕРИТЕ ПУНКТ МЕНЮ" << endl;
		ViborPunkta = (ViborPunkta + 14) % 14;
		if (ViborPunkta == 0)	cout << "->Добавить запись в начало" << endl;
		else cout << " Добавить запись в начало" << endl;

		if (ViborPunkta == 1)	cout << "->Добавить запись в конец" << endl;
		else cout << " Добавить запись в конец" << endl;

		if (ViborPunkta == 2) cout << "->Просмотр с начала" << endl;
		else cout << " Просмотр с начала" << endl;

		if (ViborPunkta == 3) cout << "->Просмотр с конца" << endl;
		else cout << " Просмотр с конца" << endl;

		if (ViborPunkta == 4) cout << "->Удалить элемент" << endl;
		else cout << " Удалить элемент" << endl;

		if (ViborPunkta == 5) cout << "->Сортировка пузырьком по ФИО" << endl;
		else cout << " Сортировка пузырьком по ФИО" << endl;

		if (ViborPunkta == 6) cout << "->Сортировка пузырьком по группе" << endl;
		else cout << " Сортировка пузырьком по группе" << endl;

		if (ViborPunkta == 7) cout << "->Проверка условия(группа)" << endl;
		else cout << " Проверка условия(группа)" << endl;

		if (ViborPunkta == 8) cout << "->Проверка условия(ср.балл)" << endl;
		else cout << " Проверка условия(ср.балл)" << endl;

		if (ViborPunkta == 9) cout << "->Копировать множество элементов, удовлетворяющих условию(группа)" << endl;
		else cout << " Копировать множество элементов, удовлетворяющих условию(группа)" << endl;

		if (ViborPunkta == 10) cout << "->Копировать множество элементов, удовлетворяющих условию(ср.балл)" << endl;
		else cout << " Копировать множество элементов, удовлетворяющих условию(ср.балл)" << endl;

		if (ViborPunkta == 11) cout << "->Редактирование" << endl;
		else cout << " Редактирование" << endl;

		if (ViborPunkta == 12) cout << "->Запрос" << endl;
		else cout << " Запрос" << endl;

		if (ViborPunkta == 13) cout << "->Закрыть программу" << endl;
		else cout << " Закрыть программу" << endl;
		//копирует множество элементов, удовлетворяющих условию

		strelka = _getch();
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


int MenuDel(string fio)
{
	int ViborPunkta = 0, strelka = 0;
	while (true) {
		cout << "Удалить данные по ФИО: " << fio << "?" << endl;
		ViborPunkta = (ViborPunkta + 2) % 2;
		if (ViborPunkta == 0)	cout << "->Не удалять" << endl;
		else cout << " Не удалять" << endl;

		if (ViborPunkta == 1)	cout << "->Удалить" << endl;
		else cout << " Удалить" << endl;


		strelka = _getch();
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