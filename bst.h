/*
 * Proyecto "Gestión de Vendedores y Ventas" clase Empresa
 * 
 * Diego Gerardo Sanchez Moreno
 * A01276011
 * 15/10/2023
 * 
 * Implementación de un árbol binario de búsqueda (BST).
 */

#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std; // Agregamos esta línea para usar std::cout

template <class T> class BST;

/**
 * Clase TreeNode representa un nodo en el árbol binario de búsqueda (BST).
 */
template <class T>
class TreeNode {
private:
    T value;
    TreeNode *left, *right;
    TreeNode<T> *successor();

public:
    TreeNode(T);
    TreeNode(T, TreeNode<T> *, TreeNode<T> *);
    void add(T);
    bool find(T);
    void remove(T);
    void removeChildren();
    void inorder(std::stringstream &) const;

    friend class BST<T>;
};

/**
 * Encuentra el sucesor del nodo actual.
 *
 * @return Puntero al sucesor del nodo actual.
 */
template <class T>
TreeNode<T> *TreeNode<T>::successor() {
    TreeNode<T> *successor = left;
    TreeNode<T> *ancestor = this;
    if (successor == NULL) {
        successor = right;
        if (right == NULL) {
            return NULL;
        } else {
            while (successor->left != NULL) {
                ancestor = successor;
                successor = successor->left;
            }
            if (successor->right != NULL) {
                ancestor->left = successor->right;
            }
            successor->right = NULL;
            return successor;
        }
    } else {
        if (successor->right == NULL) {
            ancestor->left = successor->left;
            successor->left = NULL;
            return successor;
        }
        while (successor->right != NULL) {
            ancestor = successor;
            successor = successor->right;
        }
        ancestor->right = successor->left;
        successor->left = NULL;
        return successor;
    }
}

/**
 * Constructor de TreeNode.
 *
 * @param val Valor a almacenar en el nodo.
 */
template <class T>
TreeNode<T>::TreeNode(T val) {
    value = val;
    left = NULL;
    right = NULL;
}

/**
 * Constructor de TreeNode con nodos hijos izquierdo y derecho.
 *
 * @param val Valor a almacenar en el nodo.
 * @param le Nodo hijo izquierdo.
 * @param ri Nodo hijo derecho.
 */
template <class T>
TreeNode<T>::TreeNode(T val, TreeNode<T> *le, TreeNode<T> *ri) {
    value = val;
    left = le;
    right = ri;
}

/**
 * Agrega un valor al nodo.
 *
 * @param val Valor a agregar.
 */
template <class T>
void TreeNode<T>::add(T val) {
    if (val->get_num_ventas() >= value->get_num_ventas()) {
        if (left == NULL) {
            TreeNode<T> *new_node = new TreeNode<T>(val);
            left = new_node;
        } else {
            left->add(val);
        }
    } else {
        if (right == NULL) {
            TreeNode<T> *new_node = new TreeNode<T>(val);
            right = new_node;
        } else {
            right->add(val);
        }
    }
}

/**
 * Busca un valor en el nodo y sus descendientes.
 *
 * @param val Valor a buscar.
 * @return true si el valor se encuentra, false en caso contrario.
 */
template <class T>
bool TreeNode<T>::find(T val) {
    if (val == value) {
        return true;
    }
    if (val < value) {
        if (left == NULL) {
            return false;
        }
        return left->find(val);
    } else {
        if (right == NULL) {
            return false;
        }
        return right->find(val);
    }
}

/**
 * Elimina un valor del nodo y sus descendientes.
 *
 * @param val Valor a eliminar.
 */
template <class T>
void TreeNode<T>::remove(T val) {
    if (val < value) {
        if (left->value == val) {
            if (left->left == NULL && left->right == NULL) {
                delete left;
                left = NULL;
            } else {
                TreeNode<T> *successor = left->successor();
                successor->left = left->left;
                successor->right = left->right;
                left->left = NULL;
                left->right = NULL;
                delete left;
                left = successor;
            }
        } else {
            left->remove(val);
        }
    } else {
        if (right->value == val) {
            if (right->left == NULL && right->right == NULL) {
                delete right;
                right = NULL;
            } else {
                TreeNode<T> *successor = right->successor();
                successor->left = right->left;
                successor->right = right->right;
                right->left = NULL;
                right->right = NULL;
                delete right;
                right = successor;
            }
        } else {
            right->remove(val);
        }
    }
}

/**
 * Elimina todos los hijos del nodo.
 */
template <class T>
void TreeNode<T>::removeChildren() {
    if (left != NULL) {
        left->removeChildren();
        delete left;
        left = NULL;
    }
    if (right != NULL) {
        right->removeChildren();
        delete right;
        right = NULL;
    }
}

/**
 * Realiza un recorrido en orden del nodo y sus descendientes, almacenando
 * los valores en una cadena de texto.
 *
 * @param aux Cadena de texto para almacenar los valores.
 */
template <class T> void TreeNode<T>::inorder(std::stringstream &aux) const {
    if (left != 0) {
        left->inorder(aux);
        aux << " "; // Agregar un espacio entre empleados
    }
    aux << value -> to_string(); // Llamar al método to_string del empleado y agregarlo a la cadena
    if (right != 0) {
        aux << " "; // Agregar un espacio entre empleados
        right->inorder(aux);
    }
}


/**
 * Clase BST representa un árbol binario de búsqueda (BST).
 */
template <class T>
class BST {
private:
    TreeNode<T> *root;
    void inorderToList(vector<T>& result, TreeNode<T>* current) const;

public:
    BST();
    ~BST();
    bool empty() const;
    void add(T);
    bool find(T) const;
    void remove(T);
    void removeAll();
    void inorder(std::stringstream &) const;
    void inorderToList(vector<T>& result) const;
};

/**
 * Constructor de BST que inicializa el árbol como vacío.
 */
template <class T>
BST<T>::BST() : root(NULL) {}

/**
 * Destructor de BST que elimina todos los nodos y libera la memoria.
 */
template <class T>
BST<T>::~BST() {
    removeAll();
}

/**
 * Comprueba si el árbol está vacío.
 *
 * @return true si el árbol está vacío, false en caso contrario.
 */
template <class T>
bool BST<T>::empty() const {
    return (root == NULL);
}

/**
 * Agrega un valor al árbol.
 *
 * @param val Valor a agregar al árbol.
 */
template <class T>
void BST<T>::add(T val) {
    if (empty()) {
        TreeNode<T> *new_node = new TreeNode<T>(val);
        root = new_node;
    } else {
        root->add(val);
    }
}

/**
 * Busca un valor en el árbol.
 *
 * @param val Valor a buscar.
 * @return true si el valor se encuentra en el árbol, false en caso contrario.
 */
template <class T>
bool BST<T>::find(T val) const {
    if (empty()) {
        return false;
    }
    return root->find(val);
}

/**
 * Elimina un valor del árbol.
 *
 * @param val Valor a eliminar del árbol.
 */
template <class T>
void BST<T>::remove(T val) {
    if (!root->find(val)) {
        cout << "Error";
    }

    if (val == root->value) {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        } else {
            TreeNode<T> *successor = root->successor();
            successor->left = root->left;
            successor->right = root->right;
            root->left = NULL;
            root->right = NULL;
            delete root;
            root = successor;
        }
    } else {
        root->remove(val);
    }
}

/**
 * Elimina todos los nodos del árbol y libera la memoria.
 */
template <class T>
void BST<T>::removeAll() {
    if (!empty()) {
        root->removeChildren();
        delete root;
        root = NULL;
    }
}

/**
 * Realiza un recorrido en orden del árbol, almacenando los valores en una cadena de texto.
 *
 * @param aux Cadena de texto con los valores en orden.
 */
template <class T> void BST<T>::inorder(std::stringstream &aux) const {
    if (root != nullptr) {
        root->inorder(aux);
    }
}

template <class T>
void BST<T>::inorderToList(vector<T>& result, TreeNode<T>* current) const {
    if (current != nullptr) {
        inorderToList(result, current->left);  // Recorre el subárbol izquierdo

        // Agrega el valor del nodo actual al vector
        result.push_back(current->value);

        inorderToList(result, current->right);  // Recorre el subárbol derecho
    }
}

template <class T>
void BST<T>::inorderToList(vector<T>& result) const {
    inorderToList(result, root);
}

#endif // BST_H_