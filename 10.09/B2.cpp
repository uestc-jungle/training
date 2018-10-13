#include <bits/stdc++.h>

using namespace std;

int main()
{
    int estados[101][101] = {};

    bool apareceu[1000] = {};

    auto mex = [&](int di, int dj)
    {
        memset(apareceu, 0, sizeof(apareceu));

        for(int i = 0; i < di; i++)
            apareceu[estados[i][dj]] = true;

        for(int j = 0; j < dj; j++)
            apareceu[estados[di][j]] = true;

        int mini = min(di, dj);

        for(int i = 1; i <= mini; i++)
            apareceu[estados[di - i][dj - i]] = true;

        for(int i = 0; i < 1000; i++)
            if(!apareceu[i])
                return i;
    };

    estados[0][0] = 999;
    
    for(int i = 1; i <= 100; i++)
        estados[i][0] = estados[0][i] = estados[i][i] = 999;
    
    for(int i = 1; i <= 100; i++)
    {
        for(int j = 1; j <= 100; j++)
        {
            if(i != j)
                estados[i][j] = mex(i, j);
        }
    }
    
    int n, v = 0, a, b;

    for(int i = 0; i < 10; i ++){
        for(int j = 0; j < 10; j ++)
            printf("%d ", estados[i][j]);
        puts("");
    }

    // cin >> n;

    // while(n--)
    // {
    //     cin >> a >> b;

    //     if(estados[a][b] == 999)
    //     {
    //         cout << "Y" << endl;

    //         return 0;
    //     }

    //     v ^= estados[a][b];
    // }
    
    // cout << (v == 0 ? "N" : "Y")  << endl;
}