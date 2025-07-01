#include <stdio.h>
#include <time.h>
#include <unistd.h>

// ai comments fire
void clearScreen() {
    printf("\033[2J\033[H");
}

void displayTime(int hours, int minutes, int seconds) {
    clearScreen();
    printf("=== FOCUS TIMER ===\n");
    printf("Time remaining: %02d:%02d:%02d\n", hours, minutes, seconds);
    printf("Stay focused! 💪\n");
}

int main(void) {
    printf("How long do you want the timer to be (in minutes)?\n");
    int timerInMinutes;
    scanf("%d", &timerInMinutes);
    
    if (timerInMinutes <= 0) {
        printf("Please enter a positive number of minutes!\n");
        return 1;
    }
    
    printf("Starting %d minute focus session...\n", timerInMinutes);
    sleep(2); // Give user time to read
    
    // Convert to total seconds
    int totalSeconds = timerInMinutes * 60;
    
    // Countdown loop
    while (totalSeconds > 0) {
        int hours = totalSeconds / 3600;
        int minutes = (totalSeconds % 3600) / 60;
        int seconds = totalSeconds % 60;
        
        displayTime(hours, minutes, seconds);
        
        sleep(1); // Wait 1 second
        totalSeconds--;
    }

    clearScreen();
    printf("⏰ TIME'S UP! ⏰\n");
    printf("Great job on your focus session!\n");
    printf("🎉 You completed %d minutes of focused work! 🎉\n", timerInMinutes);
    
    return 0;
}