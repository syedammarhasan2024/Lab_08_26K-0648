# include <stdio.h>

void print_taxi_info(){
    printf("\nTaxi Fare Calculation System:\n");
    printf("Base Fare   : Rs. 150\n");
    printf("First 10 km : Rs. 60 per km\n");
    printf("After 10 km : Rs. 45 per km\n");
}

float get_distance(){
    float distance;
    printf("Enter distance in km (more than 0, up to 200): ");
    scanf("%f", &distance);
    return distance;
}

int get_waiting_time(){
    int waiting;
    printf("Enter waiting time in minutes (0 to 120): ");
    scanf("%d", &waiting);
    return waiting;
}

int get_hour(){
    int hour;
    printf("Enter hour of the trip (0 to 23): ");
    scanf("%d", &hour);
    return hour;
}

float find_distance_charge(float distance){
    float charge = 150;
    if (distance <= 10){
        charge += distance * 60;
    }
    else {
        charge += (10 * 60) + ((distance - 10) * 45);
    }
    return charge;
}

float find_waiting_charge(int waiting_time){
    float charge = 0;
    if (waiting_time > 5){
        charge = (waiting_time - 5) * 10;
    }
    return charge;
}

float find_new_fare(float current_fare, int hour){
    float new_fare = current_fare;
    if (hour >= 22 || hour < 6){
        new_fare = current_fare + (current_fare * 0.25);
    }
    return new_fare;
}

void print_trip_receipt(float distance, int waiting_time, float final_fare){
    printf("\n========== TAXI TRIP RECEIPT ==========\n");
    printf("Distance      : %.2f km\n", distance);
    printf("Waiting Time  : %d minutes\n", waiting_time);
    printf("Final Fare    : Rs. %.2f\n", final_fare);
    printf("=======================================\n");
}

int main(){
    int i, waiting_time, hour;
    float distance, dist_charge, wait_charge, trip_fare, final_fare;
    float total_earnings = 0, highest_fare = 0;

    print_taxi_info();

    for (i = 0; i < 3; i++){
        printf("\nTrip %d of 3\n", i + 1);

        distance = get_distance();
        waiting_time = get_waiting_time();
        hour = get_hour();

        if (distance <= 0 || distance > 200 || waiting_time < 0 || waiting_time > 120 || hour < 0 || hour > 23){
            printf("Invalid input! Please try again.\n");
            i--;
            continue;
        }

        dist_charge = find_distance_charge(distance);
        wait_charge = find_waiting_charge(waiting_time);

        trip_fare = dist_charge + wait_charge;
        final_fare = find_new_fare(trip_fare, hour);

        print_trip_receipt(distance, waiting_time, final_fare);

        total_earnings += final_fare;

        if (final_fare > highest_fare){
            highest_fare = final_fare;
        }
    }

    printf("\nTotal earnings of the day: Rs. %.2f\n", total_earnings);
    printf("Highest fare of the day  : Rs. %.2f\n\n", highest_fare);

}