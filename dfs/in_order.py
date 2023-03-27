from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def inOrderDFS(root: Optional[TreeNode], result: List[int]):
    if root is None:
        return
    inOrderDFS(root.left, result)
    result.append(root.val)
    inOrderDFS(root.right, result)
