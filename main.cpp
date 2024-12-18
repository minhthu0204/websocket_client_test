#include <QCoreApplication>
#include "websocketclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Địa chỉ WebSocket server với hostname là 192.168.1.100 và port là 3335
    QUrl serverUrl("ws://192.168.1.26:3335");  // Địa chỉ WebSocket server
    WebSocketClient client(serverUrl);

    // Kết nối đến WebSocket server
    client.connectToServer();

    // Lắng nghe các tin nhắn từ server
    QObject::connect(&client, &WebSocketClient::messageReceived, [](const QString &message) {
        qDebug() << "Received message: " << message;
    });

    return a.exec();
}
