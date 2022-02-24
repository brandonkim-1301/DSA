/** Graph.c
 * ===========================================================
 * Name: CS220
 * Modified by: Josiah Stearns, Brandon Kim
 * Section: T5A
 * Project: PEX5
 * Purpose: The implementation of a graph.
 * ===========================================================
 */

#include "graph.h"

#include <math.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include "gameLogic.h"

/** -------------------------------------------------------------------
 * Allocate and initialize memory needed to hold a graph data structure.
 * @param numberVertices the number of vertices in the graph
 * @param bytesPerNode the number of bytes used to represent a
 *                     single vertex of the graph
 * @return a pointer to a graph struct
 */
Graph* graphCreate(int numberVertices, int bytesPerNode) {
    Graph* graph = NULL;
    graph = malloc(sizeof(Graph));              // Allocate memory for graph
    graph->numberVertices = numberVertices;     // Set number of vertices in graph
    graph->vertices = malloc(numberVertices * bytesPerNode);                // Allocate memory for verticies
    graph->edges = (int**)calloc(numberVertices, sizeof(int*));   // Allocate memory for edges (max possible edges)
    for(int i = 0; i < numberVertices; i++) {
        graph->edges[i] = (int*)calloc(numberVertices, sizeof(int));
    }
    
    printGraph(graph);
    
    return graph;
}

/** -------------------------------------------------------------------
 * Delete a graph data structure
 * @param graph the graph to delete
 */
void graphDelete(Graph* graph) {
    for (int i = 0; i < graph->numberVertices; i++) {
        free(graph->edges[i]);  // Free all edges
    }
    free(graph->vertices);      // Free all vertices
    free(graph);                // Free graph       
}

/** -------------------------------------------------------------------
 * Set the state of an edge in a graph
 * @param graph the graph to modify
 * @param fromVertex the beginning vertex of the edge
 * @param toVertex the ending vertex of the edge
 * @param state the state of the edge
 */
void graphSetEdge(Graph* graph, int fromVertex, int toVertex, int state) {
    graph->edges[fromVertex][toVertex] = state; // Set edge of graph
    graph->edges[toVertex][fromVertex] = state;
}

/** -------------------------------------------------------------------
 * Get the state of an edge in a graph
 * @param graph the graph
 * @param fromVertex the starting vertex of the edge
 * @param toVertex the ending vertex of the edge
 * @return the state of the edge
 */
int graphGetEdge(Graph* graph, int fromVertex, int toVertex) {
    return graph->edges[fromVertex][toVertex];  // Get edge of graph
}