#include "SLL.h"

using namespace std;

int main() {
    List L;
    int menu;

    createList(L); // initialize List L

    while(menu != 0) {
        cout << "1. Insert Data" << endl;
        cout << "2. Delete Data" << endl;
        cout << "3. Delete Last Data" << endl; // i add this because deleteLast function is not used in deleteData function
        cout << "4. Show Data" << endl;
        cout << "0. Exit" << endl;
        cout << "Select: ";
        cin >> menu;

        cout << endl;

        switch (menu) {
            case 1: {
                string name;
                int age;
                cout << "Name: ";
                cin >> name;
                cout << "Age: ";
                cin >> age;
                insertData(L, name, age);
                break;
            }
            case 2: {
                string name;
                int age;
                cout << "Name: ";
                cin >> name;
                cout << "Age: ";
                cin >> age;
                deleteData(L, name, age);
                break;
            }
            case 3: {
                deleteLast(L);
                break;
            }
            case 4: {
                showList(L);
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