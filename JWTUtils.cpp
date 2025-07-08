#include "JWTUtils.h"

String JWTUtils::base64urlEncode(const String &input) {
  String encoded = base64::encode(input);
  encoded.replace("+", "-");
  encoded.replace("/", "_");
  encoded.replace("=", "");
  return encoded;
}

String JWTUtils::hmacSHA256(const String &message, const String &key) {
  byte hash[32];
  mbedtls_md_context_t ctx;
  mbedtls_md_init(&ctx);
  mbedtls_md_setup(&ctx, mbedtls_md_info_from_type(MBEDTLS_MD_SHA256), 1);
  mbedtls_md_hmac_starts(&ctx, (const unsigned char*)key.c_str(), key.length());
  mbedtls_md_hmac_update(&ctx, (const unsigned char*)message.c_str(), message.length());
  mbedtls_md_hmac_finish(&ctx, hash);
  mbedtls_md_free(&ctx);

  String result = base64::encode(hash, 32);
  result.replace("+", "-");
  result.replace("/", "_");
  result.replace("=", "");
  return result;
}

String JWTUtils::createJWT(const String& payload, const String& secretKey) {
  String header = "{\"alg\":\"HS256\",\"typ\":\"JWT\"}";
  String encodedHeader = base64urlEncode(header);
  
  // Langsung encode payload tanpa wrapper encryptedData
  String encodedPayload = base64urlEncode(payload);
  
  String signature = hmacSHA256(encodedHeader + "." + encodedPayload, secretKey);
  return encodedHeader + "." + encodedPayload + "." + signature;
}