#ifndef JWTUtils_h
#define JWTUtils_h

#include <Arduino.h>
#include <base64.h>
#include <mbedtls/md.h>

class JWTUtils {
  public:
    static String createJWT(const String& payload, const String& secretKey);
    
  private:
    static String base64urlEncode(const String &input);
    static String hmacSHA256(const String &message, const String &key);
};

#endif