#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

#define LD double

typedef pair<int, int> Pair;
typedef vector<vector<Pair> > graph;


double MMC(graph g)
{
	int n = g.size();
	vector<vector<int> > d(n + 1, vector<int>(n, 1e9));
	d[0][0] = 0;
	for(int i = 0; i < n; i++)
		for(int x = 0; x < n; x++)
			for(auto&it: g[x])
				d[i + 1][it.first] = min(d[i + 1][it.first], d[i][x] + it.second);

	double Min = 1e9;
	for(int x = 0; x < n; x++)
	{
		if(d[n][x] == 1e9)
			continue;
		double Max = -1e9;
		for(int k = 0; k < n; k++)
			Max = max(Max, (double)(d[n][x] - d[k][x]) / (n - k));
		Min = min(Min, Max);
	}
	return Min;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<Pair> > g(n + 1);
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back(Pair(b, c));
	}
	for(int i = 1; i <= n; i++)
		g[0].push_back(Pair(i, 0));


	double mean = MMC(g);

	if(mean == 1e9)
		cout << "No cycle found." << endl;
	else
		cout << mean << endl;

}

int main()
{
	int T;
	cin >> T;
	cout << fixed << setprecision(2);
	for(int i = 1; i <= T; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
}
