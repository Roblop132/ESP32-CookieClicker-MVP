#include <all.h>

void check_and_switch_screen() {
    // Если номер экрана не менялся, ничего не делаем и выходим
    if (screen_steps == last_processed_screen) return;

    // Если изменился — обновляем состояние и один раз собираем новый экран
    last_processed_screen = screen_steps;

    switch (screen_steps) {
        case 1:
            load_screen_1();
            break;
        case 2:
            load_screen_2();
            break;
        default:
            break;
    }
}




void load_screen_1 () {
lv_obj_clean(scr);


    // Создание элементов интерфейса LVGL
    lv_obj_set_style_bg_color(scr, lv_color_make(91, 110, 225), LV_PART_MAIN);

        // Cookies per Second
    cps = lv_label_create(scr);
    lv_obj_set_style_text_font(cps, &lv_font_unscii_8, 0);
    lv_obj_align(cps, LV_ALIGN_BOTTOM_LEFT, 0, -5);
    lv_obj_set_width(cps, 80);
    lv_obj_set_style_text_align(cps, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_text_color(cps, lv_color_make(255, 255, 255), LV_PART_MAIN);

    // Баланс (Сверху слева)
    money = lv_label_create(scr);
    lv_obj_set_style_text_font(money, &lv_font_unscii_8, 0);
    lv_obj_align(money, LV_ALIGN_TOP_LEFT, 0, 10);
    lv_obj_set_width(money, 80);
    lv_obj_set_style_text_align(money, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_text_color(money, lv_color_make(255, 255, 255), LV_PART_MAIN);

    // Цена апгрейда (Сверху справа)
    cost = lv_label_create(scr);
    lv_obj_set_style_text_font(cost, &lv_font_unscii_8, 0);
    lv_obj_align(cost, LV_ALIGN_TOP_RIGHT, 0, 10);
    lv_obj_set_width(cost, 80);
    lv_obj_set_style_text_align(cost, LV_TEXT_ALIGN_CENTER, 0);

    // Количество автокликеров
    cunt = lv_label_create(scr);
    lv_obj_set_style_text_font(cunt, &lv_font_unscii_8, 0);
    lv_obj_set_width(cunt, 80);
    lv_obj_set_style_text_align(cunt, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align(cunt, LV_ALIGN_BOTTOM_RIGHT, 0, -40);
    lv_obj_set_style_text_color(cunt, lv_color_make(255, 255, 255), LV_PART_MAIN);
    

    // Сила клика
    info_cps = lv_label_create(scr);
    lv_obj_set_style_text_font(info_cps, &lv_font_unscii_8, 0);
    lv_obj_set_width(info_cps, 80);
    lv_obj_set_style_text_align(info_cps, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align(info_cps, LV_ALIGN_BOTTOM_RIGHT, 0, -5);
    lv_obj_set_style_text_color(info_cps, lv_color_make(255, 255, 255), LV_PART_MAIN);

    uiline = lv_obj_create(scr);
    lv_obj_set_size(uiline, 2, 128);
    lv_obj_align(uiline, LV_ALIGN_CENTER, 0, 0);

    lv_obj_set_style_bg_color(uiline, lv_color_make(198, 133, 37), 0); 
    lv_obj_set_style_bg_opa(uiline, LV_OPA_COVER, 0);             // Полная непрозрачность
    lv_obj_set_style_radius(uiline, 0, 0);                        // 0 делает углы острыми (прямыми)
    lv_obj_set_style_border_width(uiline, 0, 0);                  // Убираем обводку (если не нужна)

        uiline2 = lv_obj_create(scr);
    lv_obj_set_size(uiline2, 80, 2);
    lv_obj_align(uiline2, LV_ALIGN_CENTER, 40, 0);

        lv_obj_set_style_bg_color(uiline2, lv_color_make(198, 133, 37), 0); 
    lv_obj_set_style_bg_opa(uiline2, LV_OPA_COVER, 0);             // Полная непрозрачность
    lv_obj_set_style_radius(uiline2, 0, 0);                        // 0 делает углы острыми (прямыми)
    lv_obj_set_style_border_width(uiline2, 0, 0);                  // Убираем обводку (если не нужна)

            uiline3 = lv_obj_create(scr);
    lv_obj_set_size(uiline3, 80, 2);
    lv_obj_align(uiline3, LV_ALIGN_CENTER, 40, 30);

        lv_obj_set_style_bg_color(uiline3, lv_color_make(198, 133, 37), 0); 
    lv_obj_set_style_bg_opa(uiline3, LV_OPA_COVER, 0);             // Полная непрозрачность
    lv_obj_set_style_radius(uiline3, 0, 0);                        // 0 делает углы острыми (прямыми)
    lv_obj_set_style_border_width(uiline3, 0, 0);                  // Убираем обводку (если не нужна)

    pechenkaa = lv_image_create(scr);
    lv_image_set_src(pechenkaa, &pechenka);
    lv_obj_align(pechenkaa, LV_ALIGN_CENTER, -40, 0);

    graphickmagazine = lv_image_create(scr);
    lv_image_set_src(graphickmagazine, &cursor);
    lv_obj_align(graphickmagazine, LV_ALIGN_CENTER, 40, -17);

       static lv_anim_t a_rotate;
    lv_anim_init(&a_rotate);
    lv_anim_set_var(&a_rotate, pechenkaa);
    lv_anim_set_exec_cb(&a_rotate, set_rotation_cb);
    lv_anim_set_values(&a_rotate, 0, 3600); // Вращаем от 0 до 360 градусов (3600)
    lv_anim_set_duration(&a_rotate, 10000);  // Скорость: 10000 мс (10 секунд) на один полный оборот. Сделай больше, если нужно еще медленнее
    lv_anim_set_path_cb(&a_rotate, lv_anim_path_linear); // Линейный путь, чтобы вращение шло равномерно, без рывков и пауз
    lv_anim_set_repeat_count(&a_rotate, LV_ANIM_REPEAT_INFINITE); // Крутить бесконечно
    lv_anim_start(&a_rotate);

    // Первичный вывод текста на экран;
    previousMillis = millis(); 
}


void load_screen_2() {
lv_anim_delete(pechenkaa, NULL);
lv_obj_clean(scr);


        // Создание элементов интерфейса LVGL
    lv_obj_set_style_bg_color(scr, lv_color_make(26, 26, 26), LV_PART_MAIN);

        // Новости
    news = lv_label_create(scr);
    lv_obj_set_style_text_font(news, &lv_font_unscii_8, 0);
    lv_obj_set_width(news, 150);
    lv_obj_set_style_text_align(news, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align(news, LV_ALIGN_TOP_MID, 0, 5);
    lv_obj_set_style_text_color(news, lv_color_make(255, 255, 255), LV_PART_MAIN);
    lv_label_set_text(news, "News:\n\n!!!COOKIES!!!\n\n!!!COOKIES!!!\n\n!!!COOKIES!!!\n\n!!!COOKIES!!!\n\n!!!COOKIES!!!\n\n!!!COOKIES!!!");

}