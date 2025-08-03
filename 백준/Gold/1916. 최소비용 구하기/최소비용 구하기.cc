// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<queue>

int inf = 1000000000;

std::vector<int> dijkstra(std::vector<std::vector<std::pair<int,int>>> &graph, int start, int n){
    std::vector<int> distance(n+1,inf);
    distance[start] = 0;
    
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;
    pq.push(std::make_pair(0,start));
    
    while(!pq.empty()){
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if(dist>distance[now]){
            continue;
        }
        
        for(auto &edge :graph[now]){
            int next = edge.first;
            int cost = edge.second;
            
            if(distance[next] > distance[now] + cost){
                distance[next] = distance[now] + cost;
                pq.push(std::make_pair(distance[next], next));
            }
        }
    }
    return distance;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(NULL);
    
    int n,m;
    std::cin>>n;
    std::cin>>m;
    std::vector<std::vector<std::pair<int,int>>> graph(n+1);
    
    int s,e,c;
    for(int i = 0; i<m; i++){
        std::cin>>s>>e>>c;
        graph[s].push_back(std::make_pair(e,c));
    }
    
    int start, end;
    std::cin>>start>>end;
    
    std::vector<int> answer = dijkstra(graph, start, n);
    /*for(auto elem: answer){
        std::cout<<elem<<' ';
    }*/
    std::cout<<answer[end];
    
}

