#include <stdio.h>
struct times{
	int minutes;
	int hours;
	int seconds;
};
int main(){
	struct times time1,time2,result;
	printf("Enter the 1st time hour minutes and seconds:");
	scanf("%d %d %d",&time1.hours,&time1.minutes,&time1.seconds);
	printf("Enter time 2 hours minutes and seconds:");
	scanf("%d %d %d",&time2.hours,&time2.minutes,&time2.seconds);
	result.seconds=time1.seconds+time2.seconds;
	result.minutes=time1.minutes+time2.minutes+result.seconds/60;
	result.hours=time1.hours+time2.hours+result.minutes/60;
	result.minutes%=60;
	result.seconds%=60;
	 printf("\nResultant Time: %02d:%02d:%02d\n", result.hours, result.minutes, result.seconds);

    return 0;

}
