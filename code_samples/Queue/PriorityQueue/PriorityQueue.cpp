// Queue a priorité implémentation en c++

#include <iostream>
#include <vector>
using namespace std;

// Changer place elem pour délétion
void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

// "Heapifier" l'abre 
void heapify(vector<int> &hT, int i) {
  int size = hT.size();
  
  // Trouver le plus gros de la racine
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < size && hT[l] > hT[largest])
    largest = l;
  if (r < size && hT[r] > hT[largest])
    largest = r;

  // Effectuer swap et continuer heapify
  if (largest != i) {
    swap(&hT[i], &hT[largest]);
    heapify(hT, largest);
  }
}

// Insertion d'élément
void insert(vector<int> &hT, int newNum) {
  int size = hT.size();
  if (size == 0) {
    hT.push_back(newNum);
  } else {
    hT.push_back(newNum);
    for (int i = size / 2 - 1; i >= 0; i--) {
      heapify(hT, i);
    }
  }
}

// Délétion dans l'abre
void deleteNode(vector<int> &hT, int num) {
  int size = hT.size();
  int i;
  for (i = 0; i < size; i++) {
    if (num == hT[i])
      break;
  }
  swap(&hT[i], &hT[size - 1]);

  hT.pop_back();
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(hT, i);
  }
}

// Afficher l'abre
void printArray(vector<int> &hT) {
  for (int i = 0; i < hT.size(); ++i)
    cout << hT[i] << " ";
  cout << "\n";
}

// Main
int main() {
  vector<int> heapTree;

  insert(heapTree, 3);
  insert(heapTree, 4);
  insert(heapTree, 9);
  insert(heapTree, 5);
  insert(heapTree, 2);

  cout << "Array en max-heap: ";
  printArray(heapTree);

  deleteNode(heapTree, 4);

  cout << "Après délétion d'un élément: ";

  printArray(heapTree);
}
