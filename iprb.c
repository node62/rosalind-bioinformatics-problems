#include<stdio.h>

int main(){
    float k, m, n;
    printf("Enter k, m, n: "); scanf("%f %f %f", &k, &m, &n);
    float t = k+m+n;
    float ans = k/t + m/t*(k/(t-1) + 0.75*(m-1)/(t-1) + 0.5*n/(t-1)) + n/t*(k/(t-1) + 0.5*m/(t-1));
    printf("ans: %f", ans);
return 0;
}