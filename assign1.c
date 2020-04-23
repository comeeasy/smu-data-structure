#include <stdio.h>
#include <stdlib.h>

// upperboundary of factorial in llu is 20
#define MAX 21
typedef long long unsigned llu;

// 1. array
void f_arr(int n) {
    static llu arr[MAX];

    arr[0] = 1;
    for(int i=1; i<MAX; ++i) arr[i] = arr[i-1]*i;
    for(int i=0; i<=n; ++i) printf("%d! = %llu\n", i, arr[i]);
}
// 2. pointer
void f_pointer(int n) {
    llu* ptr = (llu*)malloc(sizeof(llu)*MAX);

    *ptr = 1;
    for(int i=1; i<MAX; ++i) *(ptr + i) = *(ptr + (i-1))*i;
    for(int i=0; i<=n; ++i) printf("%d! = %llu\n", i, *(ptr + i));

    free(ptr);
}
// 3. structure
struct facto {
    int num[MAX];
    llu arr[MAX];
};
void f_structure(int n) {
    struct facto f;

    for(int i=0; i<MAX; ++i) f.num[i] = i;
    f.arr[0] = 1;
    for(int i=1; i<MAX; ++i) f.arr[i] = f.arr[i-1]*i;

    for(int i=0; i<=n; ++i) printf("%d! = %llu\n", i, f.arr[i]);
}

void ui(void (*op1)(int), void (*op2)(int), void (*op3)(int)) {
    int num, n;

    while(1) {
        printf("-------------------------------------------------------------\n");
        printf("1. array    2. pointer    3. structure    4. exit\nselect=");
        scanf("%d", &num);
        printf("-------------------------------------------------------------\n");

        if(num >= 1 && num <= 3) break;
        else if(num == 4) return;
        else printf("wrong num selenct again\n");
    }
    while(1) {
        printf("-------------------------------------------------------------\n");
        printf("enter n ( 0 <= n <= 20)\nn=");
        scanf("%d", &n);
        printf("-------------------------------------------------------------\n");

        if(n>=0 && n<=20) break;
        else printf("enter again\n");
    }

    switch(num) {
        case 1 : op1(n); break;
        case 2 : op2(n); break;
        case 3 : op3(n); break;
    }
}
int main() {
    ui(f_arr, f_pointer, f_structure);
    return 0;
}
