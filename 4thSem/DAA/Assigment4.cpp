#include <iostream>
#include <string.h>
using namespace std;

class avlNode{
    string word, meaning;
    avlNode *left, *right;
    public:
        avlNode(){
            word = "root";
            meaning = "starting";
            left = nullptr;
            right = nullptr;
        }
        friend class avlTree;
};

class avlTree{
    public:
        avlNode *root;
        avlTree(){
            root = nullptr;
        }
        int height(avlNode *root){
            int h = 0;
            if(root != nullptr) {
                h = max(height(root->left), height(root->right)) + 1;
            }
            return h;
        }
        int diff(avlNode *node){
            return height(node->left) - height(node->right);
        }
        void insert(){
            char ch;
            do {
                avlNode *temp = new avlNode;
                cout << "Enter word: ";
                cin >> temp->word;
                cout << "Enter its meaning: ";
                cin >> temp->meaning;
                root = insert(root, temp);
                cout << "Do you want to continue? ";
                cin >> ch;
            } while(ch == 'y' || ch == 'Y');
        }
        avlNode* balance(avlNode *temp){
            int balFactor = diff(temp);
            if(balFactor > 1){
                if(diff(temp->left) > 0) temp = ll(temp);
                else temp = lr(temp);
            }
            else if(balFactor < -1){
                if(diff(temp->right) > 0) temp = rl(temp);
                else temp = rr(temp);
            }
            return temp;
        }
        avlNode* insert(avlNode *root, avlNode *temp){
            if(root == nullptr){
                root = new avlNode;
                root->word = temp->word;
                root->meaning = temp->meaning;
                root->left = nullptr;
                root->right = nullptr;
                return root;
            }
            else if(temp->word < root->word){
                root->left = insert(root->left, temp);
                root = balance(root);
            }
            else if(temp->word >= root->word){
                root->right = insert(root->right, temp);
                root = balance(root);
            }
            return root;
        }
        avlNode* rr(avlNode *parent){
            avlNode* temp = parent->right;
            parent->right = temp->left;
            temp->left = parent;
            return temp;
        }
        avlNode* ll(avlNode *parent){
            avlNode* temp = parent->left;
            parent->left = temp->right;
            temp->right = parent;
            return temp;
        }
        avlNode* lr(avlNode *parent){
            avlNode* temp = parent->left;
            parent->left = rr(temp);
            return ll(parent);
        }
        avlNode* rl(avlNode *parent){
            avlNode* temp = parent->right;
            parent->right = ll(temp);
            return rr(parent);
        }
        void display(avlNode* ptr, int level = 1){
            if (ptr != nullptr){
                display(ptr->right, level + 1);
                cout << endl;
                if (ptr == root) cout << "Root -> ";
                for (int i = 0; i < level && ptr != root; i++) cout << "        ";
                cout << ptr->word;
                display(ptr->left, level + 1);
                cout << endl;
            }
        }
        void preOrder(avlNode* root){
            if(root == nullptr) return;
            cout << root->word << " : " << root->meaning << endl;
            preOrder(root->left);
            preOrder(root->right);
        }
        void inOrder(avlNode* root){
            if(root == nullptr) return;
            inOrder(root->left);
            cout << root->word << " : " << root->meaning << endl;
            inOrder(root->right);
        }
        void postOrder(avlNode* root){
            if(root == nullptr) return;
            postOrder(root->left);
            postOrder(root->right);
            cout << root->word << " : " << root->meaning << endl;
        }
};

int main(){
    avlTree dict;
    int ch;
    while(1){
        cout << "1. Insert data\n2. Preorder traversal\n3. Inorder traversal\n4. Postorder traversal\n5. Level order traversal\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch(ch){
            case 1:
                dict.insert();
                break;
            case 2:
                cout << "Preorder traversal is:\n";
                dict.preOrder(dict.root);
                break;
            case 3:
                cout << "Inorder traversal is:\n";
                dict.inOrder(dict.root);
                break;
            case 4:
                cout << "Postorder traversal is:\n";
                dict.postOrder(dict.root);
                break;
            case 5:
                cout << "Level order traversal is:\n";
                dict.display(dict.root);
                break;
            case 6:
                cout << "Thank You!";
                return 0;
        }
    }
}