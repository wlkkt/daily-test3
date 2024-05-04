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


myfile:myfile.c
gcc - o $@ $ ^ -std = c99
.PHONY:clean
clean :
rm - rf myfile




//#include <stdio.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <string.h>
//#include <unistd.h>
//
//int main()
//{
//
//	const char* message = "hello Linux file!\n";
//	write(1, message, strlen(message));//尝试直接向代表标准输出流的显示器的1中写入message
//
//
//	// umask(0);//修改默认权限掩码，防止默认权限掩码对我们的设定产生影响
//	//系统调用接口
//	//int fd = open("log.txt",O_WRONLY | O_CREAT | O_TRUNC,0666);//写方式打开,不存在就创建,存在就先清空 
//	// int fd1 = open("log.txt",O_WRONLY | O_CREAT | O_APPEND,0666);//写方式打开,不存在就创建,存在就追加
//	// int fd2 = open("log.txt",O_WRONLY | O_CREAT ,0666);//写方式打开,不存在就创建,存在就覆盖着写,新内容可能全部覆盖原内容可能只覆盖开头的一部分
//	// if(fd < 0)
//	// {
//	//     perror("open file");
//	//     return 1;
//	// }
//
//	// const char * message = "hello Linux file!\n";
//	// write(fd,message,strlen(message));//向文件中写的时候不需要加\0
//
//	// close(fd);
//	// return 0;
//}

//#include <stdio.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <string.h>
//#include <unistd.h>
//#include <stdlib.h>
//
//const char* filename = "log.txt";
//
//int main()
//{
//    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);//此时该文件的文件描述符应该为1
//    dup2(fd, 1);//此时文件描述符1所关联的文件就是fd中存放的值所关联的文件，二者同时关联同一文件
//
//
//    printf("printf, fd: %d\n", fd);
//    fprintf(stdout, "fprintf, fd: %d\n", fd);
//
//    return 0;
//}

//
//// 对头出队列
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//
//	assert(pq->phead);
//
//	QNode* del = pq->phead;
//	pq->phead = pq->phead->next;
//	free(del);
//	del = NULL;
//
//	if (pq->phead == NULL)
//		pq->ptail = NULL;
//
//	pq->size--;
//}



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//
//    struct ListNode* reverseList(struct ListNode* head) {
//    struct ListNode* pre = NULL;
//    struct ListNode* cur = head;
//    while (cur) {
//        struct ListNode* next = cur->next;
//        cur->next = prev;
//        pre = curr;
//        cur = next;
//    }
//    return pre;
//}
//
//
//
//    //当传入的两个链表其中有一个为空，那么返回另一个链表即可
//    if (list1 == NULL)
//    {
//        return list2;
//    }
//    if (list2 == NULL)
//    {
//        return list1;
//    }
//
//
//
//    int removeDuplicates(int* nums, int numsSize)
//    {
//
//        int fast = 1, slow = 1;
//
//        while (fast < numsSize)
//        {
//            if (nums[fast] != nums[fast - 1])
//            {
//                nums[slow] = nums[fast];
//                ++slow;
//            }
//            ++fast;
//        }
//        return slow;
//    }
//
//
//    int removeElement(int* nums, int numsSize, int val)
//    {
//        int left = 0, right = numsSize;
//        while (left < right)
//        {
//            if (nums[left] == val)
//            {
//                nums[left] = nums[right - 1];
//                right--;
//            }
//            else
//            {
//                left++;
//            }
//        }
//        return left;
//    }
