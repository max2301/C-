#pragma once
#include <iostream>
#include "Data.h"
#include "Container.h"
#include "Input.h"

using namespace std;

template <class T> class Algorithm
{
public:
	void sortFIO(Ring<T>& val, Iterator<T>& begin, Iterator<T>& end) {
		/*T tempdata;
		for (Iterator<T> i = begin; i != end; ++i) {
			for (Iterator<T> j = i; j != end; ++j) {
				if (i > j) {
					tempdata = *i;
					i = *j;
					j = tempdata;
				}
			}
		}*/
		T tempdata;
		Node<T>* temp1 = val.getBegin();
		int n = val.getSize();
		
		for (int x = 0; x < n - 1; x++)
		{
			Node<T>* temp2 = temp1->prev;
		
			for (int i = x; i < n - 1; i++)
			{
				if (temp1->value.getFIO() < temp2->value.getFIO())
				{
					tempdata = temp2->value;
					temp2->value = temp1->value;
					temp1->value = tempdata;
				}
		
				temp2 = temp2->prev;
			}
			temp1 = temp1->prev;
		}
	}
	void sortGr(Ring<T>& val) {
		T tempdata;
		Node<T>* temp1 = val.getBegin();
		int n = val.getSize();

		for (int x = 0; x < n - 1; x++)
		{
			Node<T>* temp2 = temp1->prev;

			for (int i = x; i < n - 1; i++)
			{
				if (temp1->value.getGroup() == temp2->value.getGroup()) {
					if (temp1->value.getFIO() < temp2->value.getFIO())
					{
						tempdata = temp2->value;
						temp2->value = temp1->value;
						temp1->value = tempdata;
					}
				}
				else if (temp1->value.getGroup() < temp2->value.getGroup())
				{
					tempdata = temp2->value;
					temp2->value = temp1->value;
					temp1->value = tempdata;
				}

				temp2 = temp2->prev;
			}
			temp1 = temp1->prev;
		}
	}
	void checkGr(Ring<T>& val, Iterator<T> begin) {
		string gr;
		gr = inputGroup();

		Iterator<T> temp = begin;
		int count = 0;
		do
		{
			Student tempdata = *temp;
			if (tempdata.getGroup() == gr){
				//cout << tempdata;
				count++;
			}

			--temp;
		} while (temp != begin);

		cout << count << " из " << val.getSize() << " удовлетвор€ют условию!" << endl;
	}
	void checkBal(Ring<T>& val, Iterator<T> begin) {
		double bal;
		bal = inputBal();

		Iterator<T> temp = begin;
		int count = 0;
		do
		{
			Student tempdata = *temp;
			if (tempdata.getBal() >= bal) {
				//cout << tempdata;
				count++;
			}

			--temp;
		} while (temp != begin);

		cout << count << " из " << val.getSize() << " удовлетвор€ют условию(ср.балл больше " << bal << ")!" << endl;
	}
	void copyGr(Ring<T>& val, Iterator<T> begin, Iterator<T> End) {
		string gr;
		gr = inputGroup();

		Iterator<T> temp = begin;
		Ring<T> data;
		int count = 0;
		do
		{
			Student tempdata = *temp;
			if (tempdata.getGroup() == gr) {
				data.push_back(tempdata);
				count++;
			}

			--temp;
		} while (temp != begin);

		if (count == 0) {
			cout << "ƒанные не найденны!" << endl;
			return;
		}
		system("cls");
		Iterator<T> it = End;
		int i = 1;
		do {
			cout << i << ": " << *it << endl;
			++i;
			++it;
		} while (it != End);

		int num;
		cout << "¬ведите номер куда копировать данные: ";
		num = inputNum(val.getSize());

		Node<T>* node = data.getBegin();
		if (num == 1) {
			do
			{
				val.push_front(node->value);
				node = node->prev;
			} while (node != data.getBegin());
		}
		else if (num == val.getSize()) {
			do
			{
				val.push_back(node->value);
				node = node->prev;
			} while (node != data.getBegin());
		}
		else {
			for (int i = 0; i < data.getSize(); ++i) {
				val.insert(node->value, num);
				++num;
				node = node->prev;
			}
		}
		
	}
	void copyBal(Ring<T>& val, Iterator<T> begin, Iterator<T> End) {
		double bal;
		bal = inputBal();

		Iterator<T> temp = begin;
		Ring<T> data;
		int count = 0;
		do
		{
			Student tempdata = *temp;
			if (tempdata.getBal() >= bal) {
				data.push_back(tempdata);
				count++;
			}

			--temp;
		} while (temp != begin);

		if (count == 0) {
			cout << "ƒанные не найденны!" << endl;
			return;
		}
		system("cls");
		Iterator<T> it = End;
		int i = 1;
		do {
			cout << i << ": " << *it << endl;
			++i;
			++it;
		} while (it != End);

		int num;
		cout << "¬ведите номер куда копировать данные: ";
		num = inputNum(val.getSize());

		Node<T>* node = data.getBegin();
		if (num == 1) {
			do
			{
				val.push_front(node->value);
				node = node->prev;
			} while (node != data.getBegin());
		}
		else if (num == val.getSize()) {
			do
			{
				val.push_back(node->value);
				node = node->prev;
			} while (node != data.getBegin());
		}
		else {
			for (int i = 0; i < data.getSize(); ++i) {
				val.insert(node->value, num);
				++num;
				node = node->prev;
			}
		}

	}
};
//
//template <class T> void Algorithm<T>::sortFIO(Ring<T>& val, Iterator<T>& begin, Iterator<T>& end) {
//	T tempdata;
//	//Node<T>* temp1 = val.begin();
//	//Iterator<T> temp1 = begin;
//	int n = val.getSize();
//	Iterator<T> temp1 = begin;
//
//	for (int x = 0; x < n - 1; x++)
//	{
//		//Node<T>* temp2 = temp1->prev;
//		Iterator<T> temp2 = --temp1;
//
//		for (int i = x; i < n - 1; i++)
//		{
//			//if (temp1->value.getFIO() < temp2->value.getFIO())
//			if (temp1 < temp2)
//			{
//				tempdata = *temp2;
//				cout << tempdata;
//				temp2= *temp1;
//				temp1 = tempdata;
//				//tempdata = temp2->value;
//				//temp2->value = temp1->value;
//				//temp1->value = tempdata;
//			}
//			temp2 = --temp2;
//			//temp2 = temp2->prev;
//		}
//		temp1 = --temp1;
//		//temp1 = temp1->prev;
//	}
//}