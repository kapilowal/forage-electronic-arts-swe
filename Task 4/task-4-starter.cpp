#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <climits> // For INT_MAX

class Item {
private:
    std::string name;
    int quantity;
    float price;

public:
    Item(std::string name, int quantity, float price)
        : name{std::move(name)}, quantity{quantity}, price{price} {}

    std::string get_name() const {
        return name;
    }

    int get_quantity() const {
        return quantity;
    }

    void set_quantity(int new_quantity) {
        quantity = new_quantity;
    }

    float get_price() const {
        return price;
    }

    bool is_match(const std::string& other) const {
        return name == other;
    }
};

class Inventory {
private:
    std::vector<Item> items;
    float total_money;

    static void display_data(const Item& item) {
        std::cout << "\nItem name: " << item.get_name();
        std::cout << "\nQuantity: " << item.get_quantity();
        std::cout << "\nPrice: " << item.get_price();
    }

public:
    Inventory() : total_money{0} {}

    void add_item() {
        std::string name;
        int quantity;
        float price;

        std::cin.ignore(); // Ignore any leftover newline characters in the input buffer
        std::cout << "\nEnter item name: ";
        std::getline(std::cin, name); // Use getline to read the entire line, including spaces
        std::cout << "Enter quantity: ";
        std::cin >> quantity;
        std::cout << "Enter price: ";
        std::cin >> price;

        items.emplace_back(name, quantity, price);
    }

    void sell_item() {
        std::string item_to_check;
        std::cin.ignore(); // Ignore any leftover newline characters in the input buffer
        std::cout << "\nEnter item name: ";
        std::getline(std::cin, item_to_check); // Use getline to read the entire line, including spaces

        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->is_match(item_to_check)) {
                remove_item(it);
                return;
            }
        }
        std::cout << "\nThis item is not in your Inventory";
    }

    void remove_item(std::vector<Item>::iterator item) {
        int input_quantity;
        std::cout << "\nEnter number of items to sell: ";
        std::cin >> input_quantity;

        int quantity = item->get_quantity();
        if (input_quantity <= quantity) {
            float price = item->get_price();
            float money_earned = price * input_quantity;
            item->set_quantity(quantity - input_quantity);
            std::cout << "\nItems sold";
            std::cout << "\nMoney received: " << money_earned;
            total_money += money_earned;

            if (item->get_quantity() == 0) {
                items.erase(item);
                std::cout << "\nItem removed from inventory";
            }
        } else {
            std::cout << "\nCannot sell more items than you have.";
        }
    }

    void list_items() const {
        if (items.empty()) {
            std::cout << "\nInventory empty.";
            return;
        }

        for (const auto& item : items) {
            display_data(item);
            std::cout << "\n";
        }
    }
};

// no need to modify anything here
int main() {
    int choice;
    Inventory inventory_system;
    std::cout << "Welcome to the inventory!";

    while (true) {
        std::cout << "\n\nMENU\n"
                  << "1. Add new item\n"
                  << "2. Sell item\n"
                  << "3. List items\n"
                  << "4. Exit\n\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                inventory_system.add_item();
                break;

            case 2:
                inventory_system.sell_item();
                break;

            case 3:
                inventory_system.list_items();
                break;

            case 4:
                return 0;

            default:
                std::cout << "\nInvalid choice entered";
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                break;
        }
    }
}
