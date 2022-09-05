// Implémentation C++ de la liste chaînée
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Création de noeud
class Node {
   public:
  int value;
  Node* next;
};

int main() {
  Node* head;
  Node* one = NULL;
  Node* two = NULL;
  Node* three = NULL;

  // allouer 3 noeuds
  one = new Node();
  two = new Node();
  three = new Node();

  // Assigner leurs valeurs
  one->value = 1;
  two->value = 2;
  three->value = 3;

  // Connecter les noeuds
  one->next = two;
  two->next = three;
  three->next = NULL;

  // Afficher la liste et ses valeurs
  head = one;
  while (head != NULL) {
    cout << head->value;
    head = head->next;
  }
}
