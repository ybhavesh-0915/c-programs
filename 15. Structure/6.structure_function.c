#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct car_info{
    int max_speed;
    int manufacture_y;
    int tyre_p;
    int eng_capacity;
};

struct car{
    char brand[100];
    int purchase_y;
    struct car_info i;
};

// struct car createCar(char *brandname, int purchase_y, int max_speed, int tyre_p, int eng_capacity){
//     struct car c1 ={"", purchase_y, {max_speed, 2024, tyre_p, eng_capacity}};
//     strcpy(c1.brand, brandname);
//     return c1;
// }

// struct car create_car(char *brandname, int purchase_y, struct car_info i){
//     struct car c1 = {"", purchase_y, i};
//     strcpy(c1.brand, brandname);
//     return c1;
// }

struct car *create_car(char *brandname, int purchase_y, struct car_info *i){
    struct car *c1 = (struct car*)malloc(sizeof(struct car));
    strcpy(c1->brand, brandname);
    (*c1).purchase_y = purchase_y;
    c1->i = *i;

    return c1;
}

int main(){
    // struct car bmw = createCar("bmw", 2025, 350, 30, 1500);

    // struct car bmw = create_car((char*)"bmw", (int)2025, (struct car_info ){350,2024,250,550}); //complier need type info so type casting 
    struct car *bmw = create_car((char *)"bmw", (int)2025, &(struct car_info *){350,2024,250,550});
    
    printf("Brand Name = %s\n", bmw->brand);
    printf("Purchase Year = %d\n", bmw->purchase_y);
    printf("max speed = %d\n", bmw->i.max_speed);
    printf("manufacture year = %d\n", bmw->i.manufacture_y);
    printf("engine c apacity= %dcc\n", bmw->i.eng_capacity);
    return 0;
}