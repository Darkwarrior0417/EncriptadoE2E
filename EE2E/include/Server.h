#pragma once
#include "NetworkHelper.h"
#include "CryptoHelper.h"
#include "Prerequisites.h"

class Server {
public:
	Server() = default;
	Server(int port);
	~Server();

	/**
	 * @brief Inicia el servidor en el puerto indicado.
	 * @return true si se inició, false si falló.
	 */
	bool
	Start();

	/**
	 * @brief Espera conexión de un cliente e intercambia claves.
	 */
	void
	WaitForClient();

	/**
	 * @brief Recibe, descifra y muestra un mensaje del cliente.
	 */
	void
	ReceiveEncryptedMessage();

	/**
	 * @brief Bucle para recibir mensajes cifrados.
	 */
	void
	StartReceiveLoop();

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

private:
	int m_port;                  // Puerto del servidor
	SOCKET m_clientSock;         // Socket del cliente
	NetworkHelper m_net;         // Manejo de red
	CryptoHelper m_crypto;       // Manejo de cifrado
	std::thread m_rxThread;      // Hilo de recepción
	std::atomic<bool> m_running{ false }; // Estado del servidor
};
