void wrong(struct dll_node *node, struct tm tm, ALLEGRO_FONT *font0, ALLEGRO_FONT *font1, ALLEGRO_FONT *font2,ALLEGRO_FONT *font3,ALLEGRO_FONT *font4,ALLEGRO_FONT *font9,ALLEGRO_EVENT_QUEUE *queue1, ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *zstud,ALLEGRO_BITMAP *bitmap,ALLEGRO_VIDEO *studio,ALLEGRO_BITMAP *zsmutny,ALLEGRO_BITMAP *zpubli,ALLEGRO_BITMAP *zradosc,ALLEGRO_BITMAP *zstrach,ALLEGRO_BITMAP *ztele,ALLEGRO_BITMAP *zautor,ALLEGRO_BITMAP *zhub1,ALLEGRO_BITMAP *zja,ALLEGRO_BITMAP *zmilion,ALLEGRO_BITMAP *zmilion1,ALLEGRO_BITMAP *zhub,ALLEGRO_BITMAP *zman,ALLEGRO_BITMAP *zman1,ALLEGRO_BITMAP *zman2,ALLEGRO_BITMAP *znick,ALLEGRO_BITMAP *zmenu,ALLEGRO_BITMAP *ztlo1,ALLEGRO_BITMAP *ztlo,ALLEGRO_BITMAP *ztel,ALLEGRO_BITMAP *zpub,ALLEGRO_BITMAP *zpol, ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, int TIME_GAME, int width_monitor ,int height_monitor,int question_number,ALLEGRO_SAMPLE *intro,ALLEGRO_SAMPLE *gra,ALLEGRO_SAMPLE *telefon,ALLEGRO_SAMPLE *publicznosc,ALLEGRO_SAMPLE *polowa,ALLEGRO_SAMPLE *pytanie,ALLEGRO_SAMPLE *zwycienstwo,ALLEGRO_SAMPLE *zle,ALLEGRO_SAMPLE *koniec,ALLEGRO_SAMPLE *kolo,ALLEGRO_SAMPLE *przycisk,ALLEGRO_SAMPLE_ID id1,ALLEGRO_SAMPLE_ID id2,ALLEGRO_SAMPLE_ID id3,ALLEGRO_SAMPLE_ID id4,ALLEGRO_SAMPLE_ID id5,ALLEGRO_SAMPLE_ID id6,ALLEGRO_SAMPLE_ID id7,ALLEGRO_SAMPLE_ID id8,ALLEGRO_SAMPLE_ID id9,ALLEGRO_SAMPLE_ID id10,ALLEGRO_SAMPLE_ID id11,char player_name[15]){

    if(question_number < 12 && question_number >=7)
    {
        win7(node, tm, font0, font1, font2,font3,font4,font9,queue1, display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, event, queue, TIME_GAME, width_monitor, height_monitor,question_number,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
    }
    if(question_number < 7 && question_number >=2)
    {
        win2(node, tm, font0, font1, font2,font3,font4,font9,queue1, display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, event, queue, TIME_GAME, width_monitor, height_monitor,question_number,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
    }
    else
    {
    al_clear_to_color(al_map_rgb(19, 34, 71));
    al_draw_bitmap(zsmutny,width_monitor*0.1,height_monitor*0.7,NULL);
    al_draw_textf(font0, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.1, ALLEGRO_ALIGN_CENTRE, "Niestety %s ale tym razem",player_name);
    al_draw_textf(font0, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.3, ALLEGRO_ALIGN_CENTRE, "nie popisales sie wiedza");
    al_draw_textf(font0, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.5, ALLEGRO_ALIGN_CENTRE, "Bladna odpowiedz");
    al_draw_textf(font0, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.7, ALLEGRO_ALIGN_CENTRE, "Koniec Gry");

    write_to_file(node, 0, player_name, tm);

    al_flip_display();
    al_rest(5);
    al_stop_sample(&id2);
    al_play_sample(koniec,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id5);
    al_clear_to_color(al_map_rgb(19, 34, 71));
    al_draw_textf(font0, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.3, ALLEGRO_ALIGN_CENTRE, "Kliknij ESC by wyjsc");
    al_draw_textf(font0, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.5, ALLEGRO_ALIGN_CENTRE, "lub ENTER by przejsc do menu");
    al_flip_display();



    while (1) {

        al_wait_for_event(queue, &event);


        switch (event.type) {

            case ALLEGRO_EVENT_KEY_DOWN:

                switch(event.keyboard.keycode){

                    case ALLEGRO_KEY_ENTER:
                        al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                            al_stop_sample(&id5);
                            menu(node, tm, height_monitor,width_monitor, event, queue ,queue1,display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, font0, font1, font2,font3,font4,font9, TIME_GAME,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
                            break;


                    case ALLEGRO_KEY_ESCAPE:
                        al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                            done(display);
                            break;

                }
                break;
        }
    }
    }
}
