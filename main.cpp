
#include <iostream>
#include <utility>
using namespace std;

template <class T>
class LinkedList{
    struct Nodo{
        T data;
        Nodo* next;
    };

    Nodo* head;
public:
    LinkedList() : head(nullptr){}
    ~LinkedList();

    T front();
    T back();
    void push_front(T);
    void push_back(T);
    T pop_front();
    T pop_back();
    T operator[ ](int);
    bool empty();
    int size();
    void clear();
    void sort();
    void reverse();

    void print() {
        Nodo* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main(){
    LinkedList<int> lista;

    cout << "Agregando elementos al final: 10, 20" << endl;
    lista.push_back(1);
    lista.push_back(3);
    lista.push_back(8);
    lista.push_back(2);
    lista.push_back(5);
    lista.push_back(7);
    lista.push_back(10);
    lista.push_back(4);
    lista.push_back(6);
    lista.print();

    cout << "Agregando elemento elemento al inicio: " << endl;
    lista.push_front(9);
    lista.print();

    cout << "Primer elemento (front): " << lista.front() << endl;
    cout << "Ultimo elemento (back): " << lista.back() << endl;

    cout << "Tamanio de la lista: " << lista.size() << endl;

    cout << "Accediendo por indice: ";
    for (int i = 0; i < lista.size(); ++i) {
        cout << lista[i] << " ";
    }
    cout << endl;

    cout << "Ordenando la lista..." << endl;
    lista.sort();
    lista.print();

    cout << "Revirtiendo la lista..." << endl;
    lista.reverse();
    lista.print();

    cout << "Eliminando primero (pop_front): " << lista.pop_front() << endl;
    lista.print();

    cout << "Eliminando ultimo (pop_back): " << lista.pop_back() << endl;
    lista.print();

    cout << "Limpiando toda la lista..." << endl;
    lista.clear();
    cout << "La lista esta vacia? " << (lista.empty() ? "Si" : "No") << endl;

    return 0;
}


template<class T>
LinkedList<T>::~LinkedList(){
    while(head){
        Nodo* temp = head;
        head = head -> next;
        delete temp;
    }
}

template<class T>
T LinkedList<T>::front(){
    if(head == NULL){
        return T();
    }

    if(head){
        return head -> data;
    }
}

template<class T>
T LinkedList<T>::back(){
    if(head == NULL){
        cout << "Lista vacia" << endl;
        return T();
    }

    Nodo *temp = head;
    while(temp -> next != nullptr){
        temp = temp -> next;
    }
    return temp -> data;
}

template<class T>
void LinkedList<T>::push_front(T n){
    Nodo *nodo = new Nodo();
    nodo -> data = n;
    nodo -> next = head;
    head = nodo;
}

template<class T>
void LinkedList<T>::push_back(T n){
    Nodo *lista = new Nodo();
    lista -> data = n;
    lista -> next = nullptr;

    if(head == NULL){
        head = lista;
        return;
    }

    Nodo *temp = head;
    while(temp -> next){
        temp = temp -> next;
    }
    temp -> next = lista;
}

template<class T>
T LinkedList<T>::pop_front(){
    if (head == nullptr) {
        cout << "Lista vacia" << endl;
        return T();
    }
    Nodo* temp = head;
    T valor = temp->data;
    head = head->next;
    delete temp;
    return valor;
}


template<class T>
T LinkedList<T>::pop_back(){
    if (head == nullptr) {
        cout << "Lista vacia" << endl;
        return T();
    }

    if (head->next == nullptr) {
        T valor = head->data;
        delete head;
        head = nullptr;
        return valor;
    }

    Nodo* current = head;
    while (current->next->next != nullptr){
        current = current->next;
    }

    T valor = current->next->data;
    delete current->next;
    current->next = nullptr;
    return valor;
}


template<class T>
T LinkedList<T>::operator[](int index){
    if(index < 0){
        cout << "Error: índice negativo.\n";
        return T();
    }

    Nodo* temp = head;
    int count = 0;

    while(temp != nullptr){
        if(count == index){
            return temp->data;
        }
        temp = temp->next;
        count++;
    }

    cout << "Error: índice fuera de rango.\n";
    return T();
}


template<class T>
bool LinkedList<T>::empty(){
    return head == nullptr;
}

template<class T>
int LinkedList<T>::size(){
    int contador = 0;
    Nodo *current = head;
    while(current){
        ++contador;
        current = current -> next;
    }
    return contador;
}

template<class T>
void LinkedList<T>::clear(){
    while(head != NULL){
        Nodo *temp = head;
        head = head -> next;
        delete temp;
    }
}

template<class T>
void LinkedList<T>::sort(){
    if(head == NULL || head -> next == NULL){
        return;
    }

    bool swapped;
    do{
        swapped = false;
        Nodo *current = head;
        while(current -> next){
            if(current -> data > current -> next -> data){
                swap(current -> data, current -> next -> data);
                swapped = true;
            }
            current = current->next;
        }
    }while(swapped);
}

template<class T>
void LinkedList<T>::reverse(){
    Nodo* prev = nullptr;
    Nodo* current = head;
    Nodo* next = nullptr;

    while (current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}
