# 📏 Arduino #10: Yakınlık Alarmı (HC-SR04 + Buzzer)

Bu projede, **HC-SR04 ultrasonik mesafe sensörü** ile bir **yakınlık alarmı sistemi** kurulacaktır.  
Nesne belli bir mesafeye geldiğinde **buzzer sesli uyarı** verir.

🔗 [Web Siteme Bakmak İçin Tıkla](https://www.hakkiharmankaya.com/)  


---

## 🧰 Gerekli Malzemeler

- 1 adet **HC-SR04 Ultrasonik Mesafe Sensörü**
- 1 adet **aktif buzzer**
- 1 adet **direnç** (220Ω veya 330Ω) *(İsteğe bağlı)*
- 1 adet **Arduino**
- 1 adet **breadboard**
- **Jumper kabloları**

---

## ⚙️ Adım Adım Devre Kurulumu

### 🔹 Adım 1: Devreyi Kurun

- **HC-SR04** bağlantıları:
  - **VCC** → **5V**
  - **GND** → **GND**
  - **TRIG** → **D7**
  - **ECHO** → **D6**

- **Buzzer** bağlantısı:
  - **Pozitif ucu** → **D8 (direnç ile ya da direkt)**
  - **Negatif ucu** → **GND**

---

## 🔹 Adım 2: Arduino Kodunu Yazın ve Yükleyin

```cpp
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
  melodi(olcum * 10); // Mesafe küçüldükçe ses hızı artar
}

int mesafe(int a, int b) {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2; // cm cinsinden

  delay(50);

  if (distance >= a || distance <= b)
    return 0;

  return distance;
}

int melodi(int dly) {
  tone(buzzerPin, 440);  // 440Hz sabit ton
  delay(dly);
  noTone(buzzerPin);
  delay(dly);
}
