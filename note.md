# 入门
- 1.1 UNIX、Linux和GUN简介
    - 1.1.1 什么是UNIX
        - 1.UNIX简史
        - 2.UNIX哲学
            - 简单性：KISS
            - 集中性（功能单一性）
            - 可重用组件
            - 过滤器
            - 开发的文件格式
            - 灵活性
    - 1.1.2 什么是Linux
    - 1.1.3 GNU项目和自由软件基金会
    - 1.1.4 Linux发生版
- 1.2 Linux程序设计
    - 1.2.1 Linux程序
        - 可执行文件和脚本
    - 1.2.2 文本编辑器
    - 1.2.3 C语言编辑器
    - 1.2.4 开发系统引导
        - 1.应用程序
        - 2.头文件
        - 3.库文件
        - 4.静态库
            - ar crv libfoo.a bill.o fred.o (c create r insert v verbose)
        - 5.共享库
            - /etc/ld.so.config，ldconfig
            - ldd 查看程序需要的动态库
- 1.3 获得帮助
    - man
    - info
- 1.4 小结

# 第二章 shell程序设计
- 2.1 为什么使用shell编程
- 2.2 一点哲学
- 2.3 什么是shell
- 2.4 管道与重定向
    - 2.4.1 重定向输出
        - kill -1 1234 >killouterr.txt 2>&1
    - 2.4.2 重定向输入
    - 2.4.3 管道
        - 决不要在命令流中重复使用相同的文件名，cat mydata.txt | sort | uniq | > mydata.txt
- 2.5 作为程序设计语言的shell
    - 2.5.1 交互式程序
    - 2.5.2 创建脚本
        - 脚本程序上本质上被看作是shell的标准输入
        - [first.sh](/Chapter1/2.5.2/first.sh)
    - 2.5.3 把脚本设置为可执行
- 2.6 shell的语法
    - 2.6.1 变量
        - 默认情况下，所有变量都被看作字符串并以字符串形式存储
        - 1.使用引号
            - 单引号，不展开
            - 双引号，展开
            - [qutation_mark.sh](/Chapter1/2.6.1/para_envpara.sh)
        - 2.环境变量
        - 3.参数变量
            - $1,$2
            - $*
            - $@
        - [para_envpara.sh](/Chapter1/2.6.1/para_envpara.sh)
    - 2.6.2 条件
        - test或\[ 命令
        - \[ 符号和被检查的条件之间要留出空格
    - 2.6.3 控制结构
        - 1.if语句
            - [if_statement.sh](/Chapter1/2.6.3/if_statement.sh)
        - 2.elif语句
        - 3.一个与变量有关的问题
            - if \[ $timeofday = "yes" \] and if \[ "$timeofday" = "yes" \]
        - 4.for语句
            - [for_statement.sh](/Chapter1/2.6.3/for_statement.sh)
        - 5.while语句
            - [while_statement.sh](/Chapter1/2.6.3/while_statement.sh)
        - 6.until语句
            - [until_statement.sh](/Chapter1/2.6.3/until_statement.sh)
        - 7.case语句
            - [case_statement.sh](/Chapter1/2.6.3/case_statement.sh)
        - 8.命令列表
            - AND列表
            - OR列表
            - [and_or_statement.sh](/Chapter1/2.6.3/and_or_statement.sh)
        - 9.语句块
    - 2.6.4 函数
        - [function.sh](/Chapter1/2.6.4/function.sh)
    - 2.6.5 命令
        - 1.break命令
        - 2.:命令
        - 3.continue命令
        - 4..命令
        - 5.echo命令
        - 6.eval命令
        - 7.exec命令
        - 8.exit n命令
        - 9.export命令
        - 10.expr命令
        - 11.printf命令
        - 12.return命令
        - 13.set命令
        - 14.shift命令
        - 15.trap命令
        - 16.unset命令
        - 17.另外两个有用的命令和正则表达式
            - find命令
                - -exec command
            - grep命令
            - 正则表达式
    - 2.6.6 命令的执行
        - 1.算术扩展
            - ${{}}
            - [arithmetic_expansion.sh](/Chapter1/2.6.6/arithmetic_expansion.sh)
        - 2.参数扩展
            - ${}
            - [para_expansion.sh](/Chapter1/2.6.6/para_expansion.sh)
    - 2.6.7 here文档
        - [here.sh](/Chapter1/2.6.7/here.sh)
    - 2.6.8 调试脚本程序

- 2.7 迈向图形化：dialog工具
    - [dialog_tool.sh](/Chapter1/2.7/dialog_tool.sh)
    - [questions.sh](/Chapter1/2.7/questions.sh)

- 2.8 综合应用
    - 2.8.1 需求
    - 2.8.2 设计
    - 2.8.3 应用程序的说明
    - [cd.sh](/Chapter1/2.8/cd.sh)

- 2.9 小结

## 第三章 文件操作
- 3.1 Linux文件结构
    - 3.1.1 目录
        - inode(节点)，文件系统中的一个特殊数据块，包含文件的长度和文件在磁盘的位置
        - 目录中每个数据项都是指向某个文件节点的链接
        - 删除一个文件实质是删除文件对应的目录项，同时链接数减一
    - 3.1.2 文件和设备
- 3.2 系统调用和设备驱动程序
- 3.3 库函数
    - 使用系统调用会影响系统的性能
    - 硬件会限制底层系统调用一次所能读写的数据块大小
- 3.4 底层文件访问
    - 3.4.1 write系统调用
    - 3.4.2 read系统调用
    - 3.4.3 open系统调用
        - 两个进程同时打开一个文件，得到两个不同的文件描述符，各写各的，彼此覆盖
        - O_EXCL: open调用是原子操作，这个可选模式防止两个程序同时创建同一个文件
            - 在 Linux和其他Unix系统中,O_EXCL是open系统调用的一个打开文件标志。它的作用是确保当文件被打开时,该文件必须不存在。也就是说:
                1. 如果指定的文件不存在,则正常打开该文件。这相当于创建一个新文件。
                2. 如果指定的文件已经存在,则open调用会失败,并返回一个错误码(通常是EEXIST)。
                O_EXCL标志通常用于以下情况:
                    1. 当多个进程同时可能创建某个文件时,O_EXCL可以用来避免覆盖已有文件。
                    2. 作为一个简单的文件锁机制,确保同一时间只有一个进程打开某个文件。
                    3. 当程序需要一个唯一的临时文件名时,可以先用O_EXCL尝试打开,如果失败再生成一个不同的文件名。
                    4. 当需要一个原子的创建文件操作时,O_EXCL可以避免覆盖已有文件。
                    5. 创建独占锁文件,只允许打开进程访问。
                    总之,O_EXCL提供了一个在打开文件时检测文件存在性的简单机制。需要注意,O_EXCL并不能阻止打开文件后该文件被删除或覆盖。如果需要更强的文件锁,应使用fcntl等接口的锁机制。
    - 3.4.4 访问权限的初始值
        - open和create调用中的权限标志实际上是发出设置文件访问权限的请求，所请求的权限是否会被设置取决于当前的umask值
        - 1.umask
        - 2.close系统调用
            - 检查close调用的返回结果非常重要，特别是网络文件系统
        - 3.ioctl系统调用
        - 文件复制程序
            - [copy_system.c](/Chapter3/3.4/copy_system.c)
    - 3.4.5 其他与文件管理有关的系统调用
        - 1.lseek系统调用
        - 2.fstat、stat和lstat系统调用
            - struct stat
                - st_mode 文件权限和文件类型信
                - ...
            - [stat.c](/Chapter3/3.4/stat.c)
        - 3.dup和dup2系统调用
            - 复制文件描述符
- 3.5 标准I/O库
    - 在标准I/O库中，与底层文件描述符对应的是流(stream)，它被实现为指向结构FILE的指针
    - 3.5.1 fopen函数
        - 一个进程的可用文件流数量和文件描述符都有（建议）数量限制，文件流数量由stdio.h中FOPEN_MAX限制，Linux默认的FOPEN_MAX是16
        - 最大能同时打开的文件数量由操作系统决定
        - 文件流数量和文件描述符数量是分开计算的,这两者之间并没有直接关系。
        
        文件描述符(file descriptor)是内核为每个打开的文件分配的一个整数值,用来标识不同打开的文件。这个数量受限于每个进程的最大打开文件描述符数目。
        
        而文件流(file stream)是标准C库提供的向文件读写的抽象概念,是建立在文件描述符之上的更高级的概念。FILE* 在程序中是表示文件流的对象。
        
        文件流并不需要与文件描述符一一对应。多个文件流可以共享同一个文件描述符,也就是多个FILE* 指针指向同一个文件描述符。所以一个进程中文件流的数量可以远远大于文件描述符数量。
        
        另一方面,文件描述符也可以不与文件流关联,直接通过read/write等系统调用进行访问。
        
        总结来说,文件描述符是内核级的对打开文件的标识;文件流是程序级的对文件读写的抽象。两者可以关联,但数量上是分开计算的。增加文件描述符限制不会直接影响可用文件流数量。
        所以文件流与文件描述符是两个不同的概念,数量无直接关联。但文件流需要基于文件描述符才能正常访问文件。
    - 3.5.2 fread函数
    - 3.5.3 fwrite函数
        - 不推荐把fread和fwrite用于结构化数据
    - 3.5.4 fclose函数
    - 3.5.5 fflush函数
        - fflush 只是强制把缓冲区的内容写入内核的页缓存(page cache),但不一定会立即把数据写入磁盘。
        具体来说,fflush 的工作原理是:
            1. 将用户空间(用户程序)的文件流缓冲区的数据,写入内核缓冲区(page cache)。
            2. 然后内核可以随时根据策略把page cache的数据写入磁盘。
            3. fflush 返回表示用户空间的数据已写入内核缓冲区,但不保证数据已经写入磁盘。
            4. 若需要确保数据写入磁盘,需要调用 fsync 或 fdatasync。
            所以 fflush 只能保证把缓冲区的数据写入内核,而不能保证数据写入磁盘。它主要用于清空用户空间的文件流缓冲区。
            若要确保重要数据落盘,应该在调用 fflush 后再调用 fsync/fdatasync,以保证内核缓冲区的数据被写入磁盘。
    - 3.5.6 fseek函数
    - 3.5.7 fgetc、getc和getchar函数
        - 从文件流中取出下一个字节
    - 3.5.8 fputs、puts和putchar函数
        - 把一个字符写到一个输出文件流中
    - 3.5.9 fgets和gets函数
        - fgets把读到的字符写到s指向的字符串中，直到出现下面某种情况：遇到换行符，已经传输了n-1个字符，或者到达文件尾
        - 如果文件已经到达末尾，fgets会设置这个文件流(FILE)的EOF标识并返回空指针
- 3.6 格式化输入输出
    - 3.6.1 printf、fprintf和sprintf
    - 3.6.2 scanf、fscanf和sscanf
    - 3.6.3 其他流函数
        - [f_copy_system.c](/Chapter3/3.4/f_copy_system.c)
    - 3.6.4 文件流错误
        - 每个线程都有自己的errno
    - 3.6.5 文件流和文件描述符
        - fdopen实质上是为一个已经打开的文件描述符提供stdio缓冲区
- 3.7 文件和目录的维护
    - 3.7.1 chmod系统调用
    - 3.7.2 chown系统调用
    - 3.7.3 unlink、link和symlink系统调用
        - 如果一个文件链接数减少到零，并且没有进程打开它，这个文件就会删除（目录总是立刻被删除）。但文件所占用得空间要等到最后一个进程关闭它后才会被系统回收。
        - 先用open创建一个文件，然后对其调用unlink是某些程序员用来创建临时文件的技巧。这些文件只有在被打开的时候才能被程序使用，但程序退出并且文件关闭的时候它们就会被自动删除掉。
    - 3.7.4 mkdir和rmdir系统调用
    - 3.7.5 chdir系统调用和getcwd函数
- 3.8 扫描目录
    - dirent.h，DIR，目录流（DIR*）
    - 3.8.1 opendir函数
    - 3.8.2 readdir函数
    - 3.8.3 telldir函数
    - 3.8.4 seekdir函数
    - 3.8.5 closedir函数
    - [printdir.c](/Chapter3/3.8/printdir.c) 
- 3.9 错误处理
    - 程序必须在函数报告出错之后立刻检查errno变量
    - 3.9.1 strerror函数
    - 3.9.2 perror函数
- 3.10 /proc文件系统
- 3.11 高级主题: fnctl和mmap
    - 3.11.1 fcntl系统调用
        - 操作打开的文件描述符，复制，获取和设置文件描述符标志、获取和设置文件状态标志，以及管理建议性文件锁
    - 3.11.2 mmap函数
        - mmap(内存映射)函数的作用是建立一段可以被两个或更多个程序读写的内存
        - [mmap.c](/Chapter3/3.11/mmap.c)
- 3.12