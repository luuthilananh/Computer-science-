#include <iostream>
#include <map>
#include <vector>

// Class representing an item in the inventory
class Item {
private:
    std::string name;
    unsigned weight;
    unsigned price;

public:
    Item(const std::string& name, unsigned weight, unsigned price): name(name), weight(weight), price(price) {}
    /*const std::string&: Nếu bạn không cần thay đổi chuỗi và chỉ muốn truy cập nó, bạn nên sử dụng const std::string&. 
    Điều này giúp tránh việc tạo ra một bản sao của chuỗi trong bộ nhớ và làm tăng hiệu suất chương trình của bạn.*/
    const std::string& get_name() const {
        return name;
    }

    unsigned get_weight() const {
        return weight;
    }

    unsigned get_price() const {
        return price;
    }
    // cach in chuoi khac okey hon
    // Print method to output item details
    void print(std::ostream& os) const {
        os << " " << weight << " " << price;
    }
};

// Class representing the inventory of a player
class Inventory {
private:
    unsigned size;
    std::vector<Item> items;

public:
    explicit Inventory(unsigned size) : size(size) {}
    /*Từ khóa explicit ngăn chặn việc chuyển đổi ngầm định từ một kiểu dữ liệu cơ bản thành một đối tượng của lớp được xác định.*/

    // Method to add an item to the inventory if there's enough space
    bool put(const Item& item) {
        if (get_current_weight() + item.get_weight() <= size) {
            items.push_back(item); // them 1 gtri vao cuoi vector items
            return true;
        }
        return false;
    }

    
    // Method to print the inventory items
    void print(std::ostream& os) const {
        for (const auto& item : items) {
            os << ":" << item.get_name();
            item.print(os);
            os << std::endl;
    }
}

private:
    // Helper method to get the current total weight of items in the inventory
    unsigned get_current_weight() const {
        unsigned totalWeight = 0;
        for (const auto& item : items) {
            totalWeight += item.get_weight();
        }
        return totalWeight;
    }
};

// Class representing a player
class Player {
private:
    std::string name;
    unsigned strength;
    Inventory inventory;

public:
    
    // Default constructor
    Player() : strength(0), inventory(0) {}
    Player(const std::string& name, unsigned strength) : name(name), strength(strength), inventory(strength) {}

    const std::string& get_name() const {
        return name;
    }

    // Method to add an item to the player's inventory
    bool take(const Item& item) {
        return inventory.put(item);
    }

    // Method to print player's name and inventory
    void print(std::ostream& os) const {
        os << name << std::endl;
        inventory.print(os);
    }
};

// Class representing a party of players
class Party {
private:
    std::map<std::string, Player> players;

public:
    // Method to add a player to the party
    bool add(const Player& player) {
        if (players.find(player.get_name()) == players.end()) {
            players[player.get_name()] = player;
            return true;
        }
        return false;
    }

    // Method to give an item to a player in the party
    bool give(const std::string& player_name, const Item& item) {
        auto it = players.find(player_name);
        if (it != players.end()) {
            return it->second.take(item);
        }
        return false;
    }

    // Method to print the party members and their inventories
    void print(std::ostream& os) const {
        for (const auto& pair : players) {
            pair.second.print(os);
        }
    }
};

int main() {
    // Test the classes with a party of players
    Party p;
    p.add(Player("Anti-Mage", 15));
    p.add(Player("Razor", 18));
    p.give("Razor", Item("Necronomicon", 1, 5));
    p.give("Anti-Mage", Item("Refresher_Orb", 2, 2));
    p.print(std::cout);
    return 0;
}

/*pair.secondhãy đề cập đến Playerđối tượng được liên kết với tên của từng người chơi trên playersbản đồ. 
Đối tượng này Playerchứa thông tin về trình phát và bạn có thể gọi các hàm thành viên của nó hoặc truy cập các thành viên dữ liệu của nó bằng cách sử dụng pair.second. 
Ví dụ: pair.second.get_name()sẽ cung cấp cho bạn tên của người chơi.*/