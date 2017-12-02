#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

struct UndirectedGraphNode{
    int label;
    vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x) :label(x) {}
};

class Solution {
public:
    /**
    * @param node: A undirected graph node
    * @return: A undirected graph node
    */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        if (node == NULL)
            return NULL;
        queue<UndirectedGraphNode*> que;//存入原图中要访问的节点
        map<UndirectedGraphNode*, bool> isVisited;//标记原图中的节点是否被访问
        map<UndirectedGraphNode*, UndirectedGraphNode*> match;//原图节点与新节点的映射
        UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);//创建新节点
        isVisited[node] = true;
        match[node] = newNode;
        que.push(node);
        while (!que.empty())
        {
            node = que.front();//取队头节点
            que.pop();
            for (int i = 0; i<node->neighbors.size(); ++i)
            {
                if (isVisited[node->neighbors[i]] == false)//若未访问，创建新节点来与此节点对应，并将此节点的neighbors入队，新节点加入到node对应的新节点的相邻节点
                {
                    UndirectedGraphNode *temp = new UndirectedGraphNode(node->neighbors[i]->label);
                    isVisited[node->neighbors[i]] = true;
                    match[node->neighbors[i]] = temp;
                    que.push(node->neighbors[i]);
                    match[node]->neighbors.push_back(temp);
                }
                else
                {
                    match[node]->neighbors.push_back(match[node->neighbors[i]]);//若已访问，把node节点的相邻节点对应的新节点的加入到node节点对应新节点的相邻节点
                }
            }
        }
        return newNode;
    }
};

int main(int argc, char** argv)
{
    Solution slu;


    return 0;
}
