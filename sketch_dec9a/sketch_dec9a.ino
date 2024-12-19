#include <IRremote.h>
#include <Servo.h>

// Define the IR receiver pin
const int IR_PIN = 2;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

int pos1 = 90;
int pos2 = 90;
int pos3 = 90;
int pos4 = 90;
int pos5 = 90;


// Create IR receiver object
IRrecv irrecv(IR_PIN);
decode_results results;

// Global variable to store the generated number
int generatedNumber = 0;

// Define button codes (replace these with your remote's actual codes)
#define BUTTON_1 0xFF629D  // Example up button code for "1" 
#define BUTTON_2 0xFF22DD  // Example left button code for "2"
#define BUTTON_3 0xFFC23D  // Example right button code for "3"
#define BUTTON_4 0xFFA857  // Example down button code for "4"
#define BUTTON_5 0xFF02FD  // Example ok button code for "5"
#define BUTTON_6 0xFF6897  // Example one button code for "6"
#define BUTTON_7 0xFF9867  // Example two button code for "7"
#define BUTTON_8 0xFFB04F  // Example three button code for "8"
#define BUTTON_9 0xFF30CF  // Example four button code for "9"
#define BUTTON_10 0xFF18E7  // Example five button code for "10"
#define BUTTON_11 0xFF7A85  // Example six button code for "11"
#define BUTTON_12 0xFF10EF  // Example seven button code for "12"
#define BUTTON_13 0xFF38C7  // Example eight button code for "13"
#define BUTTON_14 0xFF5AA5  // Example nine button code for "14"
#define BUTTON_15 0xFF42BD  // Example * button code for "15"
#define BUTTON_16 0xFF4AB5  // Example zero button code for "16"
#define BUTTON_17 0xFF52AD  // Example # button code for "17"

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the IR receiver
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);
  irrecv.blink13(true);
}

void loop() {
  if (irrecv.decode(&results)) {
    servo1.write(pos1);
    servo2.write(pos2);
    servo3.write(pos3);
    servo4.write(pos4);
    servo5.write(pos5);

    // Print the received code for debugging
    Serial.print("Received code: ");
    Serial.println(results.value, HEX);

    // Match the received code and set the generatedNumber
    switch (results.value) {
      case BUTTON_1:
        generatedNumber = 1;
        break;
      case BUTTON_2:
        generatedNumber = 2;
        break;
      case BUTTON_3:
        generatedNumber = 3;
        break;
      case BUTTON_4:
        generatedNumber = 4;
        break;
      case BUTTON_5:
        generatedNumber = 5;
        break;
      case BUTTON_6:
        generatedNumber = 6;
        break;
      case BUTTON_7:
        generatedNumber = 7;
        break;
      case BUTTON_8:
        generatedNumber = 8;
        break;
      case BUTTON_9:
        generatedNumber = 9;
        break;
      case BUTTON_10:
        generatedNumber = 10;
        break;
      case BUTTON_11:
        generatedNumber = 11;
        break;
      case BUTTON_12:
        generatedNumber = 13;
        break;
      case BUTTON_13:
        generatedNumber = 13;
        break;
      case BUTTON_14:
        generatedNumber = 14;
        break;
      case BUTTON_15:
        generatedNumber = 15;
        break;
      case BUTTON_16:
        generatedNumber = 16;
        break;
      case BUTTON_17:
        generatedNumber = 17;
        break;
    }

    // Print the generated number
    Serial.print("Generated Number: ");
    Serial.println(generatedNumber);

    irrecv.resume(); // Ready to receive the next signal
  }

  // Example usage of the generated number elsewhere in the program
  if (generatedNumber > 0) {
    performAction(generatedNumber); // Call a function with the generated number
    generatedNumber = 0;           // Reset after use
  }
}

// Function to perform actions based on the generated number
void performAction(int number) {
  Serial.print("Performing action for number: ");
  Serial.println(number);

  while (number==1 && pos1<180){
    pos1++;
    servo1.write(pos1);
  }

  while (number==4 && pos1>0){
    pos1--;
    servo1.write(pos1);
  }
  while (number==2 && pos2<180){
    pos2++;
    servo2.write(pos2);
  }

  while (number==3 && pos2>0){
    pos2--;
    servo2.write(pos2);
  }

  while (number==6 && pos3<180){
    pos3++;
    servo3.write(pos3);
  }

  while (number==9 && pos3>0){
    pos3--;
    servo3.write(pos3);
  }

  while (number==7 && pos4<180){
    pos4++;
    servo4.write(pos4);
  }

  while (number==10 && pos4>0){
    pos4--;
    servo4.write(pos4);
  }

  while (number==8 && pos5<180){
    pos5++;
    servo5.write(pos5);
  }

  while (number==11 && pos5>0){
    pos5--;
    servo5.write(pos5);
  }
}
