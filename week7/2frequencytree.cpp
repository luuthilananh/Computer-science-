#include <iostream>

class FrequencyTree {
private:
    struct TreeNode {
        int value;
        int frequency;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val) : value(val), frequency(1), left(nullptr), right(nullptr) {} // khoi tao goc cua cay nullptrbiểu diễn con trỏ không trỏ đến bất kỳ đối tượng nào. 
    };
    //TreeNode là một cấu trúc trong lớp FrequencyTree, được sử dụng để đại diện cho mỗi nút trong cây. 
    TreeNode* root;
    //Trong lớp FrequencyTree, con trỏ root được sử dụng để giữ nút gốc của cây.
    /*Khi chúng ta thêm một giá trị mới vào cây, 
    chúng ta bắt đầu từ nút gốc và di chuyển xuống cây dựa trên giá trị của các nút để tìm vị trí phù hợp để chèn giá trị mới. */

    void addValueHelper(TreeNode*& node, int value) {
        if (!node) {
            node = new TreeNode(value);
            return;
        }

        if (value < node->value)
            addValueHelper(node->left, value);//nut co gia tri nho hon ben trai
        else if (value > node->value)
            addValueHelper(node->right, value);
        else
            node->frequency++;
    }

    void printValuesHelper(TreeNode* node) {
        if (node) {
            printValuesHelper(node->left);
            std::cout << node->value << " " << node->frequency << std::endl;
            printValuesHelper(node->right);
        }
    }

public:
    FrequencyTree() : root(nullptr) {}

    void addValue(int value) {
        addValueHelper(root, value);
    }

    void printValues() {
        printValuesHelper(root);
    }

    ~FrequencyTree() {
        clear(root);
    }

    void clear(TreeNode* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
};

int main() {
    FrequencyTree tree;

    // Thêm các giá trị vào cây
    tree.addValue(4);
    tree.addValue(5);
    tree.addValue(2);
    tree.addValue(2);
    tree.addValue(5);

    // In các giá trị trong cây
    tree.printValues();

    return 0;
}