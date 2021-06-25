struct dll_node{

    int data;
    char nick[15];
    int date_d;
    int date_m;
    int date_y;

    struct dll_node *prev ,*next;

};

struct dll_node *create_list(int data, char nick[]){

    int i;

    struct dll_node *new_node = (struct dll_node *)malloc(sizeof(struct dll_node));
    if( NULL != new_node){

        new_node->data = data;

        for(i = 0; i < 15; i++){
            if(i < strlen(nick))
                new_node->nick[i] = nick[i];
            else
                new_node->nick[i] = '\0';
        }

        new_node->date_d = 0;
        new_node->date_m = 0;
        new_node->date_y = 0;

        new_node->prev = new_node->next = new_node;

    }

return new_node;
}

struct dll_node *find_max_node(struct dll_node *node){

    struct dll_node *start = node, *result = node;
    int maximum = node->data;
    do{

        if( maximum < node->data){

            maximum = node->data;
            result = node;

        }

    node = node->next;
    } while(node != start);

    return result;

};

struct dll_node * find_next_node(struct dll_node *node ,int data){

    node = find_max_node(node);
    struct dll_node *start = node ;
    do{

        if(node-> data < data)
        break;
        node = node->next;

    } while(node != start);

    return node;

};

void insert_node(struct dll_node *node ,int data, char nick[], int a, int b, int c){

    int i;

    if(NULL == node)
        return ;

    struct dll_node *new_node = (struct dll_node *)malloc(sizeof(struct dll_node));
    if(NULL != new_node){

        new_node->data = data;

        for(i = 0; i < 15; i++){
            if(i < strlen(nick))
                new_node->nick[i] = nick[i];
            else
                new_node->nick[i] = '\0';
        }
        new_node->date_d = a;
        new_node->date_m = b;
        new_node->date_y = c;

        node = find_next_node(node, data) ;
        new_node->next = node;
        new_node->prev = node-> prev;
        node->prev->next = new_node;
        node-> prev = new_node;

    }
}

void print_list(struct dll_node *node, ALLEGRO_FONT *font, ALLEGRO_FONT *font2, int width_monitor, int height_monitor){

    if(NULL == node)
        return;

    int b = 1, c = 1;

    int number = number_of_element(node);

    number-=1;

    node = find_max_node(node);
    struct dll_node *start = node;

        if(number <= 17){

            al_draw_textf(font2, al_map_rgb(0,0,0), width_monitor*0.35, height_monitor*0.05, ALLEGRO_ALIGN_CENTRE, "Nick ");
            al_draw_textf(font2, al_map_rgb(0,0,0), width_monitor*0.5, height_monitor*0.05, ALLEGRO_ALIGN_CENTRE, "Wygrana");
            al_draw_textf(font2, al_map_rgb(0,0,0), width_monitor*0.65, height_monitor*0.05, ALLEGRO_ALIGN_CENTRE, "Data");

        }
        else{

            al_draw_textf(font2, al_map_rgb(0,0,0), width_monitor*0.1, height_monitor*0.05, ALLEGRO_ALIGN_CENTRE, "Nick ");
            al_draw_textf(font2, al_map_rgb(0,0,0), width_monitor*0.25, height_monitor*0.05, ALLEGRO_ALIGN_CENTRE, "Wygrana");
            al_draw_textf(font2, al_map_rgb(0,0,0), width_monitor*0.4, height_monitor*0.05, ALLEGRO_ALIGN_CENTRE, "Data");

            al_draw_textf(font2, al_map_rgb(0,0,0), width_monitor*0.6, height_monitor*0.05, ALLEGRO_ALIGN_CENTRE, "Nick ");
            al_draw_textf(font2, al_map_rgb(0,0,0), width_monitor*0.75, height_monitor*0.05, ALLEGRO_ALIGN_CENTRE, "Wygrana");
            al_draw_textf(font2, al_map_rgb(0,0,0), width_monitor*0.9, height_monitor*0.05, ALLEGRO_ALIGN_CENTRE, "Data");

        }

        do{

        if(node->data != -1){

            if(number <= 17){

                if(node->data == 1)
                    al_draw_textf(font, al_map_rgb(0,0,0), width_monitor*0.5, height_monitor*(0.07+(0.05*b)), ALLEGRO_ALIGN_CENTRE, "MIECZAK");
                else if(node->data == 1000000)
                    al_draw_textf(font, al_map_rgb(206,181,59), width_monitor*0.5, height_monitor*(0.07+(0.05*b)), ALLEGRO_ALIGN_CENTRE, "%d" ,node->data);
                else
                    al_draw_textf(font, al_map_rgb(0,0,0), width_monitor*0.5, height_monitor*(0.07+(0.05*b)), ALLEGRO_ALIGN_CENTRE, "%d" ,node->data);

                al_draw_textf(font, al_map_rgb(0,0,0), width_monitor*0.35, height_monitor*(0.07+(0.05*b)), ALLEGRO_ALIGN_CENTRE, "%s", node->nick);
                al_draw_textf(font, al_map_rgb(0,0,0), width_monitor*0.65, height_monitor*(0.07+(0.05*b)), ALLEGRO_ALIGN_CENTRE, "%d.%d.%d", node->date_d, node->date_m, node->date_y);

                b++;

            }
            else{

                if(b <= 17){

                    if(node->data == 1)
                        al_draw_textf(font, al_map_rgb(0,0,0), width_monitor*0.25, height_monitor*(0.07+(0.05*b)), ALLEGRO_ALIGN_CENTRE, "MIECZAK");
                    else if(node->data == 1000000)
                        al_draw_textf(font, al_map_rgb(206,181,59), width_monitor*0.25, height_monitor*(0.07+(0.05*b)), ALLEGRO_ALIGN_CENTRE, "%d" ,node->data);
                    else
                        al_draw_textf(font, al_map_rgb(0,0,0), width_monitor*0.25, height_monitor*(0.07+(0.05*b)), ALLEGRO_ALIGN_CENTRE, "%d" ,node->data);

                    al_draw_textf(font, al_map_rgb(0,0,0), width_monitor*0.1, height_monitor*(0.07+(0.05*b)), ALLEGRO_ALIGN_CENTRE, "%s", node->nick);
                    al_draw_textf(font, al_map_rgb(0,0,0), width_monitor*0.4, height_monitor*(0.07+(0.05*b)), ALLEGRO_ALIGN_CENTRE, "%d.%d.%d", node->date_d, node->date_m, node->date_y);

                    b++;

                }

                else{

                    if(c <= 17){

                        if(node->data == 1)
                            al_draw_textf(font, al_map_rgb(0,0,0), width_monitor*0.75, height_monitor*(0.07+(0.05*c)), ALLEGRO_ALIGN_CENTRE, "MIECZAK");
                        else if(node->data == 1000000)
                            al_draw_textf(font, al_map_rgb(0,0,0), width_monitor*0.75, height_monitor*(0.07+(0.05*c)), ALLEGRO_ALIGN_CENTRE, "%d" ,node->data);
                        else
                            al_draw_textf(font, al_map_rgb(0,0,0), width_monitor*0.75, height_monitor*(0.07+(0.05*c)), ALLEGRO_ALIGN_CENTRE, "%d" ,node->data);

                        al_draw_textf(font, al_map_rgb(0,0,0), width_monitor*0.6, height_monitor*(0.07+(0.05*c)), ALLEGRO_ALIGN_CENTRE, "%s", node->nick);
                        al_draw_textf(font, al_map_rgb(0,0,0), width_monitor*0.9, height_monitor*(0.07+(0.05*c)), ALLEGRO_ALIGN_CENTRE, "%d.%d.%d", node->date_d, node->date_m, node->date_y);

                        c++;

                    }

                }


            }

        }

        node = node->next;


        }while(node != start);


}

int number_of_element(struct dll_node *node){

    if(NULL == node)
        return;

    int b = 0;

    node = find_max_node(node);
    struct dll_node *start = node;

    do{

        b++;

        node = node->next;


    }while(node != start);

    return b;

}
