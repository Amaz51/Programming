

//Q1
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