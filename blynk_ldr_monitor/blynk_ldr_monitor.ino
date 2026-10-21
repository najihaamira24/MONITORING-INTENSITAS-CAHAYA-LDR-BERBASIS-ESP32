#define BLYNK_TEMPLATE_ID "TMPL6jYHyU01K"
#define BLYNK_TEMPLATE_NAME "PROYEK IOT"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Token dari Blynk (isi dengan Auth Token milik Device kamu, jangan di-commit)
char auth[] = "YOUR_BLYNK_AUTH_TOKEN";

// Wi-Fi virtual bawaan Wokwi (gratis dan otomatis tersambung)
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

BlynkTimer timer;

const int ldrPin = 34; // Pin tempat kabel AO dari modul LDR tersambung di ESP32

// Fungsi yang dipanggil otomatis setiap 1 detik untuk membaca dan mengirim data
void sendSensor() {
  int nilaiCahaya = analogRead(ldrPin); // Membaca nilai dari sensor cahaya
  Serial.print("Nilai Cahaya: ");
  Serial.println(nilaiCahaya);

  // Mengirim nilai cahaya ke Virtual Pin V0 di Blynk
  Blynk.virtualWrite(V0, nilaiCahaya);
}

void setup() {
  Serial.begin(115200);

  // Memulai koneksi ke Blynk Cloud lewat Wi-Fi Wokwi
  Blynk.begin(auth, ssid, pass);

  // Mengatur interval pengiriman data (1000 milidetik = 1 detik sekali)
  timer.setInterval(1000L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
