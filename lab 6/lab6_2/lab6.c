#include <at89c5131.h>
#include "lcd.h"

code unsigned char display_msg1[]="   START PROGRAM     ";	
code unsigned char display_msg2[]="   FIRST INPUT     ";
code unsigned char display_msg3[]="   NEXT INPUT     ";
code unsigned char display_msg4[]="   SORTING...     ";
code unsigned char display_msg5[]="   SORTING     ";
code unsigned char display_msg6[]="   COMPLETED     ";
code unsigned char display_msg7[]="  NUMBER TO BE     ";
code unsigned char display_msg8[]="   SEARCHED     ";
code unsigned char display_msg9[]="   THE INDEX IS     ";
code unsigned char display_msg10[]="   NUMBER     ";
code unsigned char display_msg11[]=" 	 NOT FOUND     ";
unsigned int swap;
unsigned int n;
unsigned int count;
unsigned int d[5];
unsigned int a[5];
unsigned char c;
unsigned int e;
unsigned int f;
unsigned int g;


void main()
{
	
	P1 = 0x00;
	lcd_init();
	lcd_cmd(0x80);	//Move cursor to first lin
	msdelay(4);
	lcd_write_string(display_msg1);
	msdelay(5000);
	n = 0;
	d[0] = 0x00;
	lcd_cmd(0x01); //clear screen
	lcd_cmd(0x80);
	msdelay(4);
	lcd_write_string(display_msg2);
	c = 15;
	while(n<5)
	{
		P1 = 0x0F; //initialise to take inputs
		if(n>0)
		{
			P1 = d[n-1];
			lcd_cmd(0x01);
			msdelay(4);
			lcd_cmd(0x80);
			msdelay(4);
			lcd_write_string(display_msg3);
		}
		P1 = P1 | 0x0F;
		msdelay(5000);
		lcd_cmd(0x01);
		msdelay(4);
		lcd_cmd(0x80);
		msdelay(4);
		P1 = P1 & c; //initialise to take inputs
		a[n] = P1;
		d[n] = a[n]<<4; //shift by 4
		msdelay(1000);
		n++;
	}
	n = 0;
	count = 1; 
	P1 = d[4];
	lcd_write_string(display_msg4);
	while( count != 0){
		count = 0;
		for (n=0;n<4;n++){
			if(a[n] >  a[n+1]){
				swap = a[n];
				a[n] = a[n+1];
				a[n+1] = swap;
				count++;
			}
		}
	}	
	msdelay(5000);
	P1 = 0x00;
	lcd_cmd(0x01);
	msdelay(4);
	lcd_write_string(display_msg5);
	lcd_cmd(0xC0);
	msdelay(4);
	lcd_write_string(display_msg6);
	n = 0;
	msdelay(1000);
	while(n<5)
	{
		P1 = a[n]<<4;
		msdelay(5000);
		P1 = 0x00;
		msdelay(1000);
		n++;
	}
	P1 = 0x00;
	msdelay(1000);
	P1 = 0xFF;
	lcd_cmd(0x01);
	msdelay(4);
	lcd_write_string(display_msg7);
	lcd_cmd(0xC0);
	msdelay(4);
	lcd_write_string(display_msg8);
	msdelay(5000);
	e = P1 & 0x0F;
	lcd_cmd(0x01);
	msdelay(4);
	P1 = 0x00;
	msdelay(1000);
	n = 0;
	while(n<5)
	{
		if(e == a[n])
		{
			f = 1;
			g = n+1;
			break;
		}
		else
		{
			f =0;
		}
		n++;
	}
	if(f == 1)
	{
		lcd_cmd(0x01);
		msdelay(4);
		lcd_write_string(display_msg9);
		P1 = (g)<<4;
		while(1);
	}
	else
	{
		lcd_cmd(0x01);
		msdelay(4);
		lcd_write_string(display_msg10);
		lcd_cmd(0xC0);
		msdelay(4);
		lcd_write_string(display_msg11);
		while(1);
	}
}
//1,9,8,12,14