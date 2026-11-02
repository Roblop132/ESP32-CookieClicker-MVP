# ESP32-CookieClicker-MVP


MVP port of Cookie Clicker to ESP32-WROOM-32 with an ST7735 greentab2 screen and a 4x4 tactile matrix keypad


![](pechenka.png)

____
## Для запуска проекта нужны:

- ESP32 WROOM32 или ему подобные микроконтроллеры.
- ST7735 GREENTAB_2 RGB TFT LCD 160x128
- Матричная клавиатура 16*16
- Немного проводов

## Pinout:

### ST7735

|                | Pins         |
| ------------- |:-------------:|
| MOSI          | 23            |
| SCLK          | 18            |
| CS            | 5      |
| DS            | 2      |
| RES           | 4     |
| BL            | 21      |


### Keypad

|               | Pins         |
| ------------- |:-------------:|
| ROW 1          | 13            |
| ROW 2          | 19            |
| ROW 3            | 22      |
| ROW 4            | 17      |
| COL 1           | 27     |
| COL 2            | 26      |
| COL 3            | 25      |
| COL 4            | 14      |







