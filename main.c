#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "build_tree.h"

static int __get_str(char s[], const int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = (char)c;

  s[i] = '\0';

  return i;
}

void postorder(const node_t *root) {
  if (root) {
    postorder(root->left);
    postorder(root->right);
    if (root->type == UNARYOP || root->type == BINARYOP){
      printf("%s", optable[root->data].symbol);
    }
    else if (root->type == VAR){
      printf("%c", 'a' + (char)root->data); //deleted: 
      //global variable of array of registers
      //added: extern char *variableAtRegister[32];
      //added: printf("%s\n", variableAtRegister[root->data]);
    }
    else{
      printf("%d", root->data);
    }
  }
}

int main(void) {

  //declare global variable that stores each registers variable name
  //added: extern char *variableAtRegister[32];
  //initialize the array of registers declared above
  //added: initRegisters();

  char expr1[MAXEXPRLENGTH];
  node_t *root;

  while (__get_str(expr1, MAXEXPRLENGTH)) {
    printf("Expression to parse: %s\n", expr1);

    root = build_tree(expr1);

    printvartable();
    printregtable();

    printf("Postfix: ");

    postorder(root);

    printf("\n");
    root = generate_code(root);

    if (root->type == REG)
      printf("root: x%d\n", root->data);
    else if (root->type == CONST)
      printf("root: %d\n", root->data);

    printregtable();
    printf("\n");
  }

  return 0;
  
}
