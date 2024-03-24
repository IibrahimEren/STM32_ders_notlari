# Timer'ların kullanımı ile aynı olarak hz değerlerini ayarlanarak başlanılıyor.
- tek fark olarak bu sefer internel clock olarak ayarlandıktan sonra aşağısında bulunan tab'larda channel kısımlarında PWM generation bölümünü seçmemiz gerekiyor.
- sonrasında yapacağımız iş main.c dosyası içerisinde bize izin verilen bölümlerden birine - tercihen 2.-**HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);** yazarak sinyali başlatmış oluyoruz.
- sonrasında kalan işimiz duty değerini ayarlamak oluyor bu da aşağıda verilen denklem ile oluyor.
- ![duty](https://github.com/IibrahimEren/STM32_ders_notlari/assets/87008174/e15636b7-8dd7-4dd9-968d-62bd76f0c287)
- kısayol olarak mesela ARR değerini 10.000 yaptıysak ve %20'lik bir duty değeri istiyorsak;
- **__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,2000);** kodunu yazarsak *2000 değeri 10.000 değerinin %20'si demek oluyor* hesap yapmadan geçmemize olanak sağlayabilir. Bu pine ne kadar bir güç verileceğini ayarlamamıza yarıyor.

  **Logic analyzer cihazı ile birlikte pwm sinyallerini görebiliriz --> Satın alınacak**

  # Kod Örneği
```
// Bunu yazarak PWM sinyalini başlatmış oluyoruz.
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2 );

  __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,10000); //bütün bir duty cycle değeri ile güç veriyor
  //arr değerimiz 1000 olarak ayarladık burada da %10'luk istiyoruz
  // Burada sönmemesini sağlayan kısım ayarladığımız arr değeri 1 Hz olasydı 0.1 saniye içerisinde %10'luk bir performansla yanıp
  //diğer 0.9 saniye içerisinde sönecekti. bu sefer de aynı oluyor ama bu iş o kadar hızlı yapılıyor ki biz göremiyoruz.
  __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,700);
  //Buradaki yanıp sönmeden sadece gücünün azalmasını sağlayabilmemizdeki fark frekans değeri ile oynamamızdan kaynaklı
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

    /* USER CODE END WHILE */
    MX_USB_HOST_Process();

    for(int i = 0; i <= 1000; i++ ){
    	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,i);
    	HAL_Delay(2);
    }

    for(int i = 1000; i >= 0; i-- ){
        	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,i);
        	HAL_Delay(2);
    }
``` 
