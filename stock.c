#include "stock.h"

store* stock[MAX_STOCK];
int income=0;
void laod_file(){
  int price,amount,num;
  char name[20],origin[20];
  FILE* myfile;
  myfile=fopen("stock.txt","r");
  fscanf(myfile,"%d",&income);
  #ifdef DEBUG
    printf("[Load]Income : %d is loading \n",income);
  #endif 
  while(!feof(myfile)){
    int n=fscanf(myfile,"%d %s %s %d %d",&num,name,origin,&price,&amount);
    if(n<5){
   #ifdef DEBUG
    printf("[error]Input is not enough. \n");
   #endif 
    break;
    }
  creat_s(num,name,origin,price,amount); 
   #ifdef DEBUG
    printf("[Load]creating %s\n",name);
   #endif 
  }
  fclose(myfile);
}
void creat_s(int nu,char*na,char*o,int pr,int a){
  int i=nu-1;
  if(i<=MAX_STOCK){
  stock[i]=(store*)malloc(sizeof(store));
  stock[i]->num=nu;
  strcpy(stock[i]->name,na);
  strcpy(stock[i]->origin,o);
  stock[i]->price=pr;
  stock[i]->amount=a;
   #ifdef DEBUG
    printf("[Load]creating %s\n",na);
   #endif 
  }
  else{
    printf("공간이 부족합니다");
   #ifdef DEBUG
    printf("count=%d\n",count_s());
   #endif 
  }
}
int count_s(){
  int i=0;
  while(stock[i]){
  #ifdef DEBUG
    printf("[Load] %s is counting \n",stock[i]->name);
   #endif 
    i++;
  }
  return i;
}
void put_all_s(int n){
  int i;
  printf("No.\t제품명\t원산지\t가격\t수량\n");
    for(i=0; i<n; i++){
      printf("%d\t%s\t%s\t%d\t%d\n",stock[i]->num,stock[i]->name,stock[i]->origin,stock[i]->price,stock[i]->amount);
    }
  printf("Income : %d \n",income);
}
void m_update(store* p, char* na, char*o,int pr, int a){
}
void print_s(store* p){
}
store* find_n(char *n){
  for(int i=0;i<count_s();i++){
    if(strcmp(stock[i]->name,n)==0){
  #ifdef DEBUG
    printf("[Load] same name %s is finding\n",stock[i]->name);
   #endif 
      return stock[i];
    }
  }
  #ifdef DEBUG
    printf("[Load] find same name nothing\n ");
   #endif 
  return 0;
}
void plus_a(int a){

}
int remove_a(int a){

}
int delete_s(int n){

}
void search_n(char* s,int n){
  int i,count=0;
  printf("No.\t제품명\t원산지\t가격\t수량\n");
  for(i=0;i<n;i++){
    if(strstr(stock[i]->name,s)){
      printf("%d\t%s\t%s\t%d\t%d\n",stock[i]->num,stock[i]->name,stock[i]->origin,stock[i]->price,stock[i]->amount);
      count++;
    }
  }
  printf("%d개 검색됨\n",count);
}
void save_file(){
  FILE*myfile;
  myfile=fopen("stock.txt","w");
  fprintf(myfile,"%d\n",income);
  #ifdef DEBUG
    printf("[Load]Income : %d is saving \n",income);
   #endif 
   for(int i=0;i<count_s();i++){
  fprintf(myfile,"%d %s %s %d %d\n",stock[i]->num,stock[i]->name,stock[i]->origin,stock[i]->price,stock[i]->amount);
  #ifdef DEBUG
    printf("[Load] %s is saving \n",stock[i]->name);
   #endif 
 }
  fclose(myfile);  
}
