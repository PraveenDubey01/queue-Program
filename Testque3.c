#include "queue3.c"

void main()
{
	queue q;
	item_type item;
	int choice;
	
	init(&q);
	
	while(1)
	{
		puts("1. INSERT");
		puts("2. DELETE");
		puts("3. PEEK");
		puts("4. SIZE");
		puts("5. DISPLAY");
		puts("6. EXIT");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter item: ");
				scanf("%d",&item);
				insert(&q,item);
				break;
			case 2:
				item = delete(&q);
				if(item!=0)
					printf("%d deleted from a queue\n",item);
				break;
			case 3:
				item = peek(&q);
				if(item!=0)
					printf("%d found at front of the queue\n",item);
				break;				
			case 4:
				printf("%d item found in the queue\n",size(&q));
				break;
			case 5:
				display(&q);
				break;
			case 6:
				exit(1);
			default:
				puts("Invalid Que Operations");
		}
		
	}
}





