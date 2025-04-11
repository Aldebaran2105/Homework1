# Homework1
Implementación de una lista enlazada en C++

Este proyecto contiene una clase genérica `LinkedList<T>` que representa una lista enlazada simple. Soporta varias operaciones comunes sobre listas de manera dinámica.

## Funcionalidades implementadas

- **`push_front(T)`**: Inserta un elemento al inicio de la lista.
- **`push_back(T)`**: Inserta un elemento al final de la lista.
- **`pop_front()`**: Elimina y retorna el primer elemento de la lista.
- **`pop_back()`**: Elimina y retorna el último elemento de la lista.
- **`front()`**: Retorna el primer elemento sin eliminarlo.
- **`back()`**: Retorna el último elemento sin eliminarlo.
- **`operator[](int)`**: Accede a un elemento por su índice (nota: O(n) en listas enlazadas).
- **`empty()`**: Verifica si la lista está vacía.
- **`size()`**: Retorna la cantidad de elementos en la lista.
- **`clear()`**: Elimina todos los elementos de la lista.
- **`sort()`**: Ordena la lista en orden ascendente.
- **`reverse()`**: Invierte el orden de los elementos de la lista.
- **`print()`**: Imprime todos los elementos de la lista.

## Ejecución

Al compilar y ejecutar el programa (`main.cpp`), se demuestra el uso de cada una de las funcionalidades listadas arriba.

## Compilación

```bash
g++ -o lista main.cpp
./lista
