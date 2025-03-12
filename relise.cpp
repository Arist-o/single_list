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

void vved(int& rozmir)
{
    do
    {
        cout << "������ ����� ������`������ ������" << endl;
        cin >> rozmir;
        if (rozmir < 1 || rozmir > 30) cout << "����������� �������� �����.������ �� ���" << endl;
    } while (rozmir < 1 || rozmir > 30);
}

void vved_n(int& number)
{

    do
    {
        cout << "������ ����� ������`������ ������" << endl;
        cin >> number;
        if (number < 1 || number > 30) cout << "����������� �������� �����.������ �� ���" << endl;
    } while (number < 1 || number > 30);
}

void vved_vubir(int& vubir)
{
    do
    {
        cout << "������� ������ � ��������������" << endl;
        cin >> vubir;
        if (vubir < 1 || vubir > 4) cout << "����������� �������� ������" << endl;
    } while (vubir < 1 || vubir > 4);
}



void create_list( s_list** Head)
{
        (*Head) = new s_list();
        do {
            cout << "������ ����� 1-30: ";
            cin >> (*Head)->pos.nomer;
        } while ((*Head)->pos.nomer < 1 || (*Head)->pos.nomer > 30);


        do {
            cout << "������ ϲ�: ";
            cin.ignore();
            getline(cin, (*Head)->pos.pib);
        } while ((*Head)->pos.pib.empty());


        do {
            cout << "������ ������: ";
            getline(cin, (*Head)->pos.adres);
        } while ((*Head)->pos.adres.empty());


        do {
            cout << "������ ����: ";
            cin >> (*Head)->pos.day;
        } while ((*Head)->pos.day < 1 || (*Head)->pos.day > 31);


        do {
            cout << "������ �����: ";
            cin >> (*Head)->pos.month;
        } while ((*Head)->pos.month < 1 || (*Head)->pos.month > 12);


        do {
            cout << "������ ��: ";
            cin >> (*Head)->pos.year;
        } while ((*Head)->pos.year < 1);


       
}

void print(s_list* Head)
{
    if (Head != NULL) {
        cout << "�����: " << Head->pos.nomer << endl;
        cout << "ϲ�: " << Head->pos.pib << endl;
        cout << "������: " << Head->pos.adres << endl;
        cout << "����: " << Head->pos.day << "/" << Head->pos.month << "/" << Head->pos.year << endl;
        print(Head->next);
    }
    else cout << endl;

}

void add_end(s_list** Head) 
{

        s_list* zmin = new s_list();
        do {
            cout << "������ ����� 1-30: ";
            cin >> zmin->pos.nomer;
        } while (zmin->pos.nomer < 1 || zmin->pos.nomer > 30);

        do {
            cout << "������ ϲ�: ";
            cin.ignore();
            getline(cin, zmin->pos.pib);
        } while (zmin->pos.pib.empty());

        do {
            cout << "������ ������: ";
            getline(cin, zmin->pos.adres);
        } while (zmin->pos.adres.empty());

        do {
            cout << "������ ����: ";
            cin >> zmin->pos.day;
        } while (zmin->pos.day < 1 || zmin->pos.day > 31);

        do {
            cout << "������ �����: ";
            cin >> zmin->pos.month;
        } while (zmin->pos.month < 1 || zmin->pos.month > 12);

        do {
            cout << "������ ��: ";
            cin >> zmin->pos.year;
        } while (zmin->pos.year < 1);

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
void add_first(s_list* Head)
{
    s_list* temp = new s_list();
    temp->next = Head; 

    Head = temp; 
}


void delet_element(s_list* Head,int number) 
{
    s_list* ptr;
    s_list* Current = Head;
    for (int i = 1; i < number && Current != nullptr; i++)
    {
        Current = Current->next;
        if (Current != nullptr) {
            if (Current == Head) {
                Head = Head->next;
                delete(Current);
                Current = Head;
            }
            else {
                ptr = Head;
                while (ptr->next != Current)
                    ptr = ptr->next;
                ptr->next = Current->next;
                delete(Current);
                Current = ptr;
            }
        }
    }
}
void delete_first_el(s_list** Head)
{
    if (*Head != nullptr)
    {
        s_list* current = *Head;
        *Head = (*Head)->next;
        delete(current);
    }
    else 
    {
        cout << "������ �� ��������.������� ������" << endl;
    }
}

void delete_last_el(s_list* Head)
{
    s_list* current = Head;
    for (size_t i=1;current!=nullptr;i++)
    {
        current = current->next;
        if (current == nullptr)
        {
            delete (current);
        }
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
            cout << "������� ��������:" << endl;
            cout << "�����: " << ptr->pos.nomer << endl;
            cout << "ϲ�: " << ptr->pos.pib << endl;
            cout << "������: " << ptr->pos.adres << endl;
            cout << "����: " << ptr->pos.day << "/" << ptr->pos.month << "/" << ptr->pos.year << endl;
            return;
        }
        ptr = ptr->next;
    }
    cout << "������� � ������� " << number << " �� ��������." << endl;
}
