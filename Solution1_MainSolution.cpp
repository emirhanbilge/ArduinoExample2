/*
        Crated by EBB (Emirhan Bilge Bulut) , All files (schematic , codes , documents) in my GitHub . Link : 

                1   2   3   4   5   6   7   
        0       x   x   x   x   x   x
        1               x   x
        2       x   x       x   x       x
        3           x   x   x   x       x                        _5_
        4               x   x       x   x                       |   |
        5           x   x       x   x   x                      6|_7_|4
        6       x   x   x           x   x                       |   |
        7               x   x   x                              1|_2_|3      Burada 7 segment displayimizde bacakları soyut olarak numaralandırdım.
        8       x   x   x   x   x   x   x                                 Normalde 5 pin altta 5 pin üstte 10 bacak bulunmaktadır fakat bunun 2si   
        9               x   x   x   x   x                                 GND ya da VCC , 1 tanesi de nokta şeklindedir fakat biz bunlara ihtiyaç 
        a       x   x   x   x   x       x                                 duymuyoruz. Yandaki tabloda counter değerlerine göre , 7 segment displayde
        b       x   x   x           x   x                                 hangilerinin yanması gerektiği gözükmekte.Biz yanması gereken bacakları  
        c       x   x           x   x   x                                 kontrol etmek yerine yanmadığı durumları kontrol etmemiz daha kolay olacaktır.
        d       x   x   x   x           x                                 Toplam 7 değerimiz olduğu için 7 adet çıkışta yanmaması gereken durumları 
        e       x   x       x   x   x   x                                 kontrol ederek 7 koşul ile bunu sağlayabiliriz. Bir diğer olumlu yanı ise 
        f       x               x   x   x                                 bazı durumlarda yanmaması gereken counter değerlerini bazen de yanması 
                                                                          gereken değerleri kontrol ederek en kısa yolu sağlayıp koşullarımızı 
                                                                          daha kısa yazaniliriz.

        Arduinoda 2. dijital pinden 8. dijital pine kadar olan sayılar sırasıyla 1 den 7ye kadardır yani :
        Arduino 2 = 7 Segmentte Numaralandırılmış 1'e , 
        Arduino 3 = 7 Segmentte Numaralandırılmış 2'ye , 
        .
        .
        .
        Arduino 8 = 7 Segmentte Numaralandırılmış 7'ye karşılık gelir. 

        !!!!!!
        !!!NOT : Benim 7 segment displayim Anot 7 Segment olduğu için Hıgh olarak kullandım eğer Katot ise Tüm Kodda Hıgh olan yerler LOW , LOW olanlar HIGH olmalıdır.  !!!       
        !!!!!!
*/
void setup()
{
    for (int j = 2; j < 9; j++)
    {
        pinMode(j, OUTPUT); // 7 segment için çıkışların sağlanması
    }
    pinMode(9, INPUT);     // Button çıkışı
    digitalWrite(8, HIGH); // Başlangıçta 0 gösterilmesi için
}

volatile boolean currentButtonValue = false; // Butonun şimdiki depğerini okuduğumuzda eşitlememiz için değişken
volatile boolean lastButtonValue = false;    // Butona basılı kaldığında değerin 1 kere değişmesi için eski değer ile kıyaslamamız gerekmekte , onun için bunu tutuyorum
static int i = 0;                            // 0 dan başlattığımız sayma sayımız
int GLOBAL_COUNTER = 1;                      // Saymanın ne aralıklarla olduğu belirleyen değişkenimiz

void clearDisplay() // Bu fonksyon 1 sayıdan diğer sayıya geçerken displayde yanan kısımları söndürmemizi sağlıyor tamamını Hıgh yaparak söndürüyoruz
{
    for (int j = 2; j < 9; j++)
    {
        digitalWrite(j, HIGH);
    }
}

void printNumber()
{
    if (i > 1 && i != 7 && i != 12) // Burada tablomuza göre 7 segmentte 7 ile numaralandırdığım kısmın yanmaması gereken kısımların tersini kontrol ederek yakar
    {
        digitalWrite(8, LOW);
    }
    if (i != 1 && i != 2 && i != 3 && i != 7 && i != 10 && i != 13) // Burada tablomuza göre 7 segmentte 6 ile numaralandırdığım kısmın yanmaması gereken kısımların tersini kontrol ederek yakar
    {
        digitalWrite(7, LOW);
    }
    if (i != 1 && i != 4 && i != 6 && i != 11 && i != 13) // Burada tablomuza göre 7 segmentte 5 ile numaralandırdığım kısmın yanmaması gereken kısımların tersini kontrol ederek yakar
    {
        digitalWrite(6, LOW);
    }
    if (i != 5 && i != 6 && i != 11 && i != 12 && i != 15) // Burada tablomuza göre 7 segmentte 4 ile numaralandırdığım kısmın yanmaması gereken kısımların tersini kontrol ederek yakar
    {
        digitalWrite(5, LOW);
    }
    if (i != 2 && i != 12 && i != 14 && i != 15) // Burada tablomuza göre 7 segmentte 3 ile numaralandırdığım kısmın yanmaması gereken kısımların tersini kontrol ederek yakar
    {
        digitalWrite(4, LOW);
    }
    if (i != 1 && i != 4 && i != 7 && i != 9 && i != 15) // Burada tablomuza göre 7 segmentte 2 ile numaralandırdığım kısmın yanmaması gereken kısımların tersini kontrol ederek yakar
    {
        digitalWrite(3, LOW);
    }
    if (i == 0 || i == 2 || i == 6 || i == 8 || i > 9) // Burada yukarıdaki ilk açıklamada bahsettiğim gibi illa yanmama durumunu değil yanma durumu daha kısaysa onu da kontrol edebiliriz.
    {
        digitalWrite(2, LOW);
    }
}

void loop()
{
    currentButtonValue = digitalRead(9);       // Button değerimiz okunur
    if (lastButtonValue != currentButtonValue) // Eğer butonun durumu değişmiş ise girecektir
    {
        if (digitalRead(9) == HIGH) // Butona basılmış ise yani HIGH konumundaysa
        {
            clearDisplay(); // 7 segment displayi temizle
            printNumber();  // satatic sayacımız i olduğundan herhangi bir değer yollamadan if elseleri çağırarak hangi sayı bastırılıcaksa onu sağlıyoruz
            // i = random(16)%16 ; // Random olarak gelmesini istiyorsak burayı açmamız yeterli allta ilk satırı yoruma almayı unutmayın
            i = (i += GLOBAL_COUNTER) % 16; // Global_counterda belirlenen artış sayısı kadar arttırıp mod 16 yaptırıyoruz overflow olmaması için
            delay(150);                     // Butondaki ani dalgalanmaları önlemek için koydum ama kaldırılabilir ya da düşürülebilir
        }
    }
    lastButtonValue = currentButtonValue; // Butonun basıldıktan sonra ya da geri çekildikten sonra işlem yapılıp yapılmadığını anlamak için geçmiş değer güncellenir
}