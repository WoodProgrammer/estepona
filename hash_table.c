
#include <stdio.h>
#include <stdlib.h>



int hash(char * str){
	int i = 0;
	int sum;
	sum = i;
	while(str[i] != NULL){
		sum = sum + (int)str[i] ;
		i = i + 1; 
	}
	return sum % 10;
}

struct node {
	char * str;
	int val;
	struct node * next;
};

typedef struct node*  node  ;

struct table {

	node* arr[1024]; 
};
typedef struct table*  table  ;



char * table_search(char * searched_file,struct table * t,struct node * z)
{

	int search_key = hash(searched_file);
	z = t->arr[search_key];
	return z->str;	
};



struct node * a ;
struct table * t;
struct node * tmp;


void put(char * key,char * value);
void get(char * key){
		int hashed_key = hash(key);
		if(t->arr[hashed_key] == NULL){

			printf("NO DATA FOUND ! \n");
		}
		else{
			tmp = t->arr[hashed_key];
			printf("%s\n",tmp->str);
		}

	}	



int main(){	


	int key = hash("index.html");
	int key2 = hash("game.html");
	a = (node * )malloc(sizeof(node));
	t = (table * )malloc(sizeof(table));
	tmp = (table * )malloc(sizeof(node));
	a->val  =1;
	a->str= "Hebeleci Hubeleleleleleler.";
	a->next = t->arr[key];
	t->arr[key] = a;
	tmp = t->arr[key];




	a->next = (node * )malloc(sizeof(node));
	a->next->val  =1;
	a->next->str= "Hebeleci Hubeleleleleleler2.";
	a->next->next = t->arr[key2];
	t->arr[key2] = a->next;
	tmp = t->arr[key2];
	get("game.html");



}
