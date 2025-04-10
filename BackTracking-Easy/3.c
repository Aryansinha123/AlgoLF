/*Embark on an adventure with Jake, a computer science enthusiast, as he explores the world of algorithms. Jake is working on a program to uncover the mysteries of chromatic numbers in undirected graphs.

Using an adjacency matrix, his program aims to find the chromatic number - the smallest number of colors needed to color vertices without having neighboring vertices share the same color.

Your role is to help Jake develop a program that efficiently calculates the chromatic number of an undirected graph.

Use Backtracking Algorithm

Input format :
The first line contains an integer v, representing the number of vertices in the graph.

The next v lines contain the adjacency matrix of the graph, where each line contains v space-separated integers (0 or 1).

Output format :
The output prints "Chromatic Number of the graph is: " followed by an integer representing the chromatic number of the graph.

Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ v ≤ 50

Sample test cases :
Input 1 :
4
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
Output 1 :
Chromatic Number of the graph is: 3
Input 2 :
5
0 1 0 1 0
1 0 1 0 1
0 1 0 1 0
1 0 1 0 1
0 1 0 1 0
Output 2 :
Chromatic Number of the graph is: 2
Input 3 :
5
0 1 1 0 0
1 0 1 1 0
1 1 0 1 1
0 1 1 0 1
0 0 1 1 0
Output 3 :
Chromatic Number of the graph is: 3
*/
#include <stdio.h>
#include <stdbool.h>

#define MAX_V 50

int v;                   // Number of vertices
int graph[MAX_V][MAX_V]; // Adjacency matrix
int colors[MAX_V];       // Colors assigned to vertices

bool isSafe(int vertex, int c)
{
    for (int i = 0; i < v; i++)
    {
        if (graph[vertex][i] && colors[i] == c)
        {
            return false;
        }
    }
    return true;
}

bool graphColoring(int vertex, int m)
{
    if (vertex == v)
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(vertex, c))
        {
            colors[vertex] = c;
            if (graphColoring(vertex + 1, m))
                return true;
            colors[vertex] = 0; // Backtrack
        }
    }
    return false;
}

int findChromaticNumber()
{
    for (int m = 1; m <= v; m++)
    {
        for (int i = 0; i < v; i++)
            colors[i] = 0;
        if (graphColoring(0, m))
            return m;
    }
    return v;
}

int main()
{
    scanf("%d", &v);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Chromatic Number of the graph is: %d\n", findChromaticNumber());
    return 0;
}
