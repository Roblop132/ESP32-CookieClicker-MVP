#include "all.h"

void autoclick () {
    // Проверяем, прошел ли хотя бы один интервал в 100 мс
    if (currentMillis - previousMillis >= interval) {
        
        // ТОЧНЫЙ РАСЧЕТ: сколько ИМЕННО интервалов по 100 мс упустил процессор
        unsigned long passed_intervals = (currentMillis - previousMillis) / interval;
        
        // Двигаем таймер строго на количество обработанных интервалов (как и ваш previousMillis += interval)
        previousMillis += passed_intervals * interval; 
        
        static unsigned long long sub_money = 0; // копейки

        // Считаем чистый доход за ОДИН интервал в 100 мс
        unsigned long long income_per_interval = 0;

        income_per_interval += (unsigned long long)cursor_count * 1;

        income_per_interval += (unsigned long long)babushka_count * 10;

        income_per_interval += (unsigned long long)farm_count * 80;

        income_per_interval += (unsigned long long)mine_count * 470;

        income_per_interval += (unsigned long long)fabric_count * 2600;

        income_per_interval += (unsigned long long)bank_count * 14000;

        income_per_interval += (unsigned long long)temple_count * 78000; 

        income_per_interval += (unsigned long long)wizard_count * 440000;

        // УМНОЖАЕМ доход на количество пропущенных интервалов.
        // Если процессор завис на 300 мс,passed_intervals будет равен 3. 
        // Мы получим доход ровно за 3 шага мгновенно, без циклов!
        sub_money += income_per_interval * passed_intervals;

        // Переводим копейки в основные монеты
        if (sub_money >= 100) {
            monkey += (long double)(sub_money / 100); 
            sub_money %= 100;          
        }
    }
}
