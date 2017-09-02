#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct n{
	
	n * next;
	int freq;
	char * page_name ;

};

typedef n node;




void show_all_nodes(node * iterator,int count){

	for(int i =0;i<=count;i++){
		
		printf("Data :  %s\n",iterator->page_name);
		printf("Pointer %p\n",iterator );
		iterator=iterator->next;	
	}

}



int main(){
	node * root ; 
	node * head ; 

	root = (node * )malloc(sizeof(node));

	root->freq=100;
	root->page_name = "index.html";
	root->next = (node * )malloc(sizeof(node));
	root->next->freq=101;
	root->next->page_name = "login.html";

	root->next->next = (node * )malloc(sizeof(node));
	root->next->next->freq=102;
	root->next->next->page_name="about.html";

	node * tmp;
	tmp =(node * )malloc(sizeof(node));
	tmp->next = root->next->next;
	root->next->next = tmp;
	tmp->freq = 1010;
	show_all_nodes(root,4);

	/*
	head=root;
	*/



	return 0;


}