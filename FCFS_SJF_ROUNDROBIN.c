#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct process {
	int PID;
	int cpu_burst;
	int waiting_time;
}Process;

void print_time(Process *algo, int n){
	
	int i=0;
	float avwt=0;
	 printf("\nProcess\t\tBurst Time\tWaiting Time");
 
   for(i=0;i<n;i++)
    {
        avwt += algo[i].waiting_time;
     
        printf("\nP[%d]\t\t%d\t\t%d\t\t",algo[i].PID,algo[i].cpu_burst,algo[i].waiting_time);
    }
 avwt=avwt/n;
    
    printf("\n\nAverage Waiting Time:%f\n",avwt);
	
}


void fcfs(Process *fcfs, int n){
	
	int i,j;
    
    fcfs[0].waiting_time=0;    //waiting time for first process is 0
 
    //calculating waiting time
    for(i=1;i<n;i++)
    {
        fcfs[i].waiting_time=0;
        for(j=0;j<i;j++)
            fcfs[i].waiting_time += fcfs[j].cpu_burst;
    }
    
    print_time(fcfs,4);
    
}


void sjf(Process *bt, int n){
	
Process sjf[4];

   
    sjf[0].waiting_time=0;    //waiting time for first process is 0
 
	int i,j,total=0,pos,temp,temp2;
    float avg_wt,avg_tat;
    
    for(i=0;i<n;i++)
    {
 sjf[i].cpu_burst=bt[i].cpu_burst;
 sjf[i].PID=bt[i].PID;
    }
 
    //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        
        for(j=i+1;j<n;j++)
        {
            if(sjf[j].cpu_burst<sjf[pos].cpu_burst)
                pos=j;
        }
 
        temp=sjf[i].cpu_burst;
        sjf[i].cpu_burst=sjf[pos].cpu_burst;
        sjf[pos].cpu_burst=temp;
 
        temp2=sjf[i].PID;
        sjf[i].PID=sjf[pos].PID;
        sjf[pos].PID=temp2;
    }
 
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        sjf[i].waiting_time=0;
        for(j=0;j<i;j++)
            sjf[i].waiting_time+=sjf[j].cpu_burst;
 
    }
 
 print_time(sjf,4);
  
}


void rr(Process *rr, int n){
	
 int i,j;
 float avwt=0;
  int time,remain,flag=0,time_quantum; 
  int at[10]={0};						
  int rt[10];							
   
 
  remain=n; 
  for(i=0; i<n; i++) 
  { 
    rt[i] = rr[i].cpu_burst; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
  printf("\nProcess\t\tBurst Time\tWaiting Time"); 
  for(time=0, i=0;remain!=0;) 
  { 
    if(rt[i]<=time_quantum && rt[i]>0) 
    { 
      time+=rt[i]; 
      rt[i]=0; 
      flag=1; 
    } 
    else if(rt[i]>0) 
    { 
      rt[i]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[i]==0 && flag==1) 
    { 
      remain--; 
      printf("\nP[%d]\t\t%d\t\t%d\t\t",rr[i].PID,rr[i].cpu_burst, time-rr[i].cpu_burst); 
      avwt+=time-at[i]-rr[i].cpu_burst; 

      flag=0; 
    } 
    if(i==n-1) 
      i=0; 
    else if(at[i+1]<=time) 
      i++; 
    else 
      i=0; 
  } 
  
  avwt/=n;
  
   printf("\n\nAverage Waiting Time= %f\n",avwt); 
  
}



int main() {
	STARTUPINFO si; //new process의 특성
	PROCESS_INFORMATION pi; // new process/thread에 대한 핸들/식별자

	/*allocate memory*/
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	/*create child process*/

	clock_t start1 = clock();
	CreateProcess(NULL, "C:\\os_process\\process_1.exe", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi); //process1 = fibonacci sequence
	WaitForSingleObject(pi.hProcess, INFINITE);
	clock_t end1 = clock();
	double p1_burst_time = (end1 - start1);
	printf("\nP1 burst time : %f\n", p1_burst_time);
	printf("------------------------------------------------\n");

	clock_t start2 = clock();
	CreateProcess(NULL, "C:\\os_process\\process_2.exe", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi); //process2 = multiplication
	WaitForSingleObject(pi.hProcess, INFINITE);
	clock_t end2 = clock(); // 끝난 시간;
	double p2_burst_time = (end2 - start2);
	printf("\nP2 burst time : %f\n", p2_burst_time);
	printf("------------------------------------------------\n");

	clock_t start3 = clock();
	CreateProcess(NULL, "C:\\os_process\\process_3.exe", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi); //process3 = hanoi top
	WaitForSingleObject(pi.hProcess, INFINITE);
	clock_t end3 = clock(); // 끝난 시간;
	double p3_burst_time = (end3 - start3);
	printf("\nP3 burst time : %f\n", p3_burst_time);
	printf("------------------------------------------------\n");

	clock_t start4 = clock();
	CreateProcess(NULL, "C:\\os_process\\process_4.exe", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi); //process4 = factiorial 30
	WaitForSingleObject(pi.hProcess, INFINITE);
	clock_t end4 = clock(); // 끝난 시간;
	double p4_burst_time = (end4 - start4);
	printf("\nP4 burst time : %f\n", p4_burst_time);
	printf("------------------------------------------------\n");


	CloseHandle(pi.hProcess); // new process에 대한 핸들 닫기
	CloseHandle(pi.hThread); // new threead에 대한 핸들 닫기

	Process ps[4];
	
printf("\n*****************SCHEDULING*********************\n\n");
	ps[0].PID = 1;
	ps[0].cpu_burst = p1_burst_time;
	ps[1].PID = 2;
	ps[1].cpu_burst = p2_burst_time;
	ps[2].PID = 3;
	ps[2].cpu_burst = p3_burst_time;
	ps[3].PID = 4;
	ps[3].cpu_burst = p4_burst_time;

	printf("--------------------FCFS------------------------\n");
	fcfs(ps,4);
	printf("\n-----------------------SJF----------------------\n");	
	sjf(ps,4);
	printf("\n-----------------------RR-----------------------\n");
	rr(ps,4);


	return 0;
}
