# Implémentation de la queue en python

class Queue:

    def __init__(self):
        self.queue = []

    # Ajout
    def enqueue(self, item):
        self.queue.append(item)

    # Suppression
    def dequeue(self):
        if len(self.queue) < 1:
            return None
        return self.queue.pop(0)

    # Affichage
    def display(self):
        print(self.queue)

    def size(self):
        return len(self.queue)


q = Queue()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
q.enqueue(4)
q.enqueue(5)

q.display()

q.dequeue()

print("Après avoir enlevé un élément")
q.display()
