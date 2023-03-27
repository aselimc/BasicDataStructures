from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def postOrderDFS(root: Optional[TreeNode], result: List[int]):
    if root is None:
        return
    postOrderDFS(root.left, result)
    postOrderDFS(root.right, result)
    result.append(root.val)
