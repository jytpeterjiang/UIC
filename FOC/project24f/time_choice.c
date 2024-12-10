/*�û�����Ԥ������9�㵽����5���ʱ�Σ�ÿ��ʱ��һСʱ��
a.����û�ѡ����죬��/������ѡ��ǰʱ���ʱ϶֮���ʱ϶��
���磬�����ǰʱ��Ϊ11:05�����޷�Ԥ������12:00֮ǰ��ʱ�Ρ�
b.����û�ѡ���˳���ϵͳ�˳���*/
#include <stdio.h>
#include <time.h>

int main() {
    // ��ȡ��ǰʱ��
    time_t now = time(NULL);
    
    if (now == -1) {
        perror("time");
        return 1;
    }

    // ��ʱ��ת��Ϊ����ʱ��
    struct tm *local_time = localtime(&now);
    
    if (local_time == NULL) {
        perror("localtime");
        return 1;
    }

    // ��ӡ����ʱ��
    printf("Current local time: %d-%02d-%02d %02d:%02d:%02d\n",
        local_time->tm_year + 1900, // ��ݴ�1900��ʼ����
        local_time->tm_mon + 1,      // �·ݴ�0��ʼ����
        local_time->tm_mday,        // һ�����еĵڼ���
        local_time->tm_hour,        // Сʱ
        local_time->tm_min,         // ����
        local_time->tm_sec);        // ����
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
