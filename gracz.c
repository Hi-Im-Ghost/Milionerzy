void gracz(struct dll_node *node, struct tm tm, int height_monitor,int width_monitor, ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue,ALLEGRO_EVENT_QUEUE *queue1, ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *zstud,ALLEGRO_BITMAP *bitmap,ALLEGRO_VIDEO *studio,ALLEGRO_BITMAP *zsmutny,ALLEGRO_BITMAP *zpubli,ALLEGRO_BITMAP *zradosc,ALLEGRO_BITMAP *zstrach,ALLEGRO_BITMAP *ztele,ALLEGRO_BITMAP *zautor,ALLEGRO_BITMAP *zhub1,ALLEGRO_BITMAP *zja,ALLEGRO_BITMAP *zmilion,ALLEGRO_BITMAP *zmilion1,ALLEGRO_BITMAP *zhub,ALLEGRO_BITMAP *zman,ALLEGRO_BITMAP *zman1,ALLEGRO_BITMAP *zman2,ALLEGRO_BITMAP *znick,ALLEGRO_BITMAP *zmenu,ALLEGRO_BITMAP *ztlo1,ALLEGRO_BITMAP *ztlo,ALLEGRO_BITMAP *ztel,ALLEGRO_BITMAP *zpub,ALLEGRO_BITMAP *zpol, ALLEGRO_FONT *font0, ALLEGRO_FONT *font1, ALLEGRO_FONT *font2,ALLEGRO_FONT *font3,ALLEGRO_FONT *font4,ALLEGRO_FONT *font9, int TIME_GAME,ALLEGRO_SAMPLE *intro,ALLEGRO_SAMPLE *gra,ALLEGRO_SAMPLE *telefon,ALLEGRO_SAMPLE *publicznosc,ALLEGRO_SAMPLE *polowa,ALLEGRO_SAMPLE *pytanie,ALLEGRO_SAMPLE *zwycienstwo,ALLEGRO_SAMPLE *zle,ALLEGRO_SAMPLE *koniec,ALLEGRO_SAMPLE *kolo,ALLEGRO_SAMPLE *przycisk,ALLEGRO_SAMPLE_ID id1,ALLEGRO_SAMPLE_ID id2,ALLEGRO_SAMPLE_ID id3,ALLEGRO_SAMPLE_ID id4,ALLEGRO_SAMPLE_ID id5,ALLEGRO_SAMPLE_ID id6,ALLEGRO_SAMPLE_ID id7,ALLEGRO_SAMPLE_ID id8,ALLEGRO_SAMPLE_ID id9,ALLEGRO_SAMPLE_ID id10,ALLEGRO_SAMPLE_ID id11,char player_name[15]){

int key, i=0, shift=0;

al_clear_to_color(al_map_rgb(19, 34, 71));
al_draw_bitmap(zhub,width_monitor*0.45,height_monitor*0.5,NULL);
al_draw_textf(font1, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.3, ALLEGRO_ALIGN_CENTRE, "Witaj w MILIONERACH");
al_flip_display();
al_rest(TIME_GAME);
while (1) {


        al_clear_to_color(al_map_rgb(19, 34, 71));
        al_draw_bitmap(znick,width_monitor*0.4,height_monitor*0.08,NULL);
        al_draw_bitmap(zman,width_monitor*0.2,height_monitor*0.3,NULL);
        al_draw_bitmap(zhub1,width_monitor*0.6,height_monitor*0.1,NULL);
        al_draw_textf(font2, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.4, ALLEGRO_ALIGN_CENTRE, "Dozwolone znaki: ");
        al_draw_textf(font2, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.45, ALLEGRO_ALIGN_CENTRE, "0-9, a-z, A-Z, -, _");
        al_draw_textf(font9, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.35, ALLEGRO_ALIGN_CENTRE, "Wprowadz nazwe gracza");
        al_draw_textf(font2, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.55, ALLEGRO_ALIGN_CENTRE, "%s|", player_name);
        al_flip_display();

        if(i <= 3)
            al_draw_textf(font9, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.6, ALLEGRO_ALIGN_CENTRE, "Minimalna dlugosc to 3");

        al_wait_for_event(queue, &event);

        switch (event.type) {

            case ALLEGRO_EVENT_KEY_DOWN:

                switch(event.keyboard.keycode){

                    case ALLEGRO_KEY_ENTER:

                        if(i >= 3){

                            al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                            start_game(node, tm, height_monitor,width_monitor, event, queue ,queue1,display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, font0, font1, font2,font3,font4,font9, TIME_GAME,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
                            break;

                        }




                    case ALLEGRO_KEY_LSHIFT:
                        al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                        shift = 1;
                        break;

                    case ALLEGRO_KEY_RSHIFT:
                        al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                        shift = 1;
                        break;

                    default:{

                        key = event.keyboard.keycode;

                        if(key >= 1 && key <= 26){

                            if(shift == 0)
                                player_name[i] = key+96;

                            else
                                player_name[i] = key+64;

                            if(i < 13)
                                i++;

                        }
                        else if(key == 63){

                        if(i > 0){
                            i--;
                            player_name[i] = '\0';

                        }

                        }
                        else if(key >= 27 && key <=36){

                            player_name[i] = key+21;

                            if(i < 13)
                                i++;

                        }
                        else if(key >= 37 && key <=46){

                            player_name[i] = key+11;

                            if(i < 13)
                                i++;

                        }
                        else if(key == 61 && shift == 1){

                            player_name[i] = key+34;

                            if(i < 13)
                                i++;

                        }
                        else if(key == 61 && shift == 0){

                            player_name[i] = key-16;

                            if(i < 13)
                                i++;

                        }
                        else if(key == 88){

                            player_name[i] = key-43;

                            if(i < 13)
                                i++;

                        }
                        break;


                    }


                }
                break;

            case ALLEGRO_EVENT_KEY_UP:
                switch(event.keyboard.keycode){

                    case ALLEGRO_KEY_LSHIFT:
                        al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                        shift = 0;
                        break;

                    case ALLEGRO_KEY_RSHIFT:
                        al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                        shift = 0;
                        break;

                }

                break;

    }
}


}
