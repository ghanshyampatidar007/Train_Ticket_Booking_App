#include"train.h"

void menu2(){
      puts("\n-----------------------------");
	puts(rcolor" TRAIN SYSTEM FACILITIES"wcolor);
	puts("-----------------------------");
	puts(ycolor"R/r: To Reserve Ticket");
	puts("C/c: To Cancel Ticket");
	puts("B/b: Booking Detail");
	puts("Q/q: Quit"wcolor);
	puts("-----------------------------\n");
}

void train_menu(TR_NODE *thead){

	while(thead){
		fflush(stdout);
	      puts("\n-------------------------------------------------------------------");
		puts(rcolor"T.No\tTrain Name\tSource\tDestination"wcolor);  
         	printf(ccolor"%u\t%s\t%s\t%s\n"wcolor,thead->train_no,thead->train_name,thead->src_place,thead->dest_place);
	        puts("-------------------------------------------------------------------");
	          puts(rcolor"Date\t\tTotal Seat\tWaiting List\tCurrent Book"wcolor);
                printf(ccolor"%u/%u/%u\t  %u\t\t  %u\t\t %u\n",thead->seat_info[0].date,thead->seat_info[0].month,thead->seat_info[0].year,thead->seat_info[0].total_seat,thead->seat_info[0].wait_list,thead->seat_info[0].cur_book_seat); 

		printf("%u/%u/%u\t  %u\t\t  %u\t\t %u\n",thead->seat_info[1].date,thead->seat_info[1].month,thead->seat_info[1].year,thead->seat_info[1].total_seat,thead->seat_info[1].wait_list,thead->seat_info[1].cur_book_seat); 
		
		printf("%u/%u/%u\t  %u\t\t  %u\t\t %u\n"wcolor,thead->seat_info[2].date,thead->seat_info[2].month,thead->seat_info[2].year,thead->seat_info[2].total_seat,thead->seat_info[2].wait_list,thead->seat_info[2].cur_book_seat); 
	       
	      puts("\n-------------------------------------------------------------------\n");
		thead=thead->next;	

	}
}

void sign_in(TD_NODE *head){

	TD_NODE *temp;
	int enter_username_cnt=1;            

ip1:	      printf(gcolor"Enter Username- "wcolor);
	      char *us=getstring();

	      printf(gcolor"Enter Password- "wcolor);
	      char *ps=getstring();

	      if(enter_username_cnt==3){
		      puts(rcolor bscolor"You Are Reached Maximum Limit Of Entering Username"wcolor becolor);
		      return;
	      }

	      enter_username_cnt++;

	      if(check_id_password(head,us,ps)!=2){
		      puts(rcolor bscolor"Incorrect Username Password"wcolor becolor);
		      goto ip1;	      
	      }      

	      TR_NODE *thead=sync_tdetail();

	      if((strcmp(us,"officer")==0)&&(strcmp(ps,"12##asAS")==0)){
		//system("clear");
		      train_menu(thead);
		      thead=edit_train_detail(thead);
		      save_tdetail(thead);
		      return;	                
	      }
	      
	      char choice;
	      
	      CR_NODE *chead=sync_cdetail(us,head);

	      while(1){
		system("clear");
		      train_menu(thead);
		      menu2();

		      __fpurge(stdin);
		      puts(gcolor"Enter The Choice- "wcolor);
		      scanf("%c",&choice);

		      switch(choice){
			      case 'R':
			      case 'r':chead=reserve_ticket(thead,chead);
				      break;
			      case 'C':
			      case 'c':chead=cancel_ticket(thead,chead);
				      break;
			      case 'B':
			      case 'b':booking_detail(thead,chead);
				      break;
			      default:
				      save_tdetail(thead);
				      save_cdetail(us,head,chead);
				      puts(mcolor"THANK YOU"wcolor);
				      return;

		      }
		      __fpurge(stdin);
		      scanf("%c",&choice);

	      }

	      return;

}

