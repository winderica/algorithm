#include <iostream>
using namespace std;

template <class T>
class BSTNode {
public:
    T key;
    BSTNode *left;
    BSTNode *right;
    BSTNode *parent;

    BSTNode(T value, BSTNode *p, BSTNode *l, BSTNode *r):
        key(value), parent(), left(l), right(r) {}
};

template <class T>
class BSTree {

private:
    BSTNode<T> *root;

public:
    void preOrder();
    void inOrder();
    void postOrder();

    BSTNode<T>* search(T key);
    BSTNode<T>* iterativeSearch(T key);

    T minimum();
    T maximum();

    BSTNode<T>* predecessor(BSTNode<T>* x);
    BSTNode<T>* successor(BSTNode<T>* x);

    void insert(T key);
    void remove(T key);
    void destroy();
    void print();

private:
    void preOrder(BSTNode<T>* tree) const;
    void inOrder(BSTNode<T>* tree) const;
    void postOrder(BSTNode<T>* tree) const;

    BSTNode<T>* search(BSTNode<T>* x, T key) const;
    BSTNode<T>* iterativeSearch(BSTNode<T>* x, T key) const;

    BSTNode<T>* minimum(BSTNode<T>* tree);
    BSTNode<T>* maximum(BSTNode<T>* tree);

    void insert(BSTNode<T>* &tree, BSTNode<T>* z);
    BSTNode<T>* remove(BSTNode<T>* &tree, BSTNode<T>* z);
    void destroy(BSTNode<T>* &tree);
    void print(BSTNode<T>* tree, T key, int direction);
};

template <class T>
void BSTree<T>::preOrder(BSTNode<T> *tree) const {
    if (tree) {
        cout << tree->key << " ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

template <class T>
void BSTree<T>::preOrder() {
    preOrder(root);
}

template <class T>
void BSTree<T>::inOrder(BSTNode<T> *tree) const {
    if (tree) {
        inOrder(tree->left);
        cout << tree->key << " ";
        inOrder(tree->right);
    }
}

template <class T>
void BSTree<T>::inOrder() {
    inOrder(root);
}

template <class T>
void BSTree<T>::postOrder(BSTNode<T> *tree) const {
    if (tree) {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->key << " ";
    }
}

template <class T>
void BSTree<T>::postOrder() {
    postOrder(root);
}

template <class T>
BSTNode<T> *BSTree<T>::search(BSTNode<T> *x, T key) const {
    if (x == nullptr || x->key == key) {
        return x;
    }
    return key < x->key ? search(x->left, key) : search(x->right, key);
}

template <class T>
BSTNode<T> *BSTree<T>::search(T key){
    search(root, key);
}

template <class T>
BSTNode<T> *BSTree<T>::iterativeSearch(BSTNode<T> *x, T key) const {
    while ((x != NULL) && (x->key != key)) {
        x = key < x->key ? x->left : x->right;
    }
}

template <class T>
BSTNode<T> *BSTree<T>::iterativeSearch(T key) {
    iterativeSearch(root, key);
}

template <class T>
BSTNode<T> *BSTree<T>::minimum(BSTNode<T> *tree) {
    if (tree == nullptr) {
        return nullptr;
    }
    while (tree->left != nullptr) {
        tree = tree->left;
    }
    return tree;
}

template <class T>
T BSTree<T>::minimum() {
    BSTNode<T> *p = minimum(root);
    return p == nullptr ? (T)NULL : p->key;
}

template <class T>
BSTNode<T> *BSTree<T>::maximum(BSTNode<T> *tree) {
    if (tree == nullptr) {
        return nullptr;
    }
    while (tree->right) {
        tree = tree->right;
    }
    return tree;
}

template <class T>
T BSTree<T>::maximum() {
    BSTNode<T> *p = maximum(root);
    return p == nullptr ? (T)NULL : p->key;
}

template <class T>
BSTNode<T> *BSTree<T>::predecessor(BSTNode<T> *x){
    if (x->left) {
        return maximum(x->left);
    }
    BSTNode<T>* y = x->parent;
    while (y && (x == y->left)) {
        x = y;
        y = y->parent;
    }
    return y;
}

template <class T>
BSTNode<T> *BSTree<T>::successor(BSTNode<T> *x){
    if (x->right) {
        return minimum(x->right);
    }
    BSTNode<T>* y = x->parent;
    while (y && (x == y->right)) {
        x = y;
        y = y->parent;
    }
    return y;
}

template <class T>
void BSTree<T>::insert(BSTNode<T> *&tree, BSTNode<T> *z) {
    BSTNode<T>* y = nullptr;
    BSTNode<T>* x = tree;
    while (x) {
        y = x;
        if (z->key == x->key) {
            free(z);
            return;
        } else {
            x = z->key < x->key ? x->left : x->right;
        }
    }
    z->parent = y;
    if (y == nullptr) {
        tree = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
}

template <class T>
void BSTree<T>::insert(T key) {
    BSTNode<T>* z = nullptr;
    if ((z = new BSTNode<T>(key, nullptr, nullptr, nullptr)) == nullptr) {
        return;
    }
    insert(root, z);
}

template <class T>
BSTNode<T> *BSTree<T>::remove(BSTNode<T> *&tree, BSTNode<T> *z) {
    BSTNode<T>* x = nullptr;
    BSTNode<T>* y = nullptr;
    y = (z->left == nullptr) || (z->right == nullptr) ? z : successor(z);
    x = y->left == nullptr ? y->right : y->left;
    if (x) {
        x->parent = y->parent;
    }
    if (y->parent == nullptr) {
        tree = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    if (y != z) {
        z->key = y->key;
    }
    return y;
}

template <class T>
void BSTree<T>::remove(T key) {
    BSTNode<T> *z, *node;
    if ((z = search(root, key))) {
        if ((node = remove(root, z))) {
            delete node;
        }
    }
}

template <class T>
void BSTree<T>::destroy(BSTNode<T> *&tree) {
    if (tree == nullptr) {
        return;
    }
    if (tree->left) {
        destroy(tree->left);
    }
    if (tree->right) {
        destroy(tree->right);
    }
    delete tree;
    tree = nullptr;
}

template <class T>
void BSTree<T>::destroy() {
    destroy(root);
}

template <class T>
void BSTree<T>::print(BSTNode<T> *tree, T key, int direction) {
    if (tree) {
        if (direction == 0) {
            cout << tree->key << " is root" << endl;
        } else {
            cout << tree->key << " is " << key << "'s " << (direction == 1 ? "right child" : "left child") << endl;
        }
        print(tree->left, tree->key, -1);
        print(tree->right, tree->key, 1);
    }
}

template <class T>
void BSTree<T>::print() {
    if (root) {
        print(root, root->key, 0);
    }
}

int main() {
    int a[6] = {1, 5, 4, 3, 2, 6};
    auto *tree = new BSTree<int>();

    for (int i : a) {
        cout << i << " ";
        tree->insert(i);
    }
    cout << endl;

    tree->preOrder();
    cout << endl;

    tree->inOrder();
    cout << endl;

    tree->postOrder();
    cout << endl;

    cout << tree->minimum() << endl;
    cout << tree->maximum() << endl;
    tree->print();

    cout << tree->successor(tree->search(5))->key << endl;

    cout << a[3] << endl;
    tree->remove(a[3]);

    tree->inOrder();

    tree->destroy();
    return 0;
}
