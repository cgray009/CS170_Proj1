#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h>
#include <queue>
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

// converts character array 
// to string and returns it 
string convertToString(char* a, int size) 
{ 
    int i; 
    string s = ""; 
    for (i = 0; i < size; i++) { 
        s = s + a[i]; 
    } 
    return s; 
} 
  
Node* makeNode(char problem[], int size)
{
    int b;
    int x;
    // Create a root node.
    Node* root = newNode(problem, 0, NULL);
    // Create a priority queue to store live nodes of 
    // search tree; 
    queue<Node*> nodes;
    vector<Node*> popped_nodes;
    nodes.push(root);
    int size_nodes = nodes.size();
    int const SIZE = 9;
    char goal_state[SIZE] = {'1', '2', '3', '4', '5', '6', '7', '8', 'b'};
    int goal = 0;
    int level = 0;
    
    while(!nodes.empty())
    {
        int duplicates = 0;
        Node* node = nodes.front();
        popped_nodes.push_back(node);
        nodes.pop();
        int popped_size = popped_nodes.size();
        int move_left, move_right, move_up, move_down = 0;

        for(int i = 0; i < popped_size; i++)
        {
            string string_a = convertToString(popped_nodes[i]->problem, size);
            string string_b = convertToString(goal_state, size);

            if(string_a == string_b)
                return popped_nodes[i];
            else
            {
                for(int j = 0; j < SIZE; j++)
                {
                    if(popped_nodes[i]->problem[j] != goal_state[j])
                    {
                        move_left = j - 1;
                        move_right = j + 1;
                        move_up = j - 3;
                        move_down = j + 3;
                        
                        // Move tile left
                        if(move_left > -1 && move_left < 9)
                        {
                            Node* new_node = newNode(popped_nodes[i]->problem, level, node);
                            x = new_node->problem[j];
                            new_node->problem[j] = new_node->problem[move_left];
                            new_node->problem[move_left] = x;
                            
                            for(int m = 0; m < popped_size; m++)
                            {
                                string string_a = convertToString(popped_nodes[m]->problem, size);
                                string string_b = convertToString(new_node->problem, size);
                                cout << "string a: " << string_a << endl;
                                cout << "string b: " << string_b << endl;
                                if(string_a != string_b)
                                    duplicates = 1;                
                            }

                            cout << "dup: " << duplicates << endl;
                            if(duplicates)
                                nodes.push(new_node);
                        }
                        
                        // Move tile right
                        if(move_right > -1 && move_right < 9)
                        {
                            Node* new_node = newNode(popped_nodes[i]->problem, level, node);
                            x = new_node->problem[j];
                            new_node->problem[j] = new_node->problem[move_right];
                            new_node->problem[move_right] = x;
                            
                            for(int m = 0; m < popped_size; m++)
                            {
                                string string_a = convertToString(popped_nodes[m]->problem, size);
                                string string_b = convertToString(new_node->problem, size);
                                cout << "string a: " << string_a << endl;
                                cout << "string b: " << string_b << endl;
                                if(string_a != string_b)
                                    duplicates = 1;                
                            }

                            cout << "dup: " << duplicates << endl;
                            if(duplicates)
                                nodes.push(new_node);
                        }
                        
                        // Move tile up
                        if(move_up > -1 && move_up < 9)
                        {
                            Node* new_node = newNode(popped_nodes[i]->problem, level, node);
                            x = new_node->problem[j];
                            new_node->problem[j] = new_node->problem[move_up];
                            new_node->problem[move_up] = x;
                            
                            for(int m = 0; m < popped_size; m++)
                            {
                                string string_a = convertToString(popped_nodes[m]->problem, size);
                                string string_b = convertToString(new_node->problem, size);
                                cout << "string a: " << string_a << endl;
                                cout << "string b: " << string_b << endl;
                                if(string_a != string_b)
                                    duplicates = 1;                
                            }

                            cout << "dup: " << duplicates << endl;
                            if(duplicates)
                                nodes.push(new_node);
                        }
                        
                        // Move tile down
                        if(move_down > -1 && move_down < 9)
                        {
                            Node* new_node = newNode(popped_nodes[i]->problem, level, node);
                            x = new_node->problem[j];
                            new_node->problem[j] = new_node->problem[move_down];
                            new_node->problem[move_down] = x;
                            
                            for(int m = 0; m < popped_size; m++)
                            {
                                string string_a = convertToString(popped_nodes[m]->problem, size);
                                string string_b = convertToString(new_node->problem, size);
                                cout << "string a: " << string_a << endl;
                                cout << "string b: " << string_b << endl;
                                if(string_a != string_b)
                                    duplicates = 1;                
                            }

                            cout << "dup: " << duplicates << endl;
                            if(duplicates)
                                nodes.push(new_node);
                        }                    
                    }
                }
                 
                // Increment level
                level += 1;
            }
        }   
    }
}

int main(int argc, char** argv) 
{
    int const SIZE = 9;
    char user[SIZE] = {'1', '2', '4', '3', '5', '6', '7', '8', 'b'};
    Node* vect;
    vect = makeNode(user, SIZE);
    for(int i = 0; i < SIZE; i++)
        cout << vect->problem[i] << " ";
    cout << endl;
    //'b', '2', '3', '4', '8', '1', '7', '6', '5'
    return 0;
}

