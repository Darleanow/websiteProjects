// Implémentation de la file en C++

#include <iostream>
#define SIZE 5

using namespace std;

class Queue {
   private:
  int items[SIZE], front, rear;

   public:
  Queue() {
    front = -1;
    rear = -1;
  }

  bool isFull() {
    if (front == 0 && rear == SIZE - 1) {
      return true;
    }
    return false;
  }

  bool isEmpty() {
    if (front == -1)
      return true;
    else
      return false;
  }

  void enQueue(int element) {
    if (isFull()) {
      cout << "La queue est pleine";
    } else {
      if (front == -1) front = 0;
      rear++;
      items[rear] = element;
      cout << endl
         << "Inséré " << element << endl;
    }
  }

  int deQueue() {
    int element;
    if (isEmpty()) {
      cout << "La queue est vide" << endl;
      return (-1);
    } else {
      element = items[front];
      if (front >= rear) {
        front = -1;
        rear = -1;
      } /*  Q n'a qu'un élément, alors on reset la file après avoir supprimé ce dernier. */
      else {
        front++;
      }
      cout << endl
         << "Supprimé -> " << element << endl;
      return (element);
    }
  }

  void display() {
    /* Fonction pour afficher la file */
    int i;
    if (isEmpty()) {
      cout << endl
         << "Queue vide" << endl;
    } else {
      cout << endl
         << "Index du premier élément-> " << front;
      cout << endl
         << "Items -> ";
      for (i = front; i <= rear; i++)
        cout << items[i] << "  ";
      cout << endl
         << "Index du dernier élément-> " << rear << endl;
    }
  }
};

int main() {
  Queue q;

  //la méthode défile n'est pas possible sur une file vide.
  q.deQueue();

  //enQueue 5 elements
  q.enQueue(1);
  q.enQueue(2);
  q.enQueue(3);
  q.enQueue(4);
  q.enQueue(5);

  // 6eme elem ne peut etre ajouté car la file est pleine.
  q.enQueue(6);

  q.display();

  //défile enleve le premier elem, ici 1
  q.deQueue();

  //Il reste 4 elems
  q.display();

  return 0;
}
