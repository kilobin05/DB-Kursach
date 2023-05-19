#include "Functions.h"
using namespace std;

void DataEntry(Data* (&d), int& n)
{
	cout << "Введите кол-во студентов, о которых вы хотите записать данные < ";
	cin >> n;
	d = new Data[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Введите фамилию, имя и отчество < ";
		cin >> d[i].StudInfo.surname >> d[i].StudInfo.name >> d[i].StudInfo.patronymic;
		cout << "Введите пол < ";
		cin >> d[i].StudInfo.gender;
		cout << "Введите дату рождения < ";
		cin >> d[i].date.day >> d[i].date.month >> d[i].date.year;
		cout << "Введите год поступления в ВУЗ < ";
		cin >> d[i].InstInfo.yearpostup;
		cout << "Введите название факультета(института) < ";
		cin >> d[i].InstInfo.institute;
		cout << "Введите название кафедры < ";
		cin >> d[i].InstInfo.department;
		cout << "Введите номер группы < ";
		cin >> d[i].InstInfo.group;
		cout << "Введите номер зачётной книжки < ";
		cin >> d[i].InstInfo.number;
		cout << "Введите кол-во сессий < ";
		cin >> d[i].quansessions;

		for (int j = 0; j < d[i].quansessions; j++)
		{
			cout << "Сколько предметов в сессии #" << j + 1 << " ? < ";
			cin >> d[i].session[j].quan;

			for (int k = 0; k < d[i].session[j].quan; k++)
			{
				cout << "Введите название предмета < ";
				cin >> d[i].session[j].maxquan[k].subject;
				cout << "Введите оценку < ";
				cin >> d[i].session[j].maxquan[k].estimation;
			}
		}
		cout << "-------------------------------------------" << endl;
	}
}

void ReadingData(Data* (&d), int& n, string fileName)
{
	ifstream reading(fileName);
	ofstream record("Buffer.txt", ios::out);
	if (reading)
	{
		reading >> n;
		d = new Data[n];

		for (int i = 0; i < n; i++)
		{
			reading >> d[i].StudInfo.surname;
			reading >> d[i].StudInfo.name;
			reading >> d[i].StudInfo.patronymic;
			reading >> d[i].StudInfo.gender;
			reading >> d[i].date.day;
			reading >> d[i].date.month;
			reading >> d[i].date.year;
			reading >> d[i].InstInfo.yearpostup;
			reading >> d[i].InstInfo.institute;
			reading >> d[i].InstInfo.department;
			reading >> d[i].InstInfo.group;
			reading >> d[i].InstInfo.number;
			reading >> d[i].quansessions;

			for (int j = 0; j < d[i].quansessions; j++)
			{
				reading >> d[i].session[j].quan;

				for (int k = 0; k < d[i].session[j].quan; k++)
				{
					reading >> d[i].session[j].maxquan[k].subject;
					reading >> d[i].session[j].maxquan[k].estimation;
				}
			}
		}
		cout << "Данные о студенте считаны" << endl;
	}
	else
		cout << "Ошибка" << endl;

	reading.close();
}

void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Данные о студенте #" << i + 1 << endl;
		cout << "Фамилия, имя и отчество - " << d[i].StudInfo.surname << " " << d[i].StudInfo.name << " " << d[i].StudInfo.patronymic << endl;
		cout << "Пол - " << d[i].StudInfo.gender << endl;
		cout << "День, месяц и год рождения - " << d[i].date.day << "." << d[i].date.month << "." << d[i].date.year << endl;
		cout << "Год поступления в ВУЗ - " << d[i].InstInfo.yearpostup << endl;
		cout << "Факультет(институт) - " << d[i].InstInfo.institute << endl;
		cout << "Название кафедры - " << d[i].InstInfo.department << endl;
		cout << "Номер группы - " << d[i].InstInfo.group << endl;
		cout << "Номер зачётной книжки - " << d[i].InstInfo.number << endl;

		for (int j = 0; j < d[i].quansessions; j++)
		{
			cout << "Сессия #" << j + 1 << endl;

			for (int k = 0; k < d[i].session[j].quan; k++)
			{
				cout << d[i].session[j].maxquan[k].subject << " ";
				cout << d[i].session[j].maxquan[k].estimation << endl;
			}
		}
		cout << "-------------------------------------------" << endl;
	}
}

void DataChange(Data* (&d), int n)
{
	int n1;
	cout << "Введите номер студента (от 1 до " << n << ") > ";
	cin >> n1;
	n1--;
	int A, B, C;
	system("cls");
	if (n1 >= 0 && n1 < n)
	{
			cout << "Данные о студенте #" << n1 + 1 << endl;
			cout << "Фамилия, имя и отчество - " << d[n1].StudInfo.surname << " " << d[n1].StudInfo.name << " " << d[n1].StudInfo.patronymic << endl;
			cout << "Пол - " << d[n1].StudInfo.gender << endl;
			cout << "День, месяц и год рождения - " << d[n1].date.day << "." << d[n1].date.month << "." << d[n1].date.year << endl;
			cout << "Год поступления в ВУЗ - " << d[n1].InstInfo.yearpostup << endl;
			cout << "Факультет(институт) - " << d[n1].InstInfo.institute << endl;
			cout << "Название кафедры - " << d[n1].InstInfo.department << endl;
			cout << "Номер группы - " << d[n1].InstInfo.group << endl;
			cout << "Номер зачётной книжки - " << d[n1].InstInfo.number << endl;

			for (int j = 0; j < d[n1].quansessions; j++)
			{
				cout << "Сессия #" << j + 1 << endl;

				for (int k = 0; k < d[n1].session[j].quan; k++)
				{
					cout << d[n1].session[j].maxquan[k].subject << " ";
					cout << d[n1].session[j].maxquan[k].estimation << endl;
				}
			}
			cout << "-------------------------------------------" << endl;

		cout << "(1) Поменять ФИО" << endl;
		cout << "(2) Поменять пол" << endl;
		cout << "(3) Поменять дату рождения" << endl;
		cout << "(4) Поменять год поступления в ВУЗ" << endl;
		cout << "(5) Поменять название факультета(института)" << endl;
		cout << "(6) Поменять название кафедры" << endl;
		cout << "(7) Поменять номер группы" << endl;
		cout << "(8) Поменять номер зачётной книжки" << endl;
		cout << "(9) Поменять количество сессий, предметы и оценки" << endl;
		cout << "<";
		cin >> A;
		system("cls");
		switch (A)
		{
		case 1:
			cout << "(1) Поменять фамилию" << endl;
			cout << "(2) Поменять имя" << endl;
			cout << "(3) Поменять отчество" << endl;
			cin >> B;
			system("cls");
			switch (B)
			{
			case 1:
				cout << "Введите фамилию < ";
				cin >> d[n1].StudInfo.surname;
				break;
			case 2:
				cout << "Введите имя < ";
				cin >> d[n1].StudInfo.name;
				break;
			case 3:
				cout << "Введите отчество < ";
				cin >> d[n1].StudInfo.patronymic;
				break;
			default:
				cout << "Ошибка";
				system("pause");
				break;
			}
			break;
		case 2:
			cout << "Введите пол < ";
			cin >> d[n1].StudInfo.gender;
			break;
		case 3:
			cout << "(1) Поменять день рождения" << endl;
			cout << "(2) Поменять месяц рождения" << endl;
			cout << "(3) Поменять год рождения" << endl;
			cin >> C;
			system("cls");
			switch (C)
			{
			case 1:
				cout << "Введите день < ";
				cin >> d[n1].date.day;
				break;
			case 2:
				cout << "Введите месяц < ";
				cin >> d[n1].date.month;
				break;
			case 3:
				cout << "Введите год < ";
				cin >> d[n1].date.year;
				break;
			default:
				cout << "Ошибка";
				system("pause");
				break;
			}
			break;
		case 4:
			cout << "Введите год поступления в ВУЗ < ";
			cin >> d[n1].InstInfo.yearpostup;
			break;
		case 5:
			cout << "Введите название факультета(института) < ";
			cin >> d[n1].InstInfo.institute;
			break;
		case 6:
			cout << "Введите название кафедры < ";
			cin >> d[n1].InstInfo.department;
			break;
		case 7:
			cout << "Введите номер группы < ";
			cin >> d[n1].InstInfo.group;
			break;
		case 8:
			cout << "Введите номер зачётной книжки < ";
			cin >> d[n1].InstInfo.number;
			break;
		case 9:
			cout << "Введите кол-во сессий < ";
			cin >> d[n1].quansessions;

			for (int j = 0; j < d[n1].quansessions; j++)
			{
				cout << "Сколько предметов в сессии #" << j + 1 << "? < ";
				cin >> d[n1].session[j].quan;

				for (int k = 0; k < d[n1].session[j].quan; k++)
				{
					cout << "Введите название предмета < ";
					cin >> d[n1].session[j].maxquan[k].subject;
					cout << "Введите оценку < ";
					cin >> d[n1].session[j].maxquan[k].estimation;
				}
			}
			break;
		default:
			cout << "Ошибка" << endl;
			system("pause");
			break;
		}
		cout << "Данные о студенте изменены" << endl;
	}
	else
		cout << "Студента с таким номером нет" << endl;
}

void DeleteData(Data* (&d), int& n)
{
	int n1;
	cout << "Введите номер студента (от 1 до " << n << ") < ";
	cin >> n1;
	n1--;
	system("cls");
	if (n1 >= 0 && n1 < n)
	{
		Data* buffer = new Data[n];
		Copy(buffer, d, n);
		--n;
		d = new Data[n];
		int k = 0;
		for (int i = 0; i <= n; i++)
		{
			if (i != n1)
			{
				d[k] = buffer[i];
				++k;
			}
		}
		system("cls");
		delete[]buffer;
		cout << "Данные о студенте удалены" << endl;
	}
	else
		cout << "Студента с таким номером нет" << endl;
}

void Copy(Data* (&d_n), Data* (&d_o), int n)
{
	for (int i = 0; i < n; i++)
	{
		d_n[i] = d_o[i];
	}
}

void Copy(Data& d_n, Data& d_o)
{
	d_n.StudInfo.surname = d_o.StudInfo.surname;
	d_n.StudInfo.name = d_o.StudInfo.name;
	d_n.StudInfo.patronymic = d_o.StudInfo.patronymic;
	d_n.StudInfo.gender = d_o.StudInfo.gender;
	d_n.date.day = d_o.date.day;
	d_n.date.month = d_o.date.month;
	d_n.date.year = d_o.date.year;
	d_n.InstInfo.yearpostup = d_o.InstInfo.yearpostup;
	d_n.InstInfo.institute = d_o.InstInfo.institute;
	d_n.InstInfo.department = d_o.InstInfo.department;
	d_n.InstInfo.group = d_o.InstInfo.group;
	d_n.InstInfo.number = d_o.InstInfo.number;
	d_n.StudInfo.gender = d_o.StudInfo.gender;
	d_n.quansessions = d_o.quansessions;

	for (int j = 0; j < d_n.quansessions; j++)
	{
		d_n.session[j].quan = d_o.session[j].quan;

		for (int m = 0; m < d_n.session[j].quan; m++)
		{
			d_n.session[j].maxquan[m].subject = d_o.session[j].maxquan[m].subject;
			d_n.session[j].maxquan[m].estimation = d_o.session[j].maxquan[m].estimation;
		}
	}
}

void AddData(Data* (&d), int& n)
{
	Data* buffer = new Data[n];
	Copy(buffer, d, n);
	n++;
	d = new Data[n];
	Copy(d, buffer, --n);
	cout << "Введите фамилию, имя и отчество < ";
	cin >> d[n].StudInfo.surname;
	cin >> d[n].StudInfo.name;
	cin >> d[n].StudInfo.patronymic;
	cout << "Введите пол < ";
	cin >> d[n].StudInfo.gender;
	cout << "Введите дату рождения < ";
	cin >> d[n].date.day;
	cin >> d[n].date.month;
	cin >> d[n].date.year;
	cout << "Введите год поступления в ВУЗ < ";
	cin >> d[n].InstInfo.yearpostup;
	cout << "Введите название факультета(института) < ";
	cin >> d[n].InstInfo.institute;
	cout << "Введите название кафедры < ";
	cin >> d[n].InstInfo.department;
	cout << "Введите номер группы < ";
	cin >> d[n].InstInfo.group;
	cout << "Введите номер зачётной книжки < ";
	cin >> d[n].InstInfo.number;
	cout << "Введите кол-во сессий < ";
	cin >> d[n].quansessions;

	for (int j = 0; j < d[n].quansessions; j++)
	{
		cout << "Сколько предметов в сессии #" << j + 1 << "? < ";
		cin >> d[n].session[j].quan;

		for (int k = 0; k < d[n].session[j].quan; k++)
		{
			cout << "Введите название предмета < ";
			cin >> d[n].session[j].maxquan[k].subject;
			cout << "Введите оценку < ";
			cin >> d[n].session[j].maxquan[k].estimation;
		}
	}
	system("cls");
	cout << "Новые данные о студенте добавлены" << endl;
	delete[]buffer;
}

void SavingData(Data* d, int n, string fileName)
{
	ofstream record(fileName, ios::out);
	if (record)
	{
		record << n << endl;
		for (int i = 0; i < n; i++)
		{
			record << d[i].StudInfo.surname << endl;
			record << d[i].StudInfo.name << endl;
			record << d[i].StudInfo.patronymic << endl;
			record << d[i].StudInfo.gender << endl;

			record << d[i].date.day << endl;
			record << d[i].date.month << endl;
			record << d[i].date.year << endl;

			record << d[i].InstInfo.yearpostup << endl;
			record << d[i].InstInfo.institute << endl;
			record << d[i].InstInfo.department << endl;
			record << d[i].InstInfo.group << endl;
			record << d[i].InstInfo.number << endl;
			record << d[i].quansessions << endl;


			for (int j = 0; j < d[i].quansessions; j++)
			{
				record << d[i].session[j].quan << endl;

				for (int k = 0; k < d[i].session[j].quan; k++)
				{
					record << d[i].session[j].maxquan[k].subject << endl;
					record << d[i].session[j].maxquan[k].estimation << endl;
				}
			}
		}
	}
	else
		cout << "Ошибка" << endl;
	record.close();
}

void personaltask(Data* d, int n)
{
	unsigned short start, end;
	cout << "Укажите интервал года рождения" << endl;
	cout << "Начало < ";
	cin >> start;
	cout << "Конец < ";
	cin >> end;

	for (int i = 0; i < n; i++)
	{
		Data buffer;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (d[i].InstInfo.yearpostup > d[j].InstInfo.yearpostup)
				{
					Copy(buffer, d[j]);
					Copy(d[j], d[i]);
					Copy(d[i], buffer);
				}
			}
		}


		if (start <= d[i].date.year && d[i].date.year <= end)
		{
			cout << "Данные о студенте #" << i + 1 << endl;
			cout << "Фамилия, имя и отчество - " << d[i].StudInfo.surname << " " << d[i].StudInfo.name << " " << d[i].StudInfo.patronymic << endl;
			cout << "Пол - " << d[i].StudInfo.gender << endl;
			cout << "День, месяц и год рождения - " << d[i].date.day << "." << d[i].date.month << "." << d[i].date.year << endl;
			cout << "Год поступления в ВУЗ - " << d[i].InstInfo.yearpostup << endl;
			cout << "Факультет(институт) - " << d[i].InstInfo.institute << endl;
			cout << "Название кафедры - " << d[i].InstInfo.department << endl;
			cout << "Номер группы - " << d[i].InstInfo.group << endl;
			cout << "Номер зачётной книжки - " << d[i].InstInfo.number << endl;

			for (int j = 0; j < d[i].quansessions; j++)
			{
				cout << "Сессия #" << j + 1 << endl;

				for (int k = 0; k < d[i].session[j].quan; k++)
				{
					cout << d[i].session[j].maxquan[k].subject << " ";
					cout << d[i].session[j].maxquan[k].estimation << endl;
				}
			}
			cout << "-------------------------------------------" << endl;
		}
		else;
	}
}
