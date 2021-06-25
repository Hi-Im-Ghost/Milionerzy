void game(struct dll_node *node, struct tm tm, int height_monitor,int width_monitor, ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue,ALLEGRO_EVENT_QUEUE *queue1, ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *zstud,ALLEGRO_BITMAP *bitmap,ALLEGRO_VIDEO *studio,ALLEGRO_BITMAP *zsmutny,ALLEGRO_BITMAP *zpubli,ALLEGRO_BITMAP *zradosc,ALLEGRO_BITMAP *zstrach,ALLEGRO_BITMAP *ztele,ALLEGRO_BITMAP *zautor,ALLEGRO_BITMAP *zhub1,ALLEGRO_BITMAP *zja,ALLEGRO_BITMAP *zmilion,ALLEGRO_BITMAP *zmilion1,ALLEGRO_BITMAP *zhub,ALLEGRO_BITMAP *zman,ALLEGRO_BITMAP *zman1,ALLEGRO_BITMAP *zman2,ALLEGRO_BITMAP *znick,ALLEGRO_BITMAP *zmenu,ALLEGRO_BITMAP *ztlo1,ALLEGRO_BITMAP *ztlo,ALLEGRO_BITMAP *ztel,ALLEGRO_BITMAP *zpub,ALLEGRO_BITMAP *zpol, ALLEGRO_FONT *font0, ALLEGRO_FONT *font1, ALLEGRO_FONT *font2,ALLEGRO_FONT *font3,ALLEGRO_FONT *font4,ALLEGRO_FONT *font9, int TIME_GAME, int question_number, int array_random_answer[5], int array_number_questions[12], int fon,int pub,int polow,int kol,int publi[3],ALLEGRO_SAMPLE *intro,ALLEGRO_SAMPLE *gra,ALLEGRO_SAMPLE *telefon,ALLEGRO_SAMPLE *publicznosc,ALLEGRO_SAMPLE *polowa,ALLEGRO_SAMPLE *pytanie,ALLEGRO_SAMPLE *zwycienstwo,ALLEGRO_SAMPLE *zle,ALLEGRO_SAMPLE *koniec,ALLEGRO_SAMPLE *kolo,ALLEGRO_SAMPLE *przycisk,ALLEGRO_SAMPLE_ID id1,ALLEGRO_SAMPLE_ID id2,ALLEGRO_SAMPLE_ID id3,ALLEGRO_SAMPLE_ID id4,ALLEGRO_SAMPLE_ID id5,ALLEGRO_SAMPLE_ID id6,ALLEGRO_SAMPLE_ID id7,ALLEGRO_SAMPLE_ID id8,ALLEGRO_SAMPLE_ID id9,ALLEGRO_SAMPLE_ID id10,ALLEGRO_SAMPLE_ID id11,char player_name[15]){

    al_clear_to_color(al_map_rgb(19, 34, 71));
    al_flip_display();
    al_clear_to_color(al_map_rgb(19, 34, 71));
    al_flip_display();
    al_clear_to_color(al_map_rgb(19, 34, 71));

    int k = 0;

    al_play_sample(gra,0.8,0.0,1.0,ALLEGRO_PLAYMODE_LOOP,&id10);

    if(question_number == 12){
    al_stop_sample(&id10);
    winer(node, tm, height_monitor,width_monitor, event, queue ,queue1,display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, font0, font1,font2,font3,font4,font9, TIME_GAME,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
    }

    if(question_number == 0){

        al_start_video(studio,al_get_default_mixer());
        while(k == 0)
        {
            al_wait_for_event(queue1, &event);

            if(event.type==ALLEGRO_EVENT_VIDEO_FRAME_SHOW)
            {
                bitmap = al_get_video_frame(studio);
                al_draw_bitmap(bitmap,width_monitor*0.33,height_monitor*0.33, 0);
                al_get_video_position(studio, 0);
                al_flip_display();
            }else if(event.type==ALLEGRO_EVENT_VIDEO_FINISHED)
                {
                    al_seek_video(studio, 0.00);
                    al_get_video_position(studio,0);
                    al_set_video_playing(studio, true);

                    k = 1;
                }
        }

    }

    char array_question[6][250] = {'\0'};
    questions_select(array_question, array_number_questions[question_number]);

    al_clear_to_color(al_map_rgb(19, 34, 71));
    al_flip_display();
    al_clear_to_color(al_map_rgb(19, 34, 71));

    al_draw_bitmap(zmenu,width_monitor*0.01, height_monitor*0.01,NULL);
    al_draw_bitmap(zstud,width_monitor*0.1, height_monitor*0.1,NULL);

    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.4, height_monitor*0.7, ALLEGRO_ALIGN_CENTER, "Pytanie nr %d", question_number+1);
    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.4, height_monitor*0.74, ALLEGRO_ALIGN_CENTER, "%s", array_question[0]);
    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.4, height_monitor*0.78, ALLEGRO_ALIGN_CENTER, "%s", array_question[5]);
    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.2, height_monitor*0.82, ALLEGRO_ALIGN_CENTER, "A) %s", array_question[array_random_answer[0]]);
    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.2, height_monitor*0.87, ALLEGRO_ALIGN_CENTER, "C) %s", array_question[array_random_answer[2]]);
    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.6, height_monitor*0.82, ALLEGRO_ALIGN_CENTER, "B) %s", array_question[array_random_answer[1]]);
    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.6, height_monitor*0.87, ALLEGRO_ALIGN_CENTER, "D) %s", array_question[array_random_answer[3]]);

   // al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.4, height_monitor*0.6, ALLEGRO_ALIGN_CENTER, "Prawidlowa: %d", array_random_answer[4]);

    if(question_number+1==12){
            al_draw_textf(font2, al_map_rgb(128, 128, 128), width_monitor*0.9, height_monitor*0.15, ALLEGRO_ALIGN_CENTER, "1 000 000");
    }else{
    al_draw_textf(font2, al_map_rgb(255, 215, 0), width_monitor*0.9, height_monitor*0.15, ALLEGRO_ALIGN_CENTER, "1 000 000");}
    if(question_number+1==11){
        al_draw_textf(font2, al_map_rgb(128, 128, 128), width_monitor*0.9, height_monitor*0.2, ALLEGRO_ALIGN_CENTER, "500 000");
    }else{
    al_draw_textf(font2, al_map_rgb(0, 0, 0), width_monitor*0.9, height_monitor*0.2, ALLEGRO_ALIGN_CENTER, "500 000");}
    if(question_number+1==10){
        al_draw_textf(font2, al_map_rgb(128, 128, 128), width_monitor*0.9, height_monitor*0.25, ALLEGRO_ALIGN_CENTER, "250 000");
    }else{
    al_draw_textf(font2, al_map_rgb(0, 0, 0), width_monitor*0.9, height_monitor*0.25, ALLEGRO_ALIGN_CENTER, "250 000");}
    if(question_number+1==9){
        al_draw_textf(font2, al_map_rgb(128, 128, 128), width_monitor*0.9, height_monitor*0.3, ALLEGRO_ALIGN_CENTER, "125 000");
    }else{
    al_draw_textf(font2, al_map_rgb(0, 0, 0), width_monitor*0.9, height_monitor*0.3, ALLEGRO_ALIGN_CENTER, "125 000");}
    if(question_number+1==8){
        al_draw_textf(font2, al_map_rgb(128, 128, 128), width_monitor*0.9, height_monitor*0.35, ALLEGRO_ALIGN_CENTER, "75 000");
    }else{
    al_draw_textf(font2, al_map_rgb(0, 0, 0), width_monitor*0.9, height_monitor*0.35, ALLEGRO_ALIGN_CENTER, "75 000");}
    if(question_number+1==7){
        al_draw_textf(font2, al_map_rgb(128, 128, 128), width_monitor*0.9, height_monitor*0.4, ALLEGRO_ALIGN_CENTER, "40 000");
    }else{
    al_draw_textf(font2, al_map_rgb(255, 0, 0), width_monitor*0.9, height_monitor*0.4, ALLEGRO_ALIGN_CENTER, "40 000");}
    if(question_number+1==6){
        al_draw_textf(font2, al_map_rgb(128, 128, 128), width_monitor*0.9, height_monitor*0.45, ALLEGRO_ALIGN_CENTER, "20 000");
    }else{
    al_draw_textf(font2, al_map_rgb(0, 0, 0), width_monitor*0.9, height_monitor*0.45, ALLEGRO_ALIGN_CENTER, "20 000");}
    if(question_number+1==5){
        al_draw_textf(font2, al_map_rgb(128, 128, 128), width_monitor*0.9, height_monitor*0.5, ALLEGRO_ALIGN_CENTER, "10 000");
    }else{
    al_draw_textf(font2, al_map_rgb(0, 0, 0), width_monitor*0.9, height_monitor*0.5, ALLEGRO_ALIGN_CENTER, "10 000");}
    if(question_number+1==4){
        al_draw_textf(font2, al_map_rgb(128, 128, 128), width_monitor*0.9, height_monitor*0.55, ALLEGRO_ALIGN_CENTER, "5000");
    }else{
    al_draw_textf(font2, al_map_rgb(0, 0, 0), width_monitor*0.9, height_monitor*0.55, ALLEGRO_ALIGN_CENTER, "5000");}
    if(question_number+1==3){
            al_draw_textf(font2, al_map_rgb(128, 128, 128), width_monitor*0.9, height_monitor*0.6, ALLEGRO_ALIGN_CENTER, "2000");
    }else{
    al_draw_textf(font2, al_map_rgb(0, 0, 0), width_monitor*0.9, height_monitor*0.6, ALLEGRO_ALIGN_CENTER, "2000");}
    if(question_number+1==2){
            al_draw_textf(font2, al_map_rgb(128, 128, 128), width_monitor*0.9, height_monitor*0.65, ALLEGRO_ALIGN_CENTER, "1000");
    }else{
    al_draw_textf(font2, al_map_rgb(255, 0, 0), width_monitor*0.9, height_monitor*0.65, ALLEGRO_ALIGN_CENTER, "1000");}
    if(question_number+1==1){
    al_draw_textf(font2, al_map_rgb(128, 128, 128), width_monitor*0.9, height_monitor*0.7, ALLEGRO_ALIGN_CENTER, "500");
    }else{
    al_draw_textf(font2, al_map_rgb(0, 0, 0), width_monitor*0.9, height_monitor*0.7, ALLEGRO_ALIGN_CENTER, "500");}

    al_draw_bitmap(zpol,width_monitor*0.7, height_monitor*0.01,NULL);
    al_draw_bitmap(ztel,width_monitor*0.8, height_monitor*0.01,NULL);
    al_draw_bitmap(zpub,width_monitor*0.9, height_monitor*0.01,NULL);

    al_flip_display();


    if(kol==3){
    kol++;
    if(pub!=0 && fon!=0 && polow!=0)
    {
        al_play_sample(kolo,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id9);
    }
    }
    while (1) {

        al_wait_for_event(queue, &event);

        switch (event.type) {

            case ALLEGRO_EVENT_KEY_DOWN:

                switch(event.keyboard.keycode){

                    case ALLEGRO_KEY_ESCAPE:
                        al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                        wrong(node, tm, font0, font1, font2,font3,font4,font9,queue1, display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, event, queue, TIME_GAME, width_monitor, height_monitor,question_number,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
                        break;

                }

                break;

            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:

                switch(event.mouse.button){

                    case 1:

                        if(event.mouse.x > 0 && event.mouse.x < width_monitor*0.05 && event.mouse.y > 0.06 && event.mouse.y < height_monitor *0.9){
                                al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                                al_stop_sample(&id10);
                                wrong(node, tm, font0, font1, font2,font3,font4,font9,queue1, display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, event, queue, TIME_GAME, width_monitor, height_monitor,question_number,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
                        break;
                        }
                        else if(event.mouse.x > width_monitor*0.15 && event.mouse.x < width_monitor*0.3 && event.mouse.y > height_monitor *0.82 && event.mouse.y < height_monitor *0.84){
                                al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                            if(array_random_answer[4] == 0){
                                al_play_sample(pytanie,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id3);
                                correct(node, tm, height_monitor,width_monitor, event, queue ,queue1,display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, font0, font1, font2,font3,font4,font9, TIME_GAME, question_number, array_random_answer, array_number_questions,fon,pub,polow,kol,publi,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
                            }
                            else{
                                al_stop_sample(&id10);
                                al_play_sample(zle,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id2);
                                wrong(node, tm, font0, font1, font2,font3,font4,font9,queue1, display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, event, queue, TIME_GAME, width_monitor, height_monitor,question_number,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
                            }
                            break;
                        }
                        else if(event.mouse.x > width_monitor*0.55 && event.mouse.x < width_monitor*0.7 && event.mouse.y > height_monitor *0.82 && event.mouse.y < height_monitor *0.84){
                                al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                            if(array_random_answer[4] == 1){
                                al_play_sample(pytanie,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id3);
                                correct(node, tm, height_monitor,width_monitor, event, queue ,queue1,display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, font0, font1, font2,font3,font4,font9, TIME_GAME, question_number, array_random_answer, array_number_questions,fon,pub,polow,kol,publi,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
                            }else{
                                al_stop_sample(&id10);
                                al_play_sample(zle,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id2);
                                wrong(node, tm, font0, font1, font2,font3,font4,font9,queue1, display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, event, queue, TIME_GAME, width_monitor, height_monitor,question_number,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
                            }break;
                        }
                        else if(event.mouse.x > width_monitor*0.15 && event.mouse.x < width_monitor*0.3 && event.mouse.y > height_monitor *0.87 && event.mouse.y < height_monitor *0.89){
                                al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                            if(array_random_answer[4] == 2){
                                al_play_sample(pytanie,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id3);
                                correct(node, tm, height_monitor,width_monitor, event, queue ,queue1,display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, font0, font1, font2,font3,font4,font9, TIME_GAME, question_number, array_random_answer, array_number_questions,fon,pub,polow,kol,publi,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
                            }else{
                                al_stop_sample(&id10);
                                al_play_sample(zle,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id2);
                                wrong(node, tm, font0, font1, font2,font3,font4,font9,queue1, display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, event, queue, TIME_GAME, width_monitor, height_monitor,question_number,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
                            }break;
                        }
                        else if(event.mouse.x > width_monitor*0.55 && event.mouse.x < width_monitor*0.7 && event.mouse.y > height_monitor *0.87 && event.mouse.y < height_monitor *0.89){
                                al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                            if(array_random_answer[4] == 3){
                                al_play_sample(pytanie,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id3);
                                correct(node, tm, height_monitor,width_monitor, event, queue ,queue1,display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, font0, font1, font2,font3,font4,font9, TIME_GAME, question_number, array_random_answer, array_number_questions,fon,pub,polow,kol,publi,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
                            }else{
                                al_stop_sample(&id10);
                                al_play_sample(zle,1.0,0.0,1.0,ALLEGRO_PLAYMODE_LOOP,&id2);
                                wrong(node, tm, font0, font1, font2,font3,font4,font9,queue1, display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, event, queue, TIME_GAME, width_monitor, height_monitor,question_number,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
                            }break;
                        }
                        else if(event.mouse.x > width_monitor*0.71 && event.mouse.x < width_monitor*0.78 && event.mouse.y > height_monitor *0 && event.mouse.y < height_monitor *0.1){
                           // pol();
                           al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                           if(polow==0){
                            al_stop_sample(&id10);
                            al_play_sample(polowa,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id7);
                           pol(node, tm, height_monitor,width_monitor, event, queue ,queue1,display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, font0, font1, font2,font3,font4,font9, TIME_GAME, question_number, array_random_answer, array_number_questions,array_question,fon,pub,polow,kol,publi,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
                        }break;
                        }
                        else if(event.mouse.x > width_monitor*0.81 && event.mouse.x < width_monitor*0.88 && event.mouse.y > height_monitor *0 && event.mouse.y < height_monitor *0.1){
                           // tel();
                           al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                           if(fon==0){
                            al_stop_sample(&id10);
                            al_play_sample(telefon,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id6);
                           tel(node, tm, height_monitor,width_monitor, event, queue ,queue1,display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, font0, font1, font2,font3,font4,font9, TIME_GAME, question_number, array_random_answer, array_number_questions,fon,pub,polow,kol,publi,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
                        }break;
                        }
                        else if(event.mouse.x > width_monitor*0.91 && event.mouse.x < width_monitor*0.98 && event.mouse.y > height_monitor *0 && event.mouse.y < height_monitor *0.1){
                            //publicznosc
                            al_play_sample(przycisk,0.5,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id11);
                            if(pub==0){
                            al_stop_sample(&id10);
                            al_play_sample(publicznosc,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id8);
                            publicznos(node, tm, height_monitor,width_monitor, event, queue ,queue1,display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, font0, font1, font2,font3,font4,font9, TIME_GAME, question_number, array_random_answer, array_number_questions,fon,pub,polow,kol,publi,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);
                            }
                        break;
                        }
                    }

                }


        }
    }


