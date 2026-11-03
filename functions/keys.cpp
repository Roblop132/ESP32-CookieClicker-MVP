      
      #include <all.h>
      
      void keys_fun(){
      if (key == 'c' && count_steps <= 8){
        count_steps++;
    }

    if (key == 'g' && count_steps != 1 ){
    count_steps--;
    }

        if (key == '7' && screen_steps != 1){
        screen_steps--;
    }

        if (key == '8' && screen_steps <= 4){
        screen_steps++;
    }

    // Клик (Кнопка '6') -> Добавляем валюту
    if (key == '6') {
        monkey += clickPoWER;
      if (screen_steps == 1 && pechenkaa != NULL){
            lv_anim_t a_pulse;
            lv_anim_init(&a_pulse);
            lv_anim_set_var(&a_pulse, pechenkaa);
            lv_anim_set_exec_cb(&a_pulse, set_scale_cb);
            lv_anim_set_values(&a_pulse, 256, 300);
            lv_anim_set_duration(&a_pulse, 50);
            lv_anim_set_playback_duration(&a_pulse, 50);
            lv_anim_start(&a_pulse);
        }
    }

        if (key == '1') {
        monkey += 1000000000000;
       
    }

         if (key == '2') {
        monkey += 10000000;
       
    }


    // Покупка улучшения (Кнопка '4') -> Берем курсор
    if (key == '4') {
        
        if(screen_steps == 1){

        if(count_steps == 1){
            if (monkey >= upgradeCostCursor) {
            monkey -= upgradeCostCursor; 
            cursor_count++;             
            upgradeCostCursor = (upgradeCostCursor * 115) / 100; // Подорожание на 15%
            cpss += cursor_cps;
              
        }
      } else if (count_steps == 2) {
            if (monkey >= upgradeCostBabushka) {
            monkey -= upgradeCostBabushka; 
            babushka_count++;             
            upgradeCostBabushka = (upgradeCostBabushka * 115) / 100; // Подорожание на 15%
            cpss += babushka_cps;
      }
    } else if (count_steps == 3){
            if (monkey >= upgradeCostFarm) {
            monkey -= upgradeCostFarm; 
            farm_count++;             
            upgradeCostFarm = (upgradeCostFarm * 115) / 100; // Подорожание на 15%
            cpss += farm_cps;
    }
    } else if (count_steps == 4){
            if (monkey >= upgradeCostMine) {
            monkey -= upgradeCostMine; 
            mine_count++;             
            upgradeCostMine = (upgradeCostMine * 115) / 100; // Подорожание на 15%
            cpss += mine_cps;
    }
    }  else if (count_steps == 5){
            if (monkey >= upgradeCostFabric) {
            monkey -= upgradeCostFabric; 
            fabric_count++;             
            upgradeCostFabric = (upgradeCostFabric * 115) / 100; // Подорожание на 15%
            cpss += fabric_cps;
    }
    }  else if (count_steps == 6){
            if (monkey >= upgradeCostBank) {
            monkey -= upgradeCostBank; 
            bank_count++;             
            upgradeCostBank = (upgradeCostBank * 115) / 100; // Подорожание на 15%
            cpss += bank_cps;
    }
    } else if (count_steps == 7){
            if (monkey >= upgradeCostTemple) {
            monkey -= upgradeCostTemple; 
            temple_count++;             
            upgradeCostTemple = (upgradeCostTemple * 115) / 100; // Подорожание на 15%
            cpss += temple_cps;
    }
    } else if (count_steps == 8){
            if (monkey >= upgradeCostWizard) {
            monkey -= upgradeCostWizard; 
            wizard_count++;             
            upgradeCostWizard = (upgradeCostWizard * 115) / 100; // Подорожание на 15%
            cpss += wizard_cps;
}
      }
    }
  }
}