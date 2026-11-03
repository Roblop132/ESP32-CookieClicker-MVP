#include <all.h>




// Функция сканирования матричной клавиатуры
char matrixscan() {
    char currentKey = 0;

    for (byte r = 0; r < ROWS; r++) {
        digitalWrite(rowpins[r], LOW);
        for (byte c = 0; c < COLS; c++) {
            if (digitalRead(colpins[c]) == LOW) {
                delay(5); // Антидребезг
                if (digitalRead(colpins[c]) == LOW) {
                    currentKey = keymap[r][c];
                }
            }
        }
        digitalWrite(rowpins[r], HIGH);
    }
    
    if (currentKey != 0) {
        if (isKeyPressed && currentKey == lastKey) {
            return 0; // Игнорируем удержание
        }
        else {
            lastKey = currentKey;
            isKeyPressed = true;
            return currentKey; // Одиночный клик
        }
    } 
    else {
        isKeyPressed = false;
        lastKey = 0;
        return 0;
    }
}