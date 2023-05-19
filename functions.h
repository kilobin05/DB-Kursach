#pragma once
#include <iostream> 
#include <fstream>
#include <Windows.h> 
#include <string>

using namespace std;

struct StudentInfo
{
	string name, surname, patronymic, gender;
};
struct Date
{
	unsigned short day, month, year;
};
struct InstituteInfo
{
	unsigned short yearpostup;
	string institute; //факультет(институт)
	string department; //кафедра
	string group;
	string number; //номер зачётной книжки
};
struct InstituteSubject
{
	string subject;
	unsigned short estimation;
};
struct Session
{
	InstituteSubject maxquan[11];
	int quan;
};
struct Data 
{
	StudentInfo StudInfo;
	Date date;
	InstituteInfo InstInfo;
	InstituteSubject InstSub;
	Session session[100];
	int quansessions;
};

//прототипы функций
void DataEntry(Data* (&d), int& n); //ввод данных
void ReadingData(Data* (&d), int& n, string fileName); //чтение данных
void Print(Data* d, int n); //вывод данных
void DataChange(Data* (&d), int n); //изменение данных
void DeleteData(Data* (&d), int& n); //удаление данных
void Copy(Data* (&d_n), Data* (&d_o), int n); //копирование данных
void Copy(Data& d_n, Data& d_o); //копирование данных элемента
void AddData(Data* (&d), int& n); //добавление данных
void SavingData(Data* d, int n, string fileName); //сохранение данных
void personaltask(Data* d, int n);
