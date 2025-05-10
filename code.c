#include<Wire.h>
#include <Adafruit_SSD1306.h>

#define PIR_PIN 14
#define BUTTON_PIN 13
#define BUZZER_PIN 26

Adafruit_SSD1306 display(128, 64, &Wire, -1);

bool isArmed = false;
// bool lastButtonState = HIGH;

// unsigned long lastDebounceTime = 0;
// const unsigned long debounceDelay = 200;

void setup(){
  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);

  digitalWrite(BUZZER_PIN, LOW);

  //display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("System Ready");
  display.display();
}

void loop(){
  handleToggleButton();

  int motion = digitalRead(PIR_PIN);

  if(isArmed && motion == HIGH){
    digitalWrite(BUZZER_PIN, HIGH);
    displayStatus("Motion!");
  }
  else{
    digitalWrite(BUZZER_PIN, LOW);
    displayStatus(isArmed ? "Armed" : "Disarmed");
  }

  delay(100);
}

void handleToggleButton() {
  static bool prevButtonState = HIGH;
  bool currentButtonState = digitalRead(BUTTON_PIN);

  // Detect button press -> release (rising edge)
  if (prevButtonState == LOW && currentButtonState == HIGH) {
    isArmed = !isArmed;
    Serial.println(isArmed ? "System Armed" : "System Disarmed");
  }

  prevButtonState = currentButtonState;
}

void displayStatus(String msg){
  display.clearDisplay();
  display.setCursor(0, 20);
  display.setTextSize(2);
  display.print(msg);
  display.display();
}
