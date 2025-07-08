# 🔐 JWTUtils Library for Arduino

JWTUtils adalah library ringan untuk membuat JSON Web Token (JWT) menggunakan algoritma **HS256**, dirancang khusus untuk platform berbasis Arduino seperti **ESP32** dan **ESP8266**.

---

## 📚 Deskripsi

Library ini memungkinkan Anda untuk membuat token JWT secara langsung pada mikrokontroler, sangat berguna untuk kebutuhan autentikasi saat mengakses API atau layanan IoT secara aman.

---

## ✨ Fitur

- 🔒 Pembuatan JWT dengan algoritma **HMAC-SHA256**
- 📦 Dukungan **Base64URL encoding** (kompatibel dengan spesifikasi JWT)
- 💡 Implementasi sederhana, cocok untuk perangkat dengan resource terbatas
- ⚙️ Cocok untuk komunikasi IoT yang aman

---

## 📦 Dependensi

Library ini menggunakan pustaka berikut (biasanya sudah tersedia di ESP32/ESP8266 Arduino Core):

- [`mbedtls`](https://github.com/ARMmbed/mbedtls) – untuk HMAC SHA-256
- `base64.h` – untuk encoding Base64
- `Arduino.h` – pustaka dasar Arduino

---

## 📁 Struktur File

```
JWTUtils/
├── JWTUtils.h           # Deklarasi kelas utama
├── JWTUtils.cpp         # Implementasi fungsi-fungsi JWT
├── basicjwt.ino         # Contoh penggunaan
└── library.properties   # Metadata library Arduino
```

---

## 🛠️ Instalasi

1. Unduh atau clone repository ini.
2. Salin folder `JWTUtils` ke dalam direktori `libraries/` milik Arduino Anda.
3. Di sketch Arduino Anda, sertakan library ini:
   ```cpp
   #include <JWTUtils.h>
   ```

---

## 🚀 Contoh Penggunaan

Contoh sederhana menggunakan library ini:

```cpp
#include <JWTUtils.h>

void setup() {
  Serial.begin(115200);
  
  String secretKey = "your-256-bit-secret";
  String payload = "encrypted-data-here";
  
  String jwt = JWTUtils::createJWT(payload, secretKey);
  
  Serial.println("Generated JWT:");
  Serial.println(jwt);
}

void loop() {}
```

---

## 🔍 Cara Kerja

1. **Header** JWT ditetapkan sebagai berikut:
   ```json
   {"alg":"HS256","typ":"JWT"}
   ```

2. **Payload** dapat berupa string JSON atau data terenkripsi.

3. Library akan:
   - Melakukan **Base64URL encoding** terhadap header dan payload.
   - Menghasilkan **signature** menggunakan HMAC-SHA256.
   - Menggabungkan semuanya menjadi format JWT:  
     ```
     base64url(header) + "." + base64url(payload) + "." + base64url(signature)
     ```

---

## ✅ Kompatibilitas

Library ini diuji pada:

- ✅ ESP32
- ✅ ESP8266

Akan bekerja pada semua board yang mendukung `mbedtls` dan `base64`.

---

## 📄 License

MIT License — gratis digunakan, dimodifikasi, dan didistribusikan.

---

## 📋 Metadata (library.properties)

```
name=JWTUtils
version=1.0.0
author=MisredIoT
maintainer=**
sentence=Library for JWT token generation
paragraph=Supports HS256 algorithm for JWT generation
category=Data Processing
url=https://github.com/yourusername/JWTUtils
architectures=esp32,esp8266
```

---

## ✍️ Penulis

- **Author:** MisredIoT  
- **Maintainer:**

---

## 🔗 Referensi

- 🔗 JWT Official Site: [https://jwt.io](https://jwt.io)
