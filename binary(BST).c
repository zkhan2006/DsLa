#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    
    return root;
}


struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}


struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}


struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    // Traverse to the correct 
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with one child or no child
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

        // Node with two children: Get inorder successor
        struct Node* temp = findMin(root->right);

       
        root->data = temp->data;

       
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display (Inorder Traversal)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Node inserted successfully.\n");
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("Node deleted successfully.\n");
            break;

        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (search(root, value))
                printf("Value found in the tree.\n");
            else
                printf("Value not found in the tree.\n");
            break;

        case 4:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 5:
            printf("Exiting program.\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

