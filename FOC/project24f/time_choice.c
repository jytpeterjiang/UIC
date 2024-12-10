/*用户可以预订上午9点到下午5点的时段，每个时段一小时。
a.如果用户选择今天，他/她可以选择当前时间的时隙之后的时隙。
例如，如果当前时间为11:05，则无法预订中午12:00之前的时段。
b.如果用户选择退出，系统退出。*/
#include <stdio.h>
#include <time.h>

int main() {
    // 获取当前时间
    time_t now = time(NULL);
    
    if (now == -1) {
        perror("time");
        return 1;
    }

    // 将时间转换为本地时间
    struct tm *local_time = localtime(&now);
    
    if (local_time == NULL) {
        perror("localtime");
        return 1;
    }

    // 打印本地时间
    printf("Current local time: %d-%02d-%02d %02d:%02d:%02d\n",
        local_time->tm_year + 1900, // 年份从1900开始计数
        local_time->tm_mon + 1,      // 月份从0开始计数
        local_time->tm_mday,        // 一个月中的第几天
        local_time->tm_hour,        // 小时
        local_time->tm_min,         // 分钟
        local_time->tm_sec);        // 秒数
    printf("Please choose a b c\n(if you want to book today please choose a\nif you want to book in future please choose b\nif you want to exit program please choose c): \n");
	char date;
	scanf("%c",&date);
	if(date=='c'){
		printf("Exiting program!\n");
		return 0;
	}
	if(date=='b'){
		int month,day,year;
		printf("Please input the future date you want to book(e.g:if you want to book on january 2,2025, please input 2025,1,2): \n");
		scanf("%d,%d,%d",&year,&month,&day);
		if(year>(local_time->tm_year + 1900)||(year==(local_time->tm_year + 1900)&&month>(local_time->tm_mon + 1))||(year==(local_time->tm_year + 1900)&&month==(local_time->tm_mon + 1)&&day>(local_time->tm_mday))){
		    printf("9~10\n10~11\n11~12\n12~13\n13~14\n14~15\n15~16\n16~17\n");
		}
		else{
			printf("Input error!\n");
		}
	}
	if (date == 'a') {
        int current_hour = local_time->tm_hour;
        if (current_hour >= 16) {
            printf("Sorry,there is no time available today!\n");
        } else {
            int start_hour = (current_hour < 9) ? 9 : current_hour+1;
            for (int i = start_hour; i+1 <=17; i++) {
                printf("%d~%d\n", i, i + 1);
            }
        }
    }
    return 0;
}
