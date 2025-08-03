#pragma once
#include "Prerequisites.h"
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")

class NetworkHelper {
public:
    /**
     * @brief Constructor. Inicializa Winsock.
     */
    NetworkHelper();

    /**
     * @brief Destructor. Libera recursos de Winsock.
     */
    ~NetworkHelper();

    // Server mode
    /**
     * @brief Inicia el servidor en el puerto dado.
     * @param port Puerto en el que escuchar.
     * @return true si se inicia correctamente.
     */
    bool StartServer(int port);

    /**
     * @brief Acepta una conexión entrante.
     * @return Socket del cliente conectado.
     */
    SOCKET AcceptClient();

    // Client mode
    /**
     * @brief Conecta al servidor remoto.
     * @param ip Dirección IP del servidor.
     * @param port Puerto del servidor.
     * @return true si la conexión fue exitosa.
     */
    bool ConnectToServer(const std::string& ip, int port);

    // Send and receive data
    /**
     * @brief Envía datos como string.
     * @param socket Socket destino.
     * @param data Datos a enviar.
     * @return true si se envía correctamente.
     */
    bool SendData(SOCKET socket, const std::string& data);

    /**
     * @brief Envía datos como vector de bytes.
     * @param socket Socket destino.
     * @param data Datos a enviar.
     * @return true si se envía correctamente.
     */
    bool SendData(SOCKET socket, const std::vector<unsigned char>& data);

    /**
     * @brief Recibe datos como string.
     * @param socket Socket desde el cual recibir.
     * @return Datos recibidos.
     */
    std::string ReceiveData(SOCKET socket);

    /**
     * @brief Recibe datos como vector de bytes.
     * @param socket Socket desde el cual recibir.
     * @param size Cantidad esperada (0 = dinámica).
     * @return Datos recibidos.
     */
    std::vector<unsigned char> ReceiveData(SOCKET socket, int size = 0);

    /**
     * @brief Cierra el socket dado.
     * @param socket Socket a cerrar.
     */
    void close(SOCKET socket);

private:
    SOCKET m_serverSocket = -1;
    bool m_initialized;
};
