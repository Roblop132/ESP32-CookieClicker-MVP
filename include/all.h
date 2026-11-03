
#include <Arduino.h>
#include <TFT_eSPI.h>
#include <lvgl.h>

#define ROWS 4
#define COLS 4
#define SCREEN_WIDTH  160
#define SCREEN_HEIGHT 128
#define FLUSH_BUF_PIXELS (160 * 32)


// LVGL Объекты
extern lv_obj_t *scr;
extern lv_obj_t *money;
extern lv_obj_t *upgrade;
extern lv_obj_t *cunt;
extern lv_obj_t *cost;
extern lv_obj_t *pechenkaa;
extern lv_obj_t *uiline;
extern lv_obj_t *uiline2;
extern lv_obj_t *uiline3;
extern lv_obj_t *graphickmagazine;
extern lv_obj_t *cps;
extern lv_obj_t *info_cps;
extern lv_obj_t *news;


// Дисплей
extern TFT_eSPI tft;


LV_IMAGE_DECLARE(pechenka);
LV_IMAGE_DECLARE(babushka);
LV_IMAGE_DECLARE(cursor);
LV_IMAGE_DECLARE(farm);
LV_IMAGE_DECLARE(mine);
LV_IMAGE_DECLARE(fabric);
LV_IMAGE_DECLARE(xram);
LV_IMAGE_DECLARE(temple);
LV_IMAGE_DECLARE(magicktower);

// Игровые переменные
extern long double monkey;
extern long double clickPoWER;
extern long double upgradeCostCursor;
extern long double upgradeCostBabushka;
extern long double upgradeCostFarm;
extern long double upgradeCostMine;
extern long double upgradeCostFabric;
extern long double upgradeCostBank;
extern long double upgradeCostTemple;
extern long double upgradeCostWizard;
extern long double cpss;
extern byte count_steps;
extern byte screen_steps;
extern byte last_processed_screen; 

// Счетчики построек
extern unsigned int farm_count;
extern unsigned int cursor_count;
extern unsigned int babushka_count;
extern unsigned int mine_count;
extern unsigned int fabric_count;
extern unsigned int bank_count;
extern unsigned int temple_count;
extern unsigned int wizard_count;

extern long double cursor_cps;
extern long double babushka_cps;
extern long double farm_cps;
extern long double mine_cps;
extern long double fabric_cps;
extern long double bank_cps;
extern long double temple_cps;
extern long double wizard_cps;

// Тайминги
extern unsigned long previousMillis;
extern const long interval;
extern unsigned long currentMillis;

// Клавиатура
extern char lastKey;
extern bool isKeyPressed;
extern byte rowpins[ROWS];
extern byte colpins[COLS];
extern char keymap[ROWS][COLS];
extern char key;

// Прототипы функций
void update_cps_label(lv_obj_t * money_obj, long double gold);
void my_disp_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map);
void tft_init();
void autoclick();
void update_cursor_cost_label(lv_obj_t * cost_obj, long double cost);
void update_score_label(lv_obj_t * money_obj, long double gold);
void keys_fun();
char matrixscan();
void shop_ui();
void run_complex_pulse(lv_obj_t * obj);
void set_scale_cb(void * var, int32_t val);
void set_rotation_cb(void * var, int32_t val);
void update_cps_magazine_label(lv_obj_t * money_obj, long double cps);
void check_and_switch_screen();
void load_screen_1();
void load_screen_2();

uint32_t tick_cb(void);


