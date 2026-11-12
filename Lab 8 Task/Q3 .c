# include <stdio.h>

void print_bus_info(){
    printf("\nBus Ticket Booking System: \n");
    printf("1 => Karachi to Hyderabad : Rs. 800\n");
    printf("2 => Karachi to Sukkur    : Rs. 2200\n");
    printf("3 => Karachi to Multan    : Rs. 3500\n");
}

int get_route_number(){
    int route;
    printf("Enter route number (1 to 3): ");
    scanf("%d", &route);
    return route;
}

int get_seats(){
    int seats;
    printf("Enter number of seats (1 to 6): ");
    scanf("%d", &seats);
    return seats;
}

char get_seat_type(){
    char type;
    printf("Enter seat type (E for Economy, B for Business): ");
    scanf(" %c", &type);
    return type;
}

int find_seat_fare(int route_num){
    int fare = 0;
    switch (route_num){
        case 1:
            fare = 800;
            break;
        case 2:
            fare = 2200;
            break;
        case 3:
            fare = 3500;
            break;
        default:
            fare = 0;
            break;
    }
    return fare;
}

int find_total_fare(int seat_fare, int seats){
    return seat_fare * seats;
}

float find_new_total(int total_fare, char seat_type){
    float new_total = total_fare;
    if (seat_type == 'B' || seat_type == 'b'){
        new_total = total_fare + (total_fare * 0.30);
    }
    return new_total;
}

void print_ticket(int route_num, int seats, char seat_type, float final_fare){
    printf("\n========== BUS TICKET ==========\n");
    printf("Route         : ");
    switch (route_num){
        case 1:
            printf("Karachi to Hyderabad\n");
            break;
        case 2:
            printf("Karachi to Sukkur\n");
            break;
        case 3:
            printf("Karachi to Multan\n");
            break;
    }
    printf("Seats         : %d\n", seats);
    printf("Seat Type     : ");
    if (seat_type == 'B' || seat_type == 'b'){
        printf("Business\n");
    }
    else {
        printf("Economy\n");
    }
    printf("Final Fare    : Rs. %.2f\n", final_fare);
    printf("================================\n");
}

int main(){
    int i, route_num, seats, seat_fare, total_fare;;
    char seat_type;
    float final_fare, total_earnings = 0;

    print_bus_info();

    for (i = 0; i < 2; i++){
        printf("\nPassenger %d of 2\n", i + 1);

        route_num = get_route_number();
        seats = get_seats();
        seat_type = get_seat_type();

        seat_fare = find_seat_fare(route_num);

        if (seat_fare == 0){
            printf("Invalid route number! Please try again.\n");
            i--;
            continue;
        }

        total_fare = find_total_fare(seat_fare, seats);
        final_fare = find_new_total(total_fare, seat_type);

        print_ticket(route_num, seats, seat_type, final_fare);

        total_earnings += final_fare;
    }

    printf("\nTotal earnings of the bus company: Rs. %.2f\n\n", total_earnings);

}