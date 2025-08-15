#pragma once
#include "NetworkHelper.h"
#include "CryptoHelper.h"
#include "Prerequisites.h"

class Client {
public:
	Client() = default;
	Client(const std::string& ip, int port);
	~Client();

	/**
	 * @brief Conecta con el servidor.
	 * @return true si se conectó, false si falló.
	 */
	bool
	Connect();

	/**
	 * @brief Intercambia claves con el servidor.
	 */
	void
	ExchangeKeys();

	/**
	 * @brief Envía la clave AES cifrada con la pública del servidor.
	 */
	void
	SendAESKeyEncrypted();

	/**
	 * @brief Cifra un mensaje con AES y lo envía.
	 * @param message Texto a enviar.
	 */
	void
	SendEncryptedMessage(const std::string& message);

	/**
	 * @brief Bucle para enviar mensajes cifrados.
	 */
	void
	SendEncryptedMessageLoop();

	/**
	 * @brief Bucle principal de chat.
	 */
	void
	StartChatLoop();

	/**
	 * @brief Bucle para recibir mensajes del servidor.
	 */
	void
	StartReceiveLoop();

private:
	std::string m_ip;       // IP del servidor
	int m_port;             // Puerto del servidor
	SOCKET m_serverSock;    // Socket de conexión
	NetworkHelper m_net;    // Manejo de red
	CryptoHelper m_crypto;  // Manejo de cifrado
};
