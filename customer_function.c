#include"train.h"

TR_NODE *check_train_no(int train_no,TR_NODE *thead){
	while(thead){
		if(thead->train_no==train_no){
			return thead;
		}
		thead=thead->next;     
	}
	return NULL;
}

CR_NODE *reserve_ticket(TR_NODE *thead,CR_NODE *chead){

	CR_NODE *newnode=calloc(1,sizeof(CR_NODE));
	TR_NODE *tthead;

	if(newnode==NULL){
		puts(rcolor"Record Not Created"wcolor);
		return chead;
	}       

ip:    printf(gcolor"Enter Train No-> "wcolor);
       scanf("%d",&newnode->train_no);

       if((tthead=check_train_no(newnode->train_no,thead))==NULL){
	       puts(rcolor bscolor"Not Valid Train No"wcolor becolor);
	       goto ip;
       }

       unsigned int n;
       n=0;
ip2:      __fpurge(stdin);
	  printf(gcolor"Enter Train Date-> "wcolor);
	  scanf("%u",&n);
	  newnode->date=n;

	  n=0;
	  __fpurge(stdin);
	  printf(gcolor"Enter Train Month-> "wcolor);
	  scanf("%u",&n);
	  newnode->month=n;

	  n=0;
	  __fpurge(stdin);
	  printf(gcolor"Enter Train Year-> "wcolor);
	  scanf("%u",&n);
	  newnode->year=n;

	  if((tthead->seat_info[0].date==newnode->date)&&(tthead->seat_info[0].month==newnode->month)&&(tthead->seat_info[0].year==newnode->year)){
		  int i=0;
		  while((i<100)&&(tthead->seat_info[0].seat_status[i]>0)){
			  i++;		       
		  }
		  if(i<100){
			  tthead->seat_info[0].seat_status[i]=1;
			  tthead->seat_info[0].cur_book_seat+=1;
			  newnode->seat_no=i+1;
		  }
		  else{
			  tthead->seat_info[0].wait_list+=1;
			  newnode->seat_no=0;
			  puts(rcolor"Train Seat Are Not Available"wcolor);
			  free(newnode);
			  return chead;
		  }


	  }
	  else if((tthead->seat_info[1].date==newnode->date)&&(tthead->seat_info[1].month==newnode->month)&&(tthead->seat_info[1].year==newnode->year)){
		  int i=0;
		  while((i<100)&&(tthead->seat_info[1].seat_status[i]>0)){
			  i++;		       
		  }
		  if(i<100){
			  tthead->seat_info[1].seat_status[i]=1;
			  tthead->seat_info[1].cur_book_seat+=1;
			  newnode->seat_no=i+1;
		  }
		  else{
			  tthead->seat_info[1].wait_list+=1;
			  newnode->seat_no=0;
			  puts(rcolor"Train Seat Are Not Available"wcolor);
			  free(newnode);
			  return chead;
		  }

	  }
          else if((tthead->seat_info[2].date==newnode->date)&&(tthead->seat_info[2].month==newnode->month)&&(tthead->seat_info[2].year==newnode->year)){
		  int i=0;
		  while((i<100)&&(tthead->seat_info[2].seat_status[i]>0)){
			  i++;		       
		  }
		  if(i<100){
			  tthead->seat_info[2].seat_status[i]=1;
			  tthead->seat_info[2].cur_book_seat+=1;
			  newnode->seat_no=i+1;
		  }
		  else{
			  tthead->seat_info[2].wait_list+=1;
			  newnode->seat_no=0;
			  puts(rcolor"Train Seat Are Not Available"wcolor);
			  free(newnode);
			  return chead;
		  }

	  }
	  else{
		  puts(rcolor bscolor"This Date Train Not Avaliable"wcolor becolor);
		  goto ip2;
	  }



	  __fpurge(stdin);
	  printf(gcolor"Enter Passenger Name-> "wcolor);
	  fgets(newnode->name,20,stdin);
	  if(newnode->name[strlen(newnode->name)-1]=='\n'){
		  newnode->name[strlen(newnode->name)-1]='\0';
	  }

	  printf(gcolor"Enter Passenger Age-> "wcolor);
	  scanf("%hd",&newnode->age);

	  if(chead==NULL){
		  chead=newnode;
	  }
	  else{
		  CR_NODE *temp=chead;
		  while(temp->next){
			  temp=temp->next;
		  }
		  temp->next=newnode;  
	  }		

	  return chead;

}

void booking_detail(TR_NODE *thead,CR_NODE *chead){

	TR_NODE *var; 

	if(chead==NULL){
           puts(rcolor bscolor"Passenger Detail Not Found"wcolor becolor);
            return;
	}

           puts("\n--------------------------------------------------------------------------------------------------------");
		puts(rcolor"T.No\tTrain Name\tSource\tDestination\tDate\t\tName\t\tAge\tSeat No"wcolor);			      
             puts("--------------------------------------------------------------------------------------------------------");
	while(chead){
		var=check_train_no(chead->train_no,thead);
		if(var==NULL){
			return;
		}
printf(ccolor"%u\t%s\t%s\t%s\t%u/%u/%u\t%s\t%hd\t%u\n"wcolor,var->train_no,var->train_name,var->src_place,var->dest_place,chead->date,chead->month,chead->year,chead->name,chead->age,chead->seat_no);

		chead=chead->next;	 

	}
           puts("--------------------------------------------------------------------------------------------------------\n");

}

CR_NODE *cancel_ticket(TR_NODE *thead,CR_NODE *chead){

	unsigned int tr_no,date,month,year;
	char name[20];

	if(chead==NULL){
		puts(rcolor bscolor"Any Train Ticket Not Avaliable"wcolor becolor);
		return chead;

	}

	__fpurge(stdin);
	printf(gcolor"Enter Train No-> "wcolor);
	scanf("%d",&tr_no);

	__fpurge(stdin);
	printf(gcolor"Enter The Date-> "wcolor);
	scanf("%d",&date);

	__fpurge(stdin);
	printf(gcolor"Enter The month-> "wcolor);
	scanf("%d",&month);

	__fpurge(stdin);
	printf(gcolor"Enter The year-> "wcolor);
	scanf("%d",&year);

	__fpurge(stdin);
	printf(gcolor"Enter Passenger Name-> "wcolor);
	fgets(name,20,stdin);
	if(name[strlen(name)-1]=='\n'){
		name[strlen(name)-1]='\0';
	}


	TR_NODE *var=NULL;
	CR_NODE *cur_ptr=NULL,*prv_ptr=NULL,*temp=chead;

	while(temp){

		if((tr_no==temp->train_no)&&(strcmp(name,temp->name)==0)&&(temp->date==date)&&(temp->month==month)&&(temp->year==year)){

			var=check_train_no(chead->train_no,thead);
			if(var==NULL){
				return chead;
			}

			if(var->seat_info[0].date==date){
				var->seat_info[0].cur_book_seat-=1;
				var->seat_info[0].seat_status[temp->seat_no-1]=0;
				if(var->seat_info[0].wait_list>0){
				    var->seat_info[0].wait_list-=1;
				}
			}
			else if(var->seat_info[1].date==date){
				var->seat_info[1].cur_book_seat-=1;
				var->seat_info[1].seat_status[temp->seat_no-1]=0;
				if(var->seat_info[1].wait_list>0){
				    var->seat_info[1].wait_list-=1;
				}
			}
			else if(var->seat_info[2].date==date){
				var->seat_info[2].cur_book_seat-=1;
				var->seat_info[2].seat_status[temp->seat_no-1]=0;
				if(var->seat_info[2].wait_list>0){
				    var->seat_info[2].wait_list-=1;
				}
			}

			if(prv_ptr==NULL){
				chead=temp->next;		
			}
			else{
				prv_ptr->next=temp->next;
			}
			free(temp);
	                return chead;	
		}
		prv_ptr=temp;
		temp=temp->next;   

	}
        puts(rcolor bscolor"Passenger Detail Not Found"wcolor becolor);
	return chead;


}
