
class UnionFind
{
public:
    UnionFind(int n) : parent(n), rank(n, 1), count(n)
    {
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }

    void unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX] += 1;
            }
            --count;
        }
    }

    int getCount() const
    {
        return count;
    }

private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

class Solution
{
public:
    int regionsBySlashes(vector<string> &grid)
    {
        int n = grid.size();
        int size = 4 * n * n; 
        UnionFind uf(size);

        for (int r = 0; r < n; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                int index = 4 * (r * n + c);
                char val = grid[r][c];

                
                if (val == ' ')
                {
                    uf.unionSets(index, index + 1);
                    uf.unionSets(index + 1, index + 2);
                    uf.unionSets(index + 2, index + 3);
                }
                else if (val == '/')
                {
                    uf.unionSets(index, index + 3);
                    uf.unionSets(index + 1, index + 2);
                }
                else if (val == '\\')
                {
                    uf.unionSets(index, index + 1);
                    uf.unionSets(index + 2, index + 3);
                }

                if (c + 1 < n)
                {
                    uf.unionSets(index + 1, 4 * (r * n + c + 1) + 3);
                }

                if (r + 1 < n)
                {
                    uf.unionSets(index + 2, 4 * ((r + 1) * n + c) + 0);
                }
            }
        }

        return uf.getCount();
    }
};
