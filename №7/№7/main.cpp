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
				cout << "���� ����!" << endl;
				break;
			}
			
			show(stack);
			break;
		case 2:
			if (stack.empty()) {
				cout << "���� ����!" << endl;
				break;
			}

			alg.sortFIO(stack);
			show(stack);
			break;
		case 3:
			if (stack.empty()) {
				cout << "���� ����!" << endl;
				break;
			}

			alg.clear(stack);
			cout << "���� ������!" << endl;
			break;
		case 4:
			if (stack.empty()) {
				cout << "���� ����!" << endl;
				break;
			}

			alg.checkGroup(stack);
			break;
		case 5:
			if (stack.empty()) {
				cout << "���� ����!" << endl;
				break;
			}

			alg.checkBal(stack);
			break;
		case 6:
			if (stack.empty()) {
				cout << "���� ����!" << endl;
				break;
			}

			alg.copyGroup(stack);
			break;
		case 7:
			if (stack.empty()) {
			cout << "���� ����!" << endl;
			break;
			}

			alg.copyBal(stack);
			break;
		case 8:
			if (stack.empty()) {
				cout << "���� ����!" << endl;
				break;
			}
			alg.edit(stack);
			break;
		case 9:
			if (stack.empty()) {
				cout << "���� ����!" << endl;
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
		cout<< "�" << num <<": " << *it << endl;
		num++;
	}
}

int startMenu()
{
	int ViborPunkta = 0, strelka = 0;
	while (true) {
		cout << "�������� ����� ����" << endl;
		ViborPunkta = (ViborPunkta + 15) % 15;
		if (ViborPunkta == 0) cout << "->�������� ������" << endl;
		else cout << " �������� ������" << endl;

		if (ViborPunkta == 1) cout << "->��������" << endl;
		else cout << " ��������" << endl;

		if (ViborPunkta == 2) cout << "->����������" << endl;
		else cout << " ����������" << endl;

		if (ViborPunkta == 3) cout << "->�������� ����" << endl;
		else cout << " �������� ����" << endl;
		
		if (ViborPunkta == 4) cout << "->�������� �������(������)" << endl;
		else cout << " �������� �������(������)" << endl;

		if (ViborPunkta == 5) cout << "->�������� �������(��.����)" << endl;
		else cout << " �������� �������(��.����)" << endl;
	
		if (ViborPunkta == 6) cout << "->����������� ���������(������)" << endl;
		else cout << " ����������� ���������(������)" << endl;

		if (ViborPunkta == 7) cout << "->����������� ���������(��.����)" << endl;
		else cout << " ����������� ���������(��.����)" << endl;

		if (ViborPunkta == 8) cout << "->��������������" << endl;
		else cout << " ��������������" << endl;

		if (ViborPunkta == 9) cout << "->�������� ��������" << endl;
		else cout << " �������� ��������" << endl;

		if (ViborPunkta == 10) cout << "->����� �� ������" << endl;
		else cout << " ����� �� ������" << endl;

		if (ViborPunkta == 11) cout << "->����� �� ���" << endl;
		else cout << " ����� �� ���" << endl;

		if (ViborPunkta == 12) cout << "->������ 1" << endl;
		else cout << " ������ 1" << endl;

		if (ViborPunkta == 13) cout << "->������ 2" << endl;
		else cout << " ������ 2" << endl;

		if (ViborPunkta == 14) cout << "->������� ���������" << endl;
		else cout << " ������� ���������" << endl;

		

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
		cout << "�������� ��� ��������" << endl;
		if (ViborPunkta == 0)
			cout << "->���: " << (*it).getFIO() << endl;
		else
			cout << " ���: " << (*it).getFIO() << endl;

		if (ViborPunkta == 1)
			cout << "->������: " << (*it).getGroup() << endl;
		else
			cout << " ������: " << (*it).getGroup() << endl;

		if (ViborPunkta == 2) {
			cout << "->������ �� ��������: ";
			(*it).showExam();
			cout << endl;
		}
		else
		{
			cout << " ������ �� ��������: ";
			(*it).showExam();
			cout << endl;
		}

		if (ViborPunkta == 3) {
			cout << "->���������� �������: ";
			(*it).showCredit();
			cout << endl;
		}
		else
		{
			cout << " ���������� �������: ";
			(*it).showCredit();
			cout << endl;
		}

		if (ViborPunkta == 4)
			cout << "->�����" << endl;
		else
			cout << " �����" << endl;

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