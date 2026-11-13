#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

static struct node *createNode(int value)
{
    struct node *newNode = malloc(sizeof *newNode);
    if (newNode == NULL) {
        perror("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

static struct node *insert(struct node *root, int value)
{
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        printf("Duplicate elements are not allowed.\n");
    }

    return root;
}

static void inorder(const struct node *root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

static void preorder(const struct node *root)
{
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

static void postorder(const struct node *root)
{
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

static struct node *findMin(struct node *root)
{
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

static struct node *deleteNode(struct node *root, int value, int *found)
{
    if (root == NULL) {
        return NULL;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value, found);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value, found);
    } else {
        struct node *temp;
        *found = 1;

        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        /* Replace this node with its in-order successor. */
        temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data, found);
    }

    return root;
}

static void freeTree(struct node *root)
{
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void)
{
    struct node *root = NULL;
    int choice;
    int value;

    do {
        printf("\n---- BINARY SEARCH TREE ----\n");
        printf("1. Insert\n");
        printf("2. Inorder traversal\n");
        printf("3. Preorder traversal\n");
        printf("4. Postorder traversal\n");
        printf("5. Delete a node\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input.\n");
            freeTree(root);
            return EXIT_FAILURE;
        }

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            if (scanf("%d", &value) != 1) {
                fprintf(stderr, "Invalid input.\n");
                freeTree(root);
                return EXIT_FAILURE;
            }
            root = insert(root, value);
            break;
        case 2:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 5: {
            int found = 0;
            printf("Enter value to delete: ");
            if (scanf("%d", &value) != 1) {
                fprintf(stderr, "Invalid input.\n");
                freeTree(root);
                return EXIT_FAILURE;
            }
            root = deleteNode(root, value, &found);
            if (!found) {
                printf("Element not found.\n");
            }
            break;
        }
        case 6:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 6);

    freeTree(root);
    return EXIT_SUCCESS;
}
