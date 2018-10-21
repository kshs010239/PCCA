#include<iostream>
#include<vector>
using namespace std;

struct segmentTree{
	vector<int>	v;
	segmentTree(int n): v(n << 2, 0){}
	segmentTree(){}
	void update(int L, int R, int C, int val, int x = 1)
	{
		//cout << L << " " << R << " " << C << endl;
		if(C < L || C > R)
			return;
		if(L == R)
		{
			v[x] = val;
			cout << L << " " << R << " " << x << endl;
		}
		else
		{
			int M = (L + R) / 2;
			update(L, M, C, val, x * 2);
			update(M + 1, R, C, val, x * 2 + 1);
			v[x] = v[x * 2] + v[x * 2 + 1];
		}
	}
	int query(int L, int R, int CL, int CR, int x = 1)
	{
		if(R < CL || L > CR)
			return 0;
		if(CL <= L && R <= CR)
			return v[x];
		int sum = 0;
		int M = (L + R) / 2;
		sum += query(L, M,     CL, CR, x * 2);
		sum += query(M + 1, R, CL, CR, x * 2 + 1);
		return sum;
	}
};

int main()
{
	int n, q;
	cin >> n >> q;
	segmentTree st(n);
	while(q--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		if(x == 1)
			st.update(1, n, y, z);
		else
			cout << st.query(1, n, y, z) << endl;
		//for(auto& it: st.v) cout << it << " ";
		//cout << endl;
	}
}

