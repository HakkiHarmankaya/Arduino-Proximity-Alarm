#define echoPin 6
#define trigPin 7
#define buzzerPin 8
int maxRange = 50;
int minRange = 0;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int olcum = mesafe(maxRange, minRange);
  melodi(olcum*10);
}

int mesafe(int a, int b)
{
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  delay(50);

  if(distance >= a || distance <= b)
  return 0;
  return distance;
}

int melodi(int dly)
{
  tone(buzzerPin, 440);
  delay(dly);
  noTone(buzzerPin);
  delay(dly);
}

-------------------------------------------------------------------



const int trigPin = 9;    // HC-SR04 Trigger pini
const int echoPin = 10;   // HC-SR04 Echo pini
const int buzzerPin = 11; // Aktif buzzer pini

void setup() {
  pinMode(trigPin, OUTPUT);    // Trigger pini çıkış olarak ayarla
  pinMode(echoPin, INPUT);     // Echo pini giriş olarak ayarla
  pinMode(buzzerPin, OUTPUT);  // Buzzer pini çıkış olarak ayarla
  Serial.begin(9600);          // Seri portu başlat
}

void loop() {
  long duration, distance;
  
  // Trigger pini 10 mikrosaniye boyunca yüksek seviyeye yükselir
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Echo pini yüksek seviyeye döneceği süreyi ölçer
  duration = pulseIn(echoPin, HIGH);
  
  // Mesafeyi hesaplar (hava hızına göre yaklaşık hesaplama)
  distance = duration * 0.034 / 2;
  
  Serial.print("Mesafe: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance < 20) {
    // Mesafe 20 cm'den daha kısa ise, yakınlık alarmını tetikle
    tone(buzzerPin, 1000);  // Buzzer'ı 1 kHz frekansında çal
  } else {
    noTone(buzzerPin);  // Buzzer'ı kapat
  }
  
  delay(500);  // 500 ms bekle
}
