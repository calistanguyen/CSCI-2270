#include <iostream>
#include <queue>
#include <vector>
#include "Graph.hpp"
using namespace std; 

void Graph::addVertex(string name)
{
	vertex *newVertex = new vertex; 
	newVertex->name = name; 
	vertices.push_back(newVertex);
}

void Graph::addEdge(string v1, string v2)
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

					adjVertex e1; 
					e1.v = vertices[i];
					vertices[j]->adj.push_back(e1);

				}
			}
		}
	}
}

void Graph::displayEdges()
{
	for(int i = 0; i < vertices.size(); i++)
	{
		cout << vertices[i]->name << " --> "; 
		for (int j = 0; j < vertices[i]->adj.size(); j++)
		{
			cout << vertices[i]->adj[j].v->name << " "; 
		}
		cout << endl;
	}

}


void Graph::breadthFirstTraverse(string sourceVertex)
{
	vertex *vStart; 
	for (int i = 0; i < vertices.size(); i++)
	{
		if (vertices[i]->name == sourceVertex)
		{
			vStart = vertices[i];
		}

	}

	vStart->visited = true;

	queue<vertex*> q; 

	q.push(vStart);

	cout<< "Starting vertex (root): " << vStart->name << "->";

	while(!q.empty())
	{
		vertex *n = q.front(); 
		q.pop(); 

		for(int i = 0; i < n->adj.size(); i++)
		{
			vertex *temp = n->adj[i].v;

			if(temp->visited == false)
			{
				temp->visited = true;
				temp->distance = n->distance + 1; 
				cout << n->adj[i].v->name <<"("<< n->adj[i].v->distance <<")"<< " "; 
				q.push(temp);
			}
		}
	}

}

void DFTraversal(vertex *n)
{
    n->visited = true;

    for(int x = 0; x < n->adj.size(); x++ )
    {
    
        if(n->adj[x].v->visited == false)
        {
            n->adj[x].v->visited = true;
            DFTraversal(n->adj[x].v);

        } 
    }


}
int Graph::getConnectedComponents()
{
	int num = 0;

	for(int i = 0; i < vertices.size(); i++)
	{
		if(vertices[i]->visited == false)
		{
			DFTraversal(vertices[i]);
			num++; 
		}
	}

	return num;
	
}



bool Graph::checkBipartite()
{
    for(int i = 0; i < int(vertices.size()); i++)
    {
        if(vertices[i]->visited == false)
        {
            vertex* vStart = vertices[i];
            vStart->visited = true;

			vStart->color = "red";

			queue<vertex*> q; 

			q.push(vStart);

			while(!q.empty())
			{
				vertex *n = q.front(); 
				q.pop(); 

				for(int i = 0; i < int(n->adj.size()); i++)
				{
					vertex *temp = n->adj[i].v;

					if(temp->visited == true)
					{ 
						if(n->color == "red" && temp->color == "red")
						{
							//cout << "U SHOULD BE FALSE" << endl;
							return false; 
						}
						
						if(n->color == "blue" && temp->color == "blue")
						{
							//cout << "U SHOULD BE FALSE" << endl;
							return false; 
						}
					}

					else if (temp->visited == false)
					{
						//cout << "here 2" << endl;
						if(n->color == "red")
						{
							temp->color = "blue";
						}
						else
						{
							temp->color = "red";
						}
						temp->visited = true; 
						q.push(temp);
					}
					
				}
	}	

        }
    }

	return true;
}