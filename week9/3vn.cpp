#include <iostream>
#include <string>

// Định nghĩa lớp vật phẩm
class Item {
protected:
    std::string title; // Tên vật phẩm
    int weight; // Trọng lượng vật phẩm
    int level; // Cấp độ vật phẩm
    bool magical; // Vật phẩm có phải là phép thuật không

public:
    // Khởi tạo một vật phẩm với các tham số chỉ định
    Item(std::string title, int weight, int level, bool magical) {
        this->title = title;
        this->weight = weight;
        this->level = level;
        this->magical = magical;
    }

    // Lấy trọng lượng của vật phẩm
    int getWeight() const {
        return weight;
    }

    // Lấy cấp độ của vật phẩm
    int getLevel() const {
        return level;
    }

    // Kiểm tra xem vật phẩm có phải là phép thuật không
    int isMagical() const {
        return magical;
    }
};

// Lớp người chơi cơ bản
class Player {
protected:
    int strength; // Sức mạnh của người chơi
    int level; // Cấp độ của người chơi

public:
    // Khởi tạo người chơi
    Player() {}

    // Hủy người chơi
    virtual ~Player() {}

    // Đặt sức mạnh cho người chơi
    virtual void setStrength(int strength) final {
        this->strength = strength;
    }

    // Đặt cấp độ cho người chơi
    virtual void setLevel(int level) final {
        this->level = level;
    }

    // Lấy sức mạnh của người chơi
    virtual int getStrength() const final {
        return strength;
    }

    // Lấy cấp độ của người chơi
    virtual int getLevel() const final {
        return level;
    }

    // Kiểm tra xem người chơi có thể sử dụng vật phẩm không
    virtual bool canUse(const Item& item) const = 0;

    // Người chơi có thể thực hiện phép thuật không
    virtual bool canCast() const = 0;

    // Kiểm tra xem người chơi có thể chữa trị người chơi khác không
    virtual bool canHeal() const {
        return canCast() || getLevel() > 10;
    }
};

// Lớp Hiệp sĩ
class Knight : public Player {
public:
    // Hiệp sĩ có thể sử dụng vật phẩm
    bool canUse(const Item& item) const override {
        return !item.isMagical() && getStrength() >= item.getWeight() && getLevel() >= item.getLevel();
    }

    // Hiệp sĩ không thể thực hiện phép thuật
    bool canCast() const override {
        return false;
    }
};

// Lớp Pháp sư
class Wizard : public Player {
public:
    // Pháp sư có thể sử dụng vật phẩm
    bool canUse(const Item& item) const override {
        return getStrength() >= item.getWeight() && getLevel() >= item.getLevel();
    }

    // Pháp sư có thể thực hiện phép thuật
    bool canCast() const override {
        return true;
    }
};

int main() {
    // Tạo các vật phẩm để kiểm tra
    Item items[3] = {
        Item("Gươm nhỏ", 1, 1, false),
        Item("Gươm lớn", 5, 3, false),
        Item("Bùa", 1, 3, true)
    };

    // Tạo các người chơi để kiểm tra
    Player* players[2];
    players[0] = new Wizard();
    players[0]->setStrength(3);
    players[0]->setLevel(5);
    players[1] = new Knight();
    players[1]->setStrength(6);
    players[1]->setLevel(5);

    // Kiểm tra khả năng chữa trị
    for (int i = 0; i < 2; i++) {
        std::cout << "Có thể chữa trị: " << players[i]->canHeal() << std::endl;
    }

    // Kiểm tra khả năng sử dụng vật phẩm
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "Có thể sử dụng: " << players[i]->canUse(items[j]) << std::endl;
        }
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < 2; i++) {
        delete players[i];
    }

    return 0;
}
