# Servo Motorlar

- Servo motorların kontrolü için PWM sinyalleri kullanıldığından bu sefer (servonun datasheet’ine göre) pwm sinyallerini kendimiz ayarlamamız gerekiyor.
- Yaptığımız uygulamada 86Mh olarak ayarlanan timer’ımızı 50 hz olarak kullanmak istediğimizden  86.000.000/50 yaparak 1.680.000 değerine ulaştık ve de bunu 1000 ile bölerek 1680 değeri *parascaler* bölümüne yazdık.
- arr değerimzin yerini alacak yüzdelik değerleri datasheet üzerinden ms değerlerini duty cycle üzerinde hesaplayarak kod başlangıcına yazdık. (datasheet üzerinde daha anlamlı gelecek)
- Toplam periyodun içerisinde gerçekleşen duty cycle değerlerinin yüzdelik oranları gerekiyor →

| 90 derece için | 2ms pulse | 2/20 → %20 değerine denk geliyor |
| --- | --- | --- |
| 0 derece için  | 1.5 ms pulse | 1.5/20 → %7.5 değerine denk geliyor |
| -90 derece için | 1 ms pulse | 1/20 → %5 değerinde denk geliyor |

### Sg90 servo motorları için compare değerleri
Kullandığımız çoğu ürün replika olduğu için burada yazılan duty cycledeğerleri datasheet ile uyumlu olmayabilir. asıl değerlerini öğrenmek için kendi denemelerimizi yapmamız gerekir

```c
/*
   * 2/20=%10'luk duty cycle
   * arr değeri 1000
   *
   * 100/1000 = 10 -> %10'luk duty cycle değeri elde edebilmek için compare deeğerini 100 vermemiz gerekiyor
   *   __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,100);
   *
   * 150/1000 = %15
   *   __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,150);
   *
   * 200/1000 = %20
   *   __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,200);
   *
   *   pozisyon   0		1.5 ms		%7.5 duty cyycle	compare değeri 75
   *   pozisyon +90		2.0 ms		%10 duty cycle		compare değeri 100
   *   pozisyon	-90		1.0 ms		%5 duty cycle 		compare değeri 50
   *
   *
   */
```
