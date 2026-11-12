# include <stdio.h>

void menu(){
    printf("\nMobile Recharge Packs: \n");
    printf("1 => Rs. 100\n");
    printf("2 => Rs. 200\n");
    printf("3 => Rs. 500\n");
    printf("4 => Rs. 1000\n");
}

int get_pack_number(){
    int pack;
    printf("Enter pack number (1 to 4): ");
    scanf("%d", &pack);
    return pack;
}

long long get_mobile_number(){
    long long mobile;
    printf("Enter 11-digit mobile number: ");
    scanf("%lld", &mobile);
    return mobile;
}

int find_pack_amount(int pack_num){
    int amount = 0;
    switch (pack_num){
        case 1:
            amount = 100;
            break;
        case 2:
            amount = 200;
            break;
        case 3:
            amount = 500;
            break;
        case 4:
            amount = 1000;
            break;
        default:
            amount = 0;
            break;
    }
    return amount;
}

float add_tax(int amount){
    float tax = amount * 0.15;
    return amount + tax;
}

float find_bonus(int amount){
    float bonus = 0;
    if (amount >= 500){
        bonus = amount * 0.10;
    }
    else {
        bonus = 0;
    }
    return bonus;
}

void print_recharge_slip(long long mobile, int amount, float tax, float total_balance){
    printf("\n========== RECHARGE SLIP ==========\n");
    printf("Mobile Number : %011lld\n", mobile);
    printf("Pack Amount   : Rs. %d\n", amount);
    printf("Tax (15%%)     : Rs. %.2f\n", tax);
    printf("Total Balance : Rs. %.2f\n", total_balance);
    printf("==================================\n");
}

int main(){
    int i, amount, pack_num;
    long long mobile_num;
    float tax_amount, new_amount, bonus, total_balance, total_money_spent = 0;

    for (i = 0; i < 3; i++){
        printf("\nRecharge %d of 3\n", i + 1);
        menu();
        
        pack_num = get_pack_number();
        mobile_num = get_mobile_number();
        
        amount = find_pack_amount(pack_num);
        
        if (amount == 0){
            printf("Invalid pack number! Please try again.\n");
            i--;
            continue;
        }

        tax_amount = amount * 0.15;
        new_amount = add_tax(amount);
        bonus = find_bonus(amount);
        total_balance = amount + bonus;

        print_recharge_slip(mobile_num, amount, tax_amount, total_balance);

        total_money_spent += new_amount;
    }

    printf("\nTotal money spent across all recharges: Rs. %.2f\n", total_money_spent);

}
