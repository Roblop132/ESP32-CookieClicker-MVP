#include <Arduino.h>
#include <TFT_eSPI.h>
#include <lvgl.h>
#include <all.h>

lv_obj_t *scr = NULL;
lv_obj_t *money = NULL;
lv_obj_t *upgrade = NULL;
lv_obj_t *cunt = NULL;
lv_obj_t *cost = NULL;
lv_obj_t *pechenkaa = NULL;
lv_obj_t *uiline = NULL;
lv_obj_t *uiline2 = NULL;
lv_obj_t *uiline3 = NULL;
lv_obj_t *graphickmagazine = NULL;
lv_obj_t *cps = NULL;
lv_obj_t *info_cps = NULL;
lv_obj_t *news = NULL;

 void set_scale_cb(void * var, int32_t val) { 
    lv_image_set_scale((lv_obj_t *)var, val); 
}

 void set_rotation_cb(void * var, int32_t val) {
    lv_image_set_rotation((lv_obj_t *)var, val);
}


TFT_eSPI tft = TFT_eSPI();

uint16_t dma_buffer[FLUSH_BUF_PIXELS];
 uint32_t tick_cb() { 
    return millis();
 }

long double monkey = 0;
long double clickPoWER = 1;
long double upgradeCostCursor = 10;
long double upgradeCostBabushka = 100;
long double upgradeCostFarm = 1100;
long double upgradeCostMine = 12000;
long double upgradeCostFabric = 130000;
long double upgradeCostBank = 1400000;
long double upgradeCostTemple = 20000000;
long double upgradeCostWizard = 330000000;
long double cpss = 0;

byte last_processed_screen = 0; 

byte count_steps = 1;
byte screen_steps = 1;

unsigned int farm_count = 0;
unsigned int cursor_count = 0;
unsigned int babushka_count = 0;
unsigned int mine_count = 0;
unsigned int fabric_count = 0;
unsigned int bank_count = 0;
unsigned int temple_count = 0;
unsigned int wizard_count = 0;

long double cursor_cps = 0.1;
long double babushka_cps = 1;
long double farm_cps = 8;
long double mine_cps = 47;
long double fabric_cps = 260;
long double bank_cps = 1400;
long double temple_cps = 7800;
long double wizard_cps = 44000;

unsigned long previousMillis = 0;
const long interval = 100; 
unsigned long currentMillis = 0;

char lastKey = 0;
bool isKeyPressed = false;
byte rowpins[ROWS] = {13, 19, 22, 17};
byte colpins[COLS] = {27, 26, 25, 14};
char keymap[ROWS][COLS] = {
    {'1', '2', '3', '4'},
    {'5', '6', '7', '8'},
    {'9', 'a', 'b', 'c'},
    {'d', 'e', 'f', 'g'},
};
char key = 0;


void setup() {
        tft_init ();
        scr = lv_screen_active();
}

void loop() {
    lv_timer_handler(); // Обработка задач LVGL
    currentMillis = millis();
    
 key = matrixscan();
if (key != 0){
 keys_fun();
}

check_and_switch_screen();

 autoclick();

 if (screen_steps == 1){
 shop_ui();
 update_score_label(money, monkey);
 update_cps_label(cps, cpss);
 }
   
delay (5);

    
    
}


//Список всех зданий и их базовый доход

//• Курсор (Cursor) — Базовая цена: 15 печенек | Базовый доход: 0.1 печ/с
//• Бабуля (Grandma) — Базовая цена: 100 печенек | Базовый доход: 1 печ/с
//• Ферма (Farm) — Базовая цена: 1,100 печенек | Базовый доход: 8 печ/с
//• Шахта (Mine) — Базовая цена: 12,000 печенек | Базовый доход: 47 печ/с
//• Фабрика (Factory) — Базовая цена: 130,000 печенек | Базовый доход: 260 печ/с
//• Банк (Bank) — Базовая цена: 1.4 млн печенек | Базовый доход: 1,400 печ/с
//• Храм (Temple) — Базовая цена: 20 млн печенек | Базовый доход: 7,800 печ/с
//• Башня волшебников (Wizard Tower) — Базовая цена: 330 млн печенек | Базовый доход: 44,000 печ/с
//• Космический корабль (Shipment) — Базовая цена: 5.1 млрд печенек | Базовый доход: 260,000 печ/с
//• Алхимическая лаборатория (Alchemy Lab) — Базовая цена: 75 млрд печенек | Базовый доход: 1.6 млн печ/с
//• Портал (Portal) — Базовая цена: 1 триллион печенек | Базовый доход: 10 млн печ/с
//• Машина времени (Time Machine) — Базовая цена: 14 триллионов печенек | Базовый доход: 65 млн печ/с
//• Конденсатор антиматерии (Antimatter Condenser) — Базовая цена: 170 триллионов печенек | Базовый доход: 430 млн печ/с
//• Призма (Prism) — Базовая цена: 2.1 квадриллиона печенек | Базовый доход: 2.9 миллиарда печ/с
//• Финансовый центр (Chancemaker) — Базовая цена: 26 квадриллионов печенек | Базовый доход: 21 миллиард печ/с
//• Фрактал (Fractal Engine) — Базовая цена: 310 квадриллионов печенек | Базовый доход: 150 миллиардов печ/с
//• Консоль JavaScript (Javascript Console) — Базовая цена: 3.9 квинтиллиона печенек | Базовый доход: 1.1 триллиона печ/с
//• Процессор Идл (Idleverse) — Базовая цена: 50 квинтиллионов печенек | Базовый доход: 8.3 триллиона печ/с
//• Крона Кортекс (Cortex Baker) — Базовая цена: 560 квинтиллионов печенек | Базовый доход: 64 триллиона печ/с
//• Вы (You) — Базовая цена: 540 септиллионов печенья | Базовый доход: 510 триллионов печ/с