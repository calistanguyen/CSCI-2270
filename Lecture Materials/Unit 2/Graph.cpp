void Graph::addEdge(string v1, string v2, int _weight) 
{
	for (int i = 0; i < vertices.size(); i++)
	{
		if(vertices[i]->name == v1)
		{
			for(int j = 0; j < vertices.size(); j++)
			{
				if(vertices[j]->name == v2 && i != j)
				{
					edge e0; 
					e0.v = vertices[j]; 
					e0.weight = _weight; 

					vertices[i] -> adj.push_back(e0);


					edge e1; 
					e1.v = vertices[i]; 
					e1.weight = _weight; 
					vertices[j] -> adj.push_back(e1); 
				}
			}
		}
	}
}