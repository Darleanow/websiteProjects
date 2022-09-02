// Stack en C++

#include <stdlib.h>
#include <iostream>


#define MAX 10
int size = 0;

// Initialisaton
struct stack {
    int items[MAX];
    int top;
};
typedef struct stack st;

void createEmptyStack(st * s) {
    s -> top = -1;
}

// Vérifie que la stack est pleine
int isfull(st * s) {
    if (s -> top == MAX - 1)
        return 1;
    else
        return 0;
}

// Vérifie que la stack est vide
int isempty(st * s) {
    if (s -> top == -1)
        return 1;
    else
        return 0;
}

// Ajout elems dans stack
void push(st * s, int newitem) {
    if (isfull(s)) {
        std::cout << "Stack pleine";
    } else {
        s -> top++;
        s -> items[s -> top] = newitem;
    }
    size++;
}

// Delete elems dans stack
void pop(st * s) {
    if (isempty(s)) {
        std::cout << "\n Stack vide \n";
    } else {
        std::cout << "Valeur du pop = " << s -> items[s -> top];
        s -> top--;
    }
    size--;
    std::cout << std::endl;
}

// Affichage elems
void printStack(st * s) {
    std::cout << "Stack: ";
    for (int i = 0; i < size; i++) {
        std::cout << s -> items[i] << " ";
    }
    std::cout << std::endl;
}

// fonction main avec test cases
int main() {
    int ch;
    st * s = (st * ) malloc(sizeof(st));

    createEmptyStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printStack(s);

    pop(s);

    std::cout << "\nAprès pop:\n";
    printStack(s);
}
