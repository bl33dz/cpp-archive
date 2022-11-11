#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED

#include <iostream>

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(P) ((P).first)
#define last(P) ((P).last)
#define nil NULL

const int defaultPortion = 20;

struct Food {
    std::string name;
    int portion;
    int price;
};

typedef Food infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void createList(List &L);
infotype createNewFood(std::string name, int price);
address createNewElm(infotype x);

void insertFirst(List &L, address P);
void insertAfter(List &L, address P, address Prec);
void insertLast(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteAfter(List &L, address &P, address Prec);
void deleteLast(List &L, address &P);

void showList(List L);

void addSomeFood(List &L);
void sellFood(List &L);
void showAvailableFood(List L);
void showSoldOutFood(List L);

#endif