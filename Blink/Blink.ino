const int buttonPin = 2; 
const int RledPin = 9;
const int GledPin = 10;
const int BledPin = 11;

// 遊戲以綠燈（中性，10分）開始[cite: 4]
int mood = 10;                           
const int neutralMood = 10;             
int buttonState = 0;                    
bool ButtonPressed = false;             

unsigned long touchedTimer = 0;         
unsigned long reducedTimer = 0;         
const long unTouchInterval = 5000;      // 5秒鐘之內沒有按壓[cite: 4]
const long reducedInterval = 1000;      // 每秒1分的速度遞減[cite: 4]

void setup() {
  // 使用內建上拉電阻（按鈕一端接 Pin 2，另一端接 GND）
  pinMode(buttonPin, INPUT_PULLUP);            
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);                 
}

void loop() {
  showLEDState(mood);                   

  buttonState = digitalRead(buttonPin); 

  // 偵測按鈕剛被按下的瞬間 (INPUT_PULLUP 模式下按下為 LOW)
  if(buttonState == LOW && !ButtonPressed){ 
    mood = mood + 1;                    // 每按壓一次算一分，讓玩具更開心[cite: 4]
    if(mood > 20) mood = 20;            // 最高 20 分[cite: 4]
    touchedTimer = millis();          
    ButtonPressed = true;               
  }
  
  // 偵測按鈕放開
  if(buttonState == HIGH && ButtonPressed){ 
    ButtonPressed = false;   
  }

  // 閒置與扣分邏輯
  unsigned long currentTimer = millis();
  if(currentTimer - touchedTimer > unTouchInterval){       // 超過 5 秒未觸碰[cite: 4]
    if(currentTimer - reducedTimer > reducedInterval){     // 每 1 秒執行一次遞減[cite: 4]
      mood = mood - 1;
      if(mood < 0) mood = 0;                               // 直至最少 0 分[cite: 4]
      reducedTimer = currentTimer;      
    }
  }
}

// 共陽極 LED 顏色連續光譜變化邏輯 (0 為最亮，255 為不亮)[cite: 4]
void showLEDState(int state) {
  float step = 255.0 / 10.0; // 每 1 分的顏色變化幅度

  if (state <= neutralMood) {
    // 0~10分區間：紅燈(0分) 漸變至 綠燈(10分)[cite: 4]
    analogWrite(RledPin, step * state);                 // 分數越接近 10，紅燈越暗
    analogWrite(GledPin, 255 - (step * state));         // 分數越接近 10，綠燈越亮
    analogWrite(BledPin, 255);                          // 藍燈保持關閉
  } else {
    // 11~20分區間：綠燈(10分) 漸變至 藍燈(20分)[cite: 4]
    analogWrite(RledPin, 255);                          // 紅燈保持關閉
    analogWrite(GledPin, step * (state - neutralMood)); // 分數越接近 20，綠燈越暗
    analogWrite(BledPin, 255 - (step * (state - neutralMood))); // 分數越接近 20，藍燈越亮
  }
}