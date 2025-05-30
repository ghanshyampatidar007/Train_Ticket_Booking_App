a.out:main.o sign_up.o sign_in.o sync_detail.o save_detail.o getstring.o check_password.o check_id_password.o sync_tdetail.o save_tdetail.o edit_train_detail.o sync_cdetail.o save_cdetail.o customer_function.c
	cc main.o sign_up.o sign_in.o sync_detail.o save_detail.o getstring.o check_password.o check_id_password.o sync_tdetail.o save_tdetail.o edit_train_detail.o sync_cdetail.o save_cdetail.o customer_function.c
main.o:main.c
	cc -c main.c
getstring.o:getstring.c
	cc -c getstring.c
sign_up.o:sign_up.c
	cc -c sign_up.c
sign_in.o:sign_in.c
	cc -c sign_in.c
sync_detail.o:sync_detail.c
	cc -c sync_detail.c
sync_tdetail.o:sync_tdetail.c
	cc -c sync_tdetail.c
sync_cdetail.o:sync_cdetail.c
	cc -c sync_cdetail.c
save_detail.o:save_detail.c
	cc -c save_detail.c
save_tdetail.o:save_tdetail.c
	cc -c save_tdetail.c
save_cdetail.o:save_cdetail.c
	cc -c save_cdetail.c
check_password.o:check_password.c
	cc -c check_password.c
check_id_password.o:check_id_password.c
	cc -c check_id_password.c
edit_train_detail.o:edit_train_detail.c
	cc -c edit_train_detail.c
customer_function.o:customer_function.c
	cc -c customer_function.c
