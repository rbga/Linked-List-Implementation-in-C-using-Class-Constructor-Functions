//Coded By
//Ganeshaanand (Rishi) Balasubramanian
//@_rbga_
//Master of Applied Sciences, Electrical and Computer Engineering
//Dalhosuie University, Halifax, Canada 2022


// This code is a linked list implementation in C++.

// The `LinkNode` class represents a node in the linked list.
// It has two fields: `key` and `next`.
// `key` stores the data for the node, and `next` points to the next node in the list.

// The `RootIns` function inserts a new node at the root of the linked list.
// The `SpecificIns` function inserts a new node at a specific point in the linked list.
// The `EndIns` function inserts a new node at the end of the linked list.
// The `display` function prints the contents of the linked list.
// The `Remove` function removes a node from the linked list.
// The `RemoveSpecific` function removes a specific node from the linked list.
// The `ListLength` function returns the number of nodes in the linked list.

// The `main` function creates a linked list with 10 nodes, then inserts two more nodes at the end,
// inserts a node at the fifth position, inserts a node at the twelfth position,
// removes the third node, removes the thirteenth node, and prints the size of the linked list.


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

///////////////////////////////////////////////////////////////////////////

class LinkNode              //Create Class                
{
    public :
        int key;            //Data
        LinkNode * next;    //Next Pointer
        
        LinkNode(int val)   //Creating LinkedNode Constructor
        {
            key = val;
            next = NULL;
        }
};

///////////////////////////////////////////////////////////////////////////

void RootIns(LinkNode *& root, int val)     //Insert At Root Funcion Definition
{
    LinkNode * data = new LinkNode(val);    //Create space for new data by allocating using NEW
    data -> next = root;                    //Make that root
    root = data;
}

///////////////////////////////////////////////////////////////////////////

void SpecificIns(LinkNode * root, int point, int val)     //Insert At Specific Point Funcion Definition
{
    LinkNode * data = new LinkNode(val);                  //Create space for new data by allocating using NEW
    
    if (point == root -> key)                             //If at exact value point
    {
        data -> next = root -> next;                      //Next data = Next Root
        root -> next = data;                              //Copy data to root next
        return;
    }
    
    
    LinkNode * temp = root;                               //Create temproary list
    
    while (temp -> key != point)                          //Until point
    {
        temp = temp -> next;                              //Keep going to next
        
        if (temp == NULL)                                 //If at final null value
        {
            return;
        }
    }
    
    data -> next = temp -> next;                          //Next data = Next Root
    temp -> next = data;                                  //Copy data to temp next
}

///////////////////////////////////////////////////////////////////////////

void EndIns(LinkNode *& root, int val)                    //Insert at End function Definition
{
    LinkNode * data = new LinkNode(val);                  //Create space for new data by allocating using NEW
    
    if (root == NULL)                                     //NULL case
    {
        root = data;
        return;
    }
      
    LinkNode * temp = root;                               //Create temproary list
    
    while (temp -> next != NULL)                          //Until point
    {
        temp = temp -> next;                              //Keep going to next
    }
    temp -> next = data;                                  //Copy data to temp next
}

///////////////////////////////////////////////////////////////////////////

void display(LinkNode *& root)                            //Display Entire List Function Declaration
{
    LinkNode * temp = root;                               //Create temproary list
    
    while (temp != NULL)                                  //Until Temp arrives at NULL value
    {
        cout << temp -> key << "->";                      //Print Key
        temp = temp -> next;                              //Goto Next
    }
    
    cout << "NULL" << endl;
}

///////////////////////////////////////////////////////////////////////////
void Remove(LinkNode *& root, int val) {
  // `temp` is a pointer to the current node in the linked list.
  // `past` is a pointer to the previous node in the linked list.

  // Iterate from 0 to `val`.
  for (int i = 0; i < val; i++) {
      
    // If `i` is 0 and `val` is 1, then the current node is the root of the linked list.
    if (i == 0 && val == 1) {
      
        // Set the root of the linked list to the next node.
      root = root->next;
      
        // Free the memory allocated to the current node.
      free(temp);
    } 
      else {
      
          // If `i` is equal to `val` - 1 and the current node is not null, then the current node is the node to be removed.
      if (i == val - 1 && temp) {
        
          // Set the next node of the previous node to the next node of the current node.
        past->next = temp->next;
        
          // Free the memory allocated to the current node.
        free(temp);
      } 
          else {
        
              // Set the previous node to the current node.
        past = temp;
        
              // If the previous node is null, then we have reached the end of the linked list.
        if (past == NULL) {
          break;
        }
        
              // Move the current node to the next node.
        temp = temp->next;
      }
    }
  }
}

///////////////////////////////////////////////////////////////////////////

void RemoveSpecific(LinkNode *& root, int val) {
  // `temp` is a pointer to the current node in the linked list.
  // `past` is a pointer to the previous node in the linked list.

  // If the current node is not null and the key of the current node is equal to `val`, then the current node is the node to be removed.
  if (temp != NULL && temp->key == val) {

      // Set the root of the linked list to the next node.
    root = temp->next;
   
      // Free the memory allocated to the current node.
    delete temp;
   
      // Return from the function.
    return;
  }

  // Otherwise, iterate through the linked list until the current node is not null and the key of the current node is not equal to `val`.
  while (temp != NULL && temp->key != val) {
    
      // Set the previous node to the current node.
    past = temp;
   
      // Move the current node to the next node.
    temp = temp->next;
  }

  // If the current node is null, then the node to be removed was not found.
  if (temp == NULL) {
    
      // Return from the function.
    return;
  }

  // Set the next node of the previous node to the next node of the current node.
  past->next = temp->next;
  
    // Free the memory allocated to the current node.
  delete temp;
}

///////////////////////////////////////////////////////////////////////////

int ListLength(LinkNode *& root) {
  // If the root of the linked list is null, then the linked list is empty.
  if (root == NULL) {
    // Return 0.
    return 0;
  }

  // Otherwise, recursively call the `ListLength` function on the next node in the linked list.
  // Add 1 to the return value of the recursive call.
  return (1 + ListLength(root->next));
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int main() {
  // Create a linked list with 10 nodes.
  LinkNode * root = NULL;
  for (int i = 0; i < 10; i++) {
    RootIns(root, i);
  }

  // Print the contents of the linked list.
  display(root);

  // Insert two more nodes at the end of the linked list.
  for (int j = i; j < (i+2); j++) {
    EndIns(root, j);
  }

  // Print the contents of the linked list.
  display(root);

  // Insert a node at the fifth position.
  SpecificIns(root, 5, 12);

  // Print the contents of the linked list.
  display(root);

  // Insert a node at the twelfth position.
  SpecificIns(root, 12, 13);

  // Print the contents of the linked list.
  display(root);

  // Remove the third node.
  Remove(root, 3);

  // Print the contents of the linked list.
  display(root);

  // Remove the thirteenth node.
  RemoveSpecific(root, 13);

  // Print the contents of the linked list.
  display(root);

  // Print the size of the linked list.
  cout << "Size = " << ListLength(root);
  return 0;
}
