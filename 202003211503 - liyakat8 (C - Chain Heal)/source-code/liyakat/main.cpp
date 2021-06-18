#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

struct node {
    int X, Y;
    int Mevcut_PP, Max_PP;
    char *ad;

    struct node *next;
    int visited;

    int adj_size;
    struct node **adj_list;

    int saglik;
};

int initial_range, jump_range, num_jumps;
double initial_power = 0;
double power_reduction;

struct node *first;
struct node *current;
struct node *temp;

int best_saglik;
struct node **best_path;
int **saglik;

struct node **temp_path;
int **current_saglik;

struct node *check1;
struct node *check2;

int th = 0;

void dfs(struct node* node, int hop, int num_jumpsL, int toplam_saglik, struct node* from, int counter_array) {

    int gereken_saglik;
    double reset_init_power = initial_power;

    if (node->visited == 1 || hop > num_jumpsL) {
        node->visited = 0;
        return;
    }
    int count;

    temp_path[counter_array] = node;

    if (counter_array == num_jumpsL - 1) {
        int loop_C;
        for (loop_C = 0; loop_C < num_jumpsL; loop_C++) {

            gereken_saglik = temp_path[loop_C]->Max_PP - temp_path[loop_C]->Mevcut_PP;
            if (gereken_saglik < initial_power)
                temp_path[loop_C]->saglik = gereken_saglik;
            else
                temp_path[loop_C]->saglik = rint(initial_power);
            
            initial_power = initial_power * (1 - power_reduction);
            toplam_saglik = toplam_saglik + temp_path[loop_C]->saglik;
            th = toplam_saglik;

            printf("%s %d\n", temp_path[loop_C]->ad, temp_path[loop_C]->saglik);
        }

        int dupC;
        int dupC2;
        for (dupC = 0; dupC < num_jumpsL - 1; dupC++) {
            for (dupC2 = dupC + 1; dupC2 < num_jumpsL; dupC2++) {
                check1 = temp_path[dupC];
                check2 = temp_path[dupC2];

                if (check1 == check2)
                    toplam_saglik = 0;
            }

        }

        initial_power = reset_init_power;

        int x;
        if (toplam_saglik > best_saglik) {

            best_saglik = toplam_saglik;
            for (x = 0; x < num_jumpsL; x++) {
                best_path[x] = temp_path[x];
                saglik[x] = current_saglik[x];
            }
        }
    }

    for (count = 0; count < node->adj_size; count++) {
        node->visited = 1;
        dfs(node->adj_list[count], hop + 1, num_jumpsL, toplam_saglik, node->next, counter_array + 1);
    }

}

int main(int argc, char *argv[]) {

    first = (struct node*) malloc(sizeof (struct node));
    current = (struct node*) malloc(sizeof (struct node));
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
    int node_counter = 0;

    while (fscanf(f, "%d %d %d %d %s", &x, &y, &Mevcut_PP, &Max_PP, ad) != EOF) {
        temp = (struct node*) malloc(sizeof (struct node));
        temp->X = x;
        temp->Y = y;
        temp->Mevcut_PP = Mevcut_PP;
        temp->Max_PP = Max_PP;
        temp->ad = (char*) malloc(sizeof (char) * 100);
        strcpy(temp->ad, ad);

        if (node_counter <= 0) {
            first = temp;
            first->next = NULL;
            current = first;
        } else {
            current->next = temp;
            current = temp;
            current->next = NULL;
        }

        node_counter++;
    }
    fclose(f);

    current = first;
    int looper = 0;

    struct node *outer_current = (struct node*) malloc(sizeof (struct node));
    struct node *inner_current = (struct node*) malloc(sizeof (struct node));

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
        outer_current->adj_list = (struct node**) malloc(sizeof (struct node*) * outer_current->adj_size);
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

    temp_path = (struct node**) malloc(sizeof (struct node*) * num_jumps);
    current_saglik = (int**) malloc(sizeof (int*) * num_jumps);

    best_path = (struct node**) malloc(sizeof (struct node*) * num_jumps);
    saglik = (int**) malloc(sizeof (int*)*num_jumps);

    check1 = (struct node*) malloc(sizeof (struct node));
    check2 = (struct node*) malloc(sizeof (struct node));

    best_saglik = 0;

    int counter;
    current = first;

    for (counter = 0; counter < node_counter; counter++) {
        if (sqrt(((first->X - current->X)*(first->X - current->X)) +
                ((first->Y - current->Y)*(first->Y - current->Y))) <= initial_range) {

            dfs(current, 1, num_jumps, 0, NULL, 0);
            current = current->next;

        }
    }
    printf("Toplam_İyileşme: %d\n", th);
    return 0;
}
