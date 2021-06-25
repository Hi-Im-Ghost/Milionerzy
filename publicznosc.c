void publicznos(struct dll_node *node, struct tm tm, int height_monitor,int width_monitor, ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue,ALLEGRO_EVENT_QUEUE *queue1, ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *zstud,ALLEGRO_BITMAP *bitmap,ALLEGRO_VIDEO *studio,ALLEGRO_BITMAP *zsmutny,ALLEGRO_BITMAP *zpubli,ALLEGRO_BITMAP *zradosc,ALLEGRO_BITMAP *zstrach,ALLEGRO_BITMAP *ztele,ALLEGRO_BITMAP *zautor,ALLEGRO_BITMAP *zhub1,ALLEGRO_BITMAP *zja,ALLEGRO_BITMAP *zmilion,ALLEGRO_BITMAP *zmilion1,ALLEGRO_BITMAP *zhub,ALLEGRO_BITMAP *zman,ALLEGRO_BITMAP *zman1,ALLEGRO_BITMAP *zman2,ALLEGRO_BITMAP *znick,ALLEGRO_BITMAP *zmenu,ALLEGRO_BITMAP *ztlo1,ALLEGRO_BITMAP *ztlo,ALLEGRO_BITMAP *ztel,ALLEGRO_BITMAP *zpub,ALLEGRO_BITMAP *zpol, ALLEGRO_FONT *font0, ALLEGRO_FONT *font1, ALLEGRO_FONT *font2,ALLEGRO_FONT *font3,ALLEGRO_FONT *font4,ALLEGRO_FONT *font9, int TIME_GAME, int question_number, int array_random_answer[5], int array_number_questions[12], int fon,int pub,int polow,int kol,int publi[3],ALLEGRO_SAMPLE *intro,ALLEGRO_SAMPLE *gra,ALLEGRO_SAMPLE *telefon,ALLEGRO_SAMPLE *publicznosc,ALLEGRO_SAMPLE *polowa,ALLEGRO_SAMPLE *pytanie,ALLEGRO_SAMPLE *zwycienstwo,ALLEGRO_SAMPLE *zle,ALLEGRO_SAMPLE *koniec,ALLEGRO_SAMPLE *kolo,ALLEGRO_SAMPLE *przycisk,ALLEGRO_SAMPLE_ID id1,ALLEGRO_SAMPLE_ID id2,ALLEGRO_SAMPLE_ID id3,ALLEGRO_SAMPLE_ID id4,ALLEGRO_SAMPLE_ID id5,ALLEGRO_SAMPLE_ID id6,ALLEGRO_SAMPLE_ID id7,ALLEGRO_SAMPLE_ID id8,ALLEGRO_SAMPLE_ID id9,ALLEGRO_SAMPLE_ID id10,ALLEGRO_SAMPLE_ID id11,char player_name[15]){

    srand(time(0));
    al_clear_to_color(al_map_rgb(19, 34, 71));
    al_draw_bitmap(zpubli,width_monitor*0.1,height_monitor*0.5,NULL);
   for(int i= 0; i<= 3; ){
        publi[i]=(rand()%21)+70;
        i++;
        publi[i]=(rand()%21)+40;
        i++;
        publi[i]=(rand()%21)+20;
        i++;
        publi[i]=rand()%21;
        i++;
   }
    if(array_random_answer[4] == 0){
    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.3, ALLEGRO_ALIGN_CENTER, "Liczba glosow dla odpowiedzi A) %d",publi[0]);
    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.4, ALLEGRO_ALIGN_CENTER, "Liczba glosow dla odpowiedzi B) %d",publi[1]);
    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.5, ALLEGRO_ALIGN_CENTER, "Liczba glosow dla odpowiedzi C) %d",publi[2]);
    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.6, ALLEGRO_ALIGN_CENTER, "Liczba glosow dla odpowiedzi D) %d",publi[3]);
    }
    else if(array_random_answer[4] == 1){
    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.4, ALLEGRO_ALIGN_CENTER, "Liczba glosow dla odpowiedzi B) %d", publi[0]);
    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.3, ALLEGRO_ALIGN_CENTER, "Liczba glosow dla odpowiedzi A) %d",publi[1]);
    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.5, ALLEGRO_ALIGN_CENTER, "Liczba glosow dla odpowiedzi C) %d",publi[2]);
    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.6, ALLEGRO_ALIGN_CENTER, "Liczba glosow dla odpowiedzi D) %d",publi[3]);
    }
    else if(array_random_answer[4] == 2){
    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.5, ALLEGRO_ALIGN_CENTER, "Liczba glosow dla odpowiedzi C) %d", publi[0]);
    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.3, ALLEGRO_ALIGN_CENTER, "Liczba glosow dla odpowiedzi A) %d",publi[1]);
    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.4, ALLEGRO_ALIGN_CENTER, "Liczba glosow dla odpowiedzi B) %d",publi[2]);
    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.6, ALLEGRO_ALIGN_CENTER, "Liczba glosow dla odpowiedzi D) %d",publi[3]);
    }
    else if(array_random_answer[4] == 3){
    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.6, ALLEGRO_ALIGN_CENTER, "Liczba glosow dla odpowiedzi D) %d", publi[0]);
    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.3, ALLEGRO_ALIGN_CENTER, "Liczba glosow dla odpowiedzi A) %d",publi[1]);
    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.4, ALLEGRO_ALIGN_CENTER, "Liczba glosow dla odpowiedzi B) %d",publi[2]);
    al_draw_textf(font3, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.5, ALLEGRO_ALIGN_CENTER, "Liczba glosow dla odpowiedzi C) %d",publi[3]);
    }
    pub++;
    kol++;
    al_flip_display();
    al_rest(10);
    game(node, tm, height_monitor,width_monitor, event, queue ,queue1,display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, font0, font1, font2,font3,font4,font9, TIME_GAME, question_number, array_random_answer, array_number_questions,fon,pub,polow,kol,publi,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);

}

