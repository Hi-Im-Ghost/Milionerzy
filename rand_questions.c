//losowanie pytan

int rand_questions(int array_number_questions[12]){

    int i=0, j, a, b;

    do{

        b = 0;

        a = rand()%100;

        if(i == 0){
            array_number_questions[i] = a;
            i++;
            continue;
        }

        for(j=0;j<=i;j++){
            if(array_number_questions[j] == a){
                b = 1;
                continue;
            }
        }
        if(b != 1){
            array_number_questions[i] = a;
            i++;
        }

    }while(i <= 12);

    return array_number_questions;

}
