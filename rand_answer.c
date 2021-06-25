int rand_answer(int array_random_answer[5]){

// losowe ustawianie pytan
    int i = 0, a,b;

    for(i=0;i<=6;i++){
            a = rand()%4;
            b = rand()%4;
            if(a != b)
                swap(&array_random_answer[b],&array_random_answer[a]);
        }

        for(i=0;i<=3;i++)
            if(array_random_answer[i] == 4){
                array_random_answer[4] = i;
                break;
        }

    return array_random_answer;
}

//zamienianie miejscami odpowiedzi

void swap(int *a, int *b){

    int tmp = *a;
    *a = *b;
    *b = tmp;

}
