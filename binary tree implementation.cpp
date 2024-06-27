#include <stdio.h>

#define MAX_NODES 100

struct Node {
    int data;
    int left;
    int right;
};

struct Node tree[MAX_NODES];
int nodeCount = 0;

// Fungsi untuk membuat node baru
int createNode(int data) {
    if (nodeCount >= MAX_NODES) {
        printf("Memory full\n");
        return -1;
    }
    tree[nodeCount].data = data;
    tree[nodeCount].left = -1;
    tree[nodeCount].right = -1;
    return nodeCount++;
}

// Fungsi untuk menyisipkan node baru dalam pohon biner
int insert(int rootIndex, int data) {
    if (rootIndex == -1) {
        return createNode(data);
    }
    if (data < tree[rootIndex].data) {
        int leftIndex = tree[rootIndex].left;
        tree[rootIndex].left = insert(leftIndex, data);
    } else if (data > tree[rootIndex].data) {
        int rightIndex = tree[rootIndex].right;
        tree[rootIndex].right = insert(rightIndex, data);
    }
    return rootIndex;
}

// Fungsi untuk traversal inorder
void inorderTraversal(int rootIndex) {
    if (rootIndex != -1) {
        inorderTraversal(tree[rootIndex].left);
        printf("%d ", tree[rootIndex].data);
        inorderTraversal(tree[rootIndex].right);
    }
}

// Fungsi untuk traversal preorder
void preorderTraversal(int rootIndex) {
    if (rootIndex != -1) {
        printf("%d ", tree[rootIndex].data);
        preorderTraversal(tree[rootIndex].left);
        preorderTraversal(tree[rootIndex].right);
    }
}

// Fungsi untuk traversal postorder
void postorderTraversal(int rootIndex) {
    if (rootIndex != -1) {
        postorderTraversal(tree[rootIndex].left);
        postorderTraversal(tree[rootIndex].right);
        printf("%d ", tree[rootIndex].data);
    }
}

int main() {
    int root = -1;
    int data, choice;

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}


