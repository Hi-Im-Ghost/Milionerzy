void open_file(struct dll_node *node){

    char buff[15];
    int punkty, a, b, c;

    FILE *file_read;

    file_read = fopen("results.txt","r+");

    while (fscanf(file_read, "%s%d%d%d%d", buff, &punkty, &a, &b, &c) != EOF)
        insert_node(node, punkty, buff, a, b, c);

    fclose(file_read);

}

