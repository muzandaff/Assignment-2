#include "Single_Linked_List.h"

using namespace std;

int main() {
    Single_Linked_List<int> list;
    int choice, value, index;

    do {
        //print menu
        cout << "\nMenu:\n";
        cout << "1.  Push Front\n";
        cout << "2.  Push Back\n";
        cout << "3.  Pop Front\n";
        cout << "4.  Pop Back\n";
        cout << "5.  Insert at Index\n";
        cout << "6.  Remove from Index\n";
        cout << "7.  Find an Element\n";
        cout << "8.  Print List\n";
        cout << "9.  Show Front Element\n";
        cout << "10. Show Back Element\n";
        cout << "11. Check Empty Status\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // push value to front
                cout << "Enter a value to push to the front: ";
                cin >> value;
                list.push_front(value);
                cout << "Value added to the front.\n";
                break;

            case 2:
                // push value to back
                cout << "Enter a value to push to the back: ";
                cin >> value;
                list.push_back(value);
                cout << "Value added to the back.\n";
                break;

            case 3:
                // pop front value
                list.pop_front();
                cout << "Front element removed.\n";
                break;

            case 4:
                // pop back element 
                list.pop_back();
                cout << "Back element removed.\n";
                break;

            case 5:
                // insert given index
                cout << "Enter the index to insert at: ";
                cin >> index;
                cout << "Enter the value to insert: ";
                cin >> value;
                list.insert(index, value);
                break;

            case 6:
                // remove given index
                cout << "Enter the index to remove from: ";
                cin >> index;
                if (list.remove(index)) {
                    cout << "Element removed from index " << index << ".\n";
                } else {
                    cout << "Invalid index.\n";
                }
                break;

            case 7:
                // find given value
                cout << "Enter the value to find: ";
                cin >> value;
                index = list.find(value);
                if (index == list.size()) {
                    cout << "Value not found.\n";
                } else {
                    cout << "Value found at index " << index << ".\n";
                }
                break;

            case 8:
                // print list
                list.print_list();
                break;

            case 9:
                // print front element
                if (!list.empty()) {
                    cout << "Front element: " << list.front() << endl;
                } else {
                    cout << "List is empty.\n";
                }
                break;

            case 10:
                // print back element
                if (!list.empty()) {
                    cout << "Back element: " << list.back() << endl;
                } else {
                    cout << "List is empty.\n";
                }
                break;

            case 11:
                // print empty status
                list.print_empty_status();
                break;

            case 12:
                // exit
                cout << "Exiting...\n";
                break;

            default:
                // invalid choice
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 12);

    return 0;
}
