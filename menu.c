void menu(struct dll_node *node, struct tm tm, int height_monitor,int width_monitor, ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue,ALLEGRO_EVENT_QUEUE *queue1, ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *zstud,ALLEGRO_BITMAP *bitmap,ALLEGRO_VIDEO *studio,ALLEGRO_BITMAP *zsmutny,ALLEGRO_BITMAP *zpubli,ALLEGRO_BITMAP *zradosc,ALLEGRO_BITMAP *zstrach,ALLEGRO_BITMAP *ztele,ALLEGRO_BITMAP *zautor,ALLEGRO_BITMAP *zhub1,ALLEGRO_BITMAP *zja,ALLEGRO_BITMAP *zmilion,ALLEGRO_BITMAP *zmilion1,ALLEGRO_BITMAP *zhub,ALLEGRO_BITMAP *zman,ALLEGRO_BITMAP *zman1,ALLEGRO_BITMAP *zman2,ALLEGRO_BITMAP *znick,ALLEGRO_BITMAP *zmenu,ALLEGRO_BITMAP *ztlo1,ALLEGRO_BITMAP *ztlo,ALLEGRO_BITMAP *ztel,ALLEGRO_BITMAP *zpub,ALLEGRO_BITMAP *zpol, ALLEGRO_FONT *font0, ALLEGRO_FONT *font1,ALLEGRO_FONT *font2,ALLEGRO_FONT *font3,ALLEGRO_FONT *font4,ALLEGRO_FONT *font9, int TIME_GAME,ALLEGRO_SAMPLE *intro,ALLEGRO_SAMPLE *gra,ALLEGRO_SAMPLE *telefon,ALLEGRO_SAMPLE *publicznosc,ALLEGRO_SAMPLE *polowa,ALLEGRO_SAMPLE *pytanie,ALLEGRO_SAMPLE *zwycienstwo,ALLEGRO_SAMPLE *zle,ALLEGRO_SAMPLE *koniec,ALLEGRO_SAMPLE *kolo,ALLEGRO_SAMPLE *przycisk,ALLEGRO_SAMPLE_ID id1,ALLEGRO_SAMPLE_ID id2,ALLEGRO_SAMPLE_ID id3,ALLEGRO_SAMPLE_ID id4,ALLEGRO_SAMPLE_ID id5,ALLEGRO_SAMPLE_ID id6,ALLEGRO_SAMPLE_ID id7,ALLEGRO_SAMPLE_ID id8,ALLEGRO_SAMPLE_ID id9,ALLEGRO_SAMPLE_ID id10,ALLEGRO_SAMPLE_ID id11,char player_name[15]){


    al_clear_to_color(al_map_rgb(19, 34, 71));
    al_draw_bitmap(ztlo1,width_monitor*0.0001, height_monitor*0.0001,NULL);
    al_draw_bitmap(zhub,width_monitor*0.05,height_monitor*0.4,NULL);
    al_draw_bitmap(zman1,width_monitor*0.7,height_monitor*0.3,NULL);

    al_draw_textf(font0, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.35, ALLEGRO_ALIGN_CENTRE, "Nowa Gra");
    al_draw_textf(font0, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.5, ALLEGRO_ALIGN_CENTRE, "Ranking");
    al_draw_textf(font0, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.65, ALLEGRO_ALIGN_CENTRE, "Autorzy");
    al_draw_textf(font0, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.8, ALLEGRO_ALIGN_CENTRE, "Wyjscie");
    al_flip_display();

    while (1) {

        al_wait_for_event(queue, &event);


        switch (event.type) {

            case ALLEGRO_EVENT_KEY_DOWN:

                switch(event.keyboard.keycode){

                    case ALLEGRO_KEY_ESCAPE:

                        al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                        done(display);
                        break;

                }

                break;

            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:

                switch(event.mouse.button){

                    case 1:

                    //Nowa Gra
                    if(event.mouse.x > width_monitor*0.37 && event.mouse.x < width_monitor*0.63 && event.mouse.y > height_monitor *0.35 && event.mouse.y < height_monitor *0.45){
                        al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                        gracz(node, tm, height_monitor,width_monitor, event, queue ,queue1,display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, font0, font1, font2,font3,font4,font9, TIME_GAME,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);

                        break;


                    }

                    //Wyniki
                    if(event.mouse.x > width_monitor*0.41 && event.mouse.x < width_monitor*0.59 && event.mouse.y > height_monitor *0.5 && event.mouse.y < height_monitor *0.6){
                        al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                        ranking(node, tm, height_monitor,width_monitor, event, queue ,queue1,display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, font0, font1, font2,font3,font4,font9, TIME_GAME,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
                        break;


                    }

                    //Autorzy
                    if(event.mouse.x > width_monitor*0.40 && event.mouse.x < width_monitor*0.6 && event.mouse.y > height_monitor *0.65 && event.mouse.y < height_monitor *0.75){
                        al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                        al_clear_to_color(al_map_rgb(19, 34, 71));
                        al_draw_bitmap(ztlo1,width_monitor*0.0001, height_monitor*0.00001,NULL);
                        al_draw_bitmap(zhub,width_monitor*0.05,height_monitor*0.4,NULL);
                        al_draw_bitmap(zman1,width_monitor*0.7,height_monitor*0.3,NULL);
                        al_draw_bitmap(zautor,width_monitor*0.25,height_monitor*0.3,NULL);
                        al_draw_bitmap(zja,width_monitor*0.57,height_monitor*0.47,NULL);
                        al_draw_textf(font0, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.35, ALLEGRO_ALIGN_CENTRE, "Autorzy");
                        al_draw_textf(font2, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.52, ALLEGRO_ALIGN_CENTRE, "Adrian Chmielowiec");
                        al_draw_textf(font2, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.57, ALLEGRO_ALIGN_CENTRE, "Marcin Kozera");
                        al_draw_textf(font2, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.62, ALLEGRO_ALIGN_CENTRE, "Marek Prajs");
                        al_flip_display();
                        al_rest(5);
                        menu(node, tm, height_monitor,width_monitor, event, queue ,queue1,display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, font0, font1, font2,font3,font4,font9, TIME_GAME,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
                        break;


                    }


                    //Koniec
                    if(event.mouse.x > width_monitor*0.40 && event.mouse.x < width_monitor*0.6 && event.mouse.y > height_monitor *0.8 && event.mouse.y < height_monitor *0.9){
                        al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                        done(display);
                        break;


                    }

                }


        }

    }

}
