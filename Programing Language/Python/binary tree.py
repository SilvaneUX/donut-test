class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

# filling nodes
a = Node("a")
b = Node("b")
c = Node("c")
d = Node("d")
e = Node("e")
f = Node("f")

# connecting nodes
a.left = b
a.right = c
b.left = d
b.right = e
c.right = f

# how its look like:
#          a
#         / \
#        b   c
#       / \   \
#      d   e   f

#depth first value
def depthFirstVal(root):
    # temp
    stack = [root]
    res = []
    # cek apakah semua nodes di tree udah tercari
    while (len(stack) > 0):
        current = stack.pop()
        res.append(current.val)

        # cek apakah punya anak di kanan
        if(current.right):
            stack.append(current.right)
        #cek apakah punya anak di kiri
        if(current.left):
            stack.append(current.left)

    return res

print(depthFirstVal(a))
print("Executed!")