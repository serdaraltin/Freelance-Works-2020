#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "unistd.h"

struct dugum {
    int X, Y;
    int Mevcut_PP, Max_PP;
    char *ad;

    struct dugum *next;
    int temas;

    int adj_size;
    struct dugum **adj_list;

    int saglik;
};

int initial_range, jump_range, num_jumps;
double initial_power = 0;
double power_reduction;

struct dugum *first;
struct dugum *current;
struct dugum *temp;

int eniyi_saglik;
struct dugum **eniyi_yol;
int **saglik;

struct dugum **gecici_yol;
int **mevcut_saglik;

struct dugum *kontrol1;
struct dugum *kontrol2;

int th = 0;

void calc(struct dugum*,int,int,int,struct dugum*,int);

int main(int argc, char *argv[]) {

    first = (struct dugum*) malloc(sizeof (struct dugum));
    current = (struct dugum*) malloc(sizeof (struct dugum));
    first = NULL;

    int x, y, Mevcut_PP, Max_PP;
    char *ad = (char*) malloc(sizeof (char) * 100);

    char *_initial_range = argv[1];
    char *_jump_range = argv[2];
    char *_num_jumps = argv[3];
    char *_initial_power = argv[4];
    char *_power_reduction = argv[5];
    initial_range = atoi(_initial_range);
    jump_range = atoi(_jump_range);
    num_jumps = atoi(_num_jumps);
    initial_power = atoi(_initial_power);
    power_reduction = atof(_power_reduction);
    char *_input_file = argv[6];

    FILE *f = fopen(_input_file, "r");
    int dugum_counter = 0;

    while (fscanf(f, "%d %d %d %d %s", &x, &y, &Mevcut_PP, &Max_PP, ad) != EOF) {
        temp = (struct dugum*) malloc(sizeof (struct dugum));
        temp->X = x;
        temp->Y = y;
        temp->Mevcut_PP = Mevcut_PP;
        temp->Max_PP = Max_PP;
        temp->ad = (char*) malloc(sizeof (char) * 100);
        strcpy(temp->ad, ad);

        if (dugum_counter <= 0) {
            first = temp;
            first->next = NULL;
            current = first;
        } else {
            current->next = temp;
            current = temp;
            current->next = NULL;
        }

        dugum_counter++;
    }
    fclose(f);

    current = first;
    int looper = 0;

    struct dugum *outer_current = (struct dugum*) malloc(sizeof (struct dugum));
    struct dugum *inner_current = (struct dugum*) malloc(sizeof (struct dugum));

    outer_current = first;

    while (outer_current) {
        int adj_counter = 0;
        inner_current = first;

        while (inner_current) {
            if (outer_current != inner_current) {
                if (sqrt(((outer_current->X - inner_current->X)*(outer_current->X - inner_current->X)) + ((outer_current->Y - inner_current->Y)*(outer_current->Y
                        - inner_current->Y))) <= jump_range) {
                    adj_counter++;
                }
            }

            inner_current = inner_current->next;
        }

        outer_current->adj_size = adj_counter;
        outer_current = outer_current->next;
    }
    current = first;

    outer_current = first;

    while (outer_current) {
        outer_current->adj_list = (struct dugum**) malloc(sizeof (struct dugum*) * outer_current->adj_size);
        int index_counter = 0;
        inner_current = first;
        while (inner_current) {
            if (outer_current != inner_current) {
                if (sqrt(((outer_current->X - inner_current->X)*(outer_current->X - inner_current->X)) + ((outer_current->Y -
                        inner_current->Y)*(outer_current->Y - inner_current->Y))) <= jump_range) {
                    outer_current->adj_list[index_counter++] = inner_current;
                }
            }

            inner_current = inner_current->next;
        }
        outer_current = outer_current->next;
    }

    gecici_yol = (struct dugum**) malloc(sizeof (struct dugum*) * num_jumps);
    mevcut_saglik = (int**) malloc(sizeof (int*) * num_jumps);

    eniyi_yol = (struct dugum**) malloc(sizeof (struct dugum*) * num_jumps);
    saglik = (int**) malloc(sizeof (int*)*num_jumps);

    kontrol1 = (struct dugum*) malloc(sizeof (struct dugum));
    kontrol2 = (struct dugum*) malloc(sizeof (struct dugum));

    eniyi_saglik = 0;

    int counter;
    current = first;

    for (counter = 0; counter < dugum_counter; counter++) {
        if (sqrt(((first->X - current->X)*(first->X - current->X)) +
                ((first->Y - current->Y)*(first->Y - current->Y))) <= initial_range) {

            calc(current, 1, num_jumps, 0, NULL, 0);
            current = current->next;

        }
    }
    printf("Toplam_İyileşme: %d\n", th);
    return 0;
}



void calc(struct dugum* dugum, int hop, int num_jumpsL, int toplam_saglik, struct dugum* from, int counter_array) {

    int gereken_saglik;
    double reset_init_power = initial_power;

    if (dugum->temas == 1 || hop > num_jumpsL) {
        dugum->temas = 0;
        return;
    }
    int count;

    gecici_yol[counter_array] = dugum;

    if (counter_array == num_jumpsL - 1) {
        int loop_C;
        for (loop_C = 0; loop_C < num_jumpsL; loop_C++) {

            gereken_saglik = gecici_yol[loop_C]->Max_PP - gecici_yol[loop_C]->Mevcut_PP;
            if (gereken_saglik < initial_power)
                gecici_yol[loop_C]->saglik = gereken_saglik;
            else
                gecici_yol[loop_C]->saglik = rint(initial_power);
            
            initial_power = initial_power * (1 - power_reduction);
            toplam_saglik = toplam_saglik + gecici_yol[loop_C]->saglik;
            th = toplam_saglik;

            printf("%s %d\n", gecici_yol[loop_C]->ad, gecici_yol[loop_C]->saglik);
        }

        int dupC;
        int dupC2;
        for (dupC = 0; dupC < num_jumpsL - 1; dupC++) {
            for (dupC2 = dupC + 1; dupC2 < num_jumpsL; dupC2++) {
                kontrol1 = gecici_yol[dupC];
                kontrol2 = gecici_yol[dupC2];

                if (kontrol1 == kontrol2)
                    toplam_saglik = 0;
            }

        }

        initial_power = reset_init_power;

        int x;
        if (toplam_saglik > eniyi_saglik) {

            eniyi_saglik = toplam_saglik;
            for (x = 0; x < num_jumpsL; x++) {
                eniyi_yol[x] = gecici_yol[x];
                saglik[x] = mevcut_saglik[x];
            }
        }
    }

    for (count = 0; count < dugum->adj_size; count++) {
        dugum->temas = 1;
        calc(dugum->adj_list[count], hop + 1, num_jumpsL, toplam_saglik, dugum->next, counter_array + 1);
    }

}