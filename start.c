void start(int height_monitor,int width_monitor, ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *ztlo,ALLEGRO_BITMAP *bitmap, ALLEGRO_FONT *font0, ALLEGRO_FONT *font1, int START_TIME,ALLEGRO_SAMPLE *intro,ALLEGRO_SAMPLE *gra,ALLEGRO_SAMPLE *telefon,ALLEGRO_SAMPLE *publicznosc,ALLEGRO_SAMPLE *polowa,ALLEGRO_SAMPLE *pytanie,ALLEGRO_SAMPLE *zwycienstwo,ALLEGRO_SAMPLE *zle,ALLEGRO_SAMPLE *koniec,ALLEGRO_SAMPLE *kolo,ALLEGRO_SAMPLE *przycisk,ALLEGRO_SAMPLE_ID id1,ALLEGRO_SAMPLE_ID id2,ALLEGRO_SAMPLE_ID id3,ALLEGRO_SAMPLE_ID id4,ALLEGRO_SAMPLE_ID id5,ALLEGRO_SAMPLE_ID id6,ALLEGRO_SAMPLE_ID id7,ALLEGRO_SAMPLE_ID id8,ALLEGRO_SAMPLE_ID id9,ALLEGRO_SAMPLE_ID id10,ALLEGRO_SAMPLE_ID id11,ALLEGRO_VIDEO *nvidia,ALLEGRO_VIDEO *amd,ALLEGRO_VIDEO *cry,ALLEGRO_VIDEO *studio){

    int x;
    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
    al_start_video(nvidia,al_get_default_mixer());

    for(x = 0; x < 100; ++x)
  {
    bitmap = al_get_video_frame(nvidia);
    if(bitmap)
    al_draw_bitmap(bitmap, 0, 0, 0);
    al_get_video_position(nvidia, 0);
    al_flip_display();
    al_rest(0.05);
  }
  al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
    al_start_video(amd,al_get_default_mixer());


    for(x = 0; x < 100; ++x)
  {
    bitmap = al_get_video_frame(amd);
    if(bitmap)
    al_draw_bitmap(bitmap, 0, 0, 0);
    al_get_video_position(amd, 0);
    al_flip_display();
    al_rest(0.05);
  }
  al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
    al_start_video(cry,al_get_default_mixer());

    for(x = 0; x < 100; ++x)
  {
    bitmap = al_get_video_frame(cry);
    if(bitmap)
    al_draw_bitmap(bitmap, 0, 0, 0);
    al_get_video_position(cry, 0);
    al_flip_display();
    al_rest(0.05);
  }

    al_close_video(nvidia);
    al_close_video(amd);
    al_close_video(cry);

    al_clear_to_color(al_map_rgb(19, 34, 71));
    al_play_sample(intro,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id1);
    al_draw_bitmap(ztlo,width_monitor*0.0001, height_monitor*0.0001,NULL);
    al_flip_display();
    al_rest(START_TIME);

}
