//Employee Id:142874
//Name:Darrel
//version 1.0

#ifndef _MOBILE_H
#define _MOBILE_H

#include<stdio.h>
#include<stddef.h>
#include<string.h>

#define MAX_SIZE 50

struct mobile{
int model_no;
char oem[50];
double display;
double battery_capacity;
double memory;
double internal_storage;
double camera_resolution;
double price;
};
typedef struct mobile mobile_t;
mobile_t * marr;
void displayModel(const mobile_t*,int);
double findAverageprice(const mobile_t *, int);
mobile_t*findmodelbymaxbc(const mobile_t*,int,double);
mobile_t*findmobilebymaxcr(const mobile_t*,int,double);
void check() { }
int testValue;
static int testValue;
int length=0;
int  main() {
 mobile_t marr[MAX_SIZE]={{201,"Sony",1000,2500,1,16,120,10500},{[3]=.price=5000}};
  readAll(marr, 50);
  length=50;
  addRecord(marr, length);
  displayModel(marr, length);
  mobile_t *bc = findmodelbymaxbc(marr, 50, 10000);
  mobile_t *cr= findmodelbymaxcr(marr, 50, 420);
double avp = findAverageprice(marr, 50);
return 0;
}
void addRecord(mobile_t *marr, int n) {
  readSingle(&marr[n]);
  length++;
}
void readAll(mobile_t *parr,int n) {
  int counter = 0;
  for(int i=0;i<n;i++)
    readSingle(&parr[i]);
}
void readSingle(mobile_t *ptr) {
  scanf("%d%s%lf%lf%lf%lf%lf%lf",ptr->model_no, ptr->oem,
          ptr->display, ptr->battery_capacity, ptr->memory,ptr->internal_storage,ptr->camera_resolution,ptr->price);
}
void displayModel(const mobile_t *parr,int n) {
  printf("Size of arr: %d\n", sizeof(parr));
  const mobile_t *pcur=parr;
  for(int i=0;i<n;i++)
    displayOne(pcur++);
}

void displayOne(const mobile_t *ptr) {
  printf("Model is %s with model no. %d\n",ptr->oem,ptr->model_no);
}

void fillRecord(mobile_t *ptr, int n , const char *name) {
   ptr->model_no=length;
   strcpy(ptr->oem,name);
   ptr->display = 15 + rand()%30;
   ptr->battery_capacity= 34 + rand()%80;
   ptr->memory = 223 + rand()%45;
   ptr->internal_storage = 145 + rand()%200;
   ptr->camera_resolution = 230 + rand()%450;
   ptr->price = 460 + rand()%500;
}

mobile_t* findmodelbymaxbc(const mobile_t *parr,int n, double maxbc) {
  const mobile_t *ptr = parr;
  for(int i=0;i<n;i++) {
    if(ptr->battery_capacity==maxbc) {
       return ptr;
    }
    ptr++;
  }
  return NULL;
}
mobile_t* findmobilebymaxcr(const mobile_t *parr,int n,
                                        double maxcr) {
  const mobile_t *ptr = parr;
  for(int i=0;i<n;i++) {
    if((ptr->camera_resolution==maxcr)){
       return ptr;
    }
    ptr++;
  }
  return NULL;
}
double findAverageprice(const mobile_t *parr, int n) {
  double sum = 0;
  const mobile_t *ptr=parr;
  for(int i=0;i<n;i++) {
    sum += ptr->price;
    ptr++;
  }
  return sum/n;
}


#endif
