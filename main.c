#include "stm32f2xx.h"


int Pres=7;//presescalizador
int Arr=40000; // periodo equivalente 20 ms 
int ci=1400; // ciclo util inicial 
int in=0;
float grados [180]={2.847,2.885,2.935,2.978,3.0215,3.066,3.109,3.1515,3.1965,3.2395,3.284,3.3275,3.3715,3.4175,3.46,3.503,3.5475,3.5905,3.6345,3.678,3.722,3.766,3.8095,3.854,3.8975,3.941,3.9845,4.029,4.072,4.1165,4.16,4.204,4.2475,4.291,4.335,4.3785,4.4225,4.466,4.5105,4.554,4.598,4.6415,4.6855,4.7295,4.773,4.8165,4.8605,4.9045,4.9485,4.9925,5.036,5.081,5.124,5.17,5.213,5.257,5.299,5.343,5.387,5.43,5.475,5.518,5.62,5.605,5.649,5.694,5.738,5.781,5.825,5.869,5.912,5.956,6.001,6.044,6.087,6.131,6.175,6.219,6.263,6.306,6.35,6.394,6.438,6.481,6.525,6.57,6.613,6.656,6.701,6.744,6.787,6.831,6.874,6.919,6.963,7.006,7.049,7.094,7.138,7.1835,7.225,7.27,7.313,7.357,7.401,7.444,7.488,7.532,7.576,7.619,7.663,7.707,7.751,7.794,7.838,7.882,7.925,7.969,8.013,8.057,8.101,8.144,8.189,8.232,8.277,8.32,8.364,8.407,8.451,8.494,8.539,8.583,8.626,8.67,8.714,8.759,8.802,8.846,8.89,8.934,8.977,9.021,9.065,9.109,9.152,9.196,9.24,9.284,9.328,9.372,9.416,9.459,9.503,9.546,9.59,9.634,9.678,9.721,9.766,9.809,9.853,9.897,9.94,9.984,10.028,10.097,10.116,10.159,10.204,10.247,10.291,10.335,10.379,10.423,10.466,10.51,10.554,10.598,10.641,10.685};
int caminar[16][12]={{120,	120,	60,	60,	90,	120,	120,	60,	60,	120,	120,	60},{120,	105,	60,	75,	90,	105,	120,	75,	60,	105,	120,	75},
{120,	90,	60,	90,	90,	90,	120,	90,	60,	90,	120,	90},{120,	75,	60,	105,	90,	75,	120,	105,	60,	75,	120,	105},{120,	60,	60,	120,	90,	60,	120,	120,	60,	60,	120,	120},
{105,	60,	75,	120,	82,	60,	112,	120,	75,	60,	105,	120},{90,	60,	90,	120,	75,	60,	105,	120,	90,	60,	90,	120},{75,	60,	105,	120,	68,	60,	98,	120,	105,	60,	75,	120},
{60,	60,	120,	120,	60,	60,	90,	120,	120,	60,	60,	120},{60,	75,	120,	105,	60,	75,	90,	105,	120,	75,	60,	105},{60,	90,	120,	90,	60,	90,	90,	90,	120,	90,	60,	90},
{60,	105,	120,	75,	60,	105,	90,	75,	120,	105,	60,	75},{60,	120,	120,	60,	60,	120,	90,	60,	120,	120,	60,	60},{75,	120,	105,	60,	68,	120,	98,	60,	105,	120,	75,	60},
{90,	120,	90,	60,	75,	120,	105,	60,	90,	120,	90,	60},{105,	120,	75,	60,	82,	120,	112,	60,	75,	120,	105,	60}};

int atras[16][12]={{120,60,60,120,120,60,120,120,60,60,90,120},{120,75,60,105,120,75,120,105,60,75,90,105},
{120,90,60,90,120,90,120,90,60,90,90,90},{120,105,60,75,120,105,120,75,60,105,90,75},
{120,120,60,60,120,120,120,60,60,120,90,60},{112,120,75,60,105,120,105,60,75,120,82,60},
{105,120,90,60,90,120,90,60,90,120,75,60},{98,120,105,60,75,120,75,60,105,120,68,60},
{90,120,120,60,60,120,60,60,120,120,60,60},{90,105,120,75,60,105,60,75,120,105,60,75},
{90,90,	120,90,60,90,60,90,120,90,60,90},{90,75,120,105,60,75,60,105,120,75,60,105},
{90,60,	120,120,60,60,60,120,120,60,60,120},{98,60,105,120,75,60,75,120,105,60,68,120},
{105,60,90,120,	90,60,90,120,90,60,75,120},{112,60,75,120,105,60,105,120,75,60,82,120}};
int giroI [16][12]={{60,	60,	90,	120,	60,	60,	90,	120,	60,	60,	90,	120},{60,	75,	90,	105,	60,	75,	90,	105,	60,	75,	90,	105},
		{60,	90,	90,	90,	60,	90,	90,	90,	60,	90,	90,	90},{60,	105,	90,	75,	60,	105,	90,	75,	60,	105,	90,	75},{60,	120,	90,	60,	60,	120,	90,	60,	60,	120,	90,	60},
		{68,	120,	82,	60,	68,	120,	82,	60,	68,	120,	82,	60},{75,	120,	75,	60,	75,	120,	75,	60,	75,	120,	75,	60},{82,	120,	68,	60,	82,	120,	68,	60,	82,	120,	68,	60},
		{90,	120,	60,	60,	90,	120,	60,	60,	90,	120,	60,	60},{90,	105,	60,	75,	90,	105,	60,	75,	90,	105,	60,	75},{90,	90,	60,	90,	90,	90,	60,	90,	90,	90,	60,	90},
		{90,	75,	60,	105,	90,	75,	60,	105,	90,	75,	60,	105},{90,	60,	60,	120,	90,	60,	60,	120,	90,	60,	60,	120},{82,	60,	68,	120,	82,	60,	68,	120,	82,	60,	68,	120},
		{75,	60,	75,	120,	75,	60,	75,	120,	75,	60,	75,	120},{68,	60,	82,	120,	68,	60,	82,	120,	68,	60,	82,	120}};


int giroD [16][12]={{120,	60,	90,	120,	120,	60,	90,	120,	120,	60,	90,	120},{120,	75,	90,	105,	120,	75,	90,	105,	120,	75,	90,	105},
{120,	90,	90,	90,	120,	90,	90,	90,	120,	90,	90,	90},{120,	105,	90,	75,	120,	105,	90,	75,	120,	105,	90,	75},{120,	120,	90,	60,	120,	120,	90,	60,	120,	120,	90,	60},
{112,	120,	98,	60,	112,	120,	98,	60,	112,	120,	98,	60},{105,	120,	105,	60,	105,	120,	105,	60,	105,	120,	105,	60},{98,	120,	112,	60,	98,	120,	112,	60,	98,	120,	112,	60},
{90,	120,	120,	60,	90,	120,	120,	60,	90,	120,	120,	60},{90,	105,	120,	75,	90,	105,	120,	75,	90,	105,	120,	75},{90,	90,	120,	90,	90,	90,	120,	90,	90,	90,	120,	90},
{90,	75,	120,	105,	90,	75,	120,	105,	90,	75,	120,	105},{90,	60,	120,	120,	90,	60,	120,	120,	90,	60,	120,	120},{98,	60,	112,	120,	98,	60,	112,	120,	98,	60,	112,	120},
{105,	60,	105,	120,	105,	60,	105,	120,	105,	60,	105,	120},{112,	60,	98,	120,	112,	60,	98,	120,	112,	60,	98,	120}};


void setuP (void);
void move(int rutina[16][12], int sp);
	
int main(void)
{
	
	int	vel;
	setuP();

  uint8_t dato=103;
	uint8_t datoant=0;
  int state=1;
	
	while(1)
	{
         
	  switch (state)
		{
			case 1:      //  ESTADO DE STOP 
				
					GPIOC -> BSRR |= GPIO_BSRR_BR15;
			    //     motores en 90 
					TIM3->CCR3 = 2698;  //Motor 1
					TIM12->CCR1 = 2698; // Motor 11		
				  TIM3->CCR4 = 2698;  // Motor 2
					TIM2->CCR3 = 2698; // Motor 22
					TIM2->CCR4 = 2698; // Motor 3	
					TIM1->CCR1 = 2698; //Motor 33
					TIM12->CCR2 = 2698;  // Motor 4
					TIM3->CCR1 = 2698;  //Motor 44		
					TIM8->CCR3 = 2698; //Motor 5
					TIM8->CCR4 = 2698; // Motor 55
					TIM1->CCR2 = 2698; //Motor 6
					TIM1->CCR3 = 2698; //Motor 66
			    if(USART1->SR & USART_SR_RXNE) // if the Rx flag turn on 
						{
							dato = USART1->DR; //fetch the data received
							USART1->DR = dato;  //send it back out
							while (!(USART1->SR & USART_SR_TC)) //wait for TX to be complete
							;
						}	
			
			  	if(dato==103) // STOP button 
						{
							state=1; // estado en stop 
						} 
					else
						{
							state=2; // estado en move							
						}	 				
		 	break;
			case 2:
				switch (dato)
					{	
						case 97:
							datoant=dato;
						  vel=1;
						  move(caminar, vel);
						
						break;
						
						case 98:
							datoant=dato;
						  vel=2;
						  move(caminar, vel);
						break;
						case 99:
							datoant=dato;
						  vel=4;
						  move(caminar, vel);
						break;						
						case 100:
							datoant=dato;
						  vel=1;
						  move(giroI, vel);
						break;		
						case 101:
							datoant=dato;
						  vel=2;
						  move(giroI, vel);
						break;	
						case 102:
							datoant=dato;
						  vel=4;
						  move(giroI, vel);
						break;
						case 104:
							datoant=dato;
						  vel=1;
						  move(giroD, vel);
						break;	
						case 105:
							datoant=dato;
						  vel=2;
						  move(giroD, vel);
						break;
						case 106:
							datoant=dato;
						  vel=4;
						  move(giroD, vel);
						break;	
						case 107:
							datoant=dato;
						  vel=1;
						  move(atras, vel);
						break;		
						case 108:
							datoant=dato;
						  vel=2;
						  move(atras, vel);
						break;	
						case 109:
							datoant=dato;
						  vel=4;
						  move(atras, vel);
						break;						
					}
						if(USART1->SR & USART_SR_RXNE) // if the Rx flag turn on 
						{
							dato = USART1->DR; //fetch the data received
							USART1->DR = dato;  //send it back out
							while (!(USART1->SR & USART_SR_TC)) //wait for TX to be complete
							;
						}	
			
			  	if(dato==103) // STOP button 
						{
							state=1; // estado en stop 
						} 
					else
						{
							if(dato==datoant)
							{
								state=2; // estado en move
							}	
							else
							{
								state=3; // estado en cambio 
							}						
						}	
			
			break;
			case 3:
					//GPIOC -> BSRR |= GPIO_BSRR_BS15;
					in=0;
					//     motores en 90 
					TIM3->CCR3 = 2698;  //Motor 1
					TIM12->CCR1 = 2698; // Motor 11		
				  TIM3->CCR4 = 2698;  // Motor 2
					TIM2->CCR3 = 2698; // Motor 22
					TIM2->CCR4 = 2698; // Motor 3	
					TIM1->CCR1 = 2698; //Motor 33
					TIM12->CCR2 = 2698;  // Motor 4
					TIM3->CCR1 = 2698;  //Motor 44		
					TIM8->CCR3 = 2698; //Motor 5
					TIM8->CCR4 = 2698; // Motor 55
					TIM1->CCR2 = 2698; //Motor 6
					TIM1->CCR3 = 2698; //Motor 66
					state=2;
			break;
		}
			 
		
				


	}
	
}

void setuP (void)
{
	//------HSEon-------------------------------
//	RCC->CR |= RCC_CR_HSEON;
//	RCC->CR |= RCC_CR_HSERDY;
//	RCC->CFGR |= RCC_CFGR_SWS_HSE;
//	//RCC->CFGR &= ~(0x00000008);
//	RCC->CFGR |= RCC_CFGR_SW_HSE;
	//------------------------------------------
	RCC ->AHB1ENR |= RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN | RCC_AHB1ENR_GPIOAEN; // Habilito el Clock del puerto B, puerto A y puerto C
	RCC ->APB1ENR |= 0b00000000000000000000000001000011;// Habilito el Clock del TIMER3 bit 1 y habilito el clock del timer 12 bit 6 TIMER 2 bit 0
	RCC ->APB2ENR |= 0b00000000000000000000000000000011;// Habilito el Clock del TIMER1 , TIMER8
	RCC->APB1ENR |=RCC_APB1ENR_TIM6EN;
	
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;	//--- USART 
	
	//CONFIGURO EL MODO EN GENERAL PURPOSE OUTPUT MODE (10)  PARA EL PIN 6 DEL PUERTO C
	GPIOA ->MODER &= ~(GPIO_MODER_MODE10_0); //PONGO UN 0 
	GPIOA ->MODER |= GPIO_MODER_MODE10_1;//PONGO UN 1 
	
	//CONFIGURO EL MODO EN GENERAL PURPOSE OUTPUT MODE (10)  PARA EL PIN 6 DEL PUERTO C
	GPIOA ->MODER &= ~(GPIO_MODER_MODE9_0); //PONGO UN 0 
	GPIOA ->MODER |= GPIO_MODER_MODE9_1;//PONGO UN 1 
	
	//CONFIGURO EL MODO EN GENERAL PURPOSE OUTPUT MODE (10)  PARA EL PIN 6 DEL PUERTO C
	GPIOC ->MODER &= ~(GPIO_MODER_MODE6_0); //PONGO UN 0 
	GPIOC ->MODER |= GPIO_MODER_MODE6_1;//PONGO UN 1 
	
	//CONFIGURO EL MODO EN GENERAL PURPOSE OUTPUT MODE (10)  PARA EL PIN 6 DEL PUERTO C
	GPIOC ->MODER &= ~(GPIO_MODER_MODE8_0); //PONGO UN 0 
	GPIOC ->MODER |= GPIO_MODER_MODE8_1;//PONGO UN 1 	
	
	//CONFIGURO EL MODO EN GENERAL PURPOSE OUTPUT MODE (10)  PARA EL PIN 6 DEL PUERTO C
	GPIOC ->MODER &= ~(GPIO_MODER_MODE9_0); //PONGO UN 0 
	GPIOC ->MODER |= GPIO_MODER_MODE9_1;//PONGO UN 1 
	
	//CONFIGURO EL MODO EN GENERAL PURPOSE OUTPUT MODE (10)  PARA EL PIN 0 DEL PUERTO B
	GPIOB ->MODER &= ~(GPIO_MODER_MODE0_0); //PONGO UN 0 EN EL BIT 0
	GPIOB ->MODER |= GPIO_MODER_MODE0_1;//PONGO UN 1 EN EL BIT 1
	//----------------------------------------------
	
	//CONFIGURO EL MODO EN GENERAL PURPOSE OUTPUT MODE (10)  PARA EL PIN 1 DEL PUERTO B
	GPIOB ->MODER &= ~(GPIO_MODER_MODE1_0); //PONGO UN 0 EN EL BIT 0
	GPIOB ->MODER |= GPIO_MODER_MODE1_1;//PONGO UN 1 EN EL BIT 1
	//----------------------------------------------

	//CONFIGURO EL MODO EN GENERAL PURPOSE OUTPUT MODE (10)  PARA EL PIN 10 DEL PUERTO B
	GPIOB ->MODER &= ~(GPIO_MODER_MODE10_0); //PONGO UN 0 EN EL BIT 0
	GPIOB ->MODER |= GPIO_MODER_MODE10_1;//PONGO UN 1 EN EL BIT 1
	//----------------------------------------------
	
	//CONFIGURO EL MODO EN GENERAL PURPOSE OUTPUT MODE (10)  PARA EL PIN 10 DEL PUERTO B
	GPIOB ->MODER &= ~(GPIO_MODER_MODE11_0); //PONGO UN 0 EN EL BIT 0
	GPIOB ->MODER |= GPIO_MODER_MODE11_1;//PONGO UN 1 EN EL BIT 1
	//----------------------------------------------
	
	//CONFIGURO EL MODO EN GENERAL PURPOSE OUTPUT MODE (01)  PARA EL PIN 12 DEL PUERTO B
	GPIOB ->MODER |= GPIO_MODER_MODE12_0; //PONGO UN 1 
	GPIOB ->MODER &= ~(GPIO_MODER_MODE12_1);//PONGO UN 0 
	
	//CONFIGURO EL MODO EN GENERAL PURPOSE OUTPUT MODE (10)  PARA EL PIN 13 DEL PUERTO B
	GPIOB ->MODER &= ~(GPIO_MODER_MODE13_0); //PONGO UN 0 
	GPIOB ->MODER |= GPIO_MODER_MODE13_1;//PONGO UN 1 
	//----------------------------------------------
	
	//CONFIGURO EL MODO EN GENERAL PURPOSE OUTPUT MODE (10)  PARA EL PIN 14 DEL PUERTO B
	GPIOB ->MODER &= ~(GPIO_MODER_MODE14_0); //PONGO UN 0 EN EL BIT 0
	GPIOB ->MODER |= GPIO_MODER_MODE14_1;//PONGO UN 1 EN EL BIT 1
	//----------------------------------------------
	
	//CONFIGURO EL MODO EN GENERAL PURPOSE OUTPUT MODE (10)  PARA EL PIN 15 DEL PUERTO B
	GPIOB ->MODER &= ~(GPIO_MODER_MODE15_0); //PONGO UN 0 
	GPIOB ->MODER |= GPIO_MODER_MODE15_1;//PONGO UN 1 
	//----------------------------------------------	
	
	GPIOA ->AFR[1]=0b100010000;// Alternate function AF1 0001 para timer 1 -channel 2 Y timer 1 -channel 3
	
	GPIOB->AFR[0]=0b01110111000000000000000000100010;	// Alternate function AF2 0010 para timer 3 -channel 3 y channel 4 / 0111 AF7 para USART1
	GPIOB ->AFR[1]=0b10011001000100000001000100000000;// Alternate function / AF9 1001 para timer 12 -channel 1 y channel 2 / AF1 0001 para timer 2 ch3
	
	GPIOC ->AFR[0]=0b10000000000000000000000000; //Alternate function AF2 0010 para timer 3 -channel 1
	GPIOC ->AFR[1]=0b110011;//Alternate function AF3 0011 para timer 8 -channel 4 / AF3 0011 para timer 8 -channel 3 

// Configuro el tipo de salida en PUSH PULL 
	GPIOA ->OTYPER &=~(GPIO_OTYPER_OT9); //PONGO UN '0'
// Configuro el tipo de salida en PUSH PULL 
	GPIOA ->OTYPER &=~(GPIO_OTYPER_OT10); //PONGO UN '0'
// Configuro el tipo de salida en PUSH PULL 
	GPIOC ->OTYPER &=~(GPIO_OTYPER_OT6); //PONGO UN '0'
// Configuro el tipo de salida en PUSH PULL 
	GPIOC ->OTYPER &=~(GPIO_OTYPER_OT8); //PONGO UN '0'
// Configuro el tipo de salida en PUSH PULL 
	GPIOC ->OTYPER &=~(GPIO_OTYPER_OT9); //PONGO UN '0' 
	// Configuro el tipo de salida en PUSH PULL 
	GPIOB ->OTYPER &=~(GPIO_OTYPER_OT0); //PONGO UN '0' EN EL BIT 0 
	// Configuro el tipo de salida en PUSH PULL 
	GPIOB ->OTYPER &=~(GPIO_OTYPER_OT1); //PONGO UN '0' EN EL BIT 1 
	// Configuro el tipo de salida en PUSH PULL 
	GPIOB ->OTYPER &=~(GPIO_OTYPER_OT10); //PONGO UN '0' EN EL BIT 10 	
	// Configuro el tipo de salida en PUSH PULL 
	GPIOB ->OTYPER &=~(GPIO_OTYPER_OT11); //PONGO UN '0' EN EL BIT 10 	
// Configuro el tipo de salida en PUSH PULL 
	GPIOB ->OTYPER &=~(GPIO_OTYPER_OT12); //PONGO UN '0'
// Configuro el tipo de salida en PUSH PULL 
	GPIOB ->OTYPER &=~(GPIO_OTYPER_OT13); //PONGO UN '0' 
	// Configuro el tipo de salida en PUSH PULL 
	GPIOB ->OTYPER &=~(GPIO_OTYPER_OT14); //PONGO UN '0' EN EL BIT 14 
	// Configuro el tipo de salida en PUSH PULL 
	GPIOB ->OTYPER &=~(GPIO_OTYPER_OT15); //PONGO UN '0' EN EL BIT 15 
	
	
// CONFIGURO LA VELOCIDAD HIGH SPEED 10
	GPIOA ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9_1; // PONGO UN 1 
	GPIOA ->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR9_0);// PONGO UN 0 		
// CONFIGURO LA VELOCIDAD HIGH SPEED 10
	GPIOA ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR10_1; // PONGO UN 1 
	GPIOA ->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR10_0);// PONGO UN 0 	
// CONFIGURO LA VELOCIDAD HIGH SPEED 10
	GPIOC ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR6_1; // PONGO UN 1 
	GPIOC ->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR6_0);// PONGO UN 0 	
// CONFIGURO LA VELOCIDAD HIGH SPEED 10
	GPIOC ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR8_1; // PONGO UN 1 
	GPIOC ->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR8_0);// PONGO UN 0 	
// CONFIGURO LA VELOCIDAD HIGH SPEED 10
	GPIOC ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9_1; // PONGO UN 1 
	GPIOC ->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR9_0);// PONGO UN 0 	
// CONFIGURO LA VELOCIDAD HIGH SPEED 10
	GPIOB ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR0_1; // PONGO UN 1 EN EL BIT 1
	GPIOB ->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR0_0);// PONGO UN 0 EN EL BIT 0 
	// CONFIGURO LA VELOCIDAD HIGH SPEED 10
	GPIOB ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR1_1; // PONGO UN 1 EN EL BIT 2
	GPIOB ->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR1_0);// PONGO UN 0 EN EL BIT 3 
	// CONFIGURO LA VELOCIDAD HIGH SPEED 10
	GPIOB ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR10_1; // PONGO UN 1 EN EL BIT 20
	GPIOB ->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR10_0);// PONGO UN 0 EN EL BIT 21 
	// CONFIGURO LA VELOCIDAD HIGH SPEED 10
	GPIOB ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR11_1; // PONGO UN 1 EN EL BIT 20
	GPIOB ->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR11_0);// PONGO UN 0 EN EL BIT 21 
// CONFIGURO LA VELOCIDAD HIGH SPEED 10
	GPIOB ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR12_1; // PONGO UN 1 
	GPIOB ->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR12_0);// PONGO UN 0 
	// CONFIGURO LA VELOCIDAD HIGH SPEED 10
	GPIOB ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR13_1; // PONGO UN 1 
	GPIOB ->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR13_0);// PONGO UN 0 	
	// CONFIGURO LA VELOCIDAD HIGH SPEED 10
	GPIOB ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR14_1; // PONGO UN 1 EN EL BIT 29
	GPIOB ->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR14_0);// PONGO UN 0 EN EL BIT 28 
	// CONFIGURO LA VELOCIDAD HIGH SPEED 10
	GPIOB ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR15_1; // PONGO UN 1 
	GPIOB ->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR15_0);// PONGO UN 0 	

 	//CONFIGURO EL REGISTRO DE PULL-UP/PULL-DOWN  COMO none
	GPIOA ->PUPDR &=~(GPIO_PUPDR_PUPD9); //PONGO 0 0

 	//CONFIGURO EL REGISTRO DE PULL-UP/PULL-DOWN  COMO none
	GPIOA ->PUPDR &=~(GPIO_PUPDR_PUPD10); //PONGO 0 0

 	//CONFIGURO EL REGISTRO DE PULL-UP/PULL-DOWN  COMO none
	GPIOC ->PUPDR &=~(GPIO_PUPDR_PUPD6); //PONGO 0 0
	
 	//CONFIGURO EL REGISTRO DE PULL-UP/PULL-DOWN  COMO none
	GPIOC ->PUPDR &=~(GPIO_PUPDR_PUPD8); //PONGO 0 0
	
 	//CONFIGURO EL REGISTRO DE PULL-UP/PULL-DOWN  COMO none
	GPIOC ->PUPDR &=~(GPIO_PUPDR_PUPD9); //PONGO 0 0	
	
	//CONFIGURO EL REGISTRO DE PULL-UP/PULL-DOWN  COMO none
	GPIOB ->PUPDR &=~(GPIO_PUPDR_PUPD0); //PONGO 0 0 EN LOS BITS 1 Y 0
	
	//CONFIGURO EL REGISTRO DE PULL-UP/PULL-DOWN  COMO none
	GPIOB ->PUPDR &=~(GPIO_PUPDR_PUPD1); //PONGO 0 0 EN LOS BITS 2 Y 3
	
	//CONFIGURO EL REGISTRO DE PULL-UP/PULL-DOWN  COMO none
	GPIOB ->PUPDR &=~(GPIO_PUPDR_PUPD10); //PONGO 0 0 EN LOS BITS 21 Y 20	

	//CONFIGURO EL REGISTRO DE PULL-UP/PULL-DOWN  COMO none
	GPIOB ->PUPDR &=~(GPIO_PUPDR_PUPD11); //PONGO 0 0 EN LOS BITS 21 Y 20	
		
	//CONFIGURO EL REGISTRO DE PULL-UP/PULL-DOWN  COMO none
	GPIOB ->PUPDR &=~(GPIO_PUPDR_PUPD12); //PONGO 0 0 

	//CONFIGURO EL REGISTRO DE PULL-UP/PULL-DOWN  COMO none
	GPIOB ->PUPDR &=~(GPIO_PUPDR_PUPD13); //PONGO 0 0 
	
	//CONFIGURO EL REGISTRO DE PULL-UP/PULL-DOWN  COMO none
	GPIOB ->PUPDR &=~(GPIO_PUPDR_PUPD14); //PONGO 0 0 EN LOS BITS 29 Y 28
 
 	//CONFIGURO EL REGISTRO DE PULL-UP/PULL-DOWN  COMO none
	GPIOB ->PUPDR &=~(GPIO_PUPDR_PUPD15); //PONGO 0 0 
	
  //----------------------------- Channel 1 TIMER 12
	TIM12->PSC=Pres;
	TIM12->ARR=Arr;
	TIM12->CCR1=ci; // ciclo util inicial 90°
	TIM12->CCR2=ci; // ciclo util inicial 	
// SE CONFIGURA OUTPUT COMPARE MODE "OC1M" y "OC2M"EN 110 para PWM MODE1 
	TIM12->CCMR1 |=   0b0110000001100000;
	TIM12->CCMR1 &= ~(0b0001000000010000);
	//------------------------------------------------------
	TIM12->CCER |= 0b0000000000010001; //CC1E Y CC2E HABILITA LA SALIDAAA
	TIM12->CR1  |= 0b0000000000000001; //CEN 

  //----------------------------- Channel 1 N TIMER 1
  TIM1->PSC=Pres;
	TIM1->ARR=Arr;
	TIM1->CCR1=ci; // ciclo util inicial 
	TIM1->CCR2=ci; // ciclo util inicial 
	TIM1->CCR3=ci;  // ciclo util inicial 
	// SE CONFIGURA OUTPUT COMPARE MODE "OC1M" , "OCM2" , "OCM3" EN 110 para PWM MODE1  y el OC1PE Y OC2PE Y OC3PE: Output compare 2 preload enable en 1
	TIM1->CCMR1 |=   0b0110100001101000;
	TIM1->CCMR1 &= ~(0b0001000000010000);	
	
	TIM1->CCMR2 |=   0b0000000001101000;
	TIM1->CCMR2 &= ~(0b0000000000010000);
	//------------------------------------------------------
	TIM1->CCER |= 0b0000000100010101; //CC1E CC2E CC3E y 	CC1NE HABILITA LA SALIDAAA
	TIM1->CCER |= 0b0000000000001000;//CC1NP complementary output Polarity  active low 
	TIM1->BDTR |= 0b1000000000000000; //MOE main output enable 
	TIM1->CR1 |=0b0000000000000001; //CEN 
	TIM1->EGR |=0b0000000000000001; //UG en 1
	 
  //----------------------------- Channel 3 TIMER 2
	TIM2->PSC=Pres;
	TIM2->ARR=Arr;
	TIM2->CCR3=ci; // ciclo util inicial
	TIM2->CCR4=ci; // ciclo util inicial	
// SE CONFIGURA OUTPUT COMPARE MODE "OC3M" y "OC4M" EN 110 para PWM MODE1 
	TIM2->CCMR2 |=   0b0110000001100000;
	TIM2->CCMR2 &= ~(0b0001000000010000);
	//------------------------------------------------------
	TIM2->CCER |= 0b0001000100000000; //CC3E y cc4e  HABILITA LA SALIDAAA
	TIM2->CR1  |= 0b0000000000000001; //CEN 
	
	//----------------------------- Channel 1 ,Channel 3 Y Channel 4  TIMER 3
	TIM3->PSC=Pres;
	TIM3->ARR=Arr;
	TIM3->CCR1=ci; // ciclo util inicial 	
	TIM3->CCR3=ci; // ciclo util inicial 
	TIM3->CCR4=ci; // ciclo util inicial 
// SE CONFIGURA OUTPUT COMPARE MODE "OC1M"  EN 110 para PWM MODE1 
	TIM3->CCMR1 |=  0b0000000001100000;
	TIM3->CCMR1 &=~(0b0000000000010000);
// SE CONFIGURA OUTPUT COMPARE MODE "OC3M" y "OC4M" EN 110 para PWM MODE1 	
	TIM3->CCMR2 |=0b0110000001100000;
	TIM3->CCMR2 &= ~(0b0001000000010000);
	//------------------------------------------------------
	TIM3->CCER |= 0b0001000100000001; // CCE1 , CC3E y CC4E HABILITA LA SALIDA
	TIM3->CR1 |=0b0000000000000001; //CEN 

	 //----------------------------- Channel 4  TIMER 8
  TIM8->PSC=Pres;
	TIM8->ARR=Arr;
	TIM8->CCR4=ci; // ciclo util inicial 
	TIM8->CCR3=ci; // ciclo util inicial
	// SE CONFIGURA OUTPUT COMPARE MODE "OC4M" Y "OC3M" EN 110 para PWM MODE1  y el OC1PE: Output compare 2 preload enable en 1
	
	TIM8->CCMR2 |=   0b0110000001100000;
	TIM8->CCMR2 &= ~(0b0001000000010000);
	//------------------------------------------------------
	TIM8->CCER |= 0b0001000100000000; //CC4E Y CC3E HABILITA LA SALIDAAA
	TIM8->BDTR |= 0b1000000000000000; //MOE main output enable 
	TIM8->CR1 |=0b0000000000000001; //CEN 
	TIM8->EGR |=0b0000000000000001; //UG en 1
	
	//------- timer 6

	TIM6->PSC=200;
	TIM6->ARR=20000;
	TIM6->CR1 |= 0b0000000000000001;
	
	//-------usart
		
	//---------tx Y rx en modo alternativo-----------------------------------
	GPIOB->MODER |=  0b00000000000000001010000000000000;	
	GPIOB->MODER &=~(0b00000000000000000101000000000000);
	
	GPIOB->OTYPER &= ~(GPIO_OTYPER_OT6);
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR6_1;
	GPIOB->OSPEEDR &=~(GPIO_OSPEEDER_OSPEEDR6_0);
	GPIOB->PUPDR &=~(GPIO_PUPDR_PUPD6);
	GPIOB->PUPDR &=~(GPIO_PUPDR_PUPD7); 
	
	USART1->BRR=0xD05; // 9600 baudios a fck=16MHz *2
	USART1->CR1 |=  USART_CR1_OVER8;
	USART1->CR1 |=  USART_CR1_RE|USART_CR1_TE|USART_CR1_UE;// BIT 2 RX ENABLE , BIT 3 TX ENABLE , BIT 13 USART ENABLE
 
	
	// led tarjeta
	
	GPIOC ->MODER |= GPIO_MODER_MODE15_0; //PONGO UN 1 EN EL BIT 30
	GPIOC ->MODER &= ~(GPIO_MODER_MODE15_1);//PONGO UN 0 EN EL BIT 31
	GPIOC ->OTYPER &=~(GPIO_OTYPER_OT15);
	GPIOC ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR15_1; // PONGO UN 1 EN EL BIT 31
	GPIOC ->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR15_0);// PONGO UN 0 EN EL BIT 30 
	GPIOC ->PUPDR &=~(GPIO_PUPDR_PUPD15); //PONGO 0 0 EN LOS BITS 31 Y 30

}


void move(int rutina[16][12], int sp)
{
	int p1,p11,p2,p22,p3,p33,p4,p44,p5,p55,p6,p66;
	int x1,x2,x3,x4,x5,x6,x11,x22,x33,x44,x55,x66;		
	float ptj1,ptj11,ptj2,ptj22,ptj3,ptj33,ptj4,ptj44,ptj5,ptj55,ptj6,ptj66;
			
					   	if((in*sp)>=15)
								{
									GPIOC -> BSRR |= GPIO_BSRR_BS15;
									in=0;
								}	
								p1=rutina[in*sp][0];
								ptj1= grados[p1-1];
								x1=((ptj1*Arr)/100);
								TIM3->CCR3 = x1;  //Motor 1
								
								p11=rutina[in*sp][1];
								ptj11= grados[p11-1];
								x11=((ptj11*Arr)/100);
								TIM12->CCR1 = x11; //Motor 11
								
								p2=rutina[in*sp][2];
								ptj2=grados[p2-1];
								x2=((ptj2*Arr)/100);
								TIM3->CCR4 = x2;  // Motor 2
							
								p22=rutina[in*sp][3];
								ptj22=grados[p22-1];
								x22=((ptj22*Arr)/100);
								TIM2->CCR3 = x22; // Motor 22
							
				   			p3=rutina[in*sp][4];
								ptj3=grados[p3-1];
								x3=((ptj3*Arr)/100);
								TIM2->CCR4=x3;  // MOTOR 3
								
						
								p33=rutina[in*sp][5];
								ptj33=grados[p33-1];
								x33=((ptj33*Arr)/100);
								TIM1->CCR1 = x33; //Motor 33
								
								p4=rutina[in*sp][6];
								ptj4=grados[p4-1];
								x4=((ptj4*Arr)/100);
								TIM12->CCR2 = x4; //Motor 4
								
								p44=rutina[in*sp][7];
								ptj44=grados[p44-1];
								x44=((ptj44*Arr)/100);
								TIM3->CCR1 = x44;  //Motor 44
								
								p5=rutina[in*sp][8];
								ptj5=grados[p5-1];
								x5=((ptj5*Arr)/100);
								TIM8->CCR3 = x5; //Motor 5	
						
								p55=rutina[in*sp][9];
								ptj55=grados[p55-1];
								x55=((ptj55*Arr)/100);
								TIM8->CCR4 = x55; // Motor 55
								
								p6=rutina[in*sp][10];
								ptj6=grados[p6-1];
								x6=((ptj6*Arr)/100);
								TIM1->CCR2 = x6; //Motor 6
							
								p66=rutina[in*sp][11];
								ptj66=grados[p66-1];
								x66=((ptj66*Arr)/100);
								TIM1->CCR3 = x66; //Motor 66
								
								if(TIM6->SR & TIM_SR_UIF)
								{
									TIM6->SR &= ~(TIM_SR_UIF);
									in=in+1;
								}	
						
								
								
}
