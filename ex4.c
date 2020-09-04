#include <stdio.h>

int main() {
    int hours, minutes, slephours, slepminutes;
do {
    printf("Enter current time (hh:mm): ");
    scanf("%d:%d", &hours, &minutes);

        if ((hours > 23) || (hours < 0) || (minutes > 59) || (minutes < 0))
         printf("Error, numbers shoud be (0-23 for hours and 0-59 for minutes)!\n");
	} while ((hours> 23) || (hours < 0) || (minutes > 59) || (minutes < 0));


do {
    printf("How long do you want to sleep (h:mm): ");
    scanf("%d:%d", &slephours, &slepminutes);

        if ((slephours > 23) || (slephours < 0) || (slepminutes > 59) || (slepminutes < 0))
         printf("Error, numbers shoud be (0-23 for hours and 0-59 for minutes)!\n");
	} while ((slephours> 23) || (slephours < 0) || (slepminutes > 59) || (slepminutes < 0));

if ((minutes + slepminutes) < 60) {
    printf("If you go to bed now you must wake up at %d:%d.\n\n", (hours + slephours)%24, (minutes + slepminutes));
}
else {
    printf("If you go to bed now you must wake up at %d:%d.\n\n", (hours + slephours + 1)%24, (minutes + slepminutes)%60);
  }
}
