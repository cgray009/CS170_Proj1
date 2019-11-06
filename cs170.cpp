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
    int size_nodes = nodes.size();
    // Find the location of the empty space.
    
    int const SIZE = 9;
    char goal_state[SIZE] = {'1', '2', '3', '4', '5', '6', '7', '8', 'b'};
    int goal = 0;
        
    while(goal < 1)
    {
        int count = 0;
        for(int i = 0; i < size; i++)
        {
            for(int x = 0; x < size; x++)
                if(nodes[count]->problem[x] == 'b')
                    b = x;
            
            // Swap tiles.
            switch(b)
            {
                int duplicates = 0;
                case 0:
                    // First arrangement
                    Node* adult = nodes.back();            
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[1];
                    node2->problem[1] = x;
                    
                    for(int a = 0; a < count + 1; a++)
                    {
                        for(int b = 0; b < size; b++)
                        {
                            if(nodes[a]->problem[b] == node2->problem[b])
                                duplicates = 1;
                            if(nodes[a]->problem[b] == goal_state[b])
                                goal = 1;
                        }
                    }
                        
                    if(!duplicates)
                        nodes.push_back(node2);
                    duplicates = 0;
                        

                    // Second arrangement
                    Node* node3 = newNode(nodes[count]->problem, count, adult);
                    x = node3->problem[b];
                    node3->problem[b] = node3->problem[3];
                    node3->problem[3] = x;
                    nodes.push_back(node3); 

                case 1:
                    // First arrangement
                    Node* adult = nodes.back();            
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[0];
                    node2->problem[0] = x;
                    nodes.push_back(node2);

                    // Second arrangement
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[2];
                    node2->problem[2] = x;
                    nodes.push_back(node2);

                    // Third arrangement
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[4];
                    node2->problem[4] = x;
                    nodes.push_back(node2);

                case 2:
                    // First arrangement
                    Node* adult = nodes.back(); 
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[1];
                    node2->problem[1] = x;
                    nodes.push_back(node2);

                    // Second arrangement
                    Node* adult = nodes.back();
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[5];
                    node2->problem[5] = x;
                    nodes.push_back(node2);

                case 3:
                    // First arrangement
                    Node* adult = nodes.back(); 
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[0];
                    node2->problem[0] = x;
                    nodes.push_back(node2);

                    // Second arrangement
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[4];
                    node2->problem[4] = x;
                    nodes.push_back(node2);

                    // Third arrangement
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[6];
                    node2->problem[6] = x;
                    nodes.push_back(node2);

                case 4:
                    // First arrangement
                    Node* adult = nodes.back(); 
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[1];
                    node2->problem[1] = x;
                    nodes.push_back(node2);

                    // Second arrangement
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[3];
                    node2->problem[3] = x;
                    nodes.push_back(node2);

                    // Third arrangement
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[5];
                    node2->problem[5] = x;
                    nodes.push_back(node2);

                    // Fourth arrangement
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[7];
                    node2->problem[7] = x;
                    nodes.push_back(node2);

                case 5:
                    // First arrangement
                    Node* adult = nodes.back(); 
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[2];
                    node2->problem[2] = x;
                    nodes.push_back(node2);

                    // Second arrangement
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[4];
                    node2->problem[4] = x;
                    nodes.push_back(node2);

                    // Third arrangement
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[8];
                    node2->problem[8] = x;
                    nodes.push_back(node2);

                case 6:
                    // First arrangement
                    Node* adult = nodes.back(); 
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[3];
                    node2->problem[3] = x;
                    nodes.push_back(node2);

                    // Second arrangement
                    Node* adult = nodes.back();
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[7];
                    node2->problem[7] = x;
                    nodes.push_back(node2);

                case 7:
                    // First arrangement
                    Node* adult = nodes.back(); 
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[4];
                    node2->problem[4] = x;
                    nodes.push_back(node2);

                    // Second arrangement
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[6];
                    node2->problem[6] = x;
                    nodes.push_back(node2);

                    // Third arrangement
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[8];
                    node2->problem[8] = x;
                    nodes.push_back(node2);

                case 8:
                     // First arrangement
                    Node* adult = nodes.back(); 
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[5];
                    node2->problem[5] = x;
                    nodes.push_back(node2);

                    // Second arrangement
                    Node* adult = nodes.back();
                    Node* node2 = newNode(nodes[count]->problem, count, adult);
                    x = node2->problem[b];
                    node2->problem[b] = node2->problem[7];
                    node2->problem[7] = x;
                    nodes.push_back(node2);
            }
            
            // Increment count
            count++;
        }
    }
          
    
    /* Calculate branching factor.
    int num_nodes;
            
    if(b == 4)
        num_nodes = 4;
    else if(b == 0 || b == 2 || b == 6 || b == 8)
        num_nodes = 2;
    else
        num_nodes = 3;
    
     */
    
    
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
            cout << vect[2]->problem[j] << " ";
    
    return 0;
}
