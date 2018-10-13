#include<bits/stdc++.h>
using namespace std;

namespace jspace {


const int threshold = 640;
const int maxn = threshold << 2;
const int maxm = threshold << 2;

#define pb push_back

int n, s;

vector<int> g[maxn + 100];
int from[maxn + 100];
bool use[maxn + 100];

bool match(int x){
	int sz = g[x].size();
    for(int i = 0; i < sz; ++ i){
        if(!use[g[x][i]]){
            use[g[x][i]] = true;
            if(from[g[x][i]] == -1 || match(from[g[x][i]])){
                from[g[x][i]] = x;
                return true;
            }
        }
    }
    return false;
}

int hungary(){
    int tot = 0;
    memset(from, 255, sizeof from);
    for(int i = 1; i <= n; i ++){
        memset(use, 0, sizeof use);
        if(match(i)) ++tot;
    }
    return tot;
}
/*
const int upp = 50;
int main(){
    for(int s = 1; s <= upp; s ++){
        for(int n = 1; n <= upp; n ++){
            for(int n = 1; n <= upp; n ++){
                g[n].clear();
            }
            for(int x = 1; x <= n; x ++)
                for(int k = 1; k <= n; k ++){
                    if((s+x) % k) continue;
                    g[x].push_back(k+maxm);
                // g[k+maxm].push_back(n);
                }
            int ans = 0;
            if(hungary() == n)
                ans = 1;
            printf("%d", ans);
        }
        puts("");
    }
}*/


int casid;

void main(void)
{
	scanf("%d%d", &n, &s);
	printf("Case #%d: ", ++casid);
	/*if (0 == s)
	{
		puts("Yes");
		return 0;
	}*/
	if (s < n) swap(s, n);
	if (n >= threshold)
	{
		puts("No");
		return;
	}
	for (int i = 1; i <= n; i++) g[i].clear();
	/*for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n + s; j += i)
			if (j > s)
				g[j - s].pb(i + threshold + 1);
	}*/
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (0 == (s + i) % j)
				g[i].pb(j);
	puts((hungary() == n) ? "Yes" : "No");
}

}

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--) jspace::main();
	return 0;
}

