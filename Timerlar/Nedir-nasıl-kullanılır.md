# Timer'lar nedir?
- Genel bir açıklama gerekirse dış interruplar yerine belli bir saniye sonrasında kendi kendine interrup eden bir kesici gibi düşünebiliriz.
- ioc dosyasında Clock configiration bölümünde TM1 üzerinden istediğimiz hz değerlerini ayarladıktan sonra aşağıdaki görseldeki gibi bir hesaplama yapılır
- ![clock hesabı](https://github.com/IibrahimEren/STM32_ders_notlari/assets/87008174/1edd09e8-95a4-4915-aae6-8a23cb885fc2)
- Burada gösterilen(hesaplanan) değerler Pinout Configiration sayfasındaki clock configiration bölümünde TIM1 bölümünde clock source Internal Clock olarak ayarlanarak altta çıkan bölümde hesaplanan değerler bulunarak yerlerine yazılır.
- İşlemcinin kendisinden kaynaklanan işlem nedeniyle değerler x-1, y-1 şeklinde girilir.
- Sonrasında NVIC SETTİNGS bölümüne geçip TIM1 capture compare interrrup  özelliğini aktif ediyoruz.
# Main.c içerisi
- Her şeyden önce bu timer'ın başlatılması lazım. Keyfe göre bir tuşa basıldığında ya da kart aktif olduğu an başlasın diye de ayarlanabilir.
- **_it.c** dosyasında seçtiğimiz timer'ın ilgili olduğu fonksiyonu bulup **ctrl+sağ** tık yaparak _hal_tim dosyasına gidiyoruz. Buradan da *HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);* fonksiyonunu alıyoruz
- Sonrasında bu fonksiyonu main dosyasının iççerisinde bize sunulan bölgeye yapıştırarak (kişisel olarak user code 4 bölümünü tercih ettik) içerisine işlenmesini istediğimiz kodu yazıyoruz
