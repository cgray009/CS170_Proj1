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
    
    int num_expand;
    
    vector<int> queueSize;
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
    
    //node->num_expand = exp;
    
    //node->queueSize = vect;
  
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
    vector<int> queue_size;
    vector<Node*> popped_nodes;
    nodes.push(root);
    int size_nodes = nodes.size();
    int const SIZE = 9;
    char goal_state[SIZE] = {'1', '2', '3', '4', '5', '6', '7', '8', 'b'};
    int goal = 0;
    int level = 0;
    vector<Node*> temp2;
    int expand_count;
    
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
        {
            node->num_expand = expand_count;
            node->queueSize = queue_size;
            return node;
        }
        else
        {
            int b_loc = 0;
            expand_count += 1;

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
                
                if(string_a != string_b)
                    duplicates = 1;                

                if(duplicates)
                {
                    nodes.push(new_node);
                    queue_size.push_back(nodes.size());
                }
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

                if(string_a != string_b)
                    duplicates = 1;                

                if(duplicates)
                    nodes.push(new_node);
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
                
                if(string_a != string_b)
                    duplicates = 1;                

                if(duplicates)
                {
                    nodes.push(new_node);
                    queue_size.push_back(nodes.size());
                }
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

                if(string_a != string_b)
                    duplicates = 1;                

                if(duplicates)
                {
                    nodes.push(new_node);
                    queue_size.push_back(nodes.size());
                }
                
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
            if(i == 0 && node->problem[i] == '1')
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
            
            // All h(n) for index 1
            else if(i == 1 && node->problem[i] == '1')
                h_n += 1;
            else if(i == 1 && node->problem[i] == '2')
                h_n += 0;
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
        }
    }
    
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
    vector<int> queue_size;
    vector<Node*> popped_nodes;
    vector<Node*> heuristic;
    nodes.push(root);
    int size_nodes = nodes.size();
    int const SIZE = 9;
    char goal_state[SIZE] = {'1', '2', '3', '4', '5', '6', '7', '8', 'b'};
    int goal = 0;
    int level = 0;
    vector<Node*> temp2;
    int expand_count;
    
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
        {
            node->num_expand = expand_count;
            node->queueSize = queue_size;
            return node;
        }
        else
        {
            int b_loc = 0;
            expand_count += 1;

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
            queue_size.push_back(nodes.size());
            heuristic.clear();
        }   
    }
}

int misplacedTileHeuristic(struct Node* node)
{
    int const SIZE = 9;
    char goal_node[SIZE] = {'1', '2', '3', '4', '5', '6', '7', '8', 'b'};
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
    vector<int> queue_size;
    vector<Node*> popped_nodes;
    vector<Node*> heuristic;
    nodes.push(root);
    int size_nodes = nodes.size();
    int const SIZE = 9;
    char goal_state[SIZE] = {'1', '2', '3', '4', '5', '6', '7', '8', 'b'};
    int goal = 0;
    int level = 0;
    vector<Node*> temp2;
    int expand_count;
    
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
        {
            node->num_expand = expand_count;
            node->queueSize = queue_size;
            return node;
        }
        else
        {
            int b_loc = 0;
            expand_count += 1;

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
            queue_size.push_back(nodes.size());
            heuristic.clear();
        }   
    }
}
#include <string>
#include <sstream>
int main(int argc, char** argv) 
{
    string puzzle_type;
    string input_a, input_b, input_c;
    int search;
    int const SIZE = 9;
    char user[SIZE] = {'1', '2', '3', '4', '5', 'b', '6', '7', '8'};
    
    Node* node = newNode(user, 3, NULL);
    Node* temp;
    /*temp = makeNodeHeuristic(user, SIZE);
    for(int i = 0; i < SIZE; i++)
        cout << temp->problem[i] << " ";
    cout << endl; */
    
    cout << "Welcome to Bertie Woosters 8-puzzle solver.\n" 
         << "Type “1” to use a default puzzle, or “2” to\n"
         << "enter your own puzzle: ";
    getline(cin, puzzle_type);
    
    stringstream geek(puzzle_type);
    int x = 0; 
    geek >> x;
    
    
    switch(x)
    {
        case 1:
            break;
        case 2:
            cout << "\nEnter your puzzle, use a zero to represent the blank\n"
                 << "Enter the first row, use space or tabs between numbers: ";
            getline(cin, input_a);
            cout << "Enter the second row, use space or tabs between numbers: ";
            getline(cin, input_b);
            cout << "Enter the third row, use space or tabs between numbers: ";
            getline(cin, input_c);
            
            input_a.erase(remove(input_a.begin(), input_a.end(), ' '), input_a.end());
            input_b.erase(remove(input_b.begin(), input_b.end(), ' '), input_b.end());
            input_c.erase(remove(input_c.begin(), input_c.end(), ' '), input_c.end());
            input_a.append(input_b);
            input_a.append(input_c);
            
            char input_arr[input_a.length()];
            for (int i = 0; i < sizeof(input_arr); i++) 
                input_arr[i] = input_a[i]; 
            
            char problem_arr[input_a.length()];
            for (int i = 0; i < sizeof(input_arr); i++) 
            {
                if(input_arr[i] == '0')
                    problem_arr[i] = 'b';
                else
                    problem_arr[i] = input_arr[i];
            }
            
            cout << "\nEnter your choice of algorithm\n";
            cout << "\t1. Uniform Cost Search\n";
            cout << "\t2. A* with the Misplaced Tile heuristic\n";
            cout << "\t3. A* with the Manhattan distance heuristic.\n";
            cin >> search;
            
            cout << "\nExpanding state\n\t";
            for(int i = 0; i < 3; i++)
            {
                if(input_arr[i] == '0')
                    cout << "b ";
                else
                    cout << input_arr[i] << " ";
            }
            cout << endl << "\t";
            
            for(int i = 3; i < 6; i++)
            {
                if(input_arr[i] == '0')
                    cout << "b ";
                else
                    cout << input_arr[i] << " ";
            }
            cout << endl << "\t";
            
            for(int i = 6; i < SIZE; i++)
            {
                if(input_arr[i] == '0')
                    cout << "b ";
                else
                    cout << input_arr[i] << " ";
            }
            cout << endl;
                
            switch(search)
            {
                case 3:
                    temp = makeNodeMisplaced(problem_arr, SIZE); 
                    
                    // Depth 1 state
                    int h_n = temp->parent->parent->heuristic - temp->parent->parent->level;
                    cout << "\nThe best state to expand with a "; 
                    cout << "g(n) = " << temp->parent->parent->level << " and h(n) = ";
                    cout << h_n << " is…\n\t";
                    
                    for(int i = 0; i < 3; i++)
                        cout << temp->parent->parent->problem[i] << " ";
                    cout << endl << "\t";

                    for(int i = 3; i < 6; i++)
                        cout << temp->parent->parent->problem[i] << " ";
                    cout << endl << "\t";

                    for(int i = 6; i < SIZE; i++)
                        cout << temp->parent->parent->problem[i] << " ";
                    cout << endl; 

                    // Depth 2 state
                    h_n = temp->parent->heuristic - temp->parent->level;
                    cout << "\nThe best state to expand with a "; 
                    cout << "g(n) = " << temp->parent->level << " and h(n) = ";
                    cout << h_n << " is…\n\t";
                    
                    for(int i = 0; i < 3; i++)
                        cout << temp->parent->problem[i] << " ";
                    cout << endl << "\t";

                    for(int i = 3; i < 6; i++)
                        cout << temp->parent->problem[i] << " ";
                    cout << endl << "\t";

                    for(int i = 6; i < SIZE; i++)
                        cout << temp->parent->problem[i] << " ";
                    cout << endl;  
                    
                    // Goal state
                    h_n = temp->heuristic - temp->level;
                    cout << "\nThe best state to expand with a "; 
                    cout << "g(n) = " << temp->level << " and h(n) = ";
                    cout << h_n << " is…\n\t";
                    
                    for(int i = 0; i < 3; i++)
                        cout << temp->problem[i] << " ";
                    cout << endl << "\t";

                    for(int i = 3; i < 6; i++)
                        cout << temp->problem[i] << " ";
                    cout << endl << "\t";

                    for(int i = 6; i < SIZE; i++)
                        cout << temp->problem[i] << " ";
                    cout << endl; 
                    
                    cout << "\nExpand Total: " << temp->num_expand << endl;
                    cout << "Max number of nodes in queue at one time:\n";
                    cout << *max_element(temp->queueSize.begin(), temp->queueSize.end());

                    break;
            }

            break;
    }
    
    
    return 0;
}

