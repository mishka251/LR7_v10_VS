#include <iostream>

class TreeNode {
    TreeNode* left, * right;
    int value;
public:
    TreeNode(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }

    ~TreeNode() {
        if (this->right != nullptr) {
            delete this->right;
        }
        if (this->left != nullptr) {
            delete this->left;
        }
    }

    void print(int level = 0) {
        if (this->right) {
            this->right->print(level + 1);
        }
        for (int i = 0; i < level; i++) {
            std::cout << "  ";
        }
        std::cout << this->value << std::endl;
        if (this->left) {
            this->left->print(level + 1);
        }
    }

    void insert(int value) {
        if (value > this->value) {
            if (this->right == nullptr) {
                this->right = new TreeNode(value);
            }
            else {
                this->right->insert(value);
            }
        }
        else {
            if (this->left == nullptr) {
                this->left = new TreeNode(value);
            }
            else {
                this->left->insert(value);
            }
        }
    }

    int getHeight() {
        int h = 1;
        if (this->left != nullptr) {
            h = this->left->getHeight() + 1;
        }
        if (this->right != nullptr) {
            int rightHeight = this->right->getHeight();
            if (rightHeight + 1 > h) {
                h = rightHeight + 1;
            }
        }
        return h;
    }

    void printLongestPath() {
        std::cout << this->value << "  ";
        bool nextRight = (this->right != nullptr && (this->left == nullptr || this->right->getHeight() >= this->left->getHeight()));

        bool nextLeft = (this->left != nullptr && (this->right == nullptr || this->right->getHeight() < this->left->getHeight()));
        if (nextRight) {
            this->right->printLongestPath();
        }
        if (nextLeft) {
            this->left->printLongestPath();
        }
    }

    void symmetricTree() {
        TreeNode* tmp = this->left;
        this->left = this->right;
        this->right = tmp;
        if (this->right) {
            this->right->symmetricTree();
        }
        if (this->left) {
            this->left->symmetricTree();
        }
    }
};

int main() {
    int n;
    std::cout << "Elements count" << std::endl;
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Incorrect value" << std::endl;
        return 0;
    }
    int a;
    std::cout << "a[0]=" << std::endl;
    std::cin >> a;
    TreeNode* root = new TreeNode(a);
    for (int i = 1; i < n; i++) {
        std::cout << "a[" << i << "]=" << std::endl;
        std::cin >> a;
        root->insert(a);
    }

    std::cout << "Tree" << std::endl;
    root->print();

    std::cout << "longest path" << std::endl;
    root->printLongestPath();
    std::cout << std::endl;

    root->symmetricTree();

    std::cout << "Symmetric Tree" << std::endl;
    root->print();

    return 0;
}