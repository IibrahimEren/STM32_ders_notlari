# Timer'ların kullanımı ile aynı olarak hz değerlerini ayarlanarak başlanılıyor.
- tek fark olarak bu sefer internel clock olarak ayarlandıktan sonra aşağısında bulunan tab'larda channel kısımlarında PWM generation bölümünü seçmemiz gerekiyor.
- sonrasında yapacağımız iş main.c dosyası içerisinde bize izin verilen bölümlerden birine - tercihen 2.-**HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);** yazarak sinyali başlatmış oluyoruz.
- sonrasında kalan işimiz duty değerini ayarlamak oluyor bu da aşağıda verilen denklem ile oluyor.
- ![duty](https://github.com/IibrahimEren/STM32_ders_notlari/assets/87008174/e15636b7-8dd7-4dd9-968d-62bd76f0c287)
- kısayol olarak mesela ARR değerini 10.000 yaptıysak ve %20'lik bir duty değeri istiyorsak;
- **__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,2000);** kodunu yazarsak *2000 değeri 10.000 değerinin %20'si demek oluyor* hesap yapmadan geçmemize olanak sağlayabilir

  **Logic analyzer cihazı ile birlikte pwm sinyallerini görebiliriz --> Satın alınacak**
- 
