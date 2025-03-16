#include <iostream>
#include <Windows.h>
#include <algorithm>
#include "function.h"


using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    bool povtor=true;
    int variant=0,rozmir=0,number=0,vubir=0;

    s_list* Head = nullptr;
    
    do
    {
        cout << R"(
                    1 Створення списку 
                    2 Перегляд списку
                    3 видалення елементу із списку 1 з початку, 2 в кінці, 3 за номером, 4 за умовою(шифром)
                    4 Вставка елементу в список 1 на початок, 2 в кінець, 3 за номером
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
           create_list(&Head,rozmir);
            break;
        case 2:
            if (empty(Head)) cout << "Список не створено" << endl;
            else print(Head);
            break;
        case 3:
            vved_vubir(vubir);
            switch (vubir)
            {
            case 1:
                if (empty(Head)) cout << "Список не створено" << endl;
                else delete_first_el(&Head);
                break;
            case 2:
                if (empty(Head)) cout << "Список не створено" << endl;
                else delete_last_el(Head);
                break;
            case 3:
                if (empty(Head)) cout << "Список не створено" << endl;
                else
                {
                     vved_n(number);
                    delet_element(Head, number);
                }
                break;
            case 4:
                char shufr_to_delete[10];
                cout << "Введіть шифр елемента, який потрібно видалити: ";
                cin.ignore();
                cin.getline(shufr_to_delete, 10);
                if (find_by_shufr(Head, shufr_to_delete)) {
                    Head = delete_by_shufr(Head, shufr_to_delete);
                    cout << "Елемент з шифром " << shufr_to_delete << " видалено" << endl;
                }
                else cout << "Елемент з шифром " << shufr_to_delete << " не знайдено" << endl;
                break;
            default:
                cout << "Неправильно введений варіант " << endl;
                break;
            }
            break;
        case 4:
           
            vved_vubir(vubir);
            switch (vubir)
            {
            case 1:
                if (empty(Head)) cout << "Список не створено" << endl;
                else {
                    vved(rozmir);
                    add_first(&Head);
                }
                break;
            case 2:
                if (empty(Head)) cout << "Список не створено" << endl;
                else {
                    vved(rozmir);
                    add_end(&Head);
                }
                break;
            case 3:
                if (empty(Head)) cout << "Список не створено" << endl;
                else
                {
                    vved_n(number);
                    add_element_number(Head, number);
                }
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
            create_sorted_list(&Head);
            break;
        case 9:
            povtor = false;
            break;
        default:
            cout << "Неправильно введений варіант" << endl;
            break;
        }
    } while (povtor);
    delete_s(Head);
}
