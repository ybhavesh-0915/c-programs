#include <stdio.h>

/*
    *ptr.member     compiler sees as *(ptr.member)
    (*ptr).member   correct (dereference then access)
    ptr->member     shorthand (same as above)

    * has low precendence as .
*/

struct car_info{
    int max_speed;
    int manufacture_y;
    int tyre_p;
    int eng_capacity;
};

struct car{
    char brand[30];
    int purchase_y;
    struct car_info i;
};

int main(){
    struct car c1 ={"Toyota", 2025, {300, 2024, 15, 1000}};

    struct car *c1ptr = &c1;
    c1ptr->purchase_y = 2026;
    (*c1ptr).purchase_y = 2027;

    printf("Brand Name = %s\n", c1ptr->brand);
    printf("Purchase Year = %d\n", c1ptr->purchase_y);
    printf("max speed = %d\n", c1ptr->i.max_speed);
    printf("manufacture year = %d\n", c1ptr->i.manufacture_y);
    printf("engine c apacity= %dcc\n", c1ptr->i.eng_capacity);
    return 0;
}