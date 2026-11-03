#include <all.h>



void my_disp_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map) {
    uint32_t w = lv_area_get_width(area);
    uint32_t h = lv_area_get_height(area);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.setSwapBytes(true);
    tft.pushPixelsDMA((uint16_t *)px_map, w * h);
    tft.endWrite();

    while (tft.dmaBusy()) { }
    lv_display_flush_ready(disp);
}