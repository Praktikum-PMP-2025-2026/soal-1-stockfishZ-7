/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 4
 *   Hari dan Tanggal    : 5 Mei 2026
 *   Nama (NIM)          : 13224074
 *   Nama File           : soal1.c
 *   Deskripsi           : Valid or invalid string of ()[]{}
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Node{
    char x;
    struct Node* left;
    struct Node* right;
} Node;

void inorderTraversal(Node* root)
{
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%c ", root->x);
    inorderTraversal(root->right);
}

void preOrder(struct Node* node) {
    if (node == NULL)
        return;

    // Visit the current node first
    printf("%c ", node->x);

    // Traverse the left subtree
    preOrder(node->left);

    // Traverse the right subtree
    preOrder(node->right);
}

void postOrder(struct Node *node)
{
    if (node == NULL)
        return;

    // First we traverse left subtree
    postOrder(node->left);

    // After visiting left, traverse right subtree
    postOrder(node->right);

    // now we visit node
    printf("%c ", node->x);
}

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for inserting a node in a binary tree
void insert(Node** root, char data)
{
    Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    // Level order traversal to find the appropriate place
    // for insertion
    Node* temp;
    Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = *root;

    while (front != rear) {
        temp = queue[++front];

        //  Insert new node as the left child
        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        }
        // if left child is not missing push it to the queue
        else {
            queue[++rear] = temp->left;
        }
        // Insert new node as the right child
        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        }
        // if right child is not missing push it to the
        // queue
        else {
            queue[++rear] = temp->right;
        }
    }
}

void remove_spaces(char* s) {
    char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}

void check(char s[]){
    int N = s[0] - '0';
    Node* root = NULL;

    for (int i =   1; i <= strlen(s); i++){
        insert(&root, s[i]);
    }
    printf ("PRE ");
    preOrder(root);
    printf("\n");
    printf ("IN ");
    inorderTraversal(root);
    printf("\n");
    printf ("POST ");
    postOrder(root);    
    printf("\n");
}

int main(){
    char s[100];
    fgets(s, 100, stdin);
    remove_spaces(s);
    for (int i = 0; i < strlen(s); i++){
        printf("%c", s[i]);
    }

    check(s);
}
