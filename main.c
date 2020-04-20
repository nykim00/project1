#include "stock.h"

void Load();
void Add();
void List();
void Update();
void Import();
void Export();
void Search();
void Delete();
void Save();

int main(){
   int menu;
   while(1){
	printf("\n메뉴 : 1.불러오기 2.재고 물품 추가 3.재고 정보 추가 및 변경 4.재고 입고(구매) 5.재고 출고(판매) 6.재고 목록 7.재고 검색 8.재고 물품 삭제 9.저장 0.프로그램 종료 >>");
	scanf("%d",&menu);
	printf("\n");
	switch(menu){
	case 1: Load();break;
	case 2: Add();break;
	case 3: Update();break;
	case 4: Import();break;
	case 5: Export();break;
	case 6: List();break;
	case 7: Search();break;
	case 8: Delete();break;
	case 9: Save();break;
	default: return 0;
	}
   }
   return 0;
}

void Load(){
  laod_file();
   printf("데이터를 불러왔습니다.\n");
}
void Add(){
   int num,amount,price;
   char name[20],origin[20];
   num = count_s()+1;
   printf("재고 제품명? ");
   scanf("%s",name);
   if(find_n(name)==0){
   printf("재고 원산지? ");
   scanf("%s",origin);
   printf("재고 가격? ");
   scanf("%d",&price);
   printf("재고 수량? ");
   scanf("%d",&amount);
   creat_s(num,name,origin,price,amount);
   printf("재고 물품이 추가되었습니다.\n");
  }
  else printf("이름이 중복됩니다\n");
}
void List(){
  int n=count_s();
  put_all_s(n);
}
void Update(){
    store* p;
    int amount, price;
    char name[20], origin[20];
    printf("변경할 재고 제품명? ");
    scanf("%s", name);
    p=find_n(name); 
    if (p) {
        printf("변경된 재고 원산지? ");
        scanf("%s", origin);
        printf("변경된 재고 가격? ");
        scanf("%d", &price);
        printf("변경된 재고 수량? ");
        scanf("%d", &amount);
        update_s(p, origin, price, amount);
        printf("재고 정보가 변경되었습니다.\n");
        print_s(p);
    }
    else printf("제품을 찾지 못했습니다\n");
}
void Import(){
    int n;
    char na[20];
    store* p;
    printf("수입할 제품명은? ");
    scanf("%s",na);
    p = find_n(na);
    if (p) {
        print_s(p);
        printf("수입할 수량은? ");
        scanf("%d", &n);
        remove_i(p, n);
    }
    else printf("제품을 찾지 못했습니다.\n");
}
void Export(){
    int n;
    char na[20];
    store* p;
    printf("수출할 제품명은? ");
    scanf("%s",na);
    p = find_n(na);
    if (p) {
        print_s(p);
        printf("수출할 수량은? ");
        scanf("%d", &n);
        plus_i(p, n);
    }
    else printf("제품을 찾지 못했습니다.\n");
}
void Search(){
  int n;
  char name[20];
  n=count_s();
  printf("제품명에 대한 검색어를 입력하세요");
  scanf("%s",name);
  search_n(name,n);
}
void Delete(){
   char name[20],an;
    store* p;
    printf("삭제할 재고 제품명? ");
    scanf("%s", name);
    p = find_n(name);
    if (p) {
        print_s(p);
        printf("정말 삭제하시겠습니까?(Y/N)");
	getchar();
        scanf("%c", &an);
        if (an == 'Y') {
            delete_s(p->num);
            printf("삭제가 완료되었습니다.\n");
        }
    }
    else printf("제품을 찾지 못했습니다.\n");
}
void Save(){
  save_file();
  printf("데이터를 저장하였습니다\n");
}
