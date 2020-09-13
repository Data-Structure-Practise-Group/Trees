/* For the following tree :
        1
      /   \
     2     3
    / \   / \
   4  5   6  7
   
 Output : 1 2 3 7 6 5 4  */

void printSpiral(node* root) 
{ 
    if (root == NULL) 
        return;
  
    // Create two stacks to store alternate levels 
    stack<node*> st1; 
    stack<node*> st2;  
  
    // Push first level to first stack 'st1' 
    st1.push(root); 
  
    // Keep printing while any of the stacks has some nodes 
    while (!st1.empty() || !st2.empty()) { 
        
        // Print nodes of current level from st1 and push nodes of 
        // next level to st2 
        while (!st1.empty()) { 
            node* temp = st1.top(); 
            st1.pop(); 
            cout << temp->data << " "; 
            
            if (temp->right) 
                st2.push(temp->right); 
            if (temp->left) 
                st2.push(temp->left); 
            
        } 
  
        // Print nodes of current level from st2 and push nodes of 
        // next level to st1 
        while (!st2.empty()) { 
            node* temp = st2.top(); 
            st2.pop(); 
            cout << temp->data << " "; 
            
            if (temp->left) 
                st1.push(temp->left); 
            if (temp->right) 
                st1.push(temp->right); 

        } 
    } 
} 