#pragma once
#include <iostream>

using namespace std;

string inputGroup() {
	string N;
	while (true)
	{
		cout << "������� ������: ";
		try {
			cin >> N;
			if (N.length() != 6) throw "������������ ����!";
			for (int i = 0; i < N.length(); i++) {
				if (N[i] < '0' || N[i] >'9') throw "������������ ����!";
			}
			if (!cin || cin.peek() != '\n') {
				throw "������������ ����!";
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
		cout << i + 1 << "-�������: ";
		try {
			cin >> N;
			if (!cin || cin.peek() != '\n' || N <= 0 || N >= 11) {
				throw "������������ ����!";
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
		cout << i + 1 << " �����: ";
		try {
			cin >> N;
			if (!cin || cin.peek() != '\n' || N < 0 || N > 1) {
				throw "������������ ����!";
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
			if ((k[i] != '.') && (k[i] != ' ') && (k[i] < 'a' || k[i] > 'z') && (k[i] < 'A' || k[i] > 'Z') && (k[i] < '�' || k[i] > '�') && (k[i] < '�' || k[i] > '�')) t = 1;
		}
		if (t == 1) {
			throw "������������ ����!";
		}
		return k;
	}
	catch (const char* s)
	{
		cout << s << endl;
		return "-1";
	}
	catch (...) {
		cout << "����������� ������!" << endl;
		return "-1";
	}
}
string inputFIO() {
	string fio;
	while (true) {
		cout << "������� ���: ";
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
		cout << "������� �����: ";
		try {
			cin >> N;
			if (!cin || cin.peek() != '\n' || N <= 0 || N > number) {
				throw "������������ ����!";
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
		cout << "������� ���-�� �������: ";
		try {
			cin >> N;
			if (!cin || cin.peek() != '\n' || N <= 0 || N > number) {
				throw "������������ ����!";
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
		cout << "������� ������� ����: ";
		try {
			cin >> N;
			if (!cin || cin.peek() != '\n' || N <= 0 || N > 10) {
				throw "������������ ����!";
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