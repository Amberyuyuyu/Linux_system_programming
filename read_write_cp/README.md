### read和write实现cp

`read`函数：

​	`size_t read(int fd, void* but, size_t count);`

​		`fd`：文件描述符

​		`buf`：存数据的缓冲区

​		`count`：缓冲区大小

​		返回值：

​			0：读到文件末尾

​			>0：成功，返回读到的字节数

​			-1：失败，设置`errno`

​			返回-1且`errno=EAGIN`或`EWOULDBLOCK`，说明不是读取失败，而是读取在以非阻塞方式读一个设备文件或网络文件，并且文件无数据。



`write`函数：

​	`ssize_t write(int fd, const void* but, size_t count);`

​		`fd`：文件描述符

​		`buf`：待写出数据的缓冲区

​		`count`：数据大小

​		返回值：

​			>0：成功写入的字节数

​			-1：失败，设置`errno`