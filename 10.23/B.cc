#include <bits/stdc++.h>
typedef double db;
using namespace std;
const db pi=acos(-1.0L);
const db eps=1e-6;

db dis(db x1,db y1,db x2,db y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main() {
    db r,l,w;
    scanf("%lf%lf%lf",&r,&l,&w);
    int cas;
    scanf("%d",&cas);
    while (cas--) {
        db A,B,ans=min(w/2.0,min(r,l/2.0));
        scanf("%lf%lf",&A,&B);
 //       ans=min(ans,(l*sin(A)/sin(1.5708-A))/4.0);
        if (B-pi/2+eps>=0) {
            if (A-pi/2-eps<0) 
                ans=min(ans,(l*sin(A)/sin(pi/2-A))/4.0);
            ans=min(ans,(w-l*sin(pi-B))/2.0);
        } else {
            if (A-pi/2-eps<0) {
                ans=min(ans,(l*sin(A)/sin(pi/2-A))/4.0);
                if (A<B) {
                    db x,y;
                    x=w+tan(A)*l-l*sin(B)+l*(1-cos(B))/tan(B);
                    x/=(tan(A)+1.0/tan(B));
                    y=-tan(A)*(x-l)+w;
                    ans=min(ans,dis(l*(1-cos(B)),l*sin(B),x,y)/2.0);
                } else {
                    db x,y;
                    x=l/tan(B)-w+l*tan(B);
                    x/=(tan(B)+1/tan(B));
                    y=-tan(B)*(x-l);
                    ans=min(ans,dis(l*(1-cos(B)),l*sin(B),x,y)/2.0); 
                }
            } else {
                ans=min(ans,dis(l,w,l*(1-cos(B)),l*sin(B))/2.0);
            }
        }
        printf("%.7lf\n",ans);
    }
}