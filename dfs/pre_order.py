from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def preOrderDFS(root: Optional[TreeNode], result: List[int]):
    if root is None:
        return
    result.append(root.val)
    preOrderDFS(root.left, result)
    preOrderDFS(root.right, result)
