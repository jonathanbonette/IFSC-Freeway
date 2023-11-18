/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under Ultimate Liberty license
 * SLA0044, the "License"; You may not use this file except in compliance with
 * the License. You may obtain a copy of the License at:
 *                             www.st.com/SLA0044
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "atraso.h"
#include "defPrincipais.h"
#include "NOKIA5110_fb.h"
#include "figuras.h"
#include "PRNG_LFSR.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

//osThreadId defaultTaskHandle;
//uint32_t defaultTaskBuffer[ 128 ];
//osStaticThreadDef_t defaultTaskControlBlock;
/* USER CODE BEGIN PV */

// Estrutura dos carros
struct pontos_t sedan5_1p;
struct pontos_t sedan5_2p;
struct pontos_t caminhao1p;
struct pontos_t corrida0p;
struct pontos_t corrida1p;
struct pontos_t corrida2p;
struct pontos_t moto0p;
struct pontos_t moto1p;
struct pontos_t caminhao0p;
struct pontos_t sedan0p;
struct pontos_t sedan0_1p;
struct pontos_t carro1p;
struct pontos_t carro1_1p;
struct pontos_t carro3p;
struct pontos_t carro3_1p;
struct pontos_t carro3_2p;
struct pontos_t principal0p;
struct pontos_t carro_teste;

// Score
int32_t score_carro = 0;
uint32_t y_principal = 45;
volatile uint8_t carro_reset = 0;

// Valor do joystick
uint32_t ADC_buffer[2];
uint32_t valor_ADC[2];

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_ADC1_Init(void);
void StartDefaultTask(void const * argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
	if(hadc->Instance == ADC1)
	{
		valor_ADC[0]=ADC_buffer[0];
		valor_ADC[1]=ADC_buffer[1];
	}
}

//---------------------------------------------------------------------------------------------------
// Tarefa para atualizar periodicamente o LCD
void vTask_LCD_Print(void *pvParameters)
{
	while(1) imprime_LCD();
}
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
// Função genérica para criar os carros - estrutura para empacotar os parâmetros
typedef struct {
	uint32_t initialX;
	uint32_t initialY;
	int32_t initialDirecao;
	struct pontos_t* objStruct;
	const struct figura_t* figura;
	const struct figura_t* figura_apaga;
	uint32_t delay;
} TaskParameters;

// TaskParameters taskParamsCarroTeste = {60, 5, -1, &carro_teste, &carro1f, &apaga_carro1f, 150};		// Teste
TaskParameters taskParamsSedan5_1 = {0, 5, 1, &sedan5_1p, &carro1f, &apaga_carro1f, 100};				// Sedan 5 1
TaskParameters taskParamsSedan5_2 = {40, 5, 1, &sedan5_2p, &carro1f, &apaga_carro1f, 100};				// Sedan 5 1
TaskParameters taskParamsCaminhao1 = {25, 10, 1, &caminhao1p, &caminhao2f, &apaga_caminhao2f, 150}; // Caminhão 1
TaskParameters taskParamsCorrida = {15, 15, -1, &corrida0p, &corrida1f, &apaga_corrida1f, 165};		// Corrida
TaskParameters taskParamsCorrida1 = {41, 15, -1, &corrida1p, &corrida1f, &apaga_corrida1f, 165};	// Corrida 1
TaskParameters taskParamsCorrida2 = {67, 15, -1, &corrida2p, &corrida1f, &apaga_corrida1f, 165};	// Corrida 2
TaskParameters taskParamsMoto = {0, 20, 1, &moto0p, &moto1f, &apaga_moto1f, 150};					// Moto
TaskParameters taskParamsMoto1 = {40, 20, 1, &moto1p, &moto1f, &apaga_moto1f, 150};					// Moto 1
TaskParameters taskParamsCaminhao = {20, 25, -1, &caminhao0p, &caminhao1f, &apaga_caminhao1f, 100}; // Caminhao
TaskParameters taskParamsSedan = {70, 30, 1, &sedan0p, &sedan1f, &apaga_sedan1f, 150};				// Sedan
TaskParameters taskParamsSedan1 = {40, 30, 1, &sedan0_1p, &sedan1f, &apaga_sedan1f, 150};			// Sedan 1
TaskParameters taskParamsCarro = {70, 35, 1, &carro1p, &carro1f, &apaga_carro1f, 300};				// Carro
TaskParameters taskParamsCarro1 = {35, 35, 1, &carro1_1p, &carro1f, &apaga_carro1f, 300};			// Carro 1
TaskParameters taskParamsCarro3 = {80, 40, -1, &carro3p, &carro1f, &apaga_carro1f, 135};			// Carro 3
TaskParameters taskParamsCarro3_1 = {60, 40, -1, &carro3_1p, &carro1f, &apaga_carro1f, 135}; 		// Carro 3 1
TaskParameters taskParamsCarro3_2 = {40, 40, -1, &carro3_2p, &carro1f, &apaga_carro1f, 135}; 		// Carro 3 2

// createDeslocaTask(posicao inicial X, posicao inicial Y, direção: direita 1 esquerda -1, struct de cada objeto (automovel), figura para desenhar, figura para apagar, velocidade do carro)
void vTask_Desloca(void *pvParameters)
{
	TaskParameters* params = (TaskParameters*)pvParameters;	// Recebe os parametros do conjunto da estrutura definida

	uint32_t x = params->initialX;		// Posição inicial X
	uint32_t y = params->initialY;		// Posição inicial Y
	int32_t direcao = params->initialDirecao;	// Direção inicial - Direita: 1 - Esquerda: -1

	params->objStruct->x2 = 0;
	params->objStruct->y2 = 0;
	params->objStruct->x3 = 0;
	params->objStruct->y3 = 0;

	while (1)
	{
		x += direcao;

		// Se a direção for passada para direita ou para a esquerda
		if(params->initialDirecao == -1) {
			if (x <= 0)
			{
				x = 80; 				// Reseta a posição para o lado direito
			}
		} else {
			if (x >= 80)
			{
				x = 0;					// Reseta a posição para o lado esquerdo
			}
		}

		params->objStruct->x1 = x;
		params->objStruct->y1 = y;

		desenha_fig(params->objStruct, params->figura);
		vTaskDelay(params->delay);
		apaga_fig(params->objStruct, params->figura_apaga);
	}
}
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
// Colisão Nova Estrutura
void isHit(uint32_t x, uint32_t y, const struct pontos_t* objStruct, const struct figura_t* objFigura)
{
    // Verificação de colisão
    if (x < objStruct->x1 + objFigura->largura &&
        x + tri1f.largura > objStruct->x1 &&
        y_principal < objStruct->y1 + objFigura->altura &&
        y_principal + tri1f.altura > objStruct->y1)
    {
        // Após a colisão ==> reseta o carro principal e diminui a pontuação
        x = 40;
        y_principal = 45;
        score_carro--;
    }
}
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
void vTask_Desloca_Principal_Colisao(void *pvParameters)
{
	static uint32_t x = 45; 	// Posição inicial do carro
	static int32_t dif_eixoX, dif_eixoY;

	principal0p.x2 = 0; principal0p.y2 = 0;
	principal0p.x3 = 0; principal0p.y3 = 0;

	while (1)
	{
		dif_eixoX = 2048 - valor_ADC[0];
		dif_eixoY = 2048 - valor_ADC[1];

		if (dif_eixoX > 200)
		{
			if (x > 0) x -= 5;
		}
		else if (dif_eixoX < -200)
		{
			if (x < 80) x += 5;
		}

		if (dif_eixoY > 200)
		{
			// Move o carro para cima (diminua a posição Y) por 5 quadradinhos
					if (y_principal >= 0) y_principal -= 5;
		}
		else if (dif_eixoY < -200)
		{
			// Move o carro para baixo (aumente a posição Y) por 5 quadradinhos
			if (y_principal <= 45) y_principal += 5;

		}

		// Limita a posição Y para que o carro não saia da tela
		if (y_principal < 0) y_principal = 0;  	// Se chegar no final reseta a posição

		// Se conseguir passar a tela, aumenta o score
		if (y_principal > 50) {
			y_principal = 45;
			carro_reset = 1;					// Reseta a posição do carro
		}

		// Limita a posição Y da parte de baixo
		if (y_principal > 45) {
			y_principal = 45;					// Reseta a posição do carro
		}

		//----------------------------------------
		// Lógica das Colisões:
		isHit(x, y_principal, &caminhao1p, &caminhao2f);
		isHit(x, y_principal, &caminhao0p, &caminhao1f);

		isHit(x, y_principal, &moto0p, &moto1f);
		isHit(x, y_principal, &moto1p, &moto1f);

		isHit(x, y_principal, &sedan0p, &sedan1f);
		isHit(x, y_principal, &sedan0_1p, &sedan1f);

		isHit(x, y_principal, &carro1p, &carro1f);
		isHit(x, y_principal, &carro1_1p, &carro1f);

		isHit(x, y_principal, &corrida0p, &corrida1f);
		isHit(x, y_principal, &corrida1p, &corrida1f);
		isHit(x, y_principal, &corrida2p, &corrida1f);

		isHit(x, y_principal, &carro3p, &carro1f);
		isHit(x, y_principal, &carro3_1p, &carro1f);
		isHit(x, y_principal, &carro3_2p, &carro1f);

		isHit(x, y_principal, &sedan5_1p, &carro1f);
		isHit(x, y_principal, &sedan5_2p, &carro1f);
		//----------------------------------------

		// Parametro inicial
		principal0p.x1 = x;
		principal0p.y1 = y_principal;

		// Desenho da figura principal
		desenha_fig(&principal0p, &tri1f);
		vTaskDelay(150);		// Quanto maior delay menor velocidade
		desenha_fig(&principal0p, &apaga_tri1f);
	}
}
//---------------------------------------------------------------------------------------------------
void vTask_Pontuacao(void *pvParameters){

	while (1)
	{
		// Testa se a nave subiu até o topo da tela e resetou a posição
		if (carro_reset == 1)
		{
			score_carro++; // Adicionar pontos toda vez que a nave subir
			carro_reset = 0; // Resetar a posição na parte de baixo
		}

		// Atualiza a exibição da pontuação na tela
		escreve_Nr_Peq(60, 0, score_carro, 6);
		vTaskDelay(10);
	}
}
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	/* USER CODE BEGIN 1 */
	uint32_t semente_PRNG=1;
	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_DMA_Init();
	MX_ADC1_Init();
	/* USER CODE BEGIN 2 */

	HAL_ADC_Start_DMA(&hadc1,(uint32_t*)ADC_buffer,2);
	HAL_ADC_Start_IT(&hadc1);

	// inicializa LCD 5110
	inic_LCD();
	limpa_LCD();

	// --------------------------------------------------------------------------------------
	// inicializa tela do jogo
	escreve2fb((unsigned char *)tela_inicial);
	imprime_LCD();

	HAL_Delay(2000);
	INVERTE_PIXELS();
	HAL_Delay(2000);
	NORMALIZA_PIXELS();
	HAL_Delay(2000);

	limpa_LCD();

	goto_XY(10, 1);
	string_LCD("Pressione o");
	goto_XY(25, 3);
	string_LCD("Botao!");
	imprime_LCD();


	while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15))// quando pressionar a tecla come�a o jogo
	{
		semente_PRNG++;
	}
	init_LFSR(semente_PRNG);	// inicializacao para geracao de numeros pseudoaleatorios
	limpa_LCD();

	// -----------------------------------------

	/* USER CODE END 2 */

	/* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
	/* USER CODE END RTOS_MUTEX */

	/* USER CODE BEGIN RTOS_SEMAPHORES */
	/* add semaphores, ... */
	/* USER CODE END RTOS_SEMAPHORES */

	/* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
	/* USER CODE END RTOS_TIMERS */

	/* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
	/* USER CODE END RTOS_QUEUES */

	/* Create the thread(s) */
	/* definition and creation of defaultTask */
	//osThreadStaticDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128, defaultTaskBuffer, &defaultTaskControlBlock);
	// defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

	/* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */

	xTaskCreate(vTask_LCD_Print, "LCD_print", 128, NULL, osPriorityNormal,NULL);						// LCD print
	xTaskCreate(vTask_Desloca_Principal_Colisao, "Principal", 128, NULL, osPriorityNormal, NULL); 		// Principal
	xTaskCreate(vTask_Pontuacao, "Pontuacao", 128, NULL, osPriorityNormal, NULL); 						// Pontuação

	xTaskCreate(vTask_Desloca, "Sedan 5 1", 128, (void*)&taskParamsSedan5_1, osPriorityNormal, NULL);
	xTaskCreate(vTask_Desloca, "Sedan 5 2", 128, (void*)&taskParamsSedan5_2, osPriorityNormal, NULL);

	xTaskCreate(vTask_Desloca, "Caminhao 1", 128, (void*)&taskParamsCaminhao1, osPriorityNormal, NULL);
	xTaskCreate(vTask_Desloca, "Caminhao", 128, (void*)&taskParamsCaminhao, osPriorityNormal, NULL);

	xTaskCreate(vTask_Desloca, "Moto", 128, (void*)&taskParamsMoto, osPriorityNormal, NULL);
	xTaskCreate(vTask_Desloca, "Moto 1", 128, (void*)&taskParamsMoto1, osPriorityNormal, NULL);

	xTaskCreate(vTask_Desloca, "Sedan", 128, (void*)&taskParamsSedan, osPriorityNormal, NULL);
	xTaskCreate(vTask_Desloca, "Sedan 1", 128, (void*)&taskParamsSedan1, osPriorityNormal, NULL);

	xTaskCreate(vTask_Desloca, "Carro", 128, (void*)&taskParamsCarro, osPriorityNormal, NULL);
	xTaskCreate(vTask_Desloca, "Carro 1", 128, (void*)&taskParamsCarro1, osPriorityNormal, NULL);
	// Triplas
	xTaskCreate(vTask_Desloca, "Carro de corrida", 128, (void*)&taskParamsCorrida, osPriorityNormal, NULL);
	xTaskCreate(vTask_Desloca, "Carro de corrida 1", 128, (void*)&taskParamsCorrida1, osPriorityNormal, NULL);
	xTaskCreate(vTask_Desloca, "Carro de corrida 2", 128, (void*)&taskParamsCorrida2, osPriorityNormal, NULL);

	xTaskCreate(vTask_Desloca, "Carro 3", 128, (void*)&taskParamsCarro3, osPriorityNormal, NULL);
	xTaskCreate(vTask_Desloca, "Carro 3_1", 128, (void*)&taskParamsCarro3_1, osPriorityNormal, NULL);
	xTaskCreate(vTask_Desloca, "Carro 3_2", 128, (void*)&taskParamsCarro3_2, osPriorityNormal, NULL);
	//----

	/* USER CODE END RTOS_THREADS */

	/* Start scheduler */
	osKernelStart();

	/* We should never get here as control is now taken by the scheduler */
	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1)
	{
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
	RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}
	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
			|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
	{
		Error_Handler();
	}
	PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
	PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
	if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
	{
		Error_Handler();
	}
}

/**
 * @brief ADC1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_ADC1_Init(void)
{

	/* USER CODE BEGIN ADC1_Init 0 */

	/* USER CODE END ADC1_Init 0 */

	ADC_ChannelConfTypeDef sConfig = {0};

	/* USER CODE BEGIN ADC1_Init 1 */

	/* USER CODE END ADC1_Init 1 */
	/** Common config
	 */
	hadc1.Instance = ADC1;
	hadc1.Init.ScanConvMode = ADC_SCAN_ENABLE;
	hadc1.Init.ContinuousConvMode = ENABLE;
	hadc1.Init.DiscontinuousConvMode = DISABLE;
	hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	hadc1.Init.NbrOfConversion = 2;
	if (HAL_ADC_Init(&hadc1) != HAL_OK)
	{
		Error_Handler();
	}
	/** Configure Regular Channel
	 */
	sConfig.Channel = ADC_CHANNEL_1;
	sConfig.Rank = ADC_REGULAR_RANK_1;
	sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;
	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
		Error_Handler();
	}
	/** Configure Regular Channel
	 */
	sConfig.Channel = ADC_CHANNEL_2;
	sConfig.Rank = ADC_REGULAR_RANK_2;
	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN ADC1_Init 2 */

	/* USER CODE END ADC1_Init 2 */

}

/**
 * Enable DMA controller clock
 */
static void MX_DMA_Init(void)
{

	/* DMA controller clock enable */
	__HAL_RCC_DMA1_CLK_ENABLE();

	/* DMA interrupt init */
	/* DMA1_Channel1_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);

}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6
			|GPIO_PIN_7, GPIO_PIN_RESET);

	/*Configure GPIO pin : PC13 */
	GPIO_InitStruct.Pin = GPIO_PIN_13;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	/*Configure GPIO pin : PC15 */
	GPIO_InitStruct.Pin = GPIO_PIN_15;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	/*Configure GPIO pins : PA3 PA4 PA5 PA6
                           PA7 */
	GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6
			|GPIO_PIN_7;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
	/* USER CODE BEGIN 5 */
	/* Infinite loop */
	for(;;)
	{
		osDelay(1);
	}
	/* USER CODE END 5 */
}

/**
 * @brief  Period elapsed callback in non blocking mode
 * @note   This function is called  when TIM4 interrupt took place, inside
 * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
 * a global variable "uwTick" used as application time base.
 * @param  htim : TIM handle
 * @retval None
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	/* USER CODE BEGIN Callback 0 */

	/* USER CODE END Callback 0 */
	if (htim->Instance == TIM4) {
		HAL_IncTick();
	}
	/* USER CODE BEGIN Callback 1 */

	/* USER CODE END Callback 1 */
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

