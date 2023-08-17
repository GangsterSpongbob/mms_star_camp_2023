#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "double_link.h"
#include "bank_acc.h"

#define ACCOUNT_ITEMS_COUNT 10

int main(void)
{
    linked_list accounts = init_list();

    for (size_t i = 0; i < ACCOUNT_ITEMS_COUNT; i++)
    {
        bank_acc new_acc = generate_random_account(i);
        data *new_data = create_data(&new_acc);
        push_front(new_data, &accounts);
    }

    printf("%s%.2lf\b", "Sum of balances is: ", calculate_total_balance(&accounts));
    printf("Max balance is in account: ");
    node *max_balance_node = find_max_balance(&accounts);
    print_account_info((bank_acc *)max_balance_node->cur_data->value);

    print_linked_list(&accounts);

    deinit_list(&accounts);

    return 0;
}