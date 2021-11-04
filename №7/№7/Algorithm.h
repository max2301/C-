#pragma once
#include <iostream>
#include "Data.h"
#include "Input.h"

using namespace std;

template <typename T, typename Container = deque<T>>
class iterable_stack : public stack<T, Container> {
public:
	typedef typename Container::iterator iterator;

	iterator begin() {
		return this->c.begin();
	}

	iterator end() {
		return this->c.end();
	}
};

template <class T> class Algorithm
{
public:
	void sortFIO(iterable_stack<T>& stack) {
		T tempdata;

		for (iterable_stack<Student>::iterator i = stack.begin(); i != stack.end(); i++) {
			for (iterable_stack<Student>::iterator j = i; j != stack.end(); j++) {
				if ((*i).getFIO() > (*j).getFIO()) {
					tempdata = *i;
					*i = *j;
					*j = tempdata;
				}
			}
		}

		cout << "Стек отсортирован!" << endl;
	}
	void sortGroup(iterable_stack<T>& stack) {
		T tempdata;

		for (iterable_stack<Student>::iterator i = stack.begin(); i != stack.end(); i++) {
			for (iterable_stack<Student>::iterator j = i; j != stack.end(); j++) {
				if ((*i).getGroup() == (*j).getGroup()) {
					if ((*i).getFIO() > (*j).getFIO()) {
						tempdata = *i;
						*i = *j;
						*j = tempdata;
					}
				}
				if ((*i).getGroup() > (*j).getGroup()) {
					tempdata = *i;
					*i = *j;
					*j = tempdata;
				}
			}
		}

		cout << "Стек отсортирован!" << endl;
	}
	void checkGroup(iterable_stack<T>& stack) {
		string group;
		group = inputGroup();

		iterable_stack<T> tmp_stack;
		int count = 0;
		for (iterable_stack<Student>::iterator it = stack.begin(); it != stack.end(); it++) {
			if ((*it).getGroup() == group) {
				tmp_stack.push(*it);
				count++;
			}
		}

		if (count == 0) {
			cout << "Данные не найдены!" << endl;
			return;
		}

		cout << count << " из " << stack.size() << " удовлетворяют условию:" << endl;

		show(tmp_stack);
	}
	void checkBal(iterable_stack<T>& stack) {
		double bal;
		bal = inputBal();

		iterable_stack<T> tmp_stack;
		int count = 0;
		for (iterable_stack<Student>::iterator it = stack.begin(); it != stack.end(); it++) {
			if ((*it).getBal() >= bal) {
				tmp_stack.push(*it);
				count++;
			}
		}

		if (count == 0) {
			cout << "Данные не найдены!" << endl;
			return;
		}

		cout << count << " из " << stack.size() << " удовлетворяют условию:" << endl;

		show(tmp_stack);
	}
	void copyGroup(iterable_stack<T>& stack) {
		string group = inputGroup();

		iterable_stack<T> tmp_stack;
		int count = 0;
		for (iterable_stack<Student>::iterator it = stack.begin(); it != stack.end(); it++) {
			if ((*it).getGroup() == group) {
				tmp_stack.push(*it);
				count++;
			}
		}

		if (count == 0) {
			cout << "Данные не найдены!" << endl;
			return;
		}

		show(stack);

		cout << "Введите номер куда вставить данные!" << endl;
		int number = inputNum(stack.size());
		int size = stack.size();
		iterable_stack<T> result_stack;
		iterable_stack<Student>::iterator iter = stack.begin();

		if (number == stack.size()) {
			for (iterable_stack<Student>::iterator it = tmp_stack.begin(); it != tmp_stack.end(); it++) {
				stack.push((*it));
			}
		}
		else if (number == 1) {
			for (iterable_stack<Student>::iterator it = tmp_stack.begin(); it != tmp_stack.end(); it++) {
				result_stack.push((*it));
			}
			for (iterable_stack<Student>::iterator it = stack.begin(); it != stack.end(); it++) {
				result_stack.push((*it));
			}
			stack = result_stack;
		}
		else {
			int num = 0;
			for (iterable_stack<Student>::iterator it = stack.begin(); it != stack.end(); it++) {
				result_stack.push((*it));
				num++;
				if (num == number - 1) {
					for (iterable_stack<Student>::iterator it = tmp_stack.begin(); it != tmp_stack.end(); it++) {
						result_stack.push((*it));
					}
				}
			}
			stack = result_stack;
		}
	}
	void copyBal(iterable_stack<T>& stack) {
		double bal;
		bal = inputBal();

		iterable_stack<T> tmp_stack;
		int count = 0;
		for (iterable_stack<Student>::iterator it = stack.begin(); it != stack.end(); it++) {
			if ((*it).getBal() >= bal) {
				tmp_stack.push(*it);
				count++;
			}
		}

		if (count == 0) {
			cout << "Данные не найдены!" << endl;
			return;
		}

		show(stack);

		cout << "Введите номер куда вставить данные!" << endl;
		int number = inputNum(stack.size());
		int size = stack.size();
		iterable_stack<T> result_stack;
		iterable_stack<Student>::iterator iter = stack.begin();

		if (number == stack.size()) {
			for (iterable_stack<Student>::iterator it = tmp_stack.begin(); it != tmp_stack.end(); it++) {
				stack.push((*it));
			}
		}
		else if (number == 1) {
			for (iterable_stack<Student>::iterator it = tmp_stack.begin(); it != tmp_stack.end(); it++) {
				result_stack.push((*it));
			}
			for (iterable_stack<Student>::iterator it = stack.begin(); it != stack.end(); it++) {
				result_stack.push((*it));
			}
			stack = result_stack;
		}
		else {
			int num = 0;
			for (iterable_stack<Student>::iterator it = stack.begin(); it != stack.end(); it++) {
				result_stack.push((*it));
				num++;
				if (num == number - 1) {
					for (iterable_stack<Student>::iterator it = tmp_stack.begin(); it != tmp_stack.end(); it++) {
						result_stack.push((*it));
					}
				}
			}
			stack = result_stack;
		}
	}
	void edit(iterable_stack<T>& stack) {
		show(stack);

		cout << "Введите номер для редактирования!" << endl;
		int number = inputNum(stack.size());
		iterable_stack<Student>::iterator it = stack.begin();

		for (int i = 0; i < number - 1; i++) {
			it++;
		}

		system("cls");

		int index;
		switch (menuUpdateData(it))
		{
		case 0:
			(*it).changeFIO(inputFIO());
			break;
		case 1:
			(*it).changeGroup(inputGroup());
			break;
		case 2:
			cout << "Оценки за экзамены:";
			(*it).showExam();
			cout << endl;
			index = inputNum(5);
			(*it).changeExam(index, inputExam(index - 1));
			break;
		case 3:
			cout << "Результаты зачетов:";
			(*it).showCredit();
			cout << endl;
			index = inputNum(5);
			(*it).changeCredit(index, inputCredit(index - 1));
			break;
		case 4:
			break;
		}
	}
	void clear(iterable_stack<T>& stack) {
		int size = stack.size();
		for (int i = 0; i < size; i++) {
			stack.pop();
		}
	}
	void del(iterable_stack<T>& stack) {
		show(stack);

		cout << "Введите номер для удаления!" << endl;
		int number = inputNum(stack.size());
		//iterable_stack<Student>::iterator it = stack.begin();
		iterable_stack<Student> tmp_stack;
		//iterable_stack<Student>::iterator tmp_iter = tmp_stack.begin();

		/*for (int i = 0; i < number - 1; i++) {
			it++;
		}*/

		if (number == stack.size()) {
			stack.pop();
		}
		else if (number == 1) {
			for (iterable_stack<Student>::iterator it = stack.begin() + 1; it != stack.end(); it++) {
				tmp_stack.push((*it));
			}
			stack = tmp_stack;
		}
		else {
			int num = 0;
			for (iterable_stack<Student>::iterator it = stack.begin(); it != stack.end(); it++) {
				tmp_stack.push((*it));
				num++;
				if (num == number - 1) {
					it++;
				}
			}
			stack = tmp_stack;
		}

		system("cls");
	}
	void searchFIO(iterable_stack<T>& stack) {
		string searchFIO = inputFIO();
		bool flag = false;

		iterable_stack<T> tmp_stack;

		for (iterable_stack<Student>::iterator i = stack.begin(); i != stack.end(); i++) {
				if ((*i).getFIO() == searchFIO) {
					tmp_stack.push((*i));
					flag = true;
				}
		}
		if (flag) {
			show(tmp_stack);
		}
		else {
			cout << "Данные не найдены!" << endl;
		}
	}
	void searchGroup(iterable_stack<T>& stack) {
		string searchGroup = inputGroup();
		bool flag = false;

		iterable_stack<T> tmp_stack;

		for (iterable_stack<Student>::iterator i = stack.begin(); i != stack.end(); i++) {
			if ((*i).getGroup() == searchGroup) {
				tmp_stack.push((*i));
				flag = true;
			}
		}

		if (flag) {
			show(tmp_stack);
		}
		else {
			cout << "Данные не найдены!" << endl;
		}
	}
	void task1(iterable_stack<T>& stack) {
		string searchGroup = inputGroup();
		bool flag = false;

		iterable_stack<T> tmp_stack;

		for (iterable_stack<Student>::iterator i = stack.begin(); i != stack.end(); i++) {
			if ((*i).getGroup() == searchGroup && ( (*i).task1Cred() || (*i).task1Ex())) {
				tmp_stack.push((*i));
				flag = true;
			}
		}

		if (flag) {
			cout << "Список неуспевающих студентов:" << endl;
			show(tmp_stack);
		}
		else {
			cout << "Данные не найдены!" << endl;
		}
	}
	void task2(iterable_stack<T>& stack) {
		string searchGroup = inputGroup();
		bool flag = false;
		int number;
		number = inputNum(5);

		iterable_stack<T> tmp_stack;

		for (iterable_stack<Student>::iterator i = stack.begin(); i != stack.end(); i++) {
			if ((*i).getGroup() == searchGroup && (*i).task2Cred() >= number) {
				tmp_stack.push((*i));
				flag = true;
			}
		}

		if (flag) {
			cout << "Список студентов:" << endl;
			show(tmp_stack);
		}
		else {
			cout << "Данные не найдены!" << endl;
		}
	}
};
