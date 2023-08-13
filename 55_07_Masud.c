#include <stdio.h>

// Define the structure
struct time_struct {
    int hour;
    int minute;
    int second;
};

// Function to input new time
void inputTime(struct time_struct *time) {
    printf("Enter hour: ");
    scanf("%d", &time->hour);

    printf("Enter minute: ");
    scanf("%d", &time->minute);

    printf("Enter second: ");
    scanf("%d", &time->second);
}

// Function to display the time
void displayTime(const struct time_struct *time) {
    printf("%02d:%02d:%02d\n", time->hour, time->minute, time->second);
}

// Function to update time by one second
void updateTime(struct time_struct *time) {
    time->second++;

    if (time->second == 60) {
        time->second = 0;
        time->minute++;

        if (time->minute == 60) {
            time->minute = 0;
            time->hour++;

            if (time->hour == 24) {
                time->hour = 0;
            }
        }
    }
}

int main() {
    struct time_struct time;

    printf("Input new time:\n");
    inputTime(&time);

    printf("\nTime entered:\n");
    displayTime(&time);

    printf("\nUpdating time by one second...\n");
    updateTime(&time);

    printf("\nUpdated time:\n");
    displayTime(&time);

    return 0;
}
