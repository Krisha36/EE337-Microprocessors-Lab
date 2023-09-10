#include <at89c5131.h>
#include <lcd.h>
sbit event = P3^4;
sbit SW = P1^0;


int count;
long int total_cycles;
long int sec;
long int min;
char time[5];
char count_alp[1];
void timer1_isr () interrupt 1
{
	count+=1;
	
}


void main(void){
	lcd_init();
	TMOD = 0x05;
	SW = 1;
	event = 1;
	count = 0;
	EA = 1;
	ET0 = 1;
	TH0 = 0xf0;
	TL0 = 0x10;
	while(1){
		TR0 = SW;
		if(!TR0)
			continue;
		else{
			total_cycles = 65536*count + 256*TH0 + TL0;
			sec = total_cycles/60;
			min = sec/60;
			sec = sec - min*60;
			lcd_cmd(0x80);
			time[0] = min/10 + 48;
			time[1] = min%10 + 48;
			time[2] = ':';
			time[3] = sec/10 + 48;
			time[4] = sec%10 + 48;
			lcd_write_string(time);
			lcd_cmd(0xc0);
			count_alp[0] = count + 48;
			lcd_write_string(count_alp);
		}
	}
}