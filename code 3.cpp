#include <iostream>
#include <vector>
#include <string>

using namespace std;

void display_menu() {
    cout << "\nTo-Do List Menu" << endl;
    cout << "1. View To-Do List" << endl;
    cout << "2. Add Item" << endl;
    cout << "3. Remove Item" << endl;
    cout << "4. Exit" << endl;
}

void view_list(const vector<string>& todo_list) {
    cout << "\nTo-Do List:" << endl;
    if (todo_list.empty()) {
        cout << "No items in the list." << endl;
    } else {
        for (size_t i = 0; i < todo_list.size(); ++i) {
            cout << i + 1 << ". " << todo_list[i] << endl;
        }
    }
}

void add_item(vector<string>& todo_list) {
    cout << "Enter the item to add: ";
    string item;
    cin.ignore();  // Clear the input buffer
    getline(cin, item);
    todo_list.push_back(item);
    cout << "'" << item << "' has been added to the list." << endl;
}

void remove_item(vector<string>& todo_list) {
    view_list(todo_list);
    if (todo_list.empty()) {
        return;
    }

    cout << "Enter the number of the item to remove: ";
    int item_num;
    cin >> item_num;

    if (item_num >= 1 && item_num <= static_cast<int>(todo_list.size())) {
        string removed_item = todo_list[item_num - 1];
        todo_list.erase(todo_list.begin() + (item_num - 1));
        cout << "'" << removed_item << "' has been removed from the list." << endl;
    } else {
        cout << "Invalid item number." << endl;
    }
}

int main() {
    vector<string> todo_list;
    while (true) {
        display_menu();
        cout << "Choose an option: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                view_list(todo_list);
                break;
            case 2:
                add_item(todo_list);
                break;
            case 3:
                remove_item(todo_list);
                break;
            case 4:
                cout << "Exiting the to-do list application." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

