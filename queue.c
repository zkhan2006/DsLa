#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front, *rear;
};


void create_queue(struct queue *q) {
    q->front = q->rear = NULL;
}


void insert(struct queue *q, int val) {
    struct node *ptr =(struct node*)malloc(sizeof(struct node));
    
    ptr->data = val;
    ptr->next = NULL;
    
   

    if (q->rear == NULL) {
     
        q->front = q->rear = ptr;
    } else {
        q->rear->next = ptr;
        q->rear =ptr;
    }
    printf("%d Inserted\n", val);
}


void delete_elements(struct queue *q) {
    if (q->front == NULL) {
        printf("\nunderflow\n");
        return ;
    }
    struct node *temp = q->front;
    printf("\nDeleted: %d",temp->data);
  

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL; 
    }
    free(temp);
   
}

int peek(struct queue *q)
{
	return(q->front)? q->front->data:-1;
	
}

void display(struct queue *q) 
{
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = q->front;
    printf("\nQueue: ");
    while (temp)
	{
        printf("%d  ", temp->data);
        temp = temp->next;
    }
   
}


int main() {
    struct queue q;
    int val,option;
     
    create_queue(&q);
    
    do{
    	printf("\n\n1. insert\n2. delete\n3. Peek\n4. display\n5.Exit");
    	printf("Enter your choice:");
    	scanf("%d",&option);
    	
    	switch(option)
    	{
    		case 1:
    			printf("Enter value: ");
    			scanf("%d",&val);
    			insert(&q,val);
    			break;
    		case 2:
				delete_elements(&q);
				break;
			case 3:
				val=peek(&q);
				if(val!=-1) printf("\nFront:%d",val);
				else printf("\nQueue Is Empty");
				break;
			case 4:
				display(&q);
				break;
			
		}
	}while(option !=5);

   
    return 0;
}

