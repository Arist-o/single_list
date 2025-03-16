#include <iostream>
#include <string>
#include <iomanip>
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
bool find_by_shufr(s_list* Head, char* shufr) 
{
    s_list* current = Head;
    while (current != nullptr) {
        if (strcmp(current->pos.shufr, shufr) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}



bool compare( Data& a, Data& b) {
    if (a.year != b.year) return a.year < b.year;
    if (a.month != b.month) return a.month < b.month;
    return a.day < b.day;
}
void create_sorted_list(s_list** Head)
{
    if (*Head == nullptr || (*Head)->next == nullptr) {
        cout << "Спиисок порожній або містить лише один елемент, сортування не потрібно" << endl;
    }
    else
    {
        bool swapped;
        do {
            swapped = false;
            s_list* current = *Head;
            s_list* prev = nullptr;

            while (current != nullptr && current->next != nullptr) {
                if (compare(current->next->pos, current->pos)) {
                    s_list* temp = current->next;
                    current->next = temp->next;
                    temp->next = current;

                    if (prev != nullptr) {
                        prev->next = temp;
                    }
                    else {
                        *Head = temp;
                    }

                    prev = temp;
                    swapped = true;
                }
                else {
                    prev = current;
                    current = current->next;
                }
            }
        } while (swapped);
    }
}



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

s_list* delete_by_shufr(s_list* Head, char* shufr)
{
    s_list* current = Head;
    s_list* prev = nullptr;

    if (strcmp(current->pos.shufr, shufr) == 0) {
        Head = current->next;
        delete current;
        return Head;
    }

    while (current != nullptr && strcmp(current->pos.shufr, shufr) != 0) {
        prev = current;
        current = current->next;
    }


    if (current != nullptr) {
        prev->next = current->next;
        delete current;
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
    cout << "Введіть шифр: "; cin.ignore(); cin.getline(vusol->pos.shufr, 10);

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

void create_list(s_list** Head, int rozmir) {
    if (rozmir > 0)
    {
        (*Head) = new s_list();
        cout << "Введіть номер: "; cin >> (*Head)->pos.nomer;
        cout << "Введіть ПІБ: "; cin.ignore(); getline(cin, (*Head)->pos.pib);
        cout << "Введіть адресу: "; getline(cin, (*Head)->pos.adres);
        cout << "Введіть день: "; cin >> (*Head)->pos.day;
        cout << "Введіть місяць: "; cin >> (*Head)->pos.month;
        cout << "Введіть рік: "; cin >> (*Head)->pos.year;
        cout << "Введіть шифр: "; cin.ignore(); cin.getline((*Head)->pos.shufr, 10);
        (*Head)->next = nullptr;
        create_list(&((*Head)->next), --rozmir);
    }
}

void print(s_list* Head)
{
    s_list* temp = Head;
    cout << setw(10) << left << "Номер"
        << setw(30) << left << "ПІБ"
        << setw(30) << left << "Адреса"
        << setw(10) << left << "Шифр"
        << setw(15) << left << "Дата" << endl;
    cout << setfill('-') << setw(85) << "-" << setfill(' ') << endl;
    while (temp != nullptr)
    {
        cout << setw(10) << temp->pos.nomer
            << setw(30) << temp->pos.pib
            << setw(30) << temp->pos.adres
            << setw(10) << temp->pos.shufr
            << setw(2) << temp->pos.day << "/"
            << setw(2) << temp->pos.month << "/"
            << setw(5) << temp->pos.year
            << endl;
        temp = temp->next;
    }
    cout << endl;
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
            cout << "Введіть шифр: "; cin.ignore(); cin.getline(zmin->pos.shufr, 10);
       
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
    cout << "Введіть шифр: "; cin.ignore(); cin.getline(zmin->pos.shufr, 10);

    zmin->next = *Head;
    *Head = zmin;
}

void delete_first_el(s_list** Head)
{
    
        s_list* current = *Head;
        (*Head) = (*Head)->next;
        delete(current);
    
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
    cout << setw(10) << "Номер"
        << setw(30) << "ПІБ"
        << setw(30) << "Адреса"
        << setw(10) << "Шифр"
        << setw(15) << "Дата" << endl;
    cout << setfill('-') << setw(95) << "-" << setfill(' ') << endl;
    while (ptr != nullptr) {
        if (ptr->pos.nomer == number) {
            cout << setw(10) << ptr->pos.nomer
                << setw(30) << ptr->pos.pib
                << setw(30) << ptr->pos.adres
                << setw(10) << ptr->pos.shufr
                << setw(2) << ptr->pos.day << "/"
                << setw(2) << ptr->pos.month << "/"
                << setw(5) << ptr->pos.year
                << endl;
            return;
        }
        ptr = ptr->next;
    }
    cout << "Елемент з номером " << number << " не знайдено." << endl;
}
