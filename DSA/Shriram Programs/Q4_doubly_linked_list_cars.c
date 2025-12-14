#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Car {
    char model[30];
    char manufacturer[30];
    float price;
    int engineCC;
    struct Car *prev, *next;
};

struct Car *head = NULL;

struct Car* createCar(const char *model, const char *manufacturer, float price, int engineCC) {
    struct Car *c = (struct Car*)malloc(sizeof(struct Car));
    strcpy(c->model, model);
    strcpy(c->manufacturer, manufacturer);
    c->price = price;
    c->engineCC = engineCC;
    c->prev = c->next = NULL;
    return c;
}

void insertCar() {
    char model[30], manufacturer[30];
    float price;
    int engineCC;
    printf("Enter model, manufacturer, price, engineCC: ");
    scanf("%s %s %f %d", model, manufacturer, &price, &engineCC);
    struct Car *c = createCar(model, manufacturer, price, engineCC);
    c->next = head;
    if (head)
        head->prev = c;
    head = c;
}

struct Car* findCar(const char *model) {
    struct Car *temp = head;
    while (temp) {
        if (strcmp(temp->model, model) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void deleteCar() {
    char model[30];
    printf("Enter model to delete: ");
    scanf("%s", model);
    struct Car *c = findCar(model);
    if (!c) {
        printf("Model not found.\n");
        return;
    }
    if (c->prev)
        c->prev->next = c->next;
    else
        head = c->next;
    if (c->next)
        c->next->prev = c->prev;
    free(c);
    printf("Model deleted.\n");
}

void updateCar() {
    char model[30];
    printf("Enter model to update price: ");
    scanf("%s", model);
    struct Car *c = findCar(model);
    if (!c) {
        printf("Model not found.\n");
        return;
    }
    printf("Enter new price: ");
    scanf("%f", &c->price);
}

void listByPriceRange() {
    float low, high;
    printf("Enter price range low high: ");
    scanf("%f%f", &low, &high);
    struct Car *temp = head;
    while (temp) {
        if (temp->price >= low && temp->price <= high)
            printf("%s %s %.2f %dcc\n", temp->model, temp->manufacturer, temp->price, temp->engineCC);
        temp = temp->next;
    }
}

void listDetailsByModel() {
    char model[30];
    printf("Enter model: ");
    scanf("%s", model);
    struct Car *c = findCar(model);
    if (!c) {
        printf("Model not found.\n");
        return;
    }
    printf("Model: %s, Manufacturer: %s, Price: %.2f, Engine: %dcc\n", c->model, c->manufacturer, c->price, c->engineCC);
}

void displayAll() {
    struct Car *temp = head;
    while (temp) {
        printf("%s %s %.2f %dcc\n", temp->model, temp->manufacturer, temp->price, temp->engineCC);
        temp = temp->next;
    }
}

int main() {
    int ch;
    do {
        printf("\n1.Insert 2.Delete 3.Update Price 4.List in Price Range 5.Show by Model 6.Display All 7.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1: insertCar(); break;
        case 2: deleteCar(); break;
        case 3: updateCar(); break;
        case 4: listByPriceRange(); break;
        case 5: listDetailsByModel(); break;
        case 6: displayAll(); break;
        case 7: printf("Exiting...\n"); break;
        default: printf("Invalid choice.\n");
        }
    } while (ch != 7);
    return 0;
}
