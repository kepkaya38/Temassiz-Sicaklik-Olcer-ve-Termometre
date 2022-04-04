#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> //Oled Ekran Kütüphanesi
#include <Wire.h> //I2c Kütüphanesi
#include <Adafruit_MLX90614.h> //Sıcaklık Kütüphanesi

#define SCREEN_WIDTH 128 // OLED display genişlik
#define SCREEN_HEIGHT 64 // OLED display yükseklik
#define OLED_RESET    -1 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); 
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {  
  mlx.begin(); 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //OLED ekranımızı başlatıyoruz
  display.clearDisplay();
  display.display();

}

void loop() {
  display.clearDisplay(); //Ekranı Temizle
 
  display.setTextSize(1);                    
  display.setTextColor(WHITE);             
  display.setCursor(60,50);                
  display.println("TK & MO"); //Logomuzu yazdırıyoruz
   
  
  display.setTextSize(2);
  display.setCursor(50,17);
  display.println(mlx.readObjectTempC(),1); //Sıcaklığımızı yazdırıyoruz ve Santigrat cinsinden istedğimizi belirtiyoruz.
  
  display.setCursor(110,17);
  display.println("C"); //Santigrat işareti

  
  display.fillCircle(18, 55, 7, WHITE);  // İçi dolu daire çiz (x,y,radius,renk). X ve Y are kordinatları orta nokta

 
  display.drawRoundRect(16, 3, 5, 49, 2, WHITE);  // Yuvarlak çiz(x,y,width,height,radius,renk)
                                                  // Konumdan aşağıya doğru çeker
    // Cetvel adımı çizme
  for (int i = 6; i<=45; i=i+3){
    display.drawLine(21, i, 22, i, WHITE);  // Çizgi çizme (x0,y0,x1,y1,renk)
  }
  
  display.display();
  
  delay(2000); // Kaç sn içinde resetlensin

}
