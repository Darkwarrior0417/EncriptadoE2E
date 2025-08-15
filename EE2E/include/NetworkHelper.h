#pragma once
#include "Prerequisites.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")

class NetworkHelper {
public:
	NetworkHelper();
	~NetworkHelper();

	/**
	 * @brief Inicia un servidor en el puerto indicado.
	 * @return true si se inició, false si falló.
	 */
	bool
	StartServer(int port);

	/**
	 * @brief Acepta un cliente entrante.
	 */
	SOCKET
	AcceptClient();

	// Cliente

	/**
	 * @brief Conecta a un servidor por IP y puerto.
	 */
	bool
	ConnectToServer(const std::string& ip, int port);

	// Envío y recepción

	/**
	 * @brief Envía texto por el socket.
	 */
	bool
	SendData(SOCKET socket, const std::string& data);

	/**
	 * @brief Envía datos binarios.
	 */
	bool
	SendData(SOCKET socket, const std::vector<unsigned char>& data);

	/**
	 * @brief Recibe texto del socket.
	 */
	std::string
	ReceiveData(SOCKET socket);

	/**
	 * @brief Recibe datos binarios.
	 */
	std::vector<unsigned char>
	ReceiveDataBinary(SOCKET socket, int size = 0);

	/**
	 * @brief Cierra un socket.
	 */
	void
	close(SOCKET socket);

	/**
	 * @brief Envía todos los bytes indicados.
	 */
	bool
	SendAll(SOCKET s, const unsigned char* data, int len);

	/**
	 * @brief Recibe exactamente la cantidad indicada de bytes.
	 */
	bool
	ReceiveExact(SOCKET s, unsigned char* out, int len);

public:
	SOCKET m_serverSocket = -1;
private:
	bool m_initialized;
};
