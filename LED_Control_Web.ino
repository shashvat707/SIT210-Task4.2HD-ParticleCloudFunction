//Task 4.2HD - Particle - Calling a function from Web to device 

int led_red = D6;
int led_yellow = D5;
int led_green = D4;

int ledToggle(String command);

// States of LED's
bool red_on_state = false;
bool yellow_on_state = false;
bool green_on_state = false;

void setup()
{
    // Debugging using USB serial port
    Serial.begin();
    delay(5000);
    
    // Pin configuration
    pinMode(led_red, OUTPUT);
    pinMode(led_yellow, OUTPUT);
    pinMode(led_green, OUTPUT);

    // Turn the LED on and off from cloud
    Particle.function("led",ledToggle);

    // Safety check, making sure all LEDs are off when start
    digitalWrite(led_red, LOW);
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_green, LOW);

}

void loop()
{
   // Nothing to do here
}

void togglePin(int led, bool led_state)
{
    if (led_state == true) {
        // LED is already ON. Turn it OFF
        digitalWrite(led,LOW);
    }
    else if (led_state == false) {
        // LED is already OFF. Turn it ON
        digitalWrite(led,HIGH);
    }
}

int ledToggle(String command) {
   
    int led = -1;
    bool led_state = false;
    
    if(command == "red"){
        led = led_red;
        led_state = red_on_state;

        // Now toggle the state
        red_on_state = !led_state;
        Serial.println("Red toggle");
    }
    else if(command == "yellow"){
        led = led_yellow;
        led_state = yellow_on_state;

        // Now toggle the state
        yellow_on_state = !led_state;
        Serial.println("Yellow toggle");
    }
    else if(command == "green"){
        led = led_green;
        led_state = green_on_state;

        // Now toggle the state
        green_on_state = !led_state;
        Serial.println("Green toggle");
    }
    else{
        // Invalid colour
        Serial.print("Invalid color: ");
        Serial.println(command);
        return -1;
    }
    
    // Actually toggle the LED
    togglePin(led, led_state);
    return led_state;
}