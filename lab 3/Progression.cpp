#include "Progression.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Arithmetic.h"
#include "Geometric.h"

using namespace std;

Progression::~Progression()
{
	cout << "������ ���������� ����������" << endl;
	system("pause");
}

void Progression::input(double result, int value)
{
	ofstream fout(path, ios_base::app);
	if (!fout.is_open())
	{
		cout << "���� �� ����� ���� ������!" << endl;
	}
	else
	{
		fout << value << " ";
		fout << member1 << " ";
		fout << const_diff_att << " ";
		fout << setprecision(3) << result << "\n";
		fout.close();
	}
}

void Progression::output()
{
	ifstream fin(path); // ������� ���� ��� ������
	if (!fin.is_open())
	{
		cout << "���� �� ����� ���� ������!" << endl;
	}
	else
	{
		string ch;
		int cnt = 0;

		while (!fin.eof())
		{
			fin >> ch;
			cnt++;
		}

		//int qwe = --cnt % 4;

		if (--cnt % 4 != 0)
		{
			cout << "��-�� ������ � ����� ������ ���-�� �� ���!" << endl;
		}
		else
		{
			int size = cnt / 4;
			Progression** ptr = new Progression * [size];
			fin.close(); // ��������� ����
			ifstream fin(path); // ������� ���� ��� ������

			string way = "";
			int opt = 0;

			cout << "������� 1 ���� ������ �������� ���� � ����� ��� ���������� �� �����, ���� ��� ������� ����� ������ �����" << endl;
			cin >> opt;

			if (opt == 1)
			{
				cout << "������� ���� ��� ��� �����" << endl;
				cin >> way;
			}

			if (path == "Arithmetic_progression.txt")
			{
				for (int i = 0; i != size; i++)
				{
					ptr[i] = new Arithmetic(way);
				}
			}
			else if (path == "Geometric_progression.txt")
			{
				for (int i = 0; i != size; i++)
				{
					ptr[i] = new Geometric(way);
				}
			}
			system("cls");
			cout << "_______________________________________________________________" << endl;
			cout << "|���������� ���������|������ ����|���������/��������|���������|" << endl;
			for (int i = 0; i != size; i++)
			{
				fin >> ptr[i]->val;
				fin >> ptr[i]->member1;
				fin >> ptr[i]->const_diff_att;
				fin >> ptr[i]->res;

				cout.setf(ios::left);

				cout << "|" << setw(20) << ptr[i]->val << "|";
				cout << setw(11) << ptr[i]->member1 << "|";
				cout << setw(18) << ptr[i]->const_diff_att << "|";
				cout << setw(9) << ptr[i]->res << "|" << endl;

				cout.unsetf(ios::left);
			}
			cout << "777777777777777777777777777777777777777777777777777777777777777" << endl;
			fin.close(); // ��������� ����

			for (int i = 0; i != size; i++)
			{
				delete[] ptr[i];
			}
			delete[] ptr;
		}
	}
}

void Progression::reader()
{
	cout << "������� ������� �������� ������������������" << endl;
	cin >> member1;
	cout << "������� ���������� �������� ��� ���������" << endl;
	cin >> const_diff_att;
}