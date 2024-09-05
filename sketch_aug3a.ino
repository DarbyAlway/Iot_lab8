int LED[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};  // Array of LED pins
int numLEDs = 10;  // Number of LEDs

void setup() {
  // Set up each pin in the LED array as an output
  for (int i = 0; i < numLEDs; i++) {
    pinMode(LED[i], OUTPUT);
  }
}
 
void loop() {

 for (int i = 0; i < numLEDs; i += 2) {
    if (i + 1 < numLEDs) {
      digitalWrite(LED[i], HIGH);
      digitalWrite(LED[i + 1], HIGH);
      delay(1000);  // Light up the LEDs for 1 second
      digitalWrite(LED[i], LOW);
      digitalWrite(LED[i + 1], LOW);
    }
  }
  
  delay(500);  // Short delay before the next sequence


  // Sequence 2: Blink all LEDs together 3 times
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < numLEDs; i++) {
      digitalWrite(LED[i], HIGH);
    }
    delay(300);
    for (int i = 0; i < numLEDs; i++) {
      digitalWrite(LED[i], LOW);
    }
    delay(300);
  }

  // Sequence 3: Chase effect from right to left
  for (int i = numLEDs - 1; i >= 0; i--) {
    digitalWrite(LED[i], HIGH);
    delay(100);
    digitalWrite(LED[i], LOW);
  }
  delay(500);

  // Sequence 4: Light up LEDs from both ends towards the center
  for (int i = 0; i < numLEDs / 2; i++) {
    digitalWrite(LED[i], HIGH);
    digitalWrite(LED[numLEDs - 1 - i], HIGH);
    delay(200);
    digitalWrite(LED[i], LOW);
    digitalWrite(LED[numLEDs - 1 - i], LOW);
  }

  // Sequence 5: "Knight Rider" style bounce
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(LED[i], HIGH);
    delay(100);
    digitalWrite(LED[i], LOW);
  }
  for (int i = numLEDs - 2; i > 0; i--) {
    digitalWrite(LED[i], HIGH);
    delay(100);
    digitalWrite(LED[i], LOW);
  }

  // Sequence 6: Light up every second LED
  for (int i = 0; i < numLEDs; i += 2) {
    digitalWrite(LED[i], HIGH);
  }
  delay(500);
  for (int i = 0; i < numLEDs; i += 2) {
    digitalWrite(LED[i], LOW);
  }
  delay(500);

  // Sequence 7: Light up LEDs in a random pattern
  for (int i = 0; i < numLEDs; i++) {
    int randomLED = random(numLEDs);
    digitalWrite(LED[randomLED], HIGH);
    delay(100);
    digitalWrite(LED[randomLED], LOW);
  }

  // Sequence 8: Light up LEDs one by one and leave them on
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(LED[i], HIGH);
    delay(200);
  }
  delay(1000);
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(LED[i], LOW);
  }

  // Sequence 9: Rapid flicker
  for (int j = 0; j < 20; j++) {
    for (int i = 0; i < numLEDs; i++) {
      digitalWrite(LED[i], HIGH);
    }
    delay(50);
    for (int i = 0; i < numLEDs; i++) {
      digitalWrite(LED[i], LOW);
    }
    delay(50);
  }

  // Sequence 10: LEDs blink together, then random sequence for 5 seconds
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < numLEDs; i++) {
      digitalWrite(LED[i], HIGH);
    }
    delay(300);  // LEDs stay on for 300 ms
    for (int i = 0; i < numLEDs; i++) {
      digitalWrite(LED[i], LOW);
    }
    delay(300);  // LEDs stay off for 300 ms
  }

  unsigned long startTime = millis();  
  while (millis() - startTime < 5000) {  
    int randomLED = random(numLEDs); 
    digitalWrite(LED[randomLED], HIGH);
    delay(30); 
    digitalWrite(LED[randomLED], LOW);
    delay(30); 
  }

  // Add a brief pause before the next cycle
  delay(1000);
}
