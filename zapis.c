void write_to_file(struct dll_node *node, int punkty, char player_name[], struct tm tm){

    FILE *write_file;

    write_file = fopen("results.txt","a+");

    fprintf(write_file, "%s %d %d %d %d\n", player_name, punkty, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    insert_node(node, punkty, player_name, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    fclose(write_file);

}
