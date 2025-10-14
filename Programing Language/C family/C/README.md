# AVL Tree Implementation in C

## Overview
This is a complete implementation of an AVL (Adelson-Velsky and Landis) tree, a self-balancing binary search tree where the height of the left and right subtrees of any node differ by at most one.

## Features
- Complete AVL Tree implementation with:
  - Automatic balancing
  - Node insertion
  - Tree rotation (left and right)
  - Balance factor calculation
  - Visual tree representation

## Functions
- `height(Node *node)`: Returns the height of a node
- `insert(Node* node, int data)`: Inserts a new value while maintaining AVL properties
- `leftRotate(Node *x)` & `rightRotate(Node *y)`: Perform tree rotations for balancing
- `printTree(Node* root, int level, char* prefix)`: Visualizes the tree structure

## Time Complexity
- Insertion: O(log n)
- Search: O(log n)
- Rotation: O(1)

## Usage Example
```c
Node *root = NULL;
root = insert(root, 10);
root = insert(root, 20);
root = insert(root, 30);
```

## Contribution
This implementation is part of Hacktoberfest 2025 contributions. Feel free to use, modify, and improve this code. Consider adding features like:
- Deletion operation
- Tree traversal methods
- Balance visualization
- Additional balancing algorithms

## License
MIT License - Feel free to use this code for any purpose.
