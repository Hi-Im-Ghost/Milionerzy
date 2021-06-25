#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_video.h>
#include <allegro5/allegro_image.h>

#include "done.c"
#include "start.c"
#include "menu.c"
#include "start_game.c"
#include "game.c"
#include "correct.c"
#include "wrong.c"
#include "questions.c"
#include "rand_answer.c"
#include "rand_questions.c"
#include "winer.c"
#include "win2.c"
#include "win7.c"
#include "telefon.c"
#include "pol.c"
#include "publicznosc.c"
#include "gracz.c"
#include "ranking.c"
#include "zapis.c"
#include "odczyt.c"
#include "list.c"

#define TIME_GAME 5
#define START_TIME 10

int main(){

    char arr[15] = {'a'};

    struct dll_node *dlcl = create_list(-1, arr);

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    ALLEGRO_FILE *file;
    ALLEGRO_DISPLAY *display;
    ALLEGRO_MONITOR_INFO info;
    ALLEGRO_EVENT_QUEUE *queue,*queue1;
    ALLEGRO_EVENT event,event1;
    ALLEGRO_FONT *font0, *font1, *font2,*font3,*font4,*font9;
    ALLEGRO_SAMPLE *intro,*gra,*telefon,*publicznosc,*polowa,*pytanie,*zwycienstwo,*zle,*koniec,*kolo,*przycisk;
    ALLEGRO_SAMPLE_ID id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11;
    ALLEGRO_VIDEO *nvidia,*amd,*cry,*studio;
    ALLEGRO_BITMAP  *bitmap = NULL;
    ALLEGRO_BITMAP  *ztel,*zpol,*zpub,*ztlo,*ztlo1,*zhub,*zman,*zman1,*zman2,*znick,*zmenu,*zautor,*zhub1,*zja,*zmilion,*zmilion1,*zpubli,*zradosc,*zstrach,*ztele,*zsmutny,*zstud;

    if (!al_init()) {
        printf("Blad inicjacji Allegro\n");
        return 1;
    }

    if(!al_install_mouse()){
        printf("Blad inicjacji myszki\n");
        return 1;
    }

    if(!al_install_keyboard()){
        printf("Blad inicjacji klawiatury\n");
        return 1;
    }
    if(!al_install_audio()){
        printf("Blad inicjacji audio\n");
        return 1;
    }
    if(!al_init_acodec_addon()){
        printf("Blad inicjacji kodekow audio\n");
        return 1;
    }
    if(!al_init_video_addon()){
        printf("Blad inicjacji video \n");
        return 1;
    }

    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();

    al_get_monitor_info(0, &info);
    int width_monitor = info.x2, height_monitor = info.y2;
    char player_name[15] = {'\0'};

    zpub = al_load_bitmap("data/image/zpub.png");
    if(!zpub) printf("Blad wczytywania obrazu zpub\n");
    ztel = al_load_bitmap("data/image/ztel.png");
    if(!ztel) printf("Blad wczytywania obrazu ztel\n");
    zpol = al_load_bitmap("data/image/zpol.png");
    if(!zpol) printf("Blad wczytywania obrazu zpol\n");
    ztlo = al_load_bitmap("data/image/tlo2.png");
    if(!ztlo) printf("Blad wczytywania obrazu tlo\n");
    ztlo1 = al_load_bitmap("data/image/tlo3.png");
    if(!ztlo1) printf("Blad wczytywania obrazu tlo1\n");
    zhub = al_load_bitmap("data/image/hubert.png");
    if(!zhub) printf("Blad wczytywania obrazu hubert\n");
    zman = al_load_bitmap("data/image/man.png");
    if(!zman) printf("Blad wczytywania obrazu man\n");
    zman1 = al_load_bitmap("data/image/man1.png");
    if(!zman1) printf("Blad wczytywania obrazu man1\n");
    zman2 = al_load_bitmap("data/image/man2.png");
    if(!zman2) printf("Blad wczytywania obrazu man2\n");
    znick = al_load_bitmap("data/image/nick.png");
    if(!znick) printf("Blad wczytywania obrazu nick\n");
    zautor = al_load_bitmap("data/image/autorzy.png");
    if(!zautor) printf("Blad wczytywania obrazu autorzy\n");
    zhub1 = al_load_bitmap("data/image/hubert1.png");
    if(!zhub1) printf("Blad wczytywania obrazu hubert1\n");
    zja = al_load_bitmap("data/image/ja.png");
    if(!zja) printf("Blad wczytywania obrazu ja\n");
    zmilion = al_load_bitmap("data/image/milion.png");
    if(!zmilion) printf("Blad wczytywania obrazu milion\n");
    zmilion1 = al_load_bitmap("data/image/milion1.png");
    if(!zmilion1) printf("Blad wczytywania obrazu milion1\n");
    zpubli = al_load_bitmap("data/image/publi.png");
    if(!zpubli) printf("Blad wczytywania obrazu publi\n");
    zradosc = al_load_bitmap("data/image/radosc.png");
    if(!zradosc) printf("Blad wczytywania obrazu radosc\n");
    zstrach = al_load_bitmap("data/image/strach.png");
    if(!zstrach) printf("Blad wczytywania obrazu strach\n");
    ztele = al_load_bitmap("data/image/tele.png");
    if(!ztele) printf("Blad wczytywania obrazu tele\n");
    zmenu = al_load_bitmap("data/image/menu.png");
    if(!zmenu) printf("Blad wczytywania obrazu menu\n");
    zsmutny = al_load_bitmap("data/image/smutek.png");
    if(!zsmutny) printf("Blad wczytywania obrazu smutek\n");
    zstud = al_load_bitmap("data/image/stud.jpg");
    if(!zstud) printf("Blad wczytywania obrazu stud\n");

    font0 = al_load_ttf_font("data/font/arial.ttf", height_monitor*0.1, 0);
        if(!font0) printf("Blad wczytywania font-u 0\n");
    font1 = al_load_ttf_font("data/font/thewitcher.ttf", height_monitor*0.16, 0);
        if(!font1) printf("Blad wczytywania font-u 1\n");
    font2 = al_load_ttf_font("data/font/arial.ttf", height_monitor*0.04, 0);
        if(!font2) printf("Blad wczytywania font-u 2\n");
    font3 = al_load_ttf_font("data/font/arial.ttf", height_monitor*0.03, 0);
        if(!font3) printf("Blad wczytywania font-u 0\n");
    font4 = al_load_ttf_font("data/font/arial.ttf", height_monitor*0.05, 0);
        if(!font4) printf("Blad wczytywania font-u 0\n");
    font9 = al_load_ttf_font("data/font/thewitcher.ttf", height_monitor*0.05, 0);
        if(!font9) printf("Blad wczytywania font-u 0\n");



    intro = al_load_sample("data/music/intro.mp3");
    //if(!intro) printf("Blad wczytywania dzwieku intro \n");
    gra = al_load_sample("data/music/gra.mp3");
   // if(!gra) printf("Blad wczytywania dzwieku gra \n");
    telefon = al_load_sample("data/music/telefon.mp3");
   // if(!telefon) printf("Blad wczytywania dzwieku telefon \n");
    publicznosc = al_load_sample("data/music/publicznosc.mp3");
   // if(!publicznosc) printf("Blad wczytywania dzwieku publicznosc \n");
    polowa = al_load_sample("data/music/polowa.mp3");
   // if(!polowa) printf("Blad wczytywania dzwieku polowa \n");
    pytanie = al_load_sample("data/music/pytanie.mp3");
   // if(!pytanie) printf("Blad wczytywania dzwieku pytanie \n");
    zwycienstwo = al_load_sample("data/music/zwycienstwo.mp3");
   // if(!zwycienstwo) printf("Blad wczytywania dzwieku zwycienstwo \n");
    zle = al_load_sample("data/music/zle.mp3");
   // if(!porazka) printf("Blad wczytywania dzwieku porazka \n");
    koniec = al_load_sample("data/music/koniec.mp3");
   // if(!koniec) printf("Blad wczytywania dzwieku koniec \n");
    kolo = al_load_sample("data/music/kolo.mp3");
   // if(!kolo) printf("Blad wczytywania dzwieku kolo \n");
    przycisk = al_load_sample("data/music/przycisk.mp3");
   // if(!przycisk) printf("Blad wczytywania dzwieku przycisk \n");

    al_reserve_samples(11);

    nvidia= al_open_video("data/video/nvidia.ogv");
    amd= al_open_video("data/video/amd.ogv");
    cry= al_open_video("data/video/cry.ogv");
    studio= al_open_video("data/video/studio.ogv");

    al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    display = al_create_display(width_monitor, height_monitor);

    queue = al_create_event_queue();
    queue1 = al_create_event_queue();
    al_register_event_source(queue, al_get_video_event_source(nvidia));
    al_register_event_source(queue, al_get_video_event_source(amd));
    al_register_event_source(queue, al_get_video_event_source(cry));
    al_register_event_source(queue1, al_get_video_event_source(studio));
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));


    open_file(dlcl);

    start(height_monitor,width_monitor, event, queue ,display,ztlo,bitmap, font0, font1, START_TIME,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,nvidia,amd,cry,studio);

    menu(dlcl, tm, height_monitor,width_monitor, event, queue ,queue1,display,zstud,bitmap,studio,zsmutny,zpubli,zradosc,zstrach,ztele,zautor,zhub1,zja,zmilion,zmilion1,zhub,zman,zman1,zman2,znick,zmenu,ztlo1,ztlo,ztel,zpub,zpol, font0, font1, font2,font3,font4,font9, TIME_GAME,intro,gra,telefon,publicznosc,polowa,pytanie,zwycienstwo,zle,koniec,kolo,przycisk,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11,player_name);

}

