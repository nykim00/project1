#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK 50

typedef struct STOCK {
	int num;//재고번호
	char name[20];//제품이름
	char origin[20];//원산지
	int price;//가격
	int amount;//수량
}store;

void laod_file();
void creat_s(int nu,char*na,char*o,int pr,int a);
int count_s();
void put_all_s(int n);
void m_update(store* p, char* na, char*o,int pr, int a);
void print_s(store* p);
store* find_n(char*n);
void plus_a(int a);
int remove_a(int a);
int delete_s(int n);
void search_n(char* s,int n);
void save_file();
