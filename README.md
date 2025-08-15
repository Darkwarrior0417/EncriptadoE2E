🔐 Encriptado de Extremo a Extremo (E2EE)
El encriptado de extremo a extremo (E2EE, por sus siglas en inglés) es un mecanismo de seguridad criptográfica que garantiza la confidencialidad de la información transmitida entre dos partes. Bajo este esquema, los datos son cifrados en el origen y solo pueden ser descifrados por el destinatario legítimo, impidiendo que terceros —incluidos proveedores de servicios, intermediarios de red o atacantes— accedan al contenido, incluso si logran interceptarlo.

📌 Principales características:
Cifrado punto a punto: El mensaje se cifra en el dispositivo del emisor y se descifra únicamente en el dispositivo del receptor.

Autonomía criptográfica: Las claves utilizadas para cifrar y descifrar no son compartidas con ningún servidor intermedio.

Alta privacidad: Ni siquiera el proveedor del servicio puede acceder al contenido de las comunicaciones.

🛡️ Beneficios:
Confidencialidad: Protege la información sensible frente a espionaje, filtraciones o accesos no autorizados.

Integridad: Asegura que los datos no sean modificados durante la transmisión sin ser detectados.

Autenticación: Puede complementarse con firmas digitales para validar la identidad de las partes involucradas.

✨ Características del proyecto

🔒 Cifrado de extremo a extremo: Intercambio de claves con RSA 2048 bits y mensajes protegidos con AES 256 bits.

💬 Arquitectura cliente-servidor para chats 1 a 1.

⚡ Comunicación en tiempo real y en ambas direcciones.

💻 Interfaz por consola fácil de usar.

🔄 Funciona en modo interactivo o con argumentos en línea de comandos.

📋 Requisitos

Compilador C++ con soporte para C++11.

Librería OpenSSL instalada.

Windows (usa Winsock2).

🛠️ Compilación

Compila todos los archivos fuente:

Client.cpp
CryptoHelper.cpp
main.cpp
NetworkHelper.cpp
Server.cpp

🚀 Uso

Puedes ejecutar en modo servidor o modo cliente.

📌 Argumentos en línea

Servidor:

E2EE server [puerto]


Cliente:

E2EE client <ip> <puerto>

📌 Modo interactivo

Ejecuta sin argumentos y sigue las indicaciones:

Elige server o client.

Si es servidor → ingresa el puerto.

Si es cliente → ingresa IP y puerto.

💡 Comandos de chat

Escribe tu mensaje y presiona Enter para enviarlo.

Escribe /exit para salir.

🛡️ Seguridad

🔑 RSA 2048 bits para intercambio de claves.

🔐 AES-256-CBC para cifrar mensajes.

🌀 IV único por cada mensaje.

🎲 Claves generadas de forma segura con RAND_bytes de OpenSSL.

🔍 Flujo del protocolo

🖥️ El servidor inicia y espera conexión.

📲 El cliente se conecta.

🔑 Intercambio de claves públicas RSA.

📨 El cliente genera clave AES y la envía cifrada con la clave pública del servidor.

🔒 Comienza el chat cifrado con AES.

📡 Formato de mensaje en red

IV (16 bytes)

Longitud del mensaje (4 bytes, orden de red)

Mensaje cifrado
