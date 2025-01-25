#include <OPC.h>

// Declare an OPCSerial object for OPC (Open Process Control) communication
OPCSerial aOPCSerial;

// Declare pin numbers for the LED, button, and analog input
int ledPin = 7;        // LED connected to pin 7
int buttonPin = 2;     // Button connected to pin 2
int analogPin = 0;     // Analog input connected to pin A0

// Callback function for handling boolean items ("led" and "button")
bool callback1(const char *itemID, const opcOperation opcOP, const bool value) {
  
  static bool ledValue = false; // Track the current state of the LED
    
  // Handle the "led" item
  if (!strcmp(itemID, "led")) { // Check if the item is "led"
    
    // Handle write operation (set LED state)
    if (opcOP == opc_opwrite) {
      ledValue = value; // Update the stored LED value
      
      // Turn the LED on or off based on the value
      if (ledValue)  
        digitalWrite(ledPin, HIGH);
      else
        digitalWrite(ledPin, LOW);
    } 
    else {
      // Handle read operation (return the LED's current state)
      return ledValue;  
    }
  } 

  // Handle the "button" item
  if (!strcmp(itemID, "button")) {    
    // Return the current state of the button (pressed or not)
    return digitalRead(buttonPin);  
  }

  // Default return value (if itemID does not match)
  return false;
}

// Callback function for handling integer items ("analog0")
int callback2(const char *itemID, const opcOperation opcOP, const int value) {
  
  // Handle the "analog0" item
  if (!strcmp(itemID, "analog0")) {    
    // Read and return the value from the analog pin A0
    return analogRead(analogPin);  
  } 

  // Default return value (if itemID does not match)
  return 0;
}

void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);

  // Configure the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Configure the button pin as an input
  pinMode(buttonPin, INPUT);

  // Initialize OPC communication
  aOPCSerial.setup();
  
  // Declare OPC items with their properties and associated callback functions
  aOPCSerial.addItem("led", opc_readwrite, opc_bool, callback1);  // LED: Read/Write, Boolean
  aOPCSerial.addItem("button", opc_read, opc_bool, callback1);   // Button: Read only, Boolean
  aOPCSerial.addItem("analog0", opc_read, opc_int, callback2);   // Analog input: Read only, Integer
}

void loop() {
  // Continuously process incoming OPC commands
  aOPCSerial.processOPCCommands();
}
