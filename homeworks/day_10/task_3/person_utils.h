#ifndef PERSON_UTILS_H
#define PERSON_UTILS_H

#include <stdint.h>
#include <stddef.h>

#define NAME_LEN 100

#define ID_LEN 10

#define MALE 0
#define FEMALE 1

typedef struct Person
{
    char name[NAME_LEN];
    char id[ID_LEN];
    uint16_t birth_year;
    uint8_t birth_month;
    uint8_t birth_day;
    uint8_t gender;
} person;

typedef struct People
{
    person *arr;
    size_t capacity;
    size_t count;
} people;

void *init_array(size_t);
person create_person(char *, uint16_t, uint8_t, uint8_t, uint8_t);
person read_person();
int add_person_to_group(person *, people *);
int print_person(people *, char *);
int remove_person(people *, char *);

void assign_char_ptr_to_arr(char[], size_t, char *);

#endif // PERSON_UTILS_H