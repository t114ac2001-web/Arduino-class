const int buttonPin = 2;  // the number of the pushbutton pin
const int RledPin = 3;    // the number of the R pin
const int GledPin = 4;    // the number of the G pin
const int BledPin = 5;    // the number of the B pin

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status
int ledcolor = 0;
bool ButtonPressed = false;
String currentcolor = "led";

void setup() {
  // initialize the LED pin as an output:
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  Serial.print("Current Color: ");
  Serial.println(currentcolor);

  // 按下按鈕時切換顏色
  if (buttonState == HIGH && !ButtonPressed) {
    ledcolor = ledcolor + 1;
    ButtonPressed = true;
  }

  // 放開按鈕時重置狀態
  if (buttonState == LOW   ButtonPressed) {
    ButtonPressed = false;
  }

  // 顏色計數循環
  if (ledcolor >= 8) {
    ledcolor = 0;
  }

  if (ledcolor == 0) {
    currentcolor = "LED off";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 1) {
    // RED
    currentcolor = "Red";
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    delay(1000);
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    delay(1000);
  }
  else if (ledcolor == 2) {
    // Green
    currentcolor = "Green";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
    delay(1000);
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    delay(1000);
  }
  else if (ledcolor == 3) {
    // Blue
    currentcolor = "Blue";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
    delay(1000);
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    delay(1000);
  }
  else if (ledcolor == 4) {
    // Yellow
    currentcolor = "Yellow";
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
    delay(1000);
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    delay(1000);
  }
  else if (ledcolor == 5) {
    // Purple
    currentcolor = "Purple";
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
    delay(1000);
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    delay(1000);
  }
  else if (ledcolor == 6) {
    // Cyan
    currentcolor = "Cyan";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
    delay(1000);
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    delay(1000);
  }
  else if (ledcolor == 7) {
    // White
    currentcolor = "White";
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
    delay(1000);
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    delay(1000);
  }
}