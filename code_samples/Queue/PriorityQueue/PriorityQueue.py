# Implémentation Queue a priorité en Python


# "Heapifier" l'abre
def heapify(arr, n, i):
    # Trouver le plus gros nombre
    largest = i
    l = 2 * i + 1 #left child
    r = 2 * i + 2 #right child

    if l < n and arr[i] < arr[l]:
        largest = l

    if r < n and arr[largest] < arr[r]:
        largest = r

    # Swap et continuer "Heapifier"
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)


# Insertion elem
def insert(array, newNum):
    size = len(array)
    if size == 0:
        array.append(newNum)
    else:
        array.append(newNum)
        for i in range((size // 2) - 1, -1, -1):
            heapify(array, size, i)


# Délétion elem
def deleteNode(array, num):
    size = len(array)
    i = 0
    for i in range(0, size):
        if num == array[i]:
            break

    array[i], array[size - 1] = array[size - 1], array[i]

    array.remove(size - 1)

    for i in range((len(array) // 2) - 1, -1, -1):
        heapify(array, len(array), i)


arr = []

insert(arr, 3)
insert(arr, 4)
insert(arr, 9)
insert(arr, 5)
insert(arr, 2)

print ("Array en max-heap:" + str(arr))

deleteNode(arr, 4)
print("Après délétion d'un élément: " + str(arr))
