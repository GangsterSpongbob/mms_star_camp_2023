#ifndef BANK_ACC_H
#define BANK_ACC_H

#include <stdint.h>

#define CURRENCY_NAME_LEN 4
#define SUPPORTED_CURRENCIES 8

extern char currencies[SUPPORTED_CURRENCIES][CURRENCY_NAME_LEN];

typedef struct Bank_Account
{
    uint16_t id;
    char account_holder_name[100];
    double availability;
    char *currency;
} bank_acc;

bank_acc generate_random_account(uint8_t);
void print_account_info(bank_acc *);

double get_balance(bank_acc *);

#endif // BANK_ACC_H