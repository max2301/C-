#pragma once
#include <iostream>
#include "Input.h"

using namespace std;

class Student {
private:
	string FIO;
	string group;
	int exam[5];
	int credit[5];
public:
	Student() {
		for (int i = 0; i < 5; i++)
		{
			credit[i] = 0;
			exam[i] = 0;
		}
	}
	Student(const Student& obj) {
		FIO = obj.FIO;
		group = obj.group;
		for (int i = 0; i < 5; i++)
		{
			credit[i] = obj.credit[i];
			exam[i] = obj.exam[i];

		}
	}
	~Student() {}
	Student& operator=(const Student& obj) {
		if (this != &obj) {
			FIO = obj.FIO;
			group = obj.group;
			for (int i = 0; i < 5; i++) {
				credit[i] = obj.credit[i];
				exam[i] = obj.exam[i];
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream&, Student&);
	friend istream& operator>>(istream&, Student&);
	void changeFIO(string);
	void changeGroup(string);
	void changeExam(int index, int ex);
	void changeCredit(int index, int cr);

	string getFIO();
	string getGroup();
	void showExam();
	void showCredit();
	double getBal();
	int colCred();
};

int Student::colCred() {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		if (credit[i] != 0) {
			sum++;
		}
	}
	return sum;
}

double Student::getBal() {
	double sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += exam[i];
	}
	return sum / 5;
}

ostream& operator<<(ostream& out, Student& obj) {
	out << "ФИО: " << obj.FIO << endl;
	out << "Группа: " << obj.group << endl;
	out << "Оценки за экзамены: " << endl;
	for (int i = 0; i < 5; i++) {
		out << i + 1 << ": ";
		out << obj.exam[i] << "; ";
	}
	out << endl;
	out << "Результаты зачетов: " << endl;
	for (int i = 0; i < 5; i++) {
		out << i + 1 << ": ";
		if (obj.credit[i] == 1) {
			out << "зачет" << "; ";
		}
		else {
			out << "незачет" << "; ";
		}
	}
	out << endl;
	return out;
}
istream& operator>>(istream& in, Student& obj) {

	obj.FIO = inputFIO();
	obj.group = inputGroup();
	cout << "Введите оценки за экзамены: " << endl;
	double sum = 0;
	for (int i = 0; i < 5; i++) {
		obj.exam[i] = inputExam(i);
		sum += obj.exam[i];
	}
	cout << "Введите результаты зачетов(1-зачет, 0-незачет): " << endl;
	for (int i = 0; i < 5; i++) {
		/*if (inputCredit(i) == 1) {
			obj.credit[i] = "зачет";
		}else obj.credit[i] = "незачет";*/
		obj.credit[i] = inputCredit(i);
	}
	return in;
}

void Student::changeFIO(string str) {
	FIO = str;
}
void Student::changeGroup(string str) {
	group = str;
}
void Student::changeExam(int index, int ex) {
	exam[index - 1] = ex;
}
void Student::changeCredit(int index, int cr) {
	credit[index - 1] = cr;
}

string Student::getFIO() {
	return FIO;
}
string Student::getGroup() {
	return group;
}
void Student::showExam() {
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ": ";
		cout << exam[i] << "; ";
	}
}
void Student::showCredit() {
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ": ";
		if (credit[i] == 1) {
			cout << "зачет" << "; ";
		}
		else {
			cout << "незачет" << "; ";
		}
	}
}

int menuUpdateData(Node<Student>* vol)
{
	int ViborPunkta = 0, strelka = 0;
	while (true) {
		ViborPunkta = (ViborPunkta + 5) % 5;
		cout << "ВЫБЕРИТЕ ЧТО ИЗМЕНИТЬ" << endl;
		if (ViborPunkta == 0)
			cout << "->ФИО: " << vol->value.getFIO() << endl;
		else
			cout << " ФИО: " << vol->value.getFIO() << endl;

		if (ViborPunkta == 1)
			cout << "->Группа: " << vol->value.getGroup() << endl;
		else
			cout << " Группа: " << vol->value.getGroup() << endl;

		if (ViborPunkta == 2) {
			cout << "->Оценки за экзамены: ";
			vol->value.showExam();
			cout << endl;
		}
		else
		{
			cout << " Оценки за экзамены: ";
			vol->value.showExam();
			cout << endl;
		}

		if (ViborPunkta == 3) {
			cout << "->Результаты зачетов: ";
			vol->value.showCredit();
			cout << endl;
		}
		else
		{
			cout << " Результаты зачетов: ";
			vol->value.showCredit();
			cout << endl;
		}

		if (ViborPunkta == 4)
			cout << "->Выход" << endl;
		else
			cout << " Выход" << endl;

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