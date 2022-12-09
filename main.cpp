//Coded By
//Ganeshaanand (Rishi) Balasubramanian
//@_rbga_
//Master of Applied Sciences, Electrical and Computer Engineering
//Dalhosuie University, Halifax, Canada 2022


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

void Remove(LinkNode *& root, int val)                //Delete function Declaration
{
    LinkNode * temp = root;                           //Create Temp List
    LinkNode * past = root;                           //Create Past List
    
    for (int i = 0; i < val; i++)                     //From 0 to val
    {
        if (i == 0 && val == 1)                       //At 0th iteration and val == 1
        {
            root = root -> next;                      //Next
            free(temp);                               //Delete
        }
        else
        {
            if (i == val - 1 && temp)                 
            {
                past -> next = temp -> next;
                free(temp);
            }
            
            else
            {
                past = temp;
                
                if (past == NULL)
                    break;
                    
                temp = temp -> next;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////

void RemoveSpecific(LinkNode *& root, int val)
{
    LinkNode * temp = root;
    LinkNode * past = NULL;
    
    if (temp != NULL && temp -> key == val)
    {
        root = temp -> next;
        delete temp;
        return;
    }
    else
    {
        while (temp != NULL && temp -> key != val)
        {
            past = temp;
            temp = temp -> next;
        }
        
        if (temp == NULL)
            return;
            
        past -> next = temp -> next;
        delete temp;
    }
}

///////////////////////////////////////////////////////////////////////////

int ListLength(LinkNode *& root)
{
    if (root == NULL)
        return 0;
    else
        return (1 + ListLength(root -> next));
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int main()
{
    int i, j;
    LinkNode * root = NULL;
    
    for (i = 0; i < 10; i++)
    {
        RootIns(root, i);
        display(root);
    }
    
    cout << endl;
    
    for (j = i; j < (i+2); j++)
    {
        EndIns(root, j);
        display(root);
    }
    
    cout << endl;
    
    SpecificIns(root, 5, 12);
    display(root);
    cout << endl;
    
    SpecificIns(root, 12, 13);
    display(root);
    cout << endl;
    
    
    Remove(root, 3);
    display(root);
    cout << endl;
    
    RemoveSpecific(root, 13);
    display(root);
    
    cout << "Size = " << ListLength(root);
    return 0;
}
