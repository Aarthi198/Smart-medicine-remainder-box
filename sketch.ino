#define BLYNK_TEMPLATE_ID "TMPL3ZmegDrr7"
#define BLYNK_TEMPLATE_NAME "Medicine Reminder"
#define BLYNK_AUTH_TOKEN "vrs5xDX-YuNOKDh7et4ef57cJ9mt5wto"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

LiquidCrystal_I2C lcd(0x27,16,2);

int led = 18;
int buzzer = 19;
int button = 23;

bool alarmActive = false;
String medicineName = "Paracetamol";

BlynkTimer timer;

void triggerAlarm(String med)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Take Medicine");
  lcd.setCursor(0,1);
  lcd.print(med);

  digitalWrite(led,HIGH);
  tone(buzzer,1000);

  alarmActive = true;

  Serial.println("Reminder Triggered");
}

void stopAlarm()
{
  noTone(buzzer);
  digitalWrite(led,LOW);

  lcd.clear();
  lcd.print("Medicine Taken");

  delay(2000);

  alarmActive = false;
}

void missedAlert()
{
  if(alarmActive)
  {
    Serial.println("Medicine Missed!");

    Blynk.logEvent("medicine_missed","Patient missed medicine!");

    lcd.clear();
    lcd.print("Medicine Missed");

    noTone(buzzer);
    digitalWrite(led,LOW);

    alarmActive = false;
  }
}

BLYNK_WRITE(V0)
{
  medicineName = param.asString();
}

void setup()
{
  Serial.begin(115200);

  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(button,INPUT_PULLUP);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Medicine Box");
  lcd.setCursor(0,1);
  lcd.print("Connecting...");

  Blynk.begin(BLYNK_AUTH_TOKEN,ssid,pass);

  lcd.clear();
  lcd.print("System Ready");

  timer.setInterval(15000L, [](){ triggerAlarm("Morning Tab"); });
  timer.setInterval(30000L, [](){ triggerAlarm("Afternoon Tab"); });
  timer.setInterval(45000L, [](){ triggerAlarm("Night Tab"); });

  timer.setInterval(20000L, missedAlert);
}

void loop()
{
  Blynk.run();
  timer.run();

  if(alarmActive && digitalRead(button)==LOW)
  {
    stopAlarm();
  }
}