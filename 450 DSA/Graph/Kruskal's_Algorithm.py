import queue
import sys

class Edge:
    def __init__(self,source,destination,weight):
        self.source = source
        self.destination = destination
        self.weight = weight

def getparent(v,parent):
    if (v==parent[v]):
        return v
    return getparent(parent[v],parent)

def kruskal(Edges,n):
    # sort the edges array according to weight
    Edges = sorted(Edges,key = lambda Edges: Edges.weight)
    # make parent dictionary
    parent = [i for i in range(n)]
    # make count variable
    count = 0
    i = 0
    output = []

    while (count<(n-1)):
        v1 = Edges[i].source
        v2 = Edges[i].destination
        srcParent = getparent(v1,parent)
        destParent = getparent(v2,parent)
        if srcParent!=destParent:
            output.append(Edges[i])
            count+=1
            parent[srcParent] = destParent

        i+=1

    return output


# MAIN
# take input
nVertices , nEdges = [int(ele) for ele in input().split()]
Edges = []
for i in range(nEdges):
    v1,v2,w = [int(ele) for ele in input().split()]
    e = Edge(v1,v2,w)
    Edges.append(e)

output = kruskal(Edges,nVertices)
for edge in output:
    if edge.source < edge.destination:
        print(str(edge.source) + " " + str(edge.destination) + " " + str(edge.weight))
    else:
        print(str(edge.destination) + " " + str(edge.source) + " " + str(edge.weight))
