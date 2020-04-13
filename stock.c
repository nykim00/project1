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
    printf("공간이 부족합니다\n");
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
void update_s(store* p, char*o,int pr, int a){
    strcpy(p->origin, o);
    p->price = pr;
    p->amount = a;
#ifdef DEBUG
    printf("updated %s\n", p->name);
#endif // DEBUG
}
void print_s(store* p){
	printf("재고번호: %d / 제품명: %s / 원산지: %s / 가격: %d / 수량: %d \n", p->num, p->name, p->origin, p->price, p->amount);
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
void plus_i(store *p,int a){
    if (p->amount > a) {
        p->amount -= a;
        income += p->price * a;
        printf("Income : %d\n", income);
    }
    else {
        printf("재고 수량이 부족합니다.\n");
    }
}
void remove_i(store *p,int a){
    if (p->price * a < income) {
        p->amount += a;
        income -= p->price * a;
        printf("Income : %d\n", income);
    }
    else {
        printf("돈이 부족합니다.\n");
    }
}
void delete_s(int n){
     int i=count_s()-1;
     n--;
     store*p;
      while (1) {
        if (i==n) {
        p=stock[n];
	free(p);
	stock[n]=NULL;
	break;
        }
	else{
        strcpy(stock[n]->name,stock[n+1]->name);
        strcpy(stock[n]->origin,stock[n+1]->origin);
        stock[n]->price = stock[n+1]->price;
        stock[n]->amount = stock[n+1]->amount;
	}
#ifdef DEBUG
        printf("%s change to %s\n", stock[n]->name, stock[n+1]->name);
#endif 
        n++;
    }
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
