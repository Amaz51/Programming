

//Q1

//We need to explore all the paths but only till first 4 edges
// after exloring all the paths till first four edges, if we have reached our destination then we increment number of
// routes otherwise we dont
// to explore all the paths we need to aplly DFS starting from the source
// The source will call DFS for all its adjecent nodes and those adjacent nodes will call DFS for all their adjacent nodes and so on until 4 edges are complete in each path
// since every node can be connected to every other node say v no of nodes
// so for source there will be v dfs calls and for each of those calls, there will be v more calls and so on till 4 edges have been complete
// so the time complexity will be (V)^4 where V is the number of vertices
routes = 0; // global  variable


findNoOfRoutes(G,src,m,dest)
{
	routes = 0; // initialize global variable
	DFS(G, src, dest, m, 0);
	return routes;
}

DFS(G,src,dest,m,counter)
{
	if(counter==m)
	{
		if(src.val == dest.val) // destination is reached
		{
			routes++;
		}
	}
	else
	{
		counter++;
		for each u belongs to G.Adj[src]
		{
			DFS(G,u,dest,m,counter);
		}
	}
}




//Q2

//If the deleted edge is not in the MST then no need to update the MST
// else the MST has been divided into two connected components
// if edge (a,b) is removed then vertex 'a' belongs to one connected component and vertex 'b' belongs to the other connected component
// we are to connect these to components back together and covert them into a single connected component
// find all vertices in the component to which vertex 'a' belongs
// find all vertices in  the component to which vertex 'b' belongs
// now take difference of set E and E'
// this will give us the edges that belong to the original graph but not the MST
// now we have to choose the minimum edge from (E-E') such that the two verices connected by the edge belong to differnt components
// add this minimum edge to set E' to complete the MST


updateMST((a,b)) // removed edge passed as parameter
{
	flag = false;
	// linear time taken 
	for each edge (u,v) belongs to T.E' 
	{
		if ((u,v) == (a,b))
		{
			flag = true;
			break;
		}
	}


	if(flag== false)
	{
		return; // return since the deleted edge does not belong to the MST
	}

	component1Vertices = {}
	component2Vertices = {}


	for each u belongs to T.V // linear time taken
	{
		u.visited = false
	}

	component1Vertices.add(a)
	a.visited=true

	make Q1 // FIFO
	Q1.add(a)
		 
	while (Q1 != {}) // linear time since each vertex is visited only once
	{
		v=Q1.remove()
		for each u belongs to T.Adj[u]
		{
			if(u.visted!=true)
			{
				u.visited=true
				component1Vertices.add(u)
				Q1.add(u)
			}
		}
	}


	component2Vertices.add(b)
	b.visited = true

	make Q2 // FIFO
	Q2.add(b)

	while (Q2 != {}) // linear time since each vertex is visited only once
	{
		v = Q2.remove()
		for each u belongs to T.Adj[v]
		{
			if (u.visted != true)
			{
				u.visited = true
				component2Vertices.add(u)
				Q2.add(u)
			}
		}
	}

	shortestEdge = infinity
	
    // find the set of edges that are not part of the MST but part of the original graph
	AlternateEdgeSet= G.E - T.E'

	for each edge (u,v) belongs to AlternateEdgeSet // loop runs in linear time
	{
		if((u belongs to component1Vertices and v belongs to component2Vertices) or(v belongs to component1Vertices and v belongs to component2Vertices) and (u,v)<shortestEdge)
		{
			shortestEdge= (u,v)
		}
	}
    
	// add this shotest edge in the MST to complete it
	T.E'.add(shortestEdge) 
}

// overall time complexity is linear i.e. O(V)