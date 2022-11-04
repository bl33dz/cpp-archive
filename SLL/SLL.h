#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED

#include <iostream>

#define info(P) (P)->info
#define next(P) (P)->next
#define first(P) ((P).first)
#define nil NULL

struct Person {
    std::string name;
    int age;
};

typedef Person infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address createNewElmt(infotype x);

void insertFirst(List &L, address P);
void insertAfter(List &L, address P, address Prec);
void insertLast(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteAfter(List &L, address &P, address Prec);
void deleteLast(List &L, address &P);

void insertData(List &L, std::string name, int age);
void deleteData(List &L, std::string name, int age);
void showList(List L);

#endif // SLL_H_INCLUDED