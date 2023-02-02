#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;
   int key;
	
   struct node *next;
   struct node *prev;
};
struct node *head = NULL;
struct node *last = NULL;

struct node *current = NULL;


bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next){
      length++;
   }
	
   return length;
}

void displayForward() {

   //start from the beginning
   struct node *ptr = head;
	
   //navigate till the end of the list
   printf("\n[ ");
	
   while(ptr != NULL) {        
      printf("(%d,%d) ",ptr->key,ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

//display the list from last to first
void displayBackward() {

   //start from the last
   struct node *ptr = last;
	
   //navigate till the start of the list
   printf("\n[ ");
	
   while(ptr != NULL) {    
	
      //print data
      printf("(%d,%d) ",ptr->key,ptr->data);
		
      //move to next item
      ptr = ptr ->prev;
      
   }
	
}

//insert link at the first location
void insertFirst(int key, int data) {

   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->key = key;
   link->data = data;
	
   if(isEmpty()) {
      //make it the last link
      last = link;
   } else {
      //update first prev link
      head->prev = link;
   }

   //point it to old first link
   link->next = head;
	
   //point first to new first link
   head = link;
}

//insert link at the last location
void insertLast(int key, int data) {

   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->key = key;
   link->data = data;
	
   if(isEmpty()) {
      //make it the last link
      last = link;
   } else {
      //make link a new last link
      last->next = link;     
      
      //mark old last node as prev of new link
      link->prev = last;
   }

  
   last = link;
}

struct node* deleteFirst() {

   
   struct node *tempLink = head;
	
   
   if(head->next == NULL){
      last = NULL;
   } else {
      head->next->prev = NULL;
   }
	
   head = head->next;
   return tempLink;
}



struct node* deleteLast() {
   
   struct node *tempLink = last;
	
   
   if(head->next == NULL) {
      head = NULL;
   } else {
      last->prev->next = NULL;
   }
	
   last = last->prev;
	
   
   return tempLink;
}



struct node* delete(int key) {

   
   struct node* current = head;
   struct node* previous = NULL;
	
   
   if(head == NULL) {
      return NULL;
   }

   
   while(current->key != key) {
      
		
      if(current->next == NULL) {
         return NULL;
      } else {
     
         previous = current;
			
         
         current = current->next;             
      }
   }

   
   if(current == head) {
      
      head = head->next;
   } else {
      
      current->prev->next = current->next;
   }    

   if(current == last) {
      
      last = current->prev;
   } else {
      current->next->prev = current->prev;
   }
	
   return current;
}

bool insertAfter(int key, int newKey, int data) {
   
   struct node *current = head; 
	
   
   if(head == NULL) {
      return false;
   }

   
   while(current->key != key) {
	
   
      if(current->next == NULL) {
         return false;
      } else {           
  
         current = current->next;
      }
   }
	
   struct node *newLink = (struct node*) malloc(sizeof(struct node));
   newLink->key = newKey;
   newLink->data = data;

   if(current == last) {
      newLink->next = NULL; 
      last = newLink; 
   } else {
      newLink->next = current->next;         
      current->next->prev = newLink;
   }
	
   newLink->prev = current; 
   current->next = newLink; 
   return true; 
}

void main() {
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56); 

   printf("\nList (First to Last): ");  
   displayForward();
	
   printf("\n");
   printf("\nList (Last to first): "); 
   displayBackward();

   printf("\nList , after deleting first record: ");
   deleteFirst();        
   displayForward();

   printf("\nList , after deleting last record: ");  
   deleteLast();
   displayForward();

   printf("\nList , insert after key(4) : ");  
   insertAfter(4,7, 13);
   displayForward();

   printf("\nList  , after delete key(4) : ");  
   delete(4);
   displayForward();
}
