# Penggaris Ultrasonik

![Penggaris Ultrasonik](https://github.com/adioperwira/PenggarisUltrasonik/assets/147690354/ad195b71-4c34-4d02-8f3f-552256833b5a)

Penggaris Ultrasonik adalah sebuah Gadget yang digunakan untuk mengukur jarak dari satu titik ke titik lainnya dengan menggunakan sensor Ultrasonik HC-SR04, Microcontroller ( Arduino Uno ) dan  LCD 16 X 2 I2C.

# Fitur

![Fitur 2 Line](https://github.com/adioperwira/PenggarisUltrasonik/assets/147690354/b766e102-483c-42d0-8f9a-2bdfa682e2fa)

Penggaris Ultrasonik memiliki Fitur sebagai berikut :
1. Sensor HC-SR04 mampu menghitung jarak hingga 4 meter
2. LCD 16 X 2 menampilkan Data jarak secara Kontinu
3. LCD 16 X 2 mampu menyimpan data dan menampilkan data tersebut pada line kedua untuk kebutuhan rekap data oleh operator

# Alat dan Bahan

Untuk mengerjakan project ini, dibutuhkan alat & bahan sebagai berikut :
1. Microcontroller ( Arduino Uno )
2. Sensor Ultrasonik HC SR-04
3. LCD Display 16 X 2 dengan module I2C
4. Push Button Tactile
5. Baterai 18650 2 pcs beserta housingnya
6. Breadboard
7. Kabel Jumper

# Wiring Diagram

![Wiring Diagram](https://github.com/adioperwira/PenggarisUltrasonik/assets/147690354/3379fcf0-672b-4165-b2bc-806ff9bac378)

Wiring Diagram dengan ketentuan sebagai berikut :

1. Trigger Pin sensor Ultrasonik  -> Pin 2 Arduino
2. Echo Pin sensor Ultrasonik -> Pin 3 Arduino
3. Save Button -> Pin 4 Arduino
4. Pin SCL & SDA LCD Screen terhubung pada pin SCL & SDA Arduino

# Petunjuk Penggunaan

Penggaris Ultrasonik digunakan dengan cara :
1. Beri sumber Power pada Arduino dengan cara menghubungkan kabel Jack 2.1 mm Battery ke Arduino
2. Penggaris Ultrasonik akan otomatis menyala. Silahkan tunggu proses booting.
3.  Arahkan ke objek yang akan diukur jaraknya dan line 1 pada LCD screen akan menghitung jarak secara kontinu setiap 500 millisecond.
4.  Tekan tombol Push Button Save jika ingin menampilkan data pada line kedua LCD Screen

