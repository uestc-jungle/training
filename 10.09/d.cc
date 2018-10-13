#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int N, cnt = 0;
    scanf("%d", &N);
    while (N--)
    {
        int ai;
        scanf("%d", &ai);
        cnt += (1 != ai);
    }
    printf("%d\n", cnt);
    return 0;
}