#include<bits/stdc++.h>
using namespace std;
const int maxn = 5 * 101010;
struct SKILL{
    int siz, num;
    bool operator < (const SKILL &tx) const{
        return siz > tx.siz;
    }
}s[maxn];

struct Edge{
    int to, stu;
    Edge(int nt=0, int ns=0):to(nt), stu(ns){}
};

int rem[maxn];
vector<int> skil[maxn];
stack<int> peop[maxn];
vector<Edge> tree[maxn];
stack<int> rem_ans;

int dfs(int x){
    int siz = tree[x].size();
    int ans = peop[x].size();
    int oth = siz ? maxn : 0;
    for(int i = 0; i < siz; i ++){
        oth = min(oth, dfs(tree[x][i].to));
    }
    return oth + ans;
}

int main(){
    int tx, n, m, p, siz;
    scanf("%d%d%d", &n, &m, &p);
    for(int i = 1; i <= m; i ++){
        scanf("%d", &siz);
        for(int j = 0; j < siz; j ++){
            scanf("%d", &tx);
            skil[i].push_back(tx);
        }
        s[i].siz = siz, s[i].num = i;
        // printf("%d\n", s[i].siz);
    }

    sort(s+1, s+1+m);

    for(int i = 1; i <= m; i ++){
        tree[rem[skil[s[i].num][0]]].push_back(Edge(s[i].num, 1));
        for(int j = 0; j < s[i].siz; j ++){
            rem[skil[s[i].num][j]] = s[i].num;
        }
        // printf("Debug : %d\n", s[i].num);
    }

    // for(int i = 1; i <= n; i ++)
    //     printf("%d ", rem[i]);


    // puts("");
    // for(int i = 0; i <= m; i ++){
    //     for(int j = 0; j < tree[i].size(); j ++){
    //         printf("%d ", tree[i][j]);
    //     }
        // puts("");
    // }
    
    for(int i = 1; i <= p; i ++){
        scanf("%d", &tx);
        peop[tx].push(i);
        // printf("%d ", tx);
    }
    // puts("");
    // for(int i = 1; i <= m; i ++){
    //     printf("debug : %d\n", peop[i].size());
    // }

    int ans = dfs(0);
    printf("%d\n", ans);
    while(ans --){
        int siz = tree[0].size();
        for(int j = 0; j < siz; j ++){
            if(!tree[0][j].stu) continue;
            if(peop[tree[0][j].to].empty()){
                tree[0][j].stu = 0;
                int tem_siz = tree[tree[0][j].to].size();
                for(int k = 0; k < tem_siz; k ++){
                    tree[0].push_back(Edge(tree[tree[0][j].to][k].to, 1));
                }
                siz = tree[0].size();
            }
            else{
                rem_ans.push(peop[tree[0][j].to].top());
                peop[tree[0][j].to].pop();
            }
        }
        printf("%ld ", rem_ans.size());
        while(!rem_ans.empty()){
            printf("%d ", rem_ans.top()); rem_ans.pop();
        }
        puts("");
    }
    // for(int i = 1; i <= m; i ++)
    //     printf("%lu ", peop[i].size());
    // siz = tree[0].size();
    // printf("%d ", siz);
}

