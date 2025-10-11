#include <stdio.h>
#include <stdlib.h>

// Structure of a node in the Binary Tree
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a new node (Binary Search Tree logic)
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find the node with the minimum value (used in deletion)
struct Node* findMin(struct Node* node) {
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

// Delete a node from the tree
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node to be deleted found
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Main function with switch-case menu
int main() {
    struct Node* root = NULL;
    int choice, value, n, i;

    while (1) {
        printf("\n\n====== Binary Tree Menu ======\n");
        printf("1. Insert n nodes\n");
        printf("2. Delete a node\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter how many nodes to insert: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter value %d: ", i + 1);
                    scanf("%d", &value);
                    root = insert(root, value);
                }
                printf("Nodes inserted successfully!\n");
                break;

            case 2:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    printf("Enter value to delete: ");
                    scanf("%d", &value);
                    root = deleteNode(root, value);
                    printf("Node deleted successfully (if it existed).\n");
                }
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                printf("Exiting program. Thank you!\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
