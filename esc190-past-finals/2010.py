#adjacency matrix 

import numpy as np
import LL 

class Graph:
    def __init__(self, num_nodes):
        self.adj_matrix = np.zeros((num_nodes, num_nodes), dtype=int)
    def is_edge(self, i, j):
        return self.adj_matrix[i][j] == 1
    def insert(self, i, j): 
        self.adj_matrix[i][j] = 1
    def remove_edge(self, i, j):
        self.adj_matrix[i][j] = 0 

#adjacency list 

class graph2: 
    def __init__(self, num_nodes):
        self.nodes = []
        for i in range(self.num_nodes):
            self.nodes.append(LL.LL())
    def is_edge(self, i, j):
        return self.nodes[i].is_in(j)
    def put_edge(self, i, j):
        self.nodes(i).insert(0, j)
    def remove_edge(self, i,j):
        self.nodes[i].remove(j) 


if __name__ == "__main__":
    g = Graph(4)
    g.insert(0,1)
    g.insert(1,2)
    g.insert(1,3)
    print(g.is_edge(1,2))
    g.remove_edge(1,2)


