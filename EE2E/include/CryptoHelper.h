#pragma once
#include "Prerequisites.h"
#include "openssl\rsa.h"
#include "openssl\aes.h"

class CryptoHelper {
public:
	CryptoHelper();
	~CryptoHelper();

	// RSA

	/**
	 * @brief Genera claves RSA (2048 bits).
	 */
	void
	GenerateRSAKeys();

	/**
	 * @brief Retorna la clave pública en formato PEM.
	 */
	std::string
	GetPublicKeyString() const;

	/**
	 * @brief Carga la clave pública del otro usuario.
	 */
	void
	LoadPeerPublicKey(const std::string& pemKey);

	// AES

	/**
	 * @brief Genera clave AES-256 (32 bytes).
	 */
	void
	GenerateAESKey();

	/**
	 * @brief Cifra la clave AES con la pública del otro usuario.
	 */
	std::vector<unsigned char>
	EncryptAESKeyWithPeer();

	/**
	 * @brief Descifra la clave AES recibida.
	 */
	void
	DecryptAESKey(const std::vector<unsigned char>& encryptedKey);

	/**
	 * @brief Cifra texto con AES-256-CBC.
	 */
	std::vector<unsigned char>
	AESEncrypt(const std::string& plaintext, std::vector<unsigned char>& outIV);

	/**
	 * @brief Descifra texto con AES-256-CBC.
	 */
	std::string
	AESDecrypt(const std::vector<unsigned char>& ciphertext, const std::vector<unsigned char>& iv);

private:
	RSA* rsaKeyPair;          // Claves propia (pública/privada)
	RSA* peerPublicKey;       // Clave pública del otro usuario
	unsigned char aesKey[32]; // Clave AES-256
};
