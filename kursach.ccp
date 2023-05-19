#include "Functions.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

struct MenuItem 
{
    string text;
    MenuItem* next;
    MenuItem* prev;

    MenuItem(string text) : text(text), next(nullptr), prev(nullptr) {}
};

class Menu 
{
private:
    MenuItem* firstItem;
    MenuItem* lastItem;
    MenuItem* selectedItem;

public:
    Menu() : firstItem(nullptr), lastItem(nullptr), selectedItem(nullptr) {}

    void addItem(const string& text) {
        MenuItem* newItem = new MenuItem(text);
        if (firstItem == nullptr) {
            firstItem = newItem;
            lastItem = newItem;
        }
        else {
            lastItem->next = newItem;
            newItem->prev = lastItem;
            lastItem = newItem;
        }
        if (selectedItem == nullptr) {
            selectedItem = newItem;
        }
    }

    void display() {
        system("cls");  // Очистить консоль
        MenuItem* currentItem = firstItem;
        while (currentItem != nullptr) 
        {
            if (currentItem == selectedItem) 
            {
                cout << "-> " << currentItem->text << endl;
            }
            else 
            {
                cout << "  " << currentItem->text << endl;
            }
            currentItem = currentItem->next;
        }
    }

    void selectNextItem() {
        if (selectedItem != nullptr && selectedItem->next != nullptr) {
            selectedItem = selectedItem->next;
        }
    }

    void selectPrevItem() {
        if (selectedItem != nullptr && selectedItem->prev != nullptr) {
            selectedItem = selectedItem->prev;
        }
    }

    string getSelectedItem() {
        if (selectedItem != nullptr) {
            return selectedItem->text;
        }
        return "";
    }
};

HANDLE hConsole;
enum ColorConsole
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};

int main()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, DarkGray);

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int case1action;
    int sMenu;
    int AmountOfData = 0;
    string filename;
    Data* d = new Data[AmountOfData];

    Menu menu;
    menu.addItem("Ввести данные о студенте");
    menu.addItem("Вывести данные о студенте");
    menu.addItem("Изменить данные о студенте");
    menu.addItem("Добавить данные о студенте");
    menu.addItem("Удалить данные о студенте");
    menu.addItem("Сохранить данные о студенте");
    menu.addItem("Личное задание(79 вариант)");
    menu.addItem("Выйти из программы");

    char key;
    while (true)
    {
        menu.display();

        key = _getch();
        if (key == 72)
        {
            menu.selectPrevItem();
        }
        else if (key == 80)
        {
            menu.selectNextItem();
        }
        else if (key == 13)
        {
            string selectedOption = menu.getSelectedItem();
            if (selectedOption == "Выйти из программы")
            {
                break;
            }
            if (selectedOption == "Ввести данные о студенте")
            {
                system("cls");
                cout << "(1) Создать новые данные" << endl;
                cout << "(2) Взять данные из файла" << endl;
                cout << " < ";
                cin >> case1action;

                if (case1action == 1)
                {
                    DataEntry(d, AmountOfData);
                }

                if (case1action == 2)
                {
                    cout << "Введите название файла < ";
                    cin >> filename;
                    ReadingData(d, AmountOfData, filename);
                }

                system("pause");
                system("cls");
                menu.display();

            }
            if (selectedOption == "Вывести данные о студенте")
            {
                system("cls");

                if (AmountOfData != 0) {
                    Print(d, AmountOfData);
                }
                else
                    cout << "Нет данных" << endl;
                system("pause");
                system("cls");
                menu.display();
            }
            if (selectedOption == "Изменить данные о студенте")
            {
                system("cls");

                if (AmountOfData != 0) {
                    DataChange(d, AmountOfData);
                }
                else
                    cout << "Нет данных" << endl;
                system("pause");
                system("cls");
                menu.display();
            }
            if (selectedOption == "Удалить данные о студенте")
            {
                system("cls");

                if (AmountOfData != 0) {
                    DeleteData(d, AmountOfData);
                }
                else
                    cout << "Нет данных" << endl;
                system("pause");
                system("cls");
                menu.display();
            }
            if (selectedOption == "Добавить данные о студенте")
            {
                system("cls");

                if (AmountOfData != 0) {
                    AddData(d, AmountOfData);
                    AmountOfData++;
                }
                else
                    cout << "Нет данных" << endl;
                system("pause");
                system("cls");
                menu.display();
            }
            if (selectedOption == "Сохранить данные о студенте")
            {
                system("cls");

                cout << "Введите название файла < ";
                cin >> filename;

                if (AmountOfData != 0)
                {
                    SavingData(d, AmountOfData, filename);
                }
                else
                    cout << "Нет данных" << endl;
                system("pause");
                system("cls");
                menu.display();
            }
            if (selectedOption == "Личное задание(79 вариант)")
            {
                system("cls");
                personaltask(d, AmountOfData);
                system("pause");
                system("cls");
                menu.display();
            }
        }
    }
    return 0;
}
