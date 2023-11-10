#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int TrigPin = 2;      //pin trigger pada sensor ultrasonik
const int EchoPin = 3;      //pin echo pada sensor ultrasonik
const int savePin = 4;      // tombol save/simpan, berfungsi untuk menyimpan nilai jarak dari sensor ultrasonik

unsigned long previousMillis = 0;  // PreviousMillis dan interval berfungsi sebagai timer untuk menentukan
unsigned long interval = 500;      // pengambilan nilai jarak.

bool savingState = false;
float simpanJarak = 0.0;

LiquidCrystal_I2C lcd(0x27, 16, 2);   // 0x27 adalah address I2C pada LCD Screen, bisa jadi berbeda. namun yg paling umum adalah 0x27 dan 0x2F. 
                                      // untuk mencari nilai address silahkan googling cara menentukan address LCD screen I2C

void setup() {

  pinMode(TrigPin, OUTPUT);           // Deklarasi pin Trigger sebagai Output
  pinMode(EchoPin, INPUT);            // Deklarasi pin Echo sebagai Input
  pinMode(savePin, INPUT_PULLUP);     // Deklarasi pin tombol save sebagai Input Pullup, Nilai HIGH saat Open dan nilai Low saat Close/dipencet

  lcd.init();                         // Inisialisasi LCD Screen
  lcd.backlight();                    // Perintah menyalakan backlight LCD

  lcd.setCursor(0, 0);                // Dari Line 26 hingga Lin 39 Ini adalah opening saat gadget dinyalakan, silahkan dihapus jika terlalu lama
  lcd.print("Selamat Datang ");
  delay(2000);
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 0);
  lcd.print("Jangan Lupa");
  lcd.setCursor(0, 1);
  lcd.print("Like & Subscribe");
  delay(2000);
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");

  lcd.setCursor(0,0);
  lcd.print("Jarak: ");           // Print "Jarak :" pada LCD screen di koordinat (0,0)

}

void loop() {

int tombolSave = digitalRead(savePin);

unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {         // Timer pengambilan data jarak
    previousMillis = currentMillis;
    float jarak = fungsiJarak();                            // Pengambilan nilai jarak dan disimpan dalam variabel "jarak"

    lcd.setCursor(7, 0);                                    // Print nilai jarak pada LCD Screen
    lcd.print("     ");
    lcd.setCursor(7, 0);
    lcd.print(jarak);
    lcd.setCursor(14, 0);
    lcd.print("cm");

    if (savingState) {                      // Kondisi ini akan aktif jika tombol Save ditekan, menyimpan jarak kedalam variabel
      simpanJarak = jarak;                  // simpanJarak serta mengembalikan savingState menjadi False
      savingState = false;
    }
  }

  if (tombolSave == LOW) {                  // jika tombol save ditekan, maka saving state akan berubah dari false menjadi true
    savingState = true;

  }
    if (savingState) {                      // Print nilai variabel simpanJarak dan menampilaknnya pada LCD screen
    lcd.setCursor(0, 1);
    lcd.print("Saved: ");
    lcd.print(simpanJarak);
    lcd.setCursor(14, 1);
    lcd.print("cm");
  }
}

float fungsiJarak() {                       // Fungsi untuk menghitung Jarak dengan menggunakan sensor Ultrasonik
  
  digitalWrite(TrigPin, HIGH);              
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  long durasi = pulseIn(EchoPin, HIGH);     
  float jarak = durasi * 0.034 / 2;
  return jarak;
}