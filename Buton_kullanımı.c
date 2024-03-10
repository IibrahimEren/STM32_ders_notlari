/* USER CODE BEGIN 2 */
  int32_t delayStats = 250;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
    MX_USB_HOST_Process();

    /* USER CODE BEGIN 3 */
    //led 4 on
    HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, 1);
    HAL_Delay(delayStats);
    //Orange Led On
    HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, 1);
    HAL_Delay(delayStats);
    // red
    HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_Pin, 1);
    HAL_Delay(delayStats);
    //blue
    HAL_GPIO_WritePin(LD6_GPIO_Port, LD6_Pin, 1);
    HAL_Delay(delayStats);

    HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, 0);
    HAL_Delay(delayStats);
    HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, 0);
    HAL_Delay(delayStats);
    HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_Pin, 0);
    HAL_Delay(delayStats);
    HAL_GPIO_WritePin(LD6_GPIO_Port, LD6_Pin, 0);
    HAL_Delay(delayStats);

    delayStats = delayStats - (20);
    if(delayStats <= 0){
    	delayStats = 250;
    }
    //Toogle bir yandırıp bir söndürmeye yarıyor
    //HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);
    //HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
    //Mavi buton basılı tutuldukça ledlerin yanıp sönmesini sağlayan bir kod yaptık
    /*Burada yapılan kod akarken mavi butona basılıp basılmadığını kontrol ederek basıldığı taktirde bu if bloğunun
     * içerisine girmesini sağlayan bir kod yaptık ---> Bu dış kesmeler kullanılarak yapılması daha uygun olacaktır.
    */
    if(HAL_GPIO_ReadPin(blueButton_GPIO_Port, blueButton_Pin)){
	    HAL_Delay(delayStats);

    	while(1){
    		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, 1);
    		    //Orange
    		HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, 1);
    		    // red
    		HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_Pin, 1);
    		    //blue
    	    HAL_GPIO_WritePin(LD6_GPIO_Port, LD6_Pin, 1);
    	    HAL_Delay(delayStats);

   		    HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, 0);
   		    HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, 0);
   		    HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_Pin, 0);
   		    HAL_GPIO_WritePin(LD6_GPIO_Port, LD6_Pin, 0);
    		HAL_Delay(delayStats);

    		    if(!(HAL_GPIO_ReadPin(blueButton_GPIO_Port, blueButton_Pin))){
    		    	break;
    		    }
    	}
    }

  }
  /* USER CODE END 3 */
