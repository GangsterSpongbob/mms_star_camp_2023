#include "bank_acc.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char currencies[SUPPORTED_CURRENCIES][CURRENCY_NAME_LEN] = {"USD", "EUR", "JPY", "GBP", "AUD", "CAD", "BGN", "TRY"};

bank_acc generate_random_account(uint8_t randomizer)
{

    srand(time(NULL) + randomizer);
    bank_acc new_account;

    new_account.id = randomizer;

    uint8_t names_count = rand() % 4 + 2;
    uint8_t name_index = 0;

    for (size_t i = 0; i < names_count; i++)
    {
        uint8_t name_len = rand() % 20 + 1;
        for (size_t j = 0; j < name_len; j++)
        {
            new_account.account_holder_name[name_index++] = 'A' + rand() % 26 + rand() % 2 * ('a' - 'A');
        }
        new_account.account_holder_name[name_index++] = ' ';
    }
    new_account.account_holder_name[name_index - 1] = '\0';

    new_account.availability = (double)(rand() % 100) / 100 + rand() % 100000;
    new_account.currency = currencies[rand() % (SUPPORTED_CURRENCIES + 1)];

    return new_account;
}

void print_account_info(bank_acc *current_account)
{
    printf("%s%d%s%s%s%.2lf%s%s\n",
           "Account No. ", current_account->id,
           " of ", current_account->account_holder_name,
           " currently holds ", current_account->availability,
           " ", current_account->currency);
}

double get_balance(bank_acc *current_acc)
{
    return current_acc->availability;
}