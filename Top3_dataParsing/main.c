/*
 * main.c
 *
 *  Created on: 2022. 3. 29.
 *      Author: heesun
 */

#include <stdio.h>
#include <string.h>

struct log{
	char time[50];
	char msg[1000];
	int cnt;
};

struct log logs[2000];

int main()
{
    FILE *fp = fopen("log.txt", "r");
    char buf[1000];

    int idx=-1;

    while(1){

        //한줄 읽기
    	fgets(buf,1000,fp);

    	if(feof(fp) != 0){
    		break;
    	}

    	//한줄 출력하기
    	//printf("%s",buf);

    	//0~16 : 시간
    	char time[50];
    	strncpy(time,buf,15);
    	time[15]='\0';

    	//printf("%s ",time);

    	char msg[1000];
    	strcpy(msg,buf+16);

    	//printf("%s\n",msg);

    	if (strcmp(logs[idx].time,time)==0){
    		logs[idx].cnt++;
    	}
    	else{
			idx++;
    		strcpy(logs[idx].time,time);
    		strcpy(logs[idx].msg,msg);
			logs[idx].cnt ++;
    	}


    }
    //printf("%s %s %d",logs[i].time,logs[i].msg,logs[i].cnt);

    int idx1=0,idx2=0,idx3=0;

    for(int i=0;i<idx;i++){
    	if(logs[i].cnt > logs[idx1].cnt){
    		idx1=i;
    	}
    }
    for(int i=0;i<idx;i++){
    	if(i == idx1) continue;
    	if(logs[i].cnt > logs[idx2].cnt){
    		idx2=i;
    	}
    }
    for(int i=0;i<idx;i++){
    	if(i == idx1 || i == idx2) continue;
    	if(logs[i].cnt > logs[idx3].cnt){
    		idx3=i;
    	}
    }
    printf("%s %s %d\n",logs[idx1].time,logs[idx1].msg,logs[idx1].cnt);
    printf("%s %s %d\n",logs[idx2].time,logs[idx2].msg,logs[idx2].cnt);
    printf("%s %s %d\n",logs[idx3].time,logs[idx3].msg,logs[idx2].cnt);

    //printf("%s %s",logs[idx1].time,logs[idx1].msg);
    //printf("%s %s",logs[idx2].time,logs[idx2].msg);
    //printf("%s %s",logs[idx3].time,logs[idx3].msg);

	fclose(fp);
	return 0;
}
