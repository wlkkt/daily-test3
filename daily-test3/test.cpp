//////////////////////////////////////////////////////int字节大小
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	printf("%d\n", sizeof(int));		        //4字节（vs的x86和x32环境种都为4字节）
//	printf("%d\n", sizeof(unsigned int));		//4字节  
//	printf("%d\n", sizeof(short));		        //2字节
//	printf("%d\n", sizeof(unsigned short));		//2字节
//	printf("%d\n", sizeof(long));		        //4字节
//	printf("%d\n", sizeof(unsigned long));		//4字节
//	printf("%d\n", sizeof(char));		        //1字节
//	printf("%d\n", sizeof(unsigned char));		//1字节
//	printf("%d\n", sizeof(long long));	        //8字节
//	printf("%d\n", sizeof(float));	            //4字节
//	printf("%d\n", sizeof(double));	            //8字节
//	printf("%d\n", sizeof(long double));	    //8字节
//	return 0;
//}


/////////////////////////////////////////////////////////linux中的非阻塞等待队列
//#include <stdio.h>
//#include <stdlib.h>
//#include <sys/types.h>
//#include <sys/wait.h>
//#include <unistd.h>
//
////子进程执行五秒后退出
//void ChildRun()
//{
//	int cnt = 5;
//	while (cnt)
//	{
//		printf("i am child process, pid: %d, ppid: %d, cnt: %d\n", getpid(), getppid(), cnt);
//		sleep(1);
//		cnt--;
//	}
//}
//
//int main()
//{
//
//	printf("i am father process, pid: %d, ppid: %d\n", getpid(), getppid());
//	pid_t id = fork();
//	if (id == 0)
//	{
//		//child
//		ChildRun();
//		printf("child quit ...\n");//打印子进程退出
//		exit(100);
//	}
//	    //father
//      while(1)//阻塞轮询
//      {
//        int status = 0;
//        pid_t rid = waitpid(id,&status,WNOHANG);//选择非阻塞等待
//        if(rid == 0)//子进程尚未退出，需要父进程频繁等待
//        {
//            sleep(1);                                                                                                    0             printf("child is running,please father check next time!\n");//父进程接着去做自己的一些事情
//        }
//        else if(rid > 0)//子进程成功返回，但是我们想知道退出码是多少
//        {
//            if(WIFEXITED(status))//检测子进程是否是正常返回的（未受信号干扰）
//            {
//                 printf("child quit success, child exit codee : %d\n",WEXITSTATUS(status));//如果子进程是正常返回的获取它>    的退出码
//            }
//            else//如果子进程是因为信号导致的，打印子进程异常返回
//            {
//                 printf("child quit unnormal!\n");
//            }
//            break;//直接退出
//        }
//        else
//        {
//            printf("waitpid failed!\n");//子进程等待失败
//            break;
//        }
//      }    
//
//  }


// #include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>
//#include <sys/types.h>
//#include <sys/wait.h>
//int main()
//{
//    printf("test.c begin ...!\n");
//
//
//    pid_t id = fork();
//    if (id == 0)
//    {
//        sleep(2);
//
//        char* const argv[] =
//        {
//            (char*)"ls",
//              (char*)"-l",
//               (char*)"-a",
//                (char*)"--color",
//             NULL
//        };
//
//        char* const envp[] =
//        {
//            (char*)"HELLO=123456",//自定义环境变量HELLO                                                     
//  (char*)"WORLD=789101",//自定义环境变量WORLD
//            NULL
//        };
//
//
//        //child
//        //execl("/usr/bin/ls","ls",NULL);
//       //execv("/usr/bin/ls",argv);//向ls程序的main函数输入命令行参数
//      //execvp("ls",argv);//向ls程序的main函数输入命令行参数,只需要告诉要执行程序的名称，编译器自动寻找路>      径
//
//        execvpe("/usr/bin/ls", argv, envp);
//
//    }
//
