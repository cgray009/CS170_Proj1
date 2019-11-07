#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include<algorithm>
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
    
    // Stores heuristic value
    int heuristic;
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
    
    for (i = 0; i < size; i++) 
    { 
        s = s + a[i]; 
    } 
    return s; 
} 
  
Node* makeNodeUniform(char problem[], int size)
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

int manhattanHeuristic(struct Node* node)
{
    int h_n = 0;
    int const SIZE = 9;
    char goal_node[SIZE] = {'1', '2', '3', '4', '5', '6', '7', '8', 'b'};
    
    for(int i = 0; i < SIZE; i++)
    {
        if(node->problem[i] != goal_node[i])
        {
            // All h(n) for index 0 
            if(i == 1 && node->problem[i] == '1')
                h_n += 0;
            else if(i == 0 && node->problem[i] == '2')
                h_n += 1;
            else if(i == 0 && node->problem[i] == '3')
                h_n += 2;
            else if(i == 0 && node->problem[i] == '4')
                h_n += 1;
            else if(i == 0 && node->problem[i] == '5')
                h_n += 2;
            else if(i == 0 && node->problem[i] == '6')
                h_n += 3;
            else if(i == 0 && node->problem[i] == '7')
                h_n += 2;
            else if(i == 0 && node->problem[i] == '8')
                h_n += 3;
            else if(i == 0 && node->problem[i] == 'b')
                h_n += 4;
            
            // All h(n) for index 1
            else if(i == 1 && node->problem[i] == '1')
                h_n += 1;
            else if(i == 1 && node->problem[i] == '2')
                h_n += 2;
            else if(i == 1 && node->problem[i] == '3')
                h_n += 1;
            else if(i == 1 && node->problem[i] == '4')
                h_n += 2;
            else if(i == 1 && node->problem[i] == '5')
                h_n += 1;
            else if(i == 1 && node->problem[i] == '6')
                h_n += 2;
            else if(i == 1 && node->problem[i] == '7')
                h_n += 3;
            else if(i == 1 && node->problem[i] == '8')
                h_n += 2;
            else if(i == 1 && node->problem[i] == 'b')
                h_n += 3;
            
            // All h(n) for index 2
            else if(i == 2 && node->problem[i] == '1')
                h_n += 2;
            else if(i == 2 && node->problem[i] == '2')
                h_n += 1;
            else if(i == 2 && node->problem[i] == '3')
                h_n += 0;
            else if(i == 2 && node->problem[i] == '4')
                h_n += 3;
            else if(i == 2 && node->problem[i] == '5')
                h_n += 2;
            else if(i == 2 && node->problem[i] == '6')
                h_n += 1;
            else if(i == 2 && node->problem[i] == '7')
                h_n += 4;
            else if(i == 2 && node->problem[i] == '8')
                h_n += 3;
            else if(i == 2 && node->problem[i] == 'b')
                h_n += 2;
            
            // All h(n) for index 3
            else if(i == 3 && node->problem[i] == '1')
                h_n += 1;
            else if(i == 3 && node->problem[i] == '2')
                h_n += 2;
            else if(i == 3 && node->problem[i] == '3')
                h_n += 3;
            else if(i == 3 && node->problem[i] == '4')
                h_n += 0;
            else if(i == 3 && node->problem[i] == '5')
                h_n += 1;
            else if(i == 3 && node->problem[i] == '6')
                h_n += 2;
            else if(i == 3 && node->problem[i] == '7')
                h_n += 1;
            else if(i == 3 && node->problem[i] == '8')
                h_n += 2;
            else if(i == 3 && node->problem[i] == 'b')
                h_n += 3;
            
            // All h(n) for index 4
            else if(i == 4 && node->problem[i] == '1')
                h_n += 2;
            else if(i == 4 && node->problem[i] == '2')
                h_n += 1;
            else if(i == 4 && node->problem[i] == '3')
                h_n += 2;
            else if(i == 4 && node->problem[i] == '4')
                h_n += 1;
            else if(i == 4 && node->problem[i] == '5')
                h_n += 0;
            else if(i == 4 && node->problem[i] == '6')
                h_n += 1;
            else if(i == 4 && node->problem[i] == '7')
                h_n += 2;
            else if(i == 4 && node->problem[i] == '8')
                h_n += 1;
            else if(i == 4 && node->problem[i] == 'b')
                h_n += 2;
            
            // All h(n) for index 5
            else if(i == 5 && node->problem[i] == '1')
                h_n += 3;
            else if(i == 5 && node->problem[i] == '2')
                h_n += 2;
            else if(i == 5 && node->problem[i] == '3')
                h_n += 1;
            else if(i == 5 && node->problem[i] == '4')
                h_n += 2;
            else if(i == 5 && node->problem[i] == '5')
                h_n += 1;
            else if(i == 5 && node->problem[i] == '6')
                h_n += 0;
            else if(i == 5 && node->problem[i] == '7')
                h_n += 3;
            else if(i == 5 && node->problem[i] == '8')
                h_n += 2;
            else if(i == 5 && node->problem[i] == 'b')
                h_n += 1;
            
            // All h(n) for index 6
            else if(i == 6 && node->problem[i] == '1')
                h_n += 2;
            else if(i == 6 && node->problem[i] == '2')
                h_n += 3;
            else if(i == 6 && node->problem[i] == '3')
                h_n += 4;
            else if(i == 6 && node->problem[i] == '4')
                h_n += 1;
            else if(i == 6 && node->problem[i] == '5')
                h_n += 2;
            else if(i == 6 && node->problem[i] == '6')
                h_n += 3;
            else if(i == 6 && node->problem[i] == '7')
                h_n += 0;
            else if(i == 6 && node->problem[i] == '8')
                h_n += 1;
            else if(i == 6 && node->problem[i] == 'b')
                h_n += 2;
            
            // All h(n) for index 7
            else if(i == 7 && node->problem[i] == '1')
                h_n += 3;
            else if(i == 7 && node->problem[i] == '2')
                h_n += 2;
            else if(i == 7 && node->problem[i] == '3')
                h_n += 3;
            else if(i == 7 && node->problem[i] == '4')
                h_n += 2;
            else if(i == 7 && node->problem[i] == '5')
                h_n += 1;
            else if(i == 7 && node->problem[i] == '6')
                h_n += 2;
            else if(i == 7 && node->problem[i] == '7')
                h_n += 1;
            else if(i == 7 && node->problem[i] == '8')
                h_n += 0;
            else if(i == 7 && node->problem[i] == 'b')
                h_n += 1;
            
            // All h(n) for index 8
            else if(i == 8 && node->problem[i] == '1')
                h_n += 4;
            else if(i == 8 && node->problem[i] == '2')
                h_n += 3;
            else if(i == 8 && node->problem[i] == '3')
                h_n += 2;
            else if(i == 8 && node->problem[i] == '4')
                h_n += 3;
            else if(i == 8 && node->problem[i] == '5')
                h_n += 2;
            else if(i == 8 && node->problem[i] == '6')
                h_n += 1;
            else if(i == 8 && node->problem[i] == '7')
                h_n += 2;
            else if(i == 8 && node->problem[i] == '8')
                h_n += 1;
            else if(i == 8 && node->problem[i] == 'b')
                h_n += 0; 
        }
    }
    
    cout << "HEU LEVEL: " << node->level << endl;
    return node->level + h_n;
}
  
vector<Node*> sortVect(vector<Node*> vect)  
{  
    bool swap;  
    Node* temp;  
    
    do 
    {         
        swap = false;         
        for (int count = 0; count < (vect.size() - 1); count++)         
        {           
            if (vect[count]->heuristic > vect[count + 1]->heuristic)            
            {               
                temp = vect[count];               
                vect[count] = vect[count + 1];               
                vect[count + 1] = temp;               
                swap = true;           
            }         
        }      
    }while(swap);   
    
    return vect;
}  

Node* makeNodeManhattan(char problem[], int size)
{
    int b;
    int x;
    // Create a root node.
    Node* root = newNode(problem, 0, NULL);
    // Create a priority queue to store live nodes of 
    // search tree; 
    queue<Node*> nodes;
    vector<Node*> popped_nodes;
    vector<Node*> heuristic;
    nodes.push(root);
    int size_nodes = nodes.size();
    int const SIZE = 9;
    char goal_state[SIZE] = {'1', '2', '3', '4', '5', '6', '7', '8', 'b'};
    int goal = 0;
    int level = 0;
    vector<Node*> temp2;
    
    while(!nodes.empty())
    {
        int duplicates = 0;
        Node* node = nodes.front();
        popped_nodes.push_back(node);
        nodes.pop();
        int popped_size = popped_nodes.size();
        int move_left, move_right, move_up, move_down = 0;

        
        string string_a = convertToString(node->problem, size);
        string string_b = convertToString(goal_state, size);

        if(string_a == string_b)
            return node;
        else
        {
            int b_loc = 0;

            // Get b's location
            for(int i = 0; i < SIZE; i++)
                if(node->problem[i] == 'b')
                    b_loc = i;

            // Operators
            move_left = b_loc - 1;
            move_right = b_loc + 1;
            move_up = b_loc - 3;
            move_down = b_loc + 3;

            // Increment level
            level += 1;

            // Move tile left
            if(move_left > -1 && move_left < size)
            {
                Node* new_node = newNode(node->problem, level, node);
                x = new_node->problem[b_loc];
                new_node->problem[b_loc] = new_node->problem[move_left];
                new_node->problem[move_left] = x;

                string string_a = convertToString(node->problem, size);
                string string_b = convertToString(new_node->problem, size);
                cout << "string a: " << string_a << endl;
                cout << "string b: " << string_b << endl;
                if(string_a != string_b)
                    duplicates = 1;                

                if(duplicates)
                    heuristic.push_back(new_node);                        
            }

            // Move tile right
            if(move_right > -1 && move_right < size)
            {
                Node* new_node = newNode(node->problem, level, node);
                x = new_node->problem[b_loc];
                new_node->problem[b_loc] = new_node->problem[move_right];
                new_node->problem[move_right] = x;

                string string_a = convertToString(node->problem, size);
                string string_b = convertToString(new_node->problem, size);
                cout << "string a: " << string_a << endl;
                cout << "string b: " << string_b << endl;

                if(string_a != string_b)
                    duplicates = 1;                

                if(duplicates)
                    heuristic.push_back(new_node);
            }

            // Move tile up
            if(move_up > -1 && move_up < size)
            {
                Node* new_node = newNode(node->problem, level, node);
                x = new_node->problem[b_loc];
                new_node->problem[b_loc] = new_node->problem[move_up];
                new_node->problem[move_up] = x;

                string string_a = convertToString(node->problem, size);
                string string_b = convertToString(new_node->problem, size);
                cout << "string a: " << string_a << endl;
                cout << "string b: " << string_b << endl;
                if(string_a != string_b)
                    duplicates = 1;                

                if(duplicates)
                    heuristic.push_back(new_node);
            }

            // Move tile down
            if(move_down > -1 && move_down < size)
            {
                Node* new_node = newNode(node->problem, level, node);
                x = new_node->problem[b_loc];
                new_node->problem[b_loc] = new_node->problem[move_down];
                new_node->problem[move_down] = x;

                string string_a = convertToString(node->problem, size);
                string string_b = convertToString(new_node->problem, size);
                cout << "string a: " << string_a << endl;
                cout << "string b: " << string_b << endl;

                if(string_a != string_b)
                    duplicates = 1;                

                if(duplicates)
                    heuristic.push_back(new_node);
            }   

            // Push by shortest heuristic
            vector<Node*> temp;
            for(int i = 0; i < heuristic.size(); i++)
                heuristic[i]->heuristic = manhattanHeuristic(heuristic[i]);
            temp = sortVect(heuristic);
            nodes.push(temp[0]);
            heuristic.clear();
        }   
    }
}

int misplacedTileHeuristic(struct Node* node)
{
    int const SIZE = 9;
    char goal_node = {'1', '2', '3', '4', '5', '6', '7', '8', 'b'};
    int h_n = 0;
    
    for(int i = 0; i < SIZE; i++)
        if(node->problem[i] != goal_node[i])
            h_n += 1;
    
    return node->level + h_n;
}

Node* makeNodeMisplaced(char problem[], int size)
{
    int b;
    int x;
    // Create a root node.
    Node* root = newNode(problem, 0, NULL);
    // Create a priority queue to store live nodes of 
    // search tree; 
    queue<Node*> nodes;
    vector<Node*> popped_nodes;
    vector<Node*> heuristic;
    nodes.push(root);
    int size_nodes = nodes.size();
    int const SIZE = 9;
    char goal_state[SIZE] = {'1', '2', '3', '4', '5', '6', '7', '8', 'b'};
    int goal = 0;
    int level = 0;
    vector<Node*> temp2;
    
    while(!nodes.empty())
    {
        int duplicates = 0;
        Node* node = nodes.front();
        popped_nodes.push_back(node);
        nodes.pop();
        int popped_size = popped_nodes.size();
        int move_left, move_right, move_up, move_down = 0;

        
        string string_a = convertToString(node->problem, size);
        string string_b = convertToString(goal_state, size);

        if(string_a == string_b)
            return node;
        else
        {
            int b_loc = 0;

            // Get b's location
            for(int i = 0; i < SIZE; i++)
                if(node->problem[i] == 'b')
                    b_loc = i;

            // Operators
            move_left = b_loc - 1;
            move_right = b_loc + 1;
            move_up = b_loc - 3;
            move_down = b_loc + 3;

            // Increment level
            level += 1;

            // Move tile left
            if(move_left > -1 && move_left < size)
            {
                Node* new_node = newNode(node->problem, level, node);
                x = new_node->problem[b_loc];
                new_node->problem[b_loc] = new_node->problem[move_left];
                new_node->problem[move_left] = x;

                string string_a = convertToString(node->problem, size);
                string string_b = convertToString(new_node->problem, size);
                cout << "string a: " << string_a << endl;
                cout << "string b: " << string_b << endl;
                if(string_a != string_b)
                    duplicates = 1;                

                if(duplicates)
                    heuristic.push_back(new_node);                        
            }

            // Move tile right
            if(move_right > -1 && move_right < size)
            {
                Node* new_node = newNode(node->problem, level, node);
                x = new_node->problem[b_loc];
                new_node->problem[b_loc] = new_node->problem[move_right];
                new_node->problem[move_right] = x;

                string string_a = convertToString(node->problem, size);
                string string_b = convertToString(new_node->problem, size);
                cout << "string a: " << string_a << endl;
                cout << "string b: " << string_b << endl;

                if(string_a != string_b)
                    duplicates = 1;                

                if(duplicates)
                    heuristic.push_back(new_node);
            }

            // Move tile up
            if(move_up > -1 && move_up < size)
            {
                Node* new_node = newNode(node->problem, level, node);
                x = new_node->problem[b_loc];
                new_node->problem[b_loc] = new_node->problem[move_up];
                new_node->problem[move_up] = x;

                string string_a = convertToString(node->problem, size);
                string string_b = convertToString(new_node->problem, size);
                cout << "string a: " << string_a << endl;
                cout << "string b: " << string_b << endl;
                if(string_a != string_b)
                    duplicates = 1;                

                if(duplicates)
                    heuristic.push_back(new_node);
            }

            // Move tile down
            if(move_down > -1 && move_down < size)
            {
                Node* new_node = newNode(node->problem, level, node);
                x = new_node->problem[b_loc];
                new_node->problem[b_loc] = new_node->problem[move_down];
                new_node->problem[move_down] = x;

                string string_a = convertToString(node->problem, size);
                string string_b = convertToString(new_node->problem, size);
                cout << "string a: " << string_a << endl;
                cout << "string b: " << string_b << endl;

                if(string_a != string_b)
                    duplicates = 1;                

                if(duplicates)
                    heuristic.push_back(new_node);
            }   

            // Push by shortest heuristic
            vector<Node*> temp;
            for(int i = 0; i < heuristic.size(); i++)
                heuristic[i]->heuristic = misplacedTileHeuristic(heuristic[i]);
            temp = sortVect(heuristic);
            nodes.push(temp[0]);
            heuristic.clear();
        }   
    }
}

int main(int argc, char** argv) 
{
    int const SIZE = 9;
    char user[SIZE] = {'1', '2', '3', '4', '5', 'b', '6', '7', '8'};
    Node* node = newNode(user, 3, NULL);
    Node* temp;
        temp    = makeNodeHeuristic(user, SIZE);
    for(int i = 0; i < SIZE; i++)
        cout << temp->problem[i] << " ";
    cout << endl;
    return 0;
}

