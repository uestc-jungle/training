#include <bits/stdc++.h>

using namespace std;

const int maxn = 10010;

int la, lb;
char cipher[maxn], crib[maxn];

int main(void)
{
    int cnt = 0;
    scanf("%s%s", cipher, crib);
    la = strlen(cipher);
    lb = strlen(crib);
    for (int i = 0; i + lb <= la; i++)
    {
        int ok = 1;
        for (int j = 0; j < lb; j++)
            if (cipher[i + j] == crib[j])
            {
                ok = 0;
                break;
            }
        cnt += ok;
    }
    printf("%d\n", cnt);
    return 0;
}
