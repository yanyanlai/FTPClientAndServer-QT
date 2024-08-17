# 计算机网络实验：FTP

# 一、 **实验名称**

Windows Socket编程

# 二、 **实验目的** 

1.熟练掌握TCP/IP协议族的体系结构

2.熟练掌握Visual C++网络编程方法

# 三、 **实验原理**

1. 客户机/服务器工作方式

服务器（Server）： 服务器是一个提供服务的计算机程序或设备。它等待并响应来自客户机的请求。服务器通常具有强大的计算能力和资源，用于执行特定的任务或提供服务。

客户机（Client）： 客户机是请求服务的计算机程序或设备。客户机向服务器发送请求，并等待服务器的响应。客户机通常通过网络连接到服务器。

客户机和服务器之间的通信可以是单向的（客户机向服务器请求服务）或双向的（客户机和服务器之间进行交互）。

2. TCP编程模式

TCP（传输控制协议）是一种面向连接的、可靠的协议，用于在网络上的两个设备之间建立可靠的通信通道。在 TCP 编程模式中，通信的两端被分为客户机和服务器。

TCP 服务器： TCP 服务器等待客户机的连接请求。一旦收到连接请求，服务器会创建一个专用的通信套接字，用于与客户机进行通信。服务器通常使用 QTcpServer 类来监听传入连接请求。

TCP 客户机： TCP 客户机负责发起与服务器的连接。一旦连接建立，客户机和服务器之间可以通过套接字进行双向通信。客户机通常使用 QTcpSocket 类来建立连接和发送/接收数据。

TCP 提供可靠的、面向连接的通信，确保数据按照正确的顺序传递，并在必要时重新发送丢失的数据。

3. UDP编程模式

UDP（用户数据报协议）是一种面向无连接的、不可靠的协议，用于在网络上进行数据传输。在 UDP 编程模式中，通信的两端同样被分为客户机和服务器。

UDP 服务器： UDP 服务器不像 TCP 服务器那样等待连接请求。它只需在已知的端口上监听数据包。服务器使用 QUdpSocket 类来接收和发送 UDP 数据包。

UDP 客户机： UDP 客户机负责向服务器发送数据包。与 TCP 不同，UDP 客户机不需要建立连接。它可以通过 QUdpSocket 直接向服务器发送数据。

UDP 提供了一种更快速的数据传输方式，但不保证数据的可靠性和顺序。在某些情况下，UDP 可以更适用于实时性要求高的应用场景，如音频和视频传输。

# 五、 **实验实现及结果分析**

开发工具：Qt Creator 4.12.2 (Community)

开发环境：Windows 11 家庭中文版

Ui设计：
![image](https://github.com/yanyanlai/FTPClientAndServer-QT/assets/110188868/be4327ec-cf94-4a15-92a2-9ba0ce2d8f99)

![image](https://github.com/yanyanlai/FTPClientAndServer-QT/assets/110188868/e6bb41f9-d47c-4a97-ac2e-6ab1a4520112)


（1）点击`server`启动即可启动服务器
![image](https://github.com/yanyanlai/FTPClientAndServer-QT/assets/110188868/ff3b6577-9f6e-4e8a-83f9-406a30397f07)


（2）然后点击client弹出客户端面，设置服务器地址和端口号，连接后开始通信。

![image](https://github.com/yanyanlai/FTPClientAndServer-QT/assets/110188868/6fe47aa4-5e6e-4b41-ad1a-13920b0ef5e1)
![image](https://github.com/yanyanlai/FTPClientAndServer-QT/assets/110188868/c37ba98f-f1d1-4017-9adc-2ea6c03e6b30)


（3）LIST命令
![image](https://github.com/yanyanlai/FTPClientAndServer-QT/assets/110188868/360f2282-06e6-4658-b63d-85ac06c6f040)


（4）PWD

展示当前目录。
![image](https://github.com/yanyanlai/FTPClientAndServer-QT/assets/110188868/49624ae5-05de-4544-8899-7409a46c8e09)


(5) CWD

切换到当前目录。

![image](https://github.com/yanyanlai/FTPClientAndServer-QT/assets/110188868/fecc263c-9e90-4d91-ab6c-2c4d0de17751)


(6) RETR

展示文件内容。

![image](https://github.com/yanyanlai/FTPClientAndServer-QT/assets/110188868/9f075911-adb1-499b-80ce-d13a20115ce4)


(7) STOR

下载文件。
![image](https://github.com/yanyanlai/FTPClientAndServer-QT/assets/110188868/d4c33765-bcff-443f-8f7c-da2f9974a9f5)


（1）QUIT

断开连接。
![image](https://github.com/yanyanlai/FTPClientAndServer-QT/assets/110188868/066c368a-f98a-4664-9266-59e9041d0754)


（2）多个客户端同时工作
![image](https://github.com/yanyanlai/FTPClientAndServer-QT/assets/110188868/a2f285d5-5800-44be-b901-183b2fbf17f9)


# **六**、问题讨论及体会

## 6.1**问题讨论**

在上述设计和实现中，可能会遇到一些问题，需要进一步讨论和解决：

***\*安全性问题\****： 上述代码中并未涉及任何安全性考虑，例如输入验证、权限控制等。在实际应用中，必须考虑如何防范潜在的安全漏洞。

***\*错误处理\****： 代码中的错误处理相对简单，没有详细处理每一种可能的错误情况。在实际应用中，应该更加细致地处理各种异常情况，以提高系统的鲁棒性。

## 6.2体会

通过这个实验，我对Windows Socket编程以及TCP/IP协议族的体系结构有了更深入的了解。以下是一些体会：

**网络编程的复杂性：** 网络编程涉及到很多细节，包括服务器的监听、连接管理、数据传输等，需要仔细考虑各种情况。

**协议的选择：** 在设计网络应用时，需要根据应用的性质选择合适的协议。TCP 提供可靠的连接，适用于要求可靠数据传输的场景，而UDP则更适用于实时性要求较高的应用。

**用户界面设计：** 客户端和服务器的用户界面在实际应用中可能需要更加人性化和友好。用户界面的设计对于用户体验和操作的方便性至关重要。
