# Timer'lar nedir?
- Genel bir açıklama gerekirse dış interruplar yerine belli bir saniye sonrasında kendi kendine interrup eden bir kesici gibi düşünebiliriz.
- ioc dosyasında Clock configiration bölümünde TM1 üzerinden istediğimiz hz değerlerini ayarladıktan sonra aşağıdaki görseldeki gibi bir hesaplama yapılır
- ![clock hesabı](https://github.com/IibrahimEren/STM32_ders_notlari/assets/87008174/1edd09e8-95a4-4915-aae6-8a23cb885fc2)
- Burada gösterilen(hesaplanan) değerler Pinout Configiration sayfasındaki clock configiration bölümünde TIM1 bölümünde clock source Internal Clock olarak ayarlanarak altta çıkan bölümde hesaplanan değerler bulunarak yerlerine yazılır.
- İşlemcinin kendisinden kaynaklanan işlem nedeniyle değerler x-1, y-1 şeklinde girilir.
- 
