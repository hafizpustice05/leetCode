#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

/**
 * Function Defination
 */
void BFS(int startingNode, int numberOfNode);
void buildGraph();
/**
 * visited[1] = 1 means visited node
 * visited[1] = 0 means unvisited node
 */

vi edge[100];
int visited[100];

/**  
 * this is undirected Graph 
 * 
 *          1-----2------3
 *         /  \         |
 *        4 --5--------6
 */
int main()
{
    buildGraph();

    /**
     * Travasing the graph
     * 1 is starting node & 6 is the number of node in this graph
     */
    BFS(1, 6);
    return 0;
}

void buildGraph()
{
    edge[1].push_back(2);
    edge[1].push_back(4);
    edge[1].push_back(5);
    
    edge[2].push_back(3);
    edge[2].push_back(1);
     
    edge[3].push_back(2);
    edge[3].push_back(6);

    edge[6].push_back(3);
    edge[6].push_back(5);

    edge[5].push_back(1);
    edge[5].push_back(6);

    edge[4].push_back(1);
    edge[4].push_back(5);
}


void BFS(int startingNode, int numberOfNode)
{
    int u,v,i;
    queue<int> nodeQueue;
    nodeQueue.push(startingNode);
    for(i=0; i<=numberOfNode; i++) visited[i]=0;
    visited[startingNode] = 1;
    
    while(!nodeQueue.empty()){
        /**
         * reading the front value of the node
         * & remove this node from the queue 
         */
        u = nodeQueue.front(); 
        nodeQueue.pop();
        printf("\n-->%d",u);
        for(i=0; i<edge[u].size(); i++){
            v = edge[u][i];
            /**
             * frist check this node is it visited
             * if it is not visited
             * visit this node & push this node in the queue
             */
            if(!visited[v]){
                printf("-->%d",v);
                visited[v]=1;
                nodeQueue.push(v);
            }
        }
    }
}

void vectorPair()
{
    vii vec1;
    vec1.push_back(make_pair(1,10));
    vec1.push_back(make_pair(1,15));

    cout<< "vector first first value: "<<  vec1[0].first;
    cout<< "\nvector first second value: "<<  vec1[0].second;
    cout<< "\nvector second first value: "<<  vec1[1].first;
    cout<< "\nvector second second value: "<<  vec1[1].second;
}