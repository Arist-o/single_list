#include <iostream>
#include <string>
#include "function.h"

using namespace std;


bool find_element(s_list* Head, int number)
{
    s_list* ptr;
    ptr = Head;
    while (ptr != nullptr) {
        if (number == ptr->pos.nomer) return true;
        else ptr = ptr->next;
    }
    return false;
}

bool empty(s_list* Head) 
{
    return Head == nullptr;
}

//

bool compare( Data& a, Data& b) {
    if (a.year != b.year) return a.year < b.year;
    if (a.month != b.month) return a.month < b.month;
    return a.day < b.day;
}
void create_sorted_list(s_list** Head, Data* clients, int size)
{
    Data** clientArray = new Data * [size];
    for (int i = 0; i < size; ++i) {
        clientArray[i] = &clients[i];
    }

    sort(clientArray, clientArray + size, []( Data* a,  Data* b) {
        return compare(*a, *b);
        });

    *Head = nullptr;
    for (int i = 0; i < size; ++i) {
        s_list* newNode = new s_list();
        newNode->pos = *clientArray[i];
        newNode->next = *Head;
        *Head = newNode;
    }

    delete[] clientArray;
}

void buff(s_list** Head)
{
    cout << "Введіть кількість клієнтів: ";
    int clientCount;
    cin >> clientCount;
    Data* clients = new Data[clientCount];

    for (int i = 0; i < clientCount; i++) {
        cout << "Клієнт " << i + 1 << endl;
        cout << "Введіть номер: "; cin >> clients[i].nomer;
        cout << "Введіть ПІБ: "; cin.ignore(); getline(cin, clients[i].pib);
        cout << "Введіть адресу: "; getline(cin, clients[i].adres);
        cout << "Введіть день: "; cin >> clients[i].day;
        cout << "Введіть місяць: "; cin >> clients[i].month;
        cout << "Введіть рік: "; cin >> clients[i].year;
    }

    create_sorted_list(Head, clients, clientCount);

 
    delete[] clients;
}

//

s_list* delet_element(s_list* Head, int number) {
   
       s_list* ptr;
        s_list* current = Head;
        for (size_t i = 1; i < number && current != nullptr; i++)
        {
            current = current->next;
        }
        if (current != nullptr) {
            if (current == Head) {
                Head = Head->next;
                delete(current);
                current = Head;
            }
            else {
                ptr = Head;
                while (ptr->next != current)
                {
                    ptr = ptr->next;
                }
                ptr->next = current->next;
                delete(current);
                current = ptr;
            }
        }
        return Head;
}

s_list* add_element_number(s_list* Head, int number) 
{
    
    s_list* vusol = new s_list();
    
    cout << "Введіть номер: "; cin >> vusol->pos.nomer;

    cout << "Введіть ПІБ: "; cin.ignore(); getline(cin, vusol->pos.pib);

    cout << "Введіть адресу: "; getline(cin, vusol->pos.adres);

    cout << "Введіть день: "; cin >> vusol->pos.day;

    cout << "Введіть місяць: "; cin >> vusol->pos.month;

    cout << "Введіть рік: "; cin >> vusol->pos.year;

    vusol->next = nullptr;

     if ( number == 1) {
        vusol->next = Head;
        return vusol;
    }

    s_list* current = Head;
    for (int i = 1; i < number-1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        current = Head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = vusol;
    }
    else {
       
        vusol->next = current->next;
        current->next = vusol;
    }

    return Head;
}


void vved(int& rozmir)
{
    do
    {
        cout << "Введіть розмір виконання функції" << endl;
        cin >> rozmir;
        if (rozmir < 1 || rozmir > 30) cout << "Неправильно введений розмір.Введіть ще раз" << endl;
    } while (rozmir < 1 || rozmir > 30);
}

void vved_n(int& number)
{

    do
    {
        cout << "Введіть номер однозв`язного списку" << endl;
        cin >> number;
        if (number < 1 || number > 30) cout << "Неправильно введений розмір.Введіть ще раз" << endl;
    } while (number < 1 || number > 30);
}

void vved_vubir(int& vubir)
{
    do
    {
        cout << "Виберіть варіант з запропонованих" << endl;
        cin >> vubir;
        if (vubir < 1 || vubir > 4) cout << "Неправильно введений варіант" << endl;
    } while (vubir < 1 || vubir > 4);
}

void create_list(s_list** Head) {
    (*Head) = new s_list();

    cout << "Введіть номер: "; cin >> (*Head)->pos.nomer;

    cout << "Введіть ПІБ: "; cin.ignore(); getline(cin, (*Head)->pos.pib);

    cout << "Введіть адресу: "; getline(cin, (*Head)->pos.adres);

    cout << "Введіть день: "; cin >> (*Head)->pos.day;

    cout << "Введіть місяць: "; cin >> (*Head)->pos.month;

    cout << "Введіть рік: "; cin >> (*Head)->pos.year;

    (*Head)->next = nullptr;
}


void print(s_list* Head)
{
    if (Head != nullptr) {
        cout << "Номер: " << Head->pos.nomer << endl;
        cout << "ПІБ: " << Head->pos.pib << endl;
        cout << "Адреса: " << Head->pos.adres << endl;
        cout << "Дата: " << Head->pos.day << "/" << Head->pos.month << "/" << Head->pos.year << endl;
        print(Head->next);
    }
    else cout << endl;

}
void add_end(s_list** Head) 
{
        s_list* zmin = new s_list();
        
            cout << "Введіть номер 1-30: "; cin >> zmin->pos.nomer;

            cout << "Введіть ПІБ: "; cin.ignore(); getline(cin, zmin->pos.pib);
            
            cout << "Введіть адресу: "; getline(cin, zmin->pos.adres);
       
            cout << "Введіть день: "; cin >> zmin->pos.day;
        
            cout << "Введіть місяць: "; cin >> zmin->pos.month;
        
            cout << "Введіть рік: "; cin >> zmin->pos.year;
       
        zmin->next = nullptr;
        if (*Head == nullptr) {
            *Head = zmin;
        }
        else {
            s_list* current = *Head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = zmin;
        }
}
void add_first(s_list** Head)
{
    s_list* zmin = new s_list();
    
    cout << "Введіть номер 1-30: "; cin >> zmin->pos.nomer;

    cout << "Введіть ПІБ: "; cin.ignore(); getline(cin, zmin->pos.pib);

    cout << "Введіть адресу: "; getline(cin, zmin->pos.adres);

    cout << "Введіть день: "; cin >> zmin->pos.day;

    cout << "Введіть місяць: "; cin >> zmin->pos.month;

    cout << "Введіть рік: "; cin >> zmin->pos.year;

    zmin->next = *Head;
    *Head = zmin;
}

void delete_first_el(s_list* Head)
{
    if (Head != nullptr)
    {
        s_list* current = Head;
        Head = Head->next;
        delete(current);
    }
    else 
    {
        cout << "Список не створено.Створіть список" << endl;
    }
}

void delete_last_el(s_list* Head)
{
    if (Head == nullptr)
    {
        cout << "Список порожній" << endl;
    }
    else
    {
        if (Head->next == nullptr) {
            delete Head;
        }
        s_list* current = Head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
}

void delete_s(s_list* Head) {
    while (Head != nullptr) {
        s_list* temp = Head;
        Head = Head->next;
        delete temp;
    }
}


void print_number(s_list* Head, int number) 
{
    s_list* ptr = Head;
    while (ptr != nullptr) {
        if (ptr->pos.nomer == number) {
            cout << "Елемент знайдено:" << endl;
            cout << "Номер: " << ptr->pos.nomer << endl;
            cout << "ПІБ: " << ptr->pos.pib << endl;
            cout << "Адреса: " << ptr->pos.adres << endl;
            cout << "Дата: " << ptr->pos.day << "/" << ptr->pos.month << "/" << ptr->pos.year << endl;
            return;
        }
        ptr = ptr->next;
    }
    cout << "Елемент з номером " << number << " не знайдено." << endl;
}
