#include "DLL.h"

void createList(List &L) {
    first(L) = nil;
    last(L) = nil;
}

infotype createNewFood(std::string name, int price) {
    infotype x;
    x.name = name;
    x.portion = defaultPortion;
    x.price = price;
    return x;
}

address createNewElm(infotype x) {
    address P = new elmlist;
    info(P) = x;
    next(P) = nil;
    prev(P) = nil;
    return P;
}

void insertFirst(List &L, address P) {
    if (first(L) == nil) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertAfter(List &L, address P, address Prec) {
    if (first(L) == nil) {
        first(L) = P;
        last(L) = P;
    } else if(next(Prec) == nil) {
        insertLast(L, P);
    } else {
        next(P) = next(Prec);
        prev(next(Prec)) = P;
        next(Prec) = P;
        prev(P) = Prec;
    }
}

void insertLast(List &L, address P) {
    if (first(L) == nil) {
        first(L) = P;
        last(L) = P;
    } else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (first(L) == nil) {
        std::cout << "List kosong" << std::endl;
    } else if (first(L) == last(L)) {
        P = first(L);
        first(L) = nil;
        last(L) = nil;
    } else {
        P = first(L);
        first(L) = next(P);
        prev(first(L)) = nil;
        next(P) = nil;
    }
}

void deleteAfter(List &L, address &P, address Prec) {
    if (first(L) == nil) {
        std::cout << "List kosong" << std::endl;
    } else if (next(Prec) == last(L)) {
        P = last(L);
        last(L) = prev(P);
        next(last(L)) = nil;
        prev(P) = nil;
    } else {
        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = nil;
        prev(P) = nil;
    }
}

void deleteLast(List &L, address &P) {
    if (first(L) == nil) {
        std::cout << "List kosong" << std::endl;
    } else if (first(L) == last(L)) {
        P = first(L);
        first(L) = nil;
        last(L) = nil;
    } else {
        P = last(L);
        last(L) = prev(P);
        next(last(L)) = nil;
        prev(P) = nil;
    }
}

void showList(List L) {
    address P = first(L);
    while (P != nil) {
        std::cout << info(P).name << " " << info(P).portion << " " << info(P).price << std::endl;
        P = next(P);
    }
}

void addSomeFood(List &L) {
    int n;
    std::cout << "Masukkan banyak makanan yang ingin ditambahkan: ";
    std::cin >> n;
    std::cin.ignore();

    for (int i = 0; i < n; i++) {
        std::string name;
        int price;
        std::cout << "Masukkan nama makanan: ";
        std::getline(std::cin, name);
        std::cout << "Masukkan harga makanan: ";
        std::cin >> price;
        std::cin.ignore();

        infotype x = createNewFood(name, price);
        address P = createNewElm(x);
        insertLast(L, P);
    }
}

void sellFood(List &L) {
    std::string name;
    int portion;
    std::cout << "Masukkan nama makanan: ";
    std::getline(std::cin, name);
    std::cout << "Masukkan banyak porsi: ";
    std::cin >> portion;
    std::cin.ignore();

    address P = first(L);
    while (P != nil) {
        if (info(P).name == name) {
            if (info(P).portion >= portion) {
                info(P).portion -= portion;
                std::cout << "Terjual" << std::endl;
            } else {
                std::cout << "Porsi tidak mencukupi" << std::endl;
            }
            break;
        }
        P = next(P);
    }
}

void showAvailableFood(List L) {
    address P = first(L);
    while (P != nil) {
        if (info(P).portion > 0) {
            std::cout << info(P).name << " " << info(P).portion << " " << info(P).price << std::endl;
        }
        P = next(P);
    }
}

void showSoldOutFood(List L) {
    address P = first(L);
    while (P != nil) {
        if (info(P).portion == 0) {
            std::cout << info(P).name << " " << info(P).portion << " " << info(P).price << std::endl;
        }
        P = next(P);
    }
}