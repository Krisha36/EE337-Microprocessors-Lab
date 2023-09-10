#include <at89c5131.h>
#include "lcd.h"
code unsigned char msg1[] ="Enter Password:";
code unsigned char msg2[] ="15A8*D6#";
code unsigned char msg3[] ="Acess Denied";
code unsigned char msg4[] ="Acess Granted";
unsigned char pass[8];
unsigned char keypress;
unsigned int a;
unsigned int b;
unsigned int j;
unsigned int m;
unsigned int row;
unsigned int col;
int anyuneq;
int i;	
unsigned char keypad[4][4] = {'1','2','3','A','4','5','6',
																'B','7','8','9','C',
																'*','0','#','D'};
void main()
{
	P3 = 0x0F;//moving 0 in all rows
	lcd_init();
	lcd_cmd(0x80);
	lcd_write_string(msg1);
	for(m = 0; m < 8; m++)
	{
		P3 = 0x0f;
		while(1)
		{	
			//check if all columns are zero 1 st time
			a = P3&0x0f;
			if(a != 0x0f)
			{
				continue;//return if p3 is not 00001111
			}
			a = P3&0x0f;
			while(a == 0x0f)
			{
				a = P3&0x0f;//continue;//return if p3 is not 00001111
			}
			msdelay(20);
			a = P3&0x0f;//read all columns, if any key down then a not 15
			if(a == 0x0f)
			{
				continue;//if no key down go back to top
			}
			b = P3|0xf0;
			j = 1;
			for(i = 0;i < 4;i++)
			{
				P3 = b - 8*(2*(j));//put p3 as 1110xxxx
				P3 = P3|0x0f;
				a = P3&0x0f;
				j= j*2;
				if(a != 0x0f)
				{
					row = i;
					break;
				}
			}
			j = 1;
			for(i = 0;i< 4;i++)
			{
				if(a == 15 - j){
				col = 3-i;
				break;}
				j = j*2;
			}
			keypress = keypad[row][col];
			pass[m] = keypress;
			lcd_cmd(0xc0);
			msdelay(4);
			lcd_write_string(pass);//write character entered
			break;
		}
	}
	anyuneq = 0;
	for(m = 0; m<8; m++)
	{
		if(pass[m] != msg2[m])
		{
			lcd_cmd(0x01);
			lcd_cmd(0x80);
			msdelay(4);
			lcd_write_string("Wrong Password");
			lcd_cmd(0xc0);
			msdelay(4);
			lcd_write_string(msg3);
			anyuneq = 1;
			break;
		}
	}
	if(anyuneq == 0)
	{
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		msdelay(4);
		lcd_write_string("Correct Password");
		lcd_cmd(0xc0);
		msdelay(4);
		lcd_write_string(msg4);
		while(1){}
	}
	while(1);
}