#pragma once
#include <iostream>

using namespace std;

string inputGroup() {
	string N;
	while (true)
	{
		cout << "Введите группу: ";
		try {
			cin >> N;
			if (N.length() != 6) throw "Некорректный ввод!";
			for (int i = 0; i < N.length(); i++) {
				if (N[i] < '0' || N[i] >'9') throw "Некорректный ввод!";
			}
			if (!cin || cin.peek() != '\n') {
				throw "Некорректный ввод!";
			}
			else {
				return N;
			}
		}
		catch (const char* str) {
			cin.clear();
			rewind(stdin);
			cout << str << endl;
		}
	}
}
int inputExam(int i) {
	int N;
	while (true)
	{
		cout << i + 1 << "-экзамен: ";
		try {
			cin >> N;
			if (!cin || cin.peek() != '\n' || N <= 0 || N >= 11) {
				throw "Некорректный ввод!";
			}
			else {
				return N;
			}
		}
		catch (const char* str) {
			cin.clear();
			rewind(stdin);
			cout << str << endl;
		}
	}
}
int inputCredit(int i) {
	int N;
	while (true)
	{
		cout << i + 1 << " зачет: ";
		try {
			cin >> N;
			if (!cin || cin.peek() != '\n' || N < 0 || N > 1) {
				throw "Некорректный ввод!";
			}
			else {
				return N;
			}
		}
		catch (const char* str) {
			cin.clear();
			rewind(stdin);
			cout << str << endl;
		}
	}
}
string checkWriteString(string k) {
	try
	{
		int t = 0;
		for (int i = 0; i < k.length(); i++) {
			if ((k[i] != '.') && (k[i] != ' ') && (k[i] < 'a' || k[i] > 'z') && (k[i] < 'A' || k[i] > 'Z') && (k[i] < 'а' || k[i] > 'я') && (k[i] < 'А' || k[i] > 'Я')) t = 1;
		}
		if (t == 1) {
			throw "Некорректный ввод!";
		}
		return k;
	}
	catch (const char* s)
	{
		cout << s << endl;
		return "-1";
	}
	catch (...) {
		cout << "Неизвестная ошибка!" << endl;
		return "-1";
	}
}
string inputFIO() {
	string fio;
	while (true) {
		cout << "Введите ФИО: ";
		cin.clear();
		rewind(stdin);
		getline(cin, fio, '\n');
		string slovo = checkWriteString(fio);
		if (slovo != "-1")
		{
			return fio;
		}
	}
}
int inputNum(int number) {
	int N;
	while (true)
	{
		cout << "Введите номер: ";
		try {
			cin >> N;
			if (!cin || cin.peek() != '\n' || N <= 0 || N > number) {
				throw "Некорректный ввод!";
			}
			else {
				return N;
			}
		}
		catch (const char* str) {
			cin.clear();
			rewind(stdin);
			cout << str << endl;
		}
	}
}
int inputNumCr(int number) {
	int N;
	while (true)
	{
		cout << "Введите кол-во зачетов: ";
		try {
			cin >> N;
			if (!cin || cin.peek() != '\n' || N <= 0 || N > number) {
				throw "Некорректный ввод!";
			}
			else {
				return N;
			}
		}
		catch (const char* str) {
			cin.clear();
			rewind(stdin);
			cout << str << endl;
		}
	}
}
double inputBal() {
	double N;
	while (true)
	{
		cout << "Введите средний балл: ";
		try {
			cin >> N;
			if (!cin || cin.peek() != '\n' || N <= 0 || N > 10) {
				throw "Некорректный ввод!";
			}
			else {
				return N;
			}
		}
		catch (const char* str) {
			cin.clear();
			rewind(stdin);
			cout << str << endl;
		}
	}
}