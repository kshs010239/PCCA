#define INF 1e9

typedef pair<int, int> Pair;
typedef vector<vector<Pair> > graph;

double MMC(graph g)
{
	int n = g.size();
	vector<vector<int> > d(n + 1, vector<int>(n, INF));
	d[0][0] = 0;
	for(int i = 0; i < n; i++)
		for(int x = 0; x < n; x++)
			for(auto&it: g[x])
				d[i + 1][it.first] = min(d[i + 1][it.first], d[i][x] + it.second);

	double Min = INF;
	for(int x = 0; x < n; x++)
	{
		if(d[n][x] == INF)
			continue;
		double Max = -INF;
		for(int k = 0; k < n; k++)
			Max = max(Max, (double)(d[n][x] - d[k][x]) / (n - k));
		Min = min(Min, Max);
	}
	return Min;
}

