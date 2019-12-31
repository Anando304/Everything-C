#include "expr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Assignment #3: Binary Search Trees
Author: Anando Zaman
Date: November 9, 2019
Course: Software ENG 2S03
*/

char *makeString(char *s1, char *s2, char *s3) {

  /*length calculation to allocate memory for concatenation */
  int concatenated_length = strlen(s1) + strlen(s2) + strlen(s3) + 1;

  char *result = (char *)malloc(sizeof(char) * concatenated_length);
  *result = (char){0}; /* Initialize to 0 to avoid jump conditional errors*/

  /* return NULL if memory cannot be allocated */
  if (result == NULL) {
    return result;
  }

  /*Concatenate strings*/
  strcpy(result, s1);
  strcat(result, s2);
  strcat(result, s3);

  return result;
}

Node *createNode(char *s, double val) {
  Node *node_pointer =
      (Node *)malloc(sizeof(Node)); /*Allocates memory for the node*/

  if (node_pointer == NULL) {
    return node_pointer;
  }

  *node_pointer = (Node){0};

  if (s != NULL) {
    char *s_copy = (char *)malloc(
        sizeof(char) * (strlen(s) + 1)); /*Allocation of memory to copy string*/
    *s_copy = (char){0};
    strcpy(s_copy, s);
    node_pointer->expr_string = s_copy;
  }

  node_pointer->left = NULL;
  node_pointer->right = NULL;
  node_pointer->value = val;
  node_pointer->num_parents = 0;

  return node_pointer;
}

Node *binop(Operation op, Node *a, Node *b) {

  Node *binopNode_pointer = (Node *)malloc(sizeof(Node));

  if (binopNode_pointer == NULL) {
    return NULL;
  }

  *binopNode_pointer = (Node){0};

  if ((a->num_parents == 1) || (b->num_parents == 1)) {
    return NULL;
  }

  binopNode_pointer->left = a;
  binopNode_pointer->right = b;
  binopNode_pointer->operation = op;
  binopNode_pointer->value = 0;

  a->num_parents = 1;
  b->num_parents = 1;

  /*Temporary variables to store makeString results*/
  char *temp = NULL;
  char *temp1 = NULL;
  char *temp_combined = NULL;

  /*Assigning Arithmetic Operator*/
  switch (op) {
  case 0:
    temp_combined = makeString(a->expr_string, "+", b->expr_string);
    break;

  case 1:
    temp_combined = makeString(a->expr_string, "-", b->expr_string);
    break;

  case 2:
    temp = makeString(
        "(", a->expr_string,
        ")"); /*Adds brackets to values before combining in temp_combined*/
    temp1 = makeString("(", b->expr_string, ")");
    temp_combined =
        makeString(temp, "*", temp1); /* Combines both node values. */
    break;

  case 3:
    temp = makeString("(", a->expr_string, ")");
    temp1 = makeString("(", b->expr_string, ")");
    temp_combined = makeString(temp, "/", temp1);
    break;
  }

  /* Save final combined string*/
  char *combined_makestring =
      (char *)malloc(sizeof(char) * (strlen(temp_combined) + 1));
  *combined_makestring = (char){0};
  strcpy(combined_makestring, temp_combined);
  binopNode_pointer->expr_string = combined_makestring;

  /*Free memory from makeString function calls*/
  free(temp);
  free(temp1);
  free(temp_combined);

  return binopNode_pointer;
}

double evalTree(Node *root) {

  /*Base case: if tree provided is empty */
  if (root == NULL) {
    return 0;
  }

  /*If reaches a leaf node (where child left and right nodes have no values
   * (NULL))*/
  if ((root->left == NULL) && (root->right == NULL)) {
    return root->value;
  }

  /*For each recursive Left subtree value*/
  double left_value = evalTree(root->left);

  /*For each recursive Right subtree value */
  double right_value = evalTree(root->right);

  /*Find the operator type*/
  switch (root->operation) {
  case 0:
    root->value = left_value + right_value;
    return left_value + right_value;

  case 1:
    root->value = left_value - right_value;
    return left_value - right_value;

  case 2:
    root->value = left_value * right_value;
    return left_value * right_value;

  case 3:
    root->value = left_value / right_value;
    return left_value / right_value;
  }

  return 0;
}

void freeTree(Node *root) {
  /* Base case: if tree provided is empty */
  if (root == NULL) {
    return;
  }

  freeTree(root->left);
  freeTree(root->right);

  free(root->expr_string);
  free(root);
}

Node *duplicateTree(Node *root) {
  /*Traverse through the tree to reach the bottom(leaf nodes) and then go back
  up the tree while copying the values to a new node*/

  /* Base case: if tree provided is empty or if reaches leaf nodes*/
  if (root == NULL) {
    return NULL;
  }

  Node *duplicateTree_pointer = malloc(sizeof(Node));

  if (duplicateTree_pointer == NULL) {
    return NULL;
  }

  *duplicateTree_pointer = (Node){0};

  duplicateTree_pointer->left =
      duplicateTree(root->left); /* create copy of left subtree/child */
  duplicateTree_pointer->right =
      duplicateTree(root->right); /* create copy of right subtree/child */

  /* Copying values of current node starting from bottom-up form of the tree */
  duplicateTree_pointer->value = root->value;
  duplicateTree_pointer->operation = root->operation;
  duplicateTree_pointer->num_parents = root->num_parents;

  /* Due to expr_string being a pointer, we must copy the value to a new memory
   * address for a valid COPY*/
  char *copy_expr_string = (char *)malloc(
      sizeof(char) *
      (strlen(root->expr_string) + 1)); /*Allocation of memory to copy string*/
  *copy_expr_string = (char){0};
  strcpy(copy_expr_string, root->expr_string);
  duplicateTree_pointer->expr_string = copy_expr_string;

  return duplicateTree_pointer;
}

void printTree(Node *root) {

  /*Base case */
  if (root == NULL) {
    return;
  }

  printf(" Node \n");
  printf("    expr_string = %s \n", root->expr_string);
  printf("    value       = %.3f \n", root->value);
  printf("    num_parents = %d \n", root->num_parents);
  printTree(root->left);
  printTree(root->right);
}
