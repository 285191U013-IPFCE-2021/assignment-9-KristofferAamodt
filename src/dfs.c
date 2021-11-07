/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "dfs.h"


void DFT (node * root)
{
	// Implement DFS
	// Hint: You can use print_node, print_tree and/or print_stack.

  //Initialize stack
  stack *topp = (stack*) malloc(sizeof(stack));
  topp->node = NULL;
  topp = push(topp,root);

  //Search through the three
  pop(topp);
  

}

node *make_node (int num, node * left, node * right)
{

  node *element = (node*) malloc(sizeof(node));
  element->num = num;
  element->lchild = left;
  element->rchild = right;
  element->visited = false;

  return element;
}

void free_node (node * p)
{
  if(p->lchild!=NULL && p->rchild!=NULL){
    free_node(p->lchild);
    free_node(p->rchild);
    free(p);
  }
  else{
    free(p);
  }

}


void print_node (node * p)
{

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d", p->num);
}


void print_tree (node * p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf (" ");
  printf ("| ");

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->num);


  if (p->lchild)
    {
      print_tree (p->lchild, depth + 1);
    }

  if (p->rchild)
    print_tree (p->rchild, depth + 1);
}

stack *push (stack * topp, node * node)
{
  stack *element = (stack*) malloc(sizeof(stack));
  element->node = node; 
  element->next = topp->next;
  topp->next = element;

  return topp; 

}

bool isEmpty (stack * topp)
{
  if(topp->node!=NULL){
    return false;
  }
  else{
    return true;
  }
}

node *top (stack * topp)
{



}

// Utility function to pop topp  
// element from the stack 

stack *pop (stack * topp)
{
  //Check if stack is empty
  if(isEmpty(topp)){
    printf("Empty Stack, not able to pop");
  }
  else{
    //Pop the node
    node *popped = topp->next->node; 
    print_node (popped);
    popped->visited = true;

    //Stack is empty
    if(topp->next->next==NULL){
      topp->next=NULL;
    }
    else{
    //Pointing at next top
    topp->next=topp->next->next;
    }

    //Push rchild and lchild onto stack if existing and not visited
    if(popped->rchild != NULL || popped->rchild->visited==false){
      topp = push(topp,popped->rchild);
    }
    if(popped->rchild != NULL || popped->lchild->visited==false){
      topp = push(topp,popped->lchild);
    }

    if(isEmpty(topp)){
      return topp;
    }
    else{
      pop(topp);
    }

  }

  return topp;
}


void print_stack (stack * topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
    {

      print_node (temp->node);
      printf ("\n");

      temp = temp->next;
    }

  printf ("====\n");

  return;
}
