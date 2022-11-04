#include "SLL.h"

void createList(List &L) {
    first(L) = nil;
}

address createNewElmt(infotype x) {
    address P = new elmlist;
    info(P) = x;
    next(P) = nil;
    return P;
}

void insertFirst(List &L, address P) {
    if (first(L) == nil) {
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertAfter(List &L, address P, address Prec) {
    if (first(L) == nil) {
        first(L) = P;
    } else {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void insertLast(List &L, address P) {
    if (first(L) == nil) {
        first(L) = P;
    } else {
        address Q = first(L);
        while (next(Q) != nil) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (first(L) == nil) {
        std::cout << "List kosong" << std::endl;
    } else {
        P = first(L);
        first(L) = next(P);
        next(P) = nil;
    }
}

void deleteAfter(List &L, address &P, address Prec) {
    if (first(L) == nil) {
        std::cout << "List kosong" << std::endl;
    } else {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = nil;
    }
}

void deleteLast(List &L, address &P) {
    if (first(L) == nil) {
        std::cout << "List kosong" << std::endl;
    } else {
        address Q = first(L);
        while (next(next(Q)) != nil) {
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = nil;
    }
}

void insertData(List &L, std::string name, int age) {
    infotype x;
    x.name = name;
    x.age = age;
    address P = createNewElmt(x);
    if(first(L) == nil) {
        insertFirst(L, P);
    } else {
        if(info(P).age <= info(first(L)).age) {
            insertFirst(L, P);
        } else if(info(P).age > info(first(L)).age) {
            address Q = first(L);
            while(next(Q) != nil && info(P).age > info(next(Q)).age) {
                Q = next(Q);
            }
            if(next(Q) == nil) {
                insertLast(L, P);
            } else {
                insertAfter(L, P, Q);
            }
        }
    }
}

void deleteData(List &L, std::string name, int age) {
    infotype x;
    x.name = name;
    x.age = age;
    address P = createNewElmt(x);
    if(first(L) == nil) {
        std::cout << "List kosong" << std::endl;
    } else {
        if(info(P).age == info(first(L)).age && info(P).name == info(first(L)).name) {
            deleteFirst(L, P);
        } else {
            address Q = first(L);
            while(next(Q) != nil && (info(P).age != info(next(Q)).age || info(P).name != info(next(Q)).name)) {
                Q = next(Q);
            }

            if(next(Q) != nil) {
                deleteAfter(L, P, Q);
            } else {
                std::cout << "Data tidak ditemukan" << std::endl;
            }
        }
    }
}

void showList(List L) {
    address P = first(L);
    while (P != nil) {
        std::cout << info(P).name << " " << info(P).age << std::endl;
        P = next(P);
    }
}