#include <stdio.h>
#include <stdlib.h>
#include "htmlpr.h"


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
int main(){

	

	struct node * a ;
	struct table * t;
	struct node * z;


	int key  = hash("index.html");

	a = (node * )malloc(sizeof(node));
	t = (table * )malloc(sizeof(table));
	a->val  =1;
	a->str= read_html_doc("index.html");
	a->next = t->arr[key];
	t->arr[key] = a;

	printf("%s",table_search("index.html",t,z));



}
