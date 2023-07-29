### 目录操作函数实现ls操作

`DIR* opendir(char* name);`



`int closedir(DIR* dp);`



`struct dirent* readdir(DIR* dp);`



`struct dirent{`

​	`inode;`

​	`char d_name[256];`

`}`