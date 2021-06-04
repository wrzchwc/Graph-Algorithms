## Graph Algorithms
# General characteristics
Project researches impact of graph representation for the time of MST and shortest path algorithms execution. It was 
writen in C++. Mersenne Twister algorithm was used for all random number generations. Graph algorithms include:
- Dijkstra Algorithm
- Bellman-Ford Algorithm
- Prim Algorithm
- Kruskal Algorithm
# Loading graphs
Program offers loading graphs saved in a txt file. To load a file choose: Control mode/Load graph from the file\
The required format of the source file is:\
a0 a1 a2 \
b0 c0 d0 \
bn cn dn\
where:
- a0 - number of edges in the graph
- a1 - number of vertexes in the graph
- a2 - initial vertex (optional for MST algorithms)
- b0 - beginning of the edge
- b1 - end of the edge
- b2 - weight of the edge

Furthermore:
- vertexes should be indexed steady from 0
- all numbers should be separated with the delimiter of " " (single space)
- there must be single empty line after data of the last edge
- source file should be located in the same location as executable file \


