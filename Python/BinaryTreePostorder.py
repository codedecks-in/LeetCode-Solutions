def postorderTraversal(root):
    ans = []
    if root == None:
         return ans
    stack1 = []
    stack2 = []
    stack1.append(root)
    while len(stack1) != 0:
        node = stack1.pop()
        stack2.append(node.val)

        if (node.left != None):
            stack1.append(node.left)
        if (node.right != None):
            stack1.append(node.right)
    return stack2[::-1]
