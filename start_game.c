void start_game(struct dll_node *node, struct tm tm, int height_monitor,int width_monitor, ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue,ALLEGRO_EVENT_QUEUE *queue1, ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *zstud,ALLEGRO_BITMAP *bitmap,ALLEGRO_VIDEO *studio,ALLEGRO_BITMAP *zsmutny,ALLEGRO_BITMAP *zpubli,ALLEGRO_BITMAP *zradosc,ALLEGRO_BITMAP *zstrach,ALLEGRO_BITMAP *ztele,ALLEGRO_BITMAP *zautor,ALLEGRO_BITMAP *zhub1,ALLEGRO_BITMAP *zja,ALLEGRO_BITMAP *zmilion,ALLEGRO_BITMAP *zmilion1,ALLEGRO_BITMAP *zhub,ALLEGRO_BITMAP *zman,ALLEGRO_BITMAP *zman1,ALLEGRO_BITMAP *zman2,ALLEGRO_BITMAP *znick,ALLEGRO_BITMAP *zmenu,ALLEGRO_BITMAP *ztlo1,ALLEGRO_BITMAP *ztlo,ALLEGRO_BITMAP *ztel,ALLEGRO_BITMAP *zpub,ALLEGRO_BITMAP *zpol, ALLEGRO_FONT *font0, ALLEGRO_FONT *font1, ALLEGRO_FONT *font2,ALLEGRO_FONT *font3,ALLEGRO_FONT *font4,ALLEGRO_FONT *font9, int TIME_GAME,ALLEGRO_SAMPLE *intro,ALLEGRO_SAMPLE *gra,ALLEGRO_SAMPLE *telefon,ALLEGRO_SAMPLE *publicznosc,ALLEGRO_SAMPLE *polowa,ALLEGRO_SAMPLE *pytanie,ALLEGRO_SAMPLE *zwycienstwo,ALLEGRO_SAMPLE *zle,ALLEGRO_SAMPLE *koniec,ALLEGRO_SAMPLE *kolo,ALLEGRO_SAMPLE *przycisk,ALLEGRO_SAMPLE_ID id1,ALLEGRO_SAMPLE_ID id2,ALLEGRO_SAMPLE_ID id3,ALLEGRO_SAMPLE_ID id4,ALLEGRO_SAMPLE_ID id5,ALLEGRO_SAMPLE_ID id6,ALLEGRO_SAMPLE_ID id7,ALLEGRO_SAMPLE_ID id8,ALLEGRO_SAMPLE_ID id9,ALLEGRO_SAMPLE_ID id10,ALLEGRO_SAMPLE_ID id11,char player_name[15]){


    int fon=0,pub=0,polow=0,kol=0;
    int question_number = 0;
    int publi[3];
    int array_number_questions[12];
    int array_random_answer[5] = {1,2,3,4,4};

    al_clear_to_color(al_map_rgb(19, 34, 71));
    al_draw_bitmap(zhub,width_monitor*0.7,height_monitor*0.3,NULL);
    al_draw_textf(font9, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.3, ALLEGRO_ALIGN_CENTRE, "Jestem Hubert i zapraszam Cie %s",player_name);
    al_draw_textf(font9, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.4, ALLEGRO_ALIGN_CENTRE, "do gry");
    al_draw_textf(font9, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.5, ALLEGRO_ALIGN_CENTRE, "o MILION!");
    al_flip_display();
    al_rest(TIME_GAME);
    al_clear_to_color(al_map_rgb(19, 34, 71));
    al_draw_textf(font2, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.2, ALLEGRO_ALIGN_CENTRE, "Jesli jestes gotowy do gry wcisnij ENTER");
    al_draw_textf(font2, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.3, ALLEGRO_ALIGN_CENTRE, "lub kliknij");
    al_draw_textf(font2, al_map_rgb(255, 0, 0), width_monitor*0.5, height_monitor*0.4, ALLEGRO_ALIGN_CENTRE, "na ten napis!");
    al_draw_textf(font2, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.5, ALLEGRO_ALIGN_CENTRE, "Jesli jednak stchorzyles i chcesz sie wycofac");
    al_draw_textf(font2, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.6, ALLEGRO_ALIGN_CENTRE, "wcisnij ESC by wyjsc");
    al_draw_textf(font2, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.7, ALLEGRO_ALIGN_CENTRE, "albo spacje by cofnac sie do menu");
    al_flip_display();


    srand(time(0));

    rand_questions(array_number_questions);
    rand_answer(array_random_answer);

    while (1) {

        al_wait_for_event(queue, &event);


        switch (event.type) {

            case ALLEGRO_EVENT_KEY_DOWN:

                switch(event.keyboard.keycode){

                    case ALLEGRO_KEY_ENTER:
                            al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                            al_clear_to_color(al_map_rgb(19, 34, 71));
                            al_draw_bitmap(zman,width_monitor*0.8,height_monitor*0.4,NULL);
                            al_draw_bitmap(zman1,width_monitor*0.05,height_monitor*0.4,NULL);
                            al_draw_textf(font9, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.3, ALLEGRO_ALIGN_CENTRE, "Zaczynamy wiec!");
                            al_draw_textf(font9, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.4, ALLEGRO_ALIGN_CENTRE, "Zlap sie lepiej mocno fotela by");
                            al_draw_textf(font9, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.5, ALLEGRO_ALIGN_CENTRE, "pierwsze pytanie nie zwalilo Cie z nog!");
                            al_flip_display();
                            al_rest(TIME_GAME);
                            game(node, tm, height_monitor,width_monitor, event, queue ,queue1,display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, font0, font1, font2,font3,font4,font9, TIME_GAME, question_number, array_random_answer, array_number_questions,fon,pub,polow,kol,publi,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
                            break;


                    case ALLEGRO_KEY_ESCAPE:
                            al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                            al_clear_to_color(al_map_rgb(19, 34, 71));
                            al_draw_bitmap(zstrach,width_monitor*0.1,height_monitor*0.4,NULL);
                            al_draw_textf(font9, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.3, ALLEGRO_ALIGN_CENTRE, "Wiedzialem od poczatku");
                            al_draw_textf(font9, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.4, ALLEGRO_ALIGN_CENTRE, "ze %s to mieczak!",player_name);
                            al_draw_textf(font9, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.5, ALLEGRO_ALIGN_CENTRE, "Bywaj!");
                            write_to_file(node, 1, player_name, tm);
                            al_flip_display();
                            al_rest(TIME_GAME);
                            done(display);
                            break;


                    case ALLEGRO_KEY_SPACE:
                            al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                            al_clear_to_color(al_map_rgb(19, 34, 71));
                            al_flip_display();
                            menu(node, tm, height_monitor,width_monitor, event, queue ,queue1,display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, font0, font1, font2,font3,font4,font9, TIME_GAME,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
                        break;



                }
                break;

            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:

                switch(event.mouse.button){

                    case 1:
                    if(event.mouse.x > width_monitor*0.42 && event.mouse.x < width_monitor*0.58 && event.mouse.y > height_monitor *0.38 && event.mouse.y < height_monitor *0.42){
                            al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                            al_clear_to_color(al_map_rgb(19, 34, 71));
                            al_draw_bitmap(zman,width_monitor*0.8,height_monitor*0.4,NULL);
                            al_draw_bitmap(zman1,width_monitor*0.05,height_monitor*0.4,NULL);
                            al_draw_textf(font9, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.3, ALLEGRO_ALIGN_CENTRE, "Zaczynamy wiec!");
                            al_draw_textf(font9, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.4, ALLEGRO_ALIGN_CENTRE, "Zlap sie lepiej mocno fotela by");
                            al_draw_textf(font9, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.5, ALLEGRO_ALIGN_CENTRE, "pierwsze pytanie nie zwalilo Cie z nog!");
                            al_flip_display();
                            al_rest(TIME_GAME);
                            game(node, tm, height_monitor,width_monitor, event, queue ,queue1,display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, font0, font1, font2,font3,font4,font9, TIME_GAME, question_number, array_random_answer, array_number_questions,fon,pub,polow,kol,publi,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
                            break;


                    }




            }
            break;

    }
    }
}


