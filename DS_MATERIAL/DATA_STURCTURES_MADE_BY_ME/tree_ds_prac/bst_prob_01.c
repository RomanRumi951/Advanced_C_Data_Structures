#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct tree
{
    int *data;
    struct tree *left;
    struct tree *right;
}*temp = NULL,*node = NULL, *newnode = NULL, *root = NULL;

void insert(struct tree *node);
void preorder(struct tree *node);
void inorder(struct tree *node);
void postorder(struct tree *node);

int choice, value;

int main()
{
    // struct tree ;
    
    do {
            printf("1. Insert Values:\n");gdg
            printf("2. To Print in Pre-order Traversal\n");
            printf("3. To Print in In-order Traversal\n");
            printf("4. To Print in Post-order Traversal\n");
            printf("5. Exit\n");
            printf("::Enter Your Choice::\n");
            scanf("%d ", &choice);

            switch (choice)
            {
                case 1:
                    insert(root);
                    break;
                case 2:
                    preorder(root);
                    break;
                case 3:
                    inorder(root);
                    break;
                case 4:
                    postorder(root);
                    break;
                case 5:
                    exit(0);
                    break;
                default:
                    printf("\nInvalid Choice::\n");
                    break;
            }

                printf("\nPress any key to continue::\n");
                getch();
    }while(choice != 5);

}

void insert(struct tree *node) {
    printf("\nEnter a value:\n");
    scanf("%d", &value);
    newnode = (struct tree *)malloc(sizeof(struct tree));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    
    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        temp = newnode;
        if (node->data < root )
        {
            root -> left = newnode;
        }
        else
        {
            root -> right = newnode;
        }
    }
        
        
    
    
}

void preorder(struct tree *node) {

    if (node != NULL)
    {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
    
}

void inorder(struct tree *node) {

    if (node != NULL)
    {
        preorder(node->left);
        printf("%d ", node->data);
        preorder(node->right);
    }

}

void postorder(struct tree *node) {

    if (node != NULL)
    {
        preorder(node->left);
        preorder(node->right);
        printf("%d ", node->data);
    }

}