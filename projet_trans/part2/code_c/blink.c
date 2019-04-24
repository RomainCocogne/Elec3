// #include <stdio.h>   // pour printf
// #include <stdlib.h>  // pour exit 
// #include <fcntl.h>   // pour open, read, write et close
// #include <unistd.h>  // pour sleep
// #include <errno.h>   // pour perror


// #define LED_PATH "/sys/class/leds/d3/brightness"


// int main(void) {

//   int led_file, i=10;

//   if ((led_file = open(LED_PATH, O_RDWR)) == -1) {
//     perror(LED_PATH);
//     exit(EXIT_FAILURE);
//   }

//   enum {LED_OFF = '0', LED_ON = '1'} led;

//   while(i--){
//       led = LED_ON;
//       write(led_file, &led, sizeof(char));
//       sleep(1);
//       led = LED_OFF;
//       write(led_file, &led, sizeof(char));
//       sleep(1);
//   }
  


//   close(led_file);

//   return EXIT_SUCCESS;

// }