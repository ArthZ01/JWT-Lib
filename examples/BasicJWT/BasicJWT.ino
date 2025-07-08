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