//ASSUME THAT VREF/2 IS CONNECTED TO 1.28V TO PROVIDE 10mV STEP SIZE
//ASSUME THAT Vin+ IS CONNECTED TO LM35 OUTPUT
#include<reg51.h>
unsigned int d,d1,d2,d3,t,j;
float a;
int ar[50]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};   //for cathode 7 seg
void delay(int n);
int adc();
sbit rd=P3^5;
sbit wr=P3^6;
sbit intr=P3^7;
sbit led1=P2^0;		//ones
sbit led2=P2^1;		//tens
sbit led3=P2^2;		//hundreds
void main()
{
	while(1){
		a=adc();
		d=(a*1.8)+32;	//celsius to fahrenheit conversion
		d1=d/100;
		t=d%100;
		d2=t/10;
		d3=t%10;
		for(j=0;j<=10;j++)
		{
			led1=1;
			P0=ar[d1];
			delay(100);
			led2=1;
			P0=ar[d2];
			delay(100);
			led3=1;
			P0=ar[d3];
			delay(100);
		}
		P2=0x00;
	}
}
int adc()
{
	P1=0xff; //P1 is connected to ADC
	rd=1;
	wr=0;	//L-H PULSE
	wr=1;
	while(intr==1);
	rd=0;	//H-L PULSE
	return P1;
}
void delay(int n)
{
	for(j=0;j<=n;j++);
}
	
	