#include<stdio.h>

int main(){
    int n, k;
    printf("Enter n, k: "); scanf("%d %d", &n, &k);
    long long a=1, b=1;
    long long ans;
    for(int i=3; i<=n; i++){
        ans = a*k+b;
        a = b;
        b = ans;
    }
    printf("ans: %lld\n", ans);
return 0;
}

