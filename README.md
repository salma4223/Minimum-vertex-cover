# Minimum-Vertex-Cover
A C++ console program that computes the Minimum Vertex Cover of an undirected graph using a brute force search over all possible subsets of vertices.
This project is intended for educational purposes and demonstrates minimization concept.

## Table of contents
[Project Description](#project-description)
[Build Instructions](#build-instructions)
[How to Run](#how-to-run)
[How to Use](#how-to-use)
[Example Output](#example-output)


### Project Description
A vertex cover is a set of vertices such that every edge in the graph has at least one endpoint in that set.

This program: . Builds a graph using an adjacency list.
. Generates all possible subsets of vertices.
. Tests which subsets are valid vertex cover.
. Selects the minimum-sized valid cover.
.Prints the result.
The code is written in C++ and is suitable for small graohs due ti its brute-force nature.

#### Build Instructions
You need a C++ compiler that supports C+ +11 or newer.
Compile using g++:
g++ -std=c++11 -o vertex_cover main.cpp

This creates an executable named vertex_cover.

##### How to Run
. Linux / macOS
./vertex_cover

. Windows
vertex_cover.exe

###### How to use
. Open main.cpp
. Modify the edges inside main():
g.addEdge(0, 1);
g.addEdge(1, 2);
g.addEdge(2, 3);
g.addEdge(3, 0);

. Add, remove, or change edges to build your own graph.
. Compile and run.
. The program will display: . The graph's edges.
. The minimum vertex cover and its size.

**Example Output**

=== Vertex Cover Solver ===
Graph edges:
0 -- 1
0 -- 3
1 -- 2
2 -- 3

Minimum Vertex Cover (size 2): 0 2
