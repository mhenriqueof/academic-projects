# include <stdio.h>

int main(void) {
    int x,y,w,*p1,*p2;
    
    x = 20;
    w = 30;

    p1 = &x;
    p2 = &w;
    
    y = *p1 + *p2;
    
    printf("%d", y);
    
    return 0;
}
