#include <all.h>
#include <math.h>
#include <stdio.h>

// Оставлены только суффиксы из одной буквы. Начиная с индекса 5 (10^15), идет экспонента.
const char* const SUFFIXES[] = {
    "", "K", "M", "B", "T"
};
const int SUFFIXES_COUNT = sizeof(SUFFIXES) / sizeof(SUFFIXES[0]);

// Вспомогательная функция для безопасного разбиения числа на мантиссу и индекс суффикса
void get_number_tier(long double value, double *short_val, int *tier) {
    if (value < 1000.0) {
        *short_val = (double)value;
        *tier = 0;
        return;
    }
    
    int t = (int)(floor(log10((double)value)) / 3);
    
    // Если число вылетает за пределы одиночных суффиксов (>= 10^15), 
    // сигнализируем об этом, возвращая tier равный SUFFIXES_COUNT
    if (t >= SUFFIXES_COUNT) {
        *short_val = (double)value;
        *tier = SUFFIXES_COUNT;
        return;
    }
    
    double s_val = (double)(value / pow(10.0, t * 3));
    
    if (s_val >= 1000.0) {
        t++;
        if (t >= SUFFIXES_COUNT) {
            *short_val = (double)value;
            *tier = SUFFIXES_COUNT;
            return;
        }
        s_val /= 1000.0;
    }
    
    *short_val = s_val;
    *tier = t;
}

// Общая логика форматирования для компактного вывода (буквы до Т, далее eXX)
void format_compact_helper(char* buffer, size_t buffer_size, double short_val, int tier, long double original_value) {
    // Если вышли за пределы одиночных суффиксов (tier >= 5), переводим в экспоненту
    if (tier >= SUFFIXES_COUNT) {
        int exponent = (int)floor(log10((double)original_value));
        double mantissa = (double)(original_value / pow(10.0, exponent));
        
        if (mantissa >= 10.0) {
            mantissa /= 10.0;
            exponent += 1;
        }
        // Вывод вида 1.23e15 (всего 7 символов)
        snprintf(buffer, buffer_size, "%.2fe%d", mantissa, exponent);
        return;
    }

    // Если число с буквенным суффиксом (K, M, B, T)
    if (tier == 0) {
        snprintf(buffer, buffer_size, "%.0f", short_val); // Меньше 1000: просто целое
    } else {
        // Всегда 3 знака после запятой. Максимум: 100.000M (8 знаков)
        snprintf(buffer, buffer_size, "%.3f%s", short_val, SUFFIXES[tier]);
    }
}

// 1. Форматирование для COOKIE и COST
void format_standard_number(char* buffer, size_t buffer_size, long double value) {
    if (value >= 1.0e306 || isinf((double)value) || isnan((double)value)) {
        snprintf(buffer, buffer_size, "MAX");
        return;
    }

    if (value < 1000.0) {
        snprintf(buffer, buffer_size, "%.0f", (double)value);
        return;
    }

    double short_val;
    int tier;
    get_number_tier(value, &short_val, &tier);

    format_compact_helper(buffer, buffer_size, short_val, tier, value);
}

// 2. Форматирование для CpS
void format_cps_number(char* buffer, size_t buffer_size, long double value) {
    if (value >= 1.0e306 || isinf((double)value) || isnan((double)value)) {
        snprintf(buffer, buffer_size, "MAX");
        return;
    }

    if (value < 100.0) {
        snprintf(buffer, buffer_size, "%.1f", (double)value);
        return;
    }

    if (value < 1000.0) {
        snprintf(buffer, buffer_size, "%.0f", (double)value);
        return;
    }

    double short_val;
    int tier;
    get_number_tier(value, &short_val, &tier);

    format_compact_helper(buffer, buffer_size, short_val, tier, value);
}

// --- Интерфейсные функции подгрузки в LVGL ярлыки ---

void update_score_label(lv_obj_t * money_obj, long double gold) {
    char buf[32]; 
    format_standard_number(buf, sizeof(buf), gold);
    lv_label_set_text_fmt(money_obj, "Cookie:\n%s", buf);
}

void update_cursor_cost_label(lv_obj_t * cost_obj, long double cost) {
    char buf[32]; 
    format_standard_number(buf, sizeof(buf), cost);
    lv_label_set_text_fmt(cost_obj, "Cost:\n%s", buf);
}

void update_cps_label(lv_obj_t * money_obj, long double cps) {
    char buf[32]; 
    format_cps_number(buf, sizeof(buf), cps); 
    lv_label_set_text_fmt(money_obj, "Main CpS:\n%s", buf);
}

void update_cps_magazine_label(lv_obj_t * money_obj, long double cps) {
    char buf[32]; 
    format_cps_number(buf, sizeof(buf), cps); 
    lv_label_set_text_fmt(money_obj, "CpS:\n%s", buf);
}