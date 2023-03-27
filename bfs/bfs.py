from typing import List

class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


def bfs(root: Node) -> List[int]:
    if root is None:
        return []
    queue = [root]
    values = []
    while len(queue):
        v = queue.pop(0)
        values.append(v.val)
        for children in v.children:
            queue.append(children)
    return values
