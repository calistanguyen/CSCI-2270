#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <climits>
using namespace std; 

void Graph::addVertex(string name)
{
	vertex *newVertex = new vertex; 
	newVertex->name = name; 
	vertices.push_back(newVertex);
}

void Graph::addEdge(string v1, string v2, int num)
{
    for(int i = 0; i < vertices.size(); i++)
	{
		if(vertices[i]->name == v1)
		{
			for(int j = 0; j < vertices.size(); j++)
			{
				if(vertices[j]->name == v2 && i != j)
				{
					adjVertex e0;
					e0.v = vertices[j];
					vertices[i]->adj.push_back(e0);
                    vertices[i]->adj.back().weight = num;

					adjVertex e1; 
					e1.v = vertices[i];
					vertices[j]->adj.push_back(e1);
                    vertices[j]->adj.back().weight = num; //.back() accesses last element in a vector

				}
			}
		}
	}
}

void depthFirstRecurse(vertex *n)
{
    n->visited = true;

    for(int x = 0; x < (int)n->adj.size(); x++ )
    {
    
        if(n->adj[x].v->visited == false)
        {
            n->adj[x].v->visited = true;
            cout<< n->adj[x].v->name << " --> " ;
            depthFirstRecurse(n->adj[x].v);

        } 
    }

}
void Graph::depthFirstTraversal(string sourceVertex)
{
    vertex *vStart; 
    for(int i = 0; i < (int)vertices.size(); i++)
    {
        if(vertices[i]->name == sourceVertex)
        {
            vStart = vertices[i]; 
        }
    }
    
    cout<< vStart->name << " --> " ;
    depthFirstRecurse(vStart); 
    cout << "Done ";

}

bool isSolved(vector<vertex*> solvedList, string key)
{
   for(int i = 0; i < (int)solvedList.size(); i++)
   {
       if(solvedList[i]->name == key)
       {
           return true; 
       }
   }

   return false; 
}
vertex* Graph::DijkstraAlgorithm(string start, string end)
{
    vertex *vStart; 
    vertex *vEnd; 
    for(int i = 0; i < (int)vertices.size(); i++)
    {
        if(vertices[i]->name == start)
        {
            vStart = vertices[i]; 
        }
        if(vertices[i]->name == end)
        {
            vEnd = vertices[i];
        }
    }
    vector<vertex*> solvedList; 
    solvedList.push_back(vStart); 

    while(!isSolved(solvedList, vEnd->name))
    {
        int minDist = INT_MAX; 
        vertex *solvedV = NULL;

        for(int i = 0; i < (int)solvedList.size(); i++)
        {
            vertex *s = solvedList[i]; 

            for(int j = 0; j < (int)s->adj.size(); j++)
            {
                if(!isSolved(solvedList, s->adj[j].v->name))
                {
                    int dist = s->distance + s->adj[j].weight; 

                    if(dist < minDist)
                    {
                        solvedV = s->adj[j].v; 
                        minDist = dist; 
                        s->adj[j].v->pred = s; 
                    }
                }
            }
        }

        solvedV->distance = minDist; 
        solvedList.push_back(solvedV); 
    
    }

    return vEnd; 

}

void Graph::shortestpath(string start, string end)
{
    vertex *vStart; 
    vertex *vEnd;
    for(int i = 0; i < (int)vertices.size(); i++)
    {
        if(vertices[i]->name == start)
        {
            vStart = vertices[i];
        }

        if(vertices[i]->name == end)
        {
            vEnd = vertices[i];
        }

    }

    vector <vertex*> path; 

    vertex *temp = vEnd; 
    path.push_back(vEnd); 

    while(temp!=vStart)
    {
        path.push_back(temp->pred);
        temp = temp->pred; 
    }

    for(int i = (int)path.size()-1; i >= 0; i--)
    {
        cout << ​path[i]->name ​<< " ";
    }

}

