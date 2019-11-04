/* 
 * File:   main.cpp
 * Author: Christian
 *
 * Created on November 3, 2019, 1:58 AM
 */

#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// state space tree nodes 
struct Node 
{ 
    // stores the parent node of the current node 
    // helps in tracing path when the answer is found 
    Node* parent;  
  
    char problem[9];
  
    // stores the number of moves so far 
    int level; 
}; 

// Function to allocate a new node 
Node* newNode(char arr[], int level, Node* parent) 
{ 
    Node* node = new Node; 
    
    for(int i = 0; i < 9; i++)
        node->problem[i] = arr[i];
  
    // set pointer for path to root 
    node->parent = parent;   
  
    // set number of moves so far 
    node->level = level; 
  
    return node; 
}
  
vector<Node*> makeNode(char problem[], int size)
{
    int b;
    int x;
    // Create a root node.
    Node* root = newNode(problem, 0, NULL);
    // Create a priority queue to store live nodes of 
    // search tree; 
    vector<Node*> nodes;
    nodes.push_back(root);
    // Find the location of the empty space.
    for(int x = 0; x < 9; x++)
        if(problem[x] == 'b')
            b = x;
    
    // Calculate branching factor.
    int num_nodes;
            
    if(b == 4)
        num_nodes = 4;
    else if(b == 0 || b == 2 || b == 6 || b == 8)
        num_nodes = 2;
    else
        num_nodes = 3;
    
    // Swap tiles.
    switch(b)
    {
        case 0:
            Node* adult = nodes.back();            
            Node* node2 = newNode(problem, 1, adult);
            x = node2->problem[b];
            node2->problem[b] = node2->problem[1];
            node2->problem[1] = x;
            nodes.push_back(node2);
            Node* node3 = newNode(problem, 1, adult);
            x = node3->problem[b];
            node3->problem[b] = node3->problem[3];
            node3->problem[3] = x;
            nodes.push_back(node3); 
    }
    return nodes;
}

int main(int argc, char** argv) 
{
    int const SIZE = 9;
    char user[SIZE] = {'b', '2', '3', '4', '8', '1', '7', '6', '5'};
    vector<Node*> vect;
    vect = makeNode(user, SIZE);
    char parent[9];
    //for(int i = 0; i < vect.size(); i++)
        for(int j = 0; j < SIZE; j++)
            cout << vect[2]->parent[0].problem[j] << " ";
    
    return 0;
}
