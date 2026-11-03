
#include "all.h"


void shop_ui() {

    if (screen_steps == 1){
if (count_steps == 1){
    lv_label_set_text_fmt(cunt, "Cursors:\n%ld", cursor_count);
   update_cps_magazine_label (info_cps, cursor_cps);
    update_cursor_cost_label(cost, upgradeCostCursor);

    //Red/blue cursor
            if (monkey < upgradeCostCursor){
        lv_obj_set_style_text_color(cost, lv_color_make(255, 0, 0), LV_PART_MAIN);
    } else {
        lv_obj_set_style_text_color(cost, lv_color_make(0, 255, 0), LV_PART_MAIN);
    }

    lv_image_set_src(graphickmagazine, &cursor);

} else if (count_steps == 2) {
lv_label_set_text_fmt(cunt, "Babushka:\n%ld", babushka_count);
update_cps_magazine_label (info_cps, babushka_cps);
update_cursor_cost_label(cost, upgradeCostBabushka);

//Red/blue babushka
        if (monkey < upgradeCostBabushka){
        lv_obj_set_style_text_color(cost, lv_color_make(255, 0, 0), LV_PART_MAIN);
    } else {
        lv_obj_set_style_text_color(cost, lv_color_make(0, 255, 0), LV_PART_MAIN);
    }

    lv_image_set_src(graphickmagazine, &babushka);



} else if (count_steps == 3) {
lv_label_set_text_fmt(cunt, "Farm:\n%ld", farm_count);
update_cps_magazine_label (info_cps, farm_cps);
update_cursor_cost_label(cost, upgradeCostFarm);


//Red/blue farm
        if (monkey < upgradeCostFarm){
        lv_obj_set_style_text_color(cost, lv_color_make(255, 0, 0), LV_PART_MAIN);
    } else {
        lv_obj_set_style_text_color(cost, lv_color_make(0, 255, 0), LV_PART_MAIN);
    } 

    lv_image_set_src(graphickmagazine, &farm);

} else if (count_steps == 4) {
lv_label_set_text_fmt(cunt, "Mine:\n%ld", mine_count);
update_cps_magazine_label (info_cps, mine_cps);
update_cursor_cost_label(cost, upgradeCostMine);

//Red/blue mine
        if (monkey < upgradeCostMine){
        lv_obj_set_style_text_color(cost, lv_color_make(255, 0, 0), LV_PART_MAIN);
    } else {
        lv_obj_set_style_text_color(cost, lv_color_make(0, 255, 0), LV_PART_MAIN);
}

lv_image_set_src(graphickmagazine, &mine);

} else if (count_steps == 5) {
lv_label_set_text_fmt(cunt, "Fabric:\n%ld", fabric_count);
update_cps_magazine_label (info_cps, fabric_cps);
update_cursor_cost_label(cost, upgradeCostFabric);

//Red/blue fabric
        if (monkey < upgradeCostFabric){
        lv_obj_set_style_text_color(cost, lv_color_make(255, 0, 0), LV_PART_MAIN);
    } else {
        lv_obj_set_style_text_color(cost, lv_color_make(0, 255, 0), LV_PART_MAIN);
    } 

    lv_image_set_src(graphickmagazine, &fabric);

} else if (count_steps == 6) {
lv_label_set_text_fmt(cunt, "Bank:\n%ld", bank_count);
update_cps_magazine_label (info_cps, bank_cps);
update_cursor_cost_label(cost, upgradeCostBank);

//Red/blue bank
        if (monkey < upgradeCostBank){
        lv_obj_set_style_text_color(cost, lv_color_make(255, 0, 0), LV_PART_MAIN);
    } else {
        lv_obj_set_style_text_color(cost, lv_color_make(0, 255, 0), LV_PART_MAIN);
    } 

    lv_image_set_src(graphickmagazine, &xram);

} else if (count_steps == 7) {
lv_label_set_text_fmt(cunt, "Temple:\n%ld", temple_count);
update_cps_magazine_label (info_cps, temple_cps);
update_cursor_cost_label(cost, upgradeCostTemple);

//Red/blue temple
        if (monkey < upgradeCostTemple){
        lv_obj_set_style_text_color(cost, lv_color_make(255, 0, 0), LV_PART_MAIN);
    } else {
        lv_obj_set_style_text_color(cost, lv_color_make(0, 255, 0), LV_PART_MAIN);
    } 

    lv_image_set_src(graphickmagazine, &temple);

} else if (count_steps == 8) {
lv_label_set_text_fmt(cunt, "Wizard:\n%ld", wizard_count);
update_cps_magazine_label (info_cps, wizard_cps);
update_cursor_cost_label(cost, upgradeCostWizard);

//Red/blue wizard tower
        if (monkey < upgradeCostWizard){
        lv_obj_set_style_text_color(cost, lv_color_make(255, 0, 0), LV_PART_MAIN);
    } else {
        lv_obj_set_style_text_color(cost, lv_color_make(0, 255, 0), LV_PART_MAIN);
    } 

    lv_image_set_src(graphickmagazine, &magicktower);

    }
  }
}