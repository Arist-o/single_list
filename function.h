#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>

using namespace std;

struct Data {
    int nomer = 0;
    string pib = "";
    string adres = "";
    int day = 0;
    int month = 0;
    int year = 0;
};
struct s_list
{
    Data pos;
    s_list* next=nullptr;
};

bool find_element(s_list* Head, int number);

bool empty(s_list* Head);

//

bool compare(Data& a, Data& b);

void create_sorted_list(s_list** Head, Data* clients, int size);

void buff(s_list** Head);

//

s_list* delet_element(s_list* Head, int number);

s_list* add_element_number(s_list* Head, int number);

void vved(int& rozmir);

void vved_n(int& number);

void vved_vubir(int& vubir);

void create_list( s_list* Head);

void print(s_list* Head);

void add_first(s_list** Head);

void add_end(s_list** Head);

void delete_first_el(s_list* Head);

void delete_last_el(s_list* Head);

void delete_s(s_list* Head);

void print_number(s_list* Head, int number);

