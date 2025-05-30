#include"train.h"
TR_NODE *edit_train_detail(TR_NODE *head){

	TR_NODE *newnode=NULL,*temp=NULL;
	newnode=calloc(1,sizeof(TR_NODE));

	if(newnode==NULL){
		puts(rcolor"Record Not Created"wcolor);
		return head;
	}

	__fpurge(stdin);
	printf(gcolor"Enter Train Name-> "wcolor);
	fgets(newnode->train_name,30,stdin);
	if(newnode->train_name[strlen(newnode->train_name)-1]=='\n'){
		newnode->train_name[strlen(newnode->train_name)-1]='\0';
	}

	__fpurge(stdin);
	printf(gcolor"Enter Train No-> "wcolor);
	scanf("%d",&newnode->train_no);

	__fpurge(stdin);
	printf(gcolor"Enter Source Place-> "wcolor);
	fgets(newnode->src_place,10,stdin);
	if(newnode->src_place[strlen(newnode->src_place)-1]=='\n'){
		newnode->src_place[strlen(newnode->src_place)-1]='\0';
	}

	__fpurge(stdin);
	printf(gcolor"Enter Destination Place-> "wcolor);
	fgets(newnode->dest_place,10,stdin);
	if(newnode->dest_place[strlen(newnode->dest_place)-1]=='\n'){
		newnode->dest_place[strlen(newnode->dest_place)-1]='\0';
	}

	unsigned int n;
         n=0;
	 puts(gcolor"\nTrain Day1 Detail\n"wcolor);
	__fpurge(stdin);
	printf(mcolor"Enter Date1-> "wcolor);
	scanf("%u",&n);
	newnode->seat_info[0].date=n;
	
         n=0;
	__fpurge(stdin);
	printf(mcolor"Enter Month1-> "wcolor);
	scanf("%u",&n);
	newnode->seat_info[0].month=n;

         n=0;
	__fpurge(stdin);
	printf(mcolor"Enter Year1-> "wcolor);
	scanf("%u",&n);
	newnode->seat_info[0].year=n;
	
	newnode->seat_info[0].total_seat=100;
	newnode->seat_info[0].wait_list=0;
	newnode->seat_info[0].cur_book_seat=0;

	for(int i=0;i<100;i++){
		newnode->seat_info[0].seat_status[i]=0;
	}

         n=0;
	 puts(gcolor"\nTrain Day2 Detail\n"wcolor);
	__fpurge(stdin);
	printf(mcolor"Enter Date2-> "wcolor);
	scanf("%u",&n);
	newnode->seat_info[1].date=n;
         
	n=0;
	__fpurge(stdin);
	printf(mcolor"Enter Month2-> "wcolor);
	scanf("%u",&n);
	newnode->seat_info[1].month=n;

         n=0;
	__fpurge(stdin);
	printf(mcolor"Enter Year2-> "wcolor);
	scanf("%u",&n);
	newnode->seat_info[1].year=n;
	
	newnode->seat_info[1].total_seat=100;
	newnode->seat_info[1].wait_list=0;
	newnode->seat_info[1].cur_book_seat=0;

	for(int i=0;i<100;i++){
		newnode->seat_info[1].seat_status[i]=0;
	}
        
       	n=0;
	 puts(gcolor"\nTrain Day3 Detail\n"wcolor);
	__fpurge(stdin);
	printf(mcolor"Enter Date3-> "wcolor);
	scanf("%u",&n);
	newnode->seat_info[2].date=n;
	
         n=0;
	__fpurge(stdin);
	printf(mcolor"Enter Month3-> "wcolor);
	scanf("%u",&n);
	newnode->seat_info[2].month=n;

         n=0;
	__fpurge(stdin);
	printf(mcolor"Enter Year3-> "wcolor);
	scanf("%u",&n);
	newnode->seat_info[2].year=n;
	
	newnode->seat_info[2].total_seat=100;
	newnode->seat_info[2].wait_list=0;
	newnode->seat_info[2].cur_book_seat=0;

	for(int i=0;i<100;i++){
		newnode->seat_info[2].seat_status[i]=0;
	}

	if(head==NULL){
		head=newnode;
	}
	else{
		temp=head;
		while(temp->next){
			temp=temp->next;
		}
		temp->next=newnode;  
	}		

	return head;
}
