#include <iostream>
using namespace std;

template <class T>
class AVLTNode {
public:
    T key;
    AVLTNode *left;
    AVLTNode *right;
    int height;

    AVLTNode(T value, AVLTNode *l, AVLTNode *r):
            key(value), height(0), left(l), right(r) {}
};

template <class T>
class AVLTree {

private:
    AVLTNode<T> *root;

public:
    AVLTree();
    ~AVLTree();

    int height();
    int max(int a, int b);

    void preOrder();
    void inOrder();
    void postOrder();

    AVLTNode<T>* search(T key);
    AVLTNode<T>* iterativeSearch(T key);

    T minimum();
    T maximum();

    void insert(T key);
    void remove(T key);
    void destroy();
    void print();

private:
    int height(AVLTNode<T> *tree);

    void preOrder(AVLTNode<T>* tree) const;
    void inOrder(AVLTNode<T>* tree) const;
    void postOrder(AVLTNode<T>* tree) const;

    AVLTNode<T>* search(AVLTNode<T>* x, T key) const;
    AVLTNode<T>* iterativeSearch(AVLTNode<T>* x, T key) const;

    AVLTNode<T>* minimum(AVLTNode<T>* tree);
    AVLTNode<T>* maximum(AVLTNode<T>* tree);

    AVLTNode<T>* llRotation(AVLTNode<T>* k2);
    AVLTNode<T>* rrRotation(AVLTNode<T>* k1);
    AVLTNode<T>* lrRotation(AVLTNode<T>* k3);
    AVLTNode<T>* rlRotation(AVLTNode<T>* k1);

    AVLTNode<T>* insert(AVLTNode<T>* &tree, T key);
    AVLTNode<T>* remove(AVLTNode<T>* &tree, AVLTNode<T>* z);
    void destroy(AVLTNode<T>* &tree);
    void print(AVLTNode<T>* tree, T key, int direction);
};

template <class T>
AVLTree<T>::AVLTree():root(nullptr) {}

template <class T>
AVLTree<T>::~AVLTree() {
    destroy(root);
}

template <class T>
int AVLTree<T>::height(AVLTNode<T> *tree) {
    if (tree != NULL) {
        return tree->height;
    }
    return 0;
}

template <class T>
int AVLTree<T>::height() {
    return height(root);
}

template <class T>
int AVLTree<T>::max(int a, int b) {
    return a > b ? a : b;
}

template <class T>
void AVLTree<T>::preOrder(AVLTNode<T> *tree) const {
    if (tree) {
        cout << tree->key << " ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

template <class T>
void AVLTree<T>::preOrder() {
    preOrder(root);
}

template <class T>
void AVLTree<T>::inOrder(AVLTNode<T> *tree) const {
    if (tree) {
        inOrder(tree->left);
        cout << tree->key << " ";
        inOrder(tree->right);
    }
}

template <class T>
void AVLTree<T>::inOrder() {
    inOrder(root);
}

template <class T>
void AVLTree<T>::postOrder(AVLTNode<T> *tree) const {
    if (tree) {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->key << " ";
    }
}

template <class T>
void AVLTree<T>::postOrder() {
    postOrder(root);
}

template <class T>
AVLTNode<T> *AVLTree<T>::search(AVLTNode<T> *x, T key) const {
    if (x == nullptr || x->key == key) {
        return x;
    }
    return key < x->key ? search(x->left, key) : search(x->right, key);
}

template <class T>
AVLTNode<T> *AVLTree<T>::search(T key){
    search(root, key);
}

template <class T>
AVLTNode<T> *AVLTree<T>::iterativeSearch(AVLTNode<T> *x, T key) const {
    while ((x != NULL) && (x->key != key)) {
        x = key < x->key ? x->left : x->right;
    }
}

template <class T>
AVLTNode<T> *AVLTree<T>::iterativeSearch(T key) {
    iterativeSearch(root, key);
}

template <class T>
AVLTNode<T> *AVLTree<T>::minimum(AVLTNode<T> *tree) {
    if (tree == nullptr) {
        return nullptr;
    }
    while (tree->left != nullptr) {
        tree = tree->left;
    }
    return tree;
}

template <class T>
T AVLTree<T>::minimum() {
    AVLTNode<T> *p = minimum(root);
    return p == nullptr ? (T)NULL : p->key;
}

template <class T>
AVLTNode<T> *AVLTree<T>::maximum(AVLTNode<T> *tree) {
    if (tree == nullptr) {
        return nullptr;
    }
    while (tree->right) {
        tree = tree->right;
    }
    return tree;
}

template <class T>
T AVLTree<T>::maximum() {
    AVLTNode<T> *p = maximum(root);
    return p == nullptr ? (T)NULL : p->key;
}

template <class T>
AVLTNode<T>* AVLTree<T>::llRotation(AVLTNode<T> *k2) {
    AVLTNode<T>* k1;

    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    return k1;
}

template <class T>
AVLTNode<T>* AVLTree<T>::rrRotation(AVLTNode<T> *k1) {
    AVLTNode<T>* k2;

    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;
    return k2;
}

template <class T>
AVLTNode<T>* AVLTree<T>::lrRotation(AVLTNode<T> *k3) {
    k3->left = rrRotation(k3->left);
    return llRotation(k3);
}

template <class T>
AVLTNode<T>* AVLTree<T>::rlRotation(AVLTNode<T> *k1) {
    k1->right = llRotation(k1->right);
    return rrRotation(k1);
}

template <class T>
AVLTNode<T>* AVLTree<T>::insert(AVLTNode<T> *&tree, T key) {
    if (tree == nullptr) {
        tree = new AVLTNode<T>(key, NULL, NULL);
    } else if (key < tree->key) {
        tree->left = insert(tree->left, key);
        if (height(tree->left) - height(tree->right) == 2) {
            tree = key < tree->left->key ? llRotation(tree) : lrRotation(tree);
        }
    } else if (key > tree->key) {
        tree->right = insert(tree->right, key);
        if (height(tree->right) - height(tree->left) == 2) {
            tree = key > tree->right->key ? rrRotation(tree) :rlRotation(tree);
        }
    } else {
        cout << "nodes are same" << endl;
    }

    tree->height = max(height(tree->left), height(tree->right)) + 1;

    return tree;
}

template <class T>
void AVLTree<T>::insert(T key) {
    insert(root, key);
}

template <class T>
AVLTNode<T> *AVLTree<T>::remove(AVLTNode<T> *&tree, AVLTNode<T> *z) {
    if (tree == NULL || z == NULL) {
        return NULL;
    }
    if (z->key < tree->key) {
        tree->left = remove(tree->left, z);
        if (height(tree->right) - height(tree->left) == 2) {
            AVLTNode<T> *r = tree->right;
            tree = height(r->left) > height(r->right) ? rlRotation(tree) : rrRotation(tree);
        }
    } else if (z->key > tree->key) {
        tree->right = remove(tree->right, z);
        if (height(tree->left) - height(tree->right) == 2) {
            AVLTNode<T> *l = tree->left;
            tree = height(l->right) > height(l->left) ? lrRotation(tree) : llRotation(tree);
        }
    } else {
        if (tree->left && tree->right) {
            if (height(tree->left) > height(tree->right)) {
                AVLTNode<T>* max = maximum(tree->left);
                tree->key = max->key;
                tree->left = remove(tree->left, max);
            } else {
                AVLTNode<T>* min = minimum(tree->right);
                tree->key = min->key;
                tree->right = remove(tree->right, min);
            }
        } else {
            AVLTNode<T>* t = tree;
            tree = tree->left ? tree->left : tree->right;
            delete t;
        }
    }

    return tree;
}

template <class T>
void AVLTree<T>::remove(T key) {
    AVLTNode<T> *z;
    if ((z = search(root, key))) {
        root = remove(root, z);
    }
}

template <class T>
void AVLTree<T>::destroy(AVLTNode<T> *&tree) {
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
void AVLTree<T>::destroy() {
    destroy(root);
}

template <class T>
void AVLTree<T>::print(AVLTNode<T> *tree, T key, int direction) {
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
void AVLTree<T>::print() {
    if (root) {
        print(root, root->key, 0);
    }
}

int main() {
    int a[] = {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};
    auto *tree = new AVLTree<int>();

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

    cout << tree->height() << endl;
    cout << tree->minimum() << endl;
    cout << tree->maximum() << endl;
    tree->print();

    cout << 8 << endl;
    tree->remove(8);

    cout << tree->height() << endl;
    tree->inOrder();
    cout << endl;
    tree->print();
    tree->destroy();
    return 0;
}

