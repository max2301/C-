#pragma once
#include <iostream>
#include "Input.h"
#include <conio.h>
#include <string>


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
	bool task1Cred();
	bool task1Ex();

	int task2Cred();

	double getEx();
};

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

int Student::colCred() {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		if (credit[i] != 0) {
			sum++;
		}
	}
	return sum;
}

bool Student::task1Cred() {

	for (int i = 0; i < 5; i++) {
		if (credit[i] == 0) {
			return true;
		}
	}
	return false;
}
bool Student::task1Ex() {
	for (int i = 0; i < 5; i++) {
		if (exam[i] < 4) {
			return true;
		}
	}
	return false;
}

int Student::task2Cred() {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		if (credit[i] == 0) {
			sum++;
		}
	}
	return sum;
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