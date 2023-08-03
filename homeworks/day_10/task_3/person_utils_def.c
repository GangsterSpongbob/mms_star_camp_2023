#include "person_utils.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

void *init_array(size_t capacity)
{
    person *new_peeps = malloc(capacity * sizeof(person));

    return new_peeps;
}

void assign_char_ptr_to_arr(char dest[], size_t max_size, char *src)
{
    for (size_t i = 0; i < max_size; i++)
    {
        if (src[i] == '\0')
        {
            break;
        }
        else
        {
            dest[i] = src[i];
        }
    }
}

person create_person(char *name, uint16_t birth_year, uint8_t birth_month, uint8_t birth_day, uint8_t gender)
{
    srand(time(NULL));
    char rand_id[ID_LEN];
    for (size_t i = 0; i < ID_LEN; i++)
    {
        rand_id[i] = 'A' + rand() % 26 + rand() % 2 * ('A' - 'a');
    }

    person current_person;
    assign_char_ptr_to_arr(current_person.name, NAME_LEN, name);
    assign_char_ptr_to_arr(current_person.id, ID_LEN, rand_id);
    current_person.birth_year = birth_year;
    current_person.birth_month = birth_month;
    current_person.birth_day = birth_day;

    return current_person;
}

person read_person()
{
    char name[NAME_LEN];
    printf("%s%d%s", "Enter name up to ", NAME_LEN, " characters: ");
    scanf("%s", name);

    uint16_t birth_year;
    printf("Enter year of birth: ");
    scanf("%hu", &birth_year);

    uint8_t birth_moth, birth_day;
    printf("Enter date of birth in the format <day> <month>: ");
    scanf("%c %c", &birth_day, &birth_moth);

    uint8_t gender;
    printf("Enter gender (M or F): ");
    scanf("%c", &gender);
    if (toupper(gender) == 'M' || gender == MALE)
    {
        gender = MALE;
    }
    else if (toupper(gender) == 'F' || gender == FEMALE)
    {
        gender = FEMALE;
    }
    else
    {
        gender = !!gender;
    }

    return create_person(name, birth_year, birth_moth, birth_day, gender);
}

int add_person_to_group(person *new_person, people *group)
{
    if (group->count == group->capacity)
    {
        return -1;
    }

    group->arr[group->count++] = *new_person;

    return 0;
}

int print_person(people *group, char *id)
{
    for (size_t i = 0; i < group->count; i++)
    {
        if (!strcmp(id, group->arr[i].id))
        {
            printf("%s%s%s%d%c%d%c%d%s%s\n",
                   "Name: ", group->arr[i].name,
                   ", Birthday: ", group->arr[i].birth_day,
                   '/', group->arr[i].birth_month,
                   '/', group->arr[i].birth_year,
                   ", Gender: ", group->arr[i].gender ? "female" : "male");
            return 0;
        }
    }

    return -1;
}

int remove_person(people *group, char *id)
{
    for (size_t i = 0; i < group->count; i++)
    {
        if (!strcmp(id, group->arr[i].id))
        {
            for (size_t j = 0; j < group->count - i - 1; j++)
            {
                assign_char_ptr_to_arr(group->arr[i + j].name, NAME_LEN, group->arr[i + j + 1].name);
                assign_char_ptr_to_arr(group->arr[i + j].id, ID_LEN, group->arr[i + j + 1].id);
                group->arr[i + j].birth_year = group->arr[i + j + 1].birth_year;
                group->arr[i + j].birth_month = group->arr[i + j + 1].birth_month;
                group->arr[i + j].birth_day = group->arr[i + j + 1].birth_day;
                group->arr[i + j].gender = group->arr[i + j + 1].gender;
            }

            group->count--;

            return 0;
        }
    }

    return -1;
}