# include <stdio.h>

void print_hospital_info(){
    printf("\nCity Hospital Billing System\n");
    printf("1 => General Ward  : Rs. 1500/day\n");
    printf("2 => Semi-Private  : Rs. 3500/day\n");
    printf("3 => Private       : Rs. 6000/day\n");
}

int get_room_type(){
    int room;
    printf("Enter room type (1 to 3): ");
    scanf("%d", &room);
    return room;
}

int get_days(){
    int days;
    printf("Enter number of days stayed (1 to 30): ");
    scanf("%d", &days);
    return days;
}

float get_medicine_bill(){
    float med;
    printf("Enter medicine bill: ");
    scanf("%f", &med);
    return med;
}

int find_room_charges(int room_type, int days){
    int rate = 0;
    switch (room_type){
        case 1:
            rate = 1500;
            break;
        case 2:
            rate = 3500;
            break;
        case 3:
            rate = 6000;
            break;
        default:
            rate = 0;
            break;
    }
    return rate * days;
}

float find_new_medicine_charge(float medicine_bill){
    float service_charge = medicine_bill * 0.05;
    return medicine_bill + service_charge;
}

float apply_discount(float total, int days){
    float discount = 0;
    if (days >= 7){
        discount = total * 0.08;
    }
    else {
        discount = 0;
    }
    return total - discount;
}

void print_final_bill(int room_type, int days, int room_charges, float med_charges, float final_amount){
    printf("\n========== HOPITAL FINAL BILL ==========\n");
    printf("Room Type     : ");
    switch (room_type){
        case 1:
            printf("General Ward\n");
            break;
        case 2:
            printf("Semi-Private\n");
            break;
        case 3:
            printf("Private\n");
            break;
    }
    printf("Days Stayed   : %d\n", days);
    printf("Room Charges  : Rs. %d\n", room_charges);
    printf("Medicine Bill : Rs. %.2f\n", med_charges);
    printf("Final Amount  : Rs. %.2f\n", final_amount);
    printf("=======================================\n");
}

int main(){
    int room_type, days, room_charges;
    float base_med, med_charges, total_amount, discounted_amount, final_amount;
    char senior_choice;

    print_hospital_info();

    room_type = get_room_type();
    days = get_days();
    base_med = get_medicine_bill();

    room_charges = find_room_charges(room_type, days);
    med_charges = find_new_medicine_charge(base_med);

    total_amount = room_charges + med_charges;
    discounted_amount = apply_discount(total_amount, days);

    printf("Is the patient a senior citizen? (y/n): ");
    scanf(" %c", &senior_choice);

    final_amount = discounted_amount;
    if (senior_choice == 'y' || senior_choice == 'Y'){
        final_amount -= 1000;
    }

    if (final_amount < 0){
        final_amount = 0;
    }

    print_final_bill(room_type, days, room_charges, med_charges, final_amount);

}