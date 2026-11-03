  #include <all.h>  

    void tft_init (){
    tft.init();
    tft.initDMA();
    tft.setRotation(3);

    lv_init();
    lv_tick_set_cb(tick_cb);

    #define DRAW_BUF_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT / 2 * (LV_COLOR_DEPTH / 8))
    static uint8_t *draw_buf = (uint8_t *)heap_caps_malloc(DRAW_BUF_SIZE, MALLOC_CAP_DMA | MALLOC_CAP_8BIT);
    if (!draw_buf) {
        Serial.begin(115200);
        Serial.println("No DMA RAM");
        while (1);
    }

    lv_display_t *disp = lv_display_create(SCREEN_WIDTH, SCREEN_HEIGHT);
    lv_display_set_flush_cb(disp, my_disp_flush);
    lv_display_set_buffers(disp, draw_buf, NULL, DRAW_BUF_SIZE, LV_DISPLAY_RENDER_MODE_PARTIAL);
    lv_display_set_color_format(disp, LV_COLOR_FORMAT_RGB565); 

    // Настройка пинов
    for (byte r = 0; r < ROWS; r++) {
        pinMode(rowpins[r], OUTPUT);
        digitalWrite(rowpins[r], HIGH);
    }
    for (byte c = 0; c < COLS; c++) {
        pinMode(colpins[c], INPUT_PULLUP);
    }
}