def init_stack():
  stack =[]
  return stack

def isEmpty():
  return len(stack)==0

def push(stack,item):
  stack.append(item)
  
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
