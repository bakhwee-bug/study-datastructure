#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct word {
    char eng[15];
    char kor[10];
    struct word* next;
}word;

int compare(const void* a, const void* b) {
    word* p1 = (word*)a;
    word* p2 = (word*)b;
    return strcmp(p1->eng, p2->eng);
}

void quiz() {
    FILE* fp;
    int c, v;
    char d;
    fp = fopen("dic.txt", "r");
    int SIZE = 0;

    while ((v = getc(fp)) != EOF) {
        fseek(fp, -1, SEEK_CUR);
        while ((d = getc(fp)) != '\n') {
        }
        SIZE++;
    }//몇단어인지 가져오기

    
    char eng2[15];
    char eng3[15] = { ".quit" };
    word wd_a[SIZE];

    rewind(fp);
    word* current;
    word* head;

    for (int i = 0; i < SIZE; i++) {
        fscanf(fp, "%s", wd_a[i].eng);
        fscanf(fp, "%s", wd_a[i].kor);
    }


    qsort((void*)&wd_a, sizeof(wd_a) / sizeof(wd_a[0]), sizeof(word), compare);

    for (int i = 0; i < SIZE; i++) {
        word* temp = malloc(sizeof(word));
        strcpy(temp->eng, wd_a[i].eng);
        strcpy(temp->kor, wd_a[i].kor);

        if (i != 0) {
            current->next = temp;
        }

        else if (i == 0) {
            head = temp;
        }

        else if (i == SIZE - 1) {
            current->next = NULL;
        }

        current = temp;

    }

 
    double ALL = 0;
    double COR = 0;
    double SCORE = 0;

    printf("%s -> ", head->kor);
    scanf("%s", eng2);

    current = head;

    while ((strcmp(eng2, eng3) != 0) && (current->next !=NULL)) {

        ALL++;
        if (strcmp(current->eng, eng2) == 0) {
            printf("correct!\n");
            COR++;
        }

        else {
            printf("incorrect!\n");
        }

        if (current->next != NULL) {
            current = current->next;
            printf("%s -> ", current->kor);
            scanf("%s", eng2);
        }
    }
    if (ALL == 0) {
        SCORE == 0;
    }

    else {
        SCORE = (COR / ALL) * 100.0;
    }

    printf("당신의 점수는 %.2f 점입니다.\n", SCORE);
   
		fclose(fp);
    current = head;
    while (current->next != NULL) {
        word* past;
        past = current;
        current = current->next;
        free(past);
    }
		int enter;
		enter = getchar();

}
 

int main() {

    int sel;

    printf(">> 영어 단어 맞추기 프로그램 <<\n");
    printf("1. 영어 단어 맞추기       2. 프로그램 종료\n\n번호를 선택하세요: ");
    scanf("%d", &sel);
    while (sel == 1) {
        system("clear");
        quiz();

				while(1){
	 			int enter;
				enter = getchar();
				if(enter == '\n'){
				system("clear");
				break;
				}
				else{
						continue;
				}
			}



        printf(">> 영어 단어 맞추기 프로그램 <<\n");
        printf("1. 영어 단어 맞추기       2. 프로그램 종료\n\n번호를 선택하세요: ");
        scanf("%d", &sel);
    }
		
		system("clear");

    return 0;

}
