İnterrup ayarlanması için öncelikle ioc dosyası içerisinde buton olarak ayarlayacağımız butonu **GPIO_EXTI0** olarak ayarlamammız gerekiyor --> Externalinput --> Dış kesme
SOnrasında bu interrrup'ı aktif edebilmemiz için **System Core** bölümünden NVIC sekmesini açarak ''EXTI line0'' seçimini aktif ediyoruz. Böylece interrup'ları aktif etmiş oluyoruz.
