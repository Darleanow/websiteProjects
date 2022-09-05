# Implémentation Python de la liste chaînée

class Node:
   #Création de noeud
    def __init__(self, item):
        self.item = item
        self.next = None


class LinkedList:

    def __init__(self):
        self.head = None


if __name__ == '__main__':

    linked_list = LinkedList()

    # Assignage de valeur
    linked_list.head = Node(1)
    second = Node(2)
    third = Node(3)

    # Connecter les noeuds
    linked_list.head.next = second
    second.next = third

    # Afficher la liste et ses items
    while linked_list.head != None:
        print(linked_list.head.item, end=" ")
        linked_list.head = linked_list.head.next
