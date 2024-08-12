


Node* findParent(Node* root, map<Node*, Node*> &parent, int target){
        queue<Node*>q;
        q.push(root);
        Node* res;
        while(!q.empty()){
            Node* node = q.front();
            if(node->data == target) res = node;
            q.pop();
            
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
    
    int findMinTime(map<Node*, Node*> &parent, Node* target ){
        queue<Node*>q;
        q.push(target);
        map<Node*, int>vis;
        vis[target] = 1;
        int maxi = 0;
        while(!q.empty()){
            int size = q.size();
            int flag = 0;
            for(int i=0; i<size; i++){
                Node* node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    flag = 1;
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    flag = 1;
                    vis[node->right] = 1;
                    q.push(node->right);
                }
                if(parent[node] && !vis[parent[node]]){
                    flag = 1;
                    vis[parent[node]] = 1;
                    q.push(parent[node]);
                }
            }
            if(flag) maxi++;
        }
        return maxi;
    }
  
    int minTime(Node* root, int target)
    {
        // Your code goes here
        map<Node*, Node*> parent;
        Node* start = findParent(root, parent, target);
        int maxi = findMinTime(parent, start);
        
        return maxi;
    }