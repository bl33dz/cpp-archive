#include "DLL.h"

using namespace std;

int main() {
    List L;
    int menu;
    address P;

    createList(L);

    cout << "███████  ██████   ██████  ██████  ███████\n";
    cout << "██      ██    ██ ██    ██ ██   ██ ██\n";
    cout << "█████   ██    ██ ██    ██ ██   ██ ███████\n";
    cout << "██      ██    ██ ██    ██ ██   ██      ██\n";
    cout << "██       ██████   ██████  ██████  ███████\n";
    cout << endl;

    cout << "1. Tambah Makanan" << endl;
    cout << "2. Jual Makanan" << endl;
    cout << "3. Tampilkan Makanan" << endl;
    cout << "4. Tampilkan Makanan yang Tersedia" << endl;
    cout << "5. Tampilkan Makanan yang Habis" << endl;
    cout << "0. Exit" << endl;

    while(menu != 0) {

        cout << "Pilih: ";
        cin >> menu;
        cin.ignore();

        switch(menu) {
            case 1: {
                addSomeFood(L);
                break;
            }
            case 2: {
                sellFood(L);
                break;
            }
            case 3: {
                showList(L);
                break;
            }
            case 4: {
                showAvailableFood(L);
                break;
            }
            case 5: {
                showSoldOutFood(L);
                break;
            }
            case 0: {
                cout << "Exit";
                break;
            }
            default: {
                cout << "Invalid input" << endl;
                break;
            }
        }
        cout << endl;
    }
}