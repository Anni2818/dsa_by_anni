/**
 * Return the length of the shortest path between root and target node.
 */
int BFS(Node root, Node target) {
    Queue<Node> queue;  // store all nodes which are waiting to be processed
    int step = 0;       // number of steps needed from root to current node
    // initialize
    add root to queue;
    // BFS
    while (queue is not empty) {
        // iterate the nodes which are already in the queue
        int size = queue.size();
        for (int i = 0; i < size; ++i) {
            Node cur = the first node in queue;
            return step if cur is target;
            for (Node next : the neighbors of cur) {
                add next to queue;
            }
            remove the first node from queue;
        }
        step = step + 1;
    }
    return -1;          // there is no path from root to target
}



//the actual code:

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<bool>vis(adj.size(),false);
        queue<int>q;
        vector<int>ans;
        // int i=0;
        q.push(0);
        vis[0] = true;
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(int j=0;j<adj[front].size();j++)
            {
                int nbr = adj[front][j];
                if(!vis[nbr]){
                    q.push(nbr);
                    vis[nbr] = true;
                }
            }
            // i++;
        }
        return ans;
    }
};