//1.В магазині формується список осіб, які записалися на купівлю товару підвищеного попиту. 
// Кожна структура цього списку містить: порядковий номер, П.І.Б., домашню адресу покупця і дату постановки на облік. 
// Вивести список осіб в порядку черги за датою постановки на облік. 
#include <iostream>
#include <Windows.h>
#include "function.h"


using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    bool povtor=true;
    int variant=0,rozmir=0,number=0,vubir=0;

    s_list* Head = nullptr;
    s_list* Current = nullptr;
    
    do
    {
        cout << R"(
                    1 Створення списку
                    2 Перегляд списку
                    3 видалення елементу із списку 1 з початку, 2 в кінці, 3 за номером, 4 за умовою
                    4 Вставка елементу в список 1 на початок, 2 в кінець, 3 за номером, 4 за умовою
                    5 пошук елемента в списку
                    6 перевірка порожнечі списку
                    7 видалення списку
                    8 завдання по сортуванню за датою
                    9 закрити програму)" << endl;
        cin >> variant;
        switch (variant)
        {
        case 1:
            vved(rozmir);
            for (size_t i = 0; i < rozmir; i++)
            {
                create_list(&Head);
            }
            break;
        case 2:
            print(Head);
            break;
        case 3:
            vved_vubir(vubir);
            switch (vubir)
            {
            case 1:
                delete_first_el(&Head);
                break;
            case 2:
                delete_last_el(&Head);
                break;
            case 3:
                delet_element(Head, number);
                break;
            case 4:
                break;
            default:
                cout << "Неправильно введений варіант " << endl;
                break;
            }
            break;
        case 4:
            vved_n(number);
            vved_vubir(vubir);
            switch (vubir)
            {
            case 1:
                break;
            case 2:
                for (size_t i = 0; i < rozmir; i++)
                {
                    add_end(&Head);
                }
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                cout << "Неправильно введений варіант " << endl;
                break;
            }
            break;
        case 5:
            vved_n(number);
            if (find_element(Head, number))
            {
                print_number(Head, number);
            }
            else
            {
                cout << "За вказаним номером нічого не знайдено" << endl;
            }
            break;
        case 6:
            if (empty(Head))
            {
                cout << "Список порожній" << endl;
            }
            else
            {
                cout << "Список не порожній" << endl;
            }
            break;
        case 7:
            delete_s(Head);
            break;
        case 8:
            
            break;
        case 9:
            povtor = false;
        default:
            cout << "Неправильно введений варіант" << endl;
            break;
        }
    } while (povtor);
    delete_s(Head);
}