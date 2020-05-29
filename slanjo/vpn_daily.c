#include <stdio.h>
#include <ctype.h>
#include <string.h>
int sessions, total_bytes_out, total_bytes_in, bytes_session, bytes_rcv, bytes_xmt;
char bytes_rcvtxt[12], bytes_xmttxt[12];
char info1[16], info2[65]; //%ASA-4-113019 and Session disconnected
char duration[12];
char bytes_rec[12];
char nighthawk, shootingstar, day_of_month, disconnect_time, year, asa_event_id, group, equality1, group_name, equality2, Username, ad_uname, IP, equality3, ip_addr, info3;
//if we want to capture CLI input
//int main(int argc, char *argv[]){
int main(){
	char line[350];
	char month[3];
	FILE *secVPN;
	if (!(secVPN = fopen("secVPNUsage", "r"))){
		fprintf(stderr,"File does not exist!\n");
		return 1;
	
	
	}
	
	while(fscanf(secVPN,"%s3,%s300[^\n]", month, line) == 1){
		printf(month);	
			
			
			}


	return 0;

}
