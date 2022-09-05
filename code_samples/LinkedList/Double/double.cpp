#include <iostream>
using namespace std;

// Création de noeud
struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

// Insertion au front
void insertFront(struct Node** head, int data) {
  // Allouage mémoire
  struct Node* newNode = new Node;

  // Allouage Data
  newNode->data = data;

  // nouveau node en tant que head
  newNode->next = (*head);

  // Assigner null a newNode-
  newNode->prev = NULL;

  // Ctrl Z du head
  if ((*head) != NULL)
    (*head)->prev = newNode;

  // head pointe vers newNode
  (*head) = newNode;
}

// Insertion d'un noeud 
void insertAfter(struct Node* prev_node, int data) {
  // check if previous node is null
  if (prev_node == NULL) {
    cout << "previous node cannot be null";
    return;
  }

  // allocation mémoire pour un nouveau noeud
  struct Node* newNode = new Node;

  // Allocation data 
  newNode->data = data;

  // mettre nouveau noeud vers celui d'avant
  newNode->next = prev_node->next;

  prev_node->next = newNode;

  newNode->prev = prev_node;

  if (newNode->next != NULL)
    newNode->next->prev = newNode;
}


void insertEnd(struct Node** head, int data) {

  struct Node* newNode = new Node;


  newNode->data = data;

  newNode->next = NULL;


  struct Node* temp = *head;


  if (*head == NULL) {
    newNode->prev = NULL;
    *head = newNode;
    return;
  }


  while (temp->next != NULL)
    temp = temp->next;


  temp->next = newNode;


  newNode->prev = temp;
}

void deleteNode(struct Node** head, struct Node* del_node) {

  if (*head == NULL || del_node == NULL)
    return;


  if (*head == del_node)
    *head = del_node->next;

  if (del_node->next != NULL)
    del_node->next->prev = del_node->prev;


  if (del_node->prev != NULL)
    del_node->prev->next = del_node->next;

  // Libérer memoire
  free(del_node);
}

// Afficher la liste 
void displayList(struct Node* node) {
  struct Node* last;

  while (node != NULL) {
    cout << node->data << "->";
    last = node;
    node = node->next;
  }
  if (node == NULL)
    cout << "NULL\n";
}

int main() {
  // init des noeuds
  struct Node* head = NULL;

  insertEnd(&head, 5);
  insertFront(&head, 1);
  insertFront(&head, 6);
  insertEnd(&head, 9);

  // insertion 11 apres HEAD
  insertAfter(head, 11);

  // Insertion 15 apres deuxieme noeud
  insertAfter(head->next, 15);

  displayList(head);

  // Délétion dernier noeud
  deleteNode(&head, head->next->next->next->next->next);

  displayList(head);
}
