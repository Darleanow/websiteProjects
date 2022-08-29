#Implémentation Stack en python

#Création de la stack
def init_stack():
  stack =[]
  return stack

#Verifier si elle est vide
def isEmpty():
  return len(stack)==0

#Ajout d'élément dedans
def push(stack,item):
  stack.append(item)
  
#Suppression d'élément  
def pop(stack):
  if not isEmpty(stack):
    return stack.pop()

stack = init_stack()
push(stack, str(1))
push(stack, str(2))
push(stack, str(3))
push(stack, str(4))
print("Pop = " + pop(stack))
print("Après pop: " + str(stack))
