//////////////////////////////////////////////////////int�ֽڴ�С
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	printf("%d\n", sizeof(int));		        //4�ֽڣ�vs��x86��x32�����ֶ�Ϊ4�ֽڣ�
//	printf("%d\n", sizeof(unsigned int));		//4�ֽ�  
//	printf("%d\n", sizeof(short));		        //2�ֽ�
//	printf("%d\n", sizeof(unsigned short));		//2�ֽ�
//	printf("%d\n", sizeof(long));		        //4�ֽ�
//	printf("%d\n", sizeof(unsigned long));		//4�ֽ�
//	printf("%d\n", sizeof(char));		        //1�ֽ�
//	printf("%d\n", sizeof(unsigned char));		//1�ֽ�
//	printf("%d\n", sizeof(long long));	        //8�ֽ�
//	printf("%d\n", sizeof(float));	            //4�ֽ�
//	printf("%d\n", sizeof(double));	            //8�ֽ�
//	printf("%d\n", sizeof(long double));	    //8�ֽ�
//	return 0;
//}


/////////////////////////////////////////////////////////linux�еķ������ȴ�����
//#include <stdio.h>
//#include <stdlib.h>
//#include <sys/types.h>
//#include <sys/wait.h>
//#include <unistd.h>
//
////�ӽ���ִ��������˳�
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
//		printf("child quit ...\n");//��ӡ�ӽ����˳�
//		exit(100);
//	}
//	    //father
//      while(1)//������ѯ
//      {
//        int status = 0;
//        pid_t rid = waitpid(id,&status,WNOHANG);//ѡ��������ȴ�
//        if(rid == 0)//�ӽ�����δ�˳�����Ҫ������Ƶ���ȴ�
//        {
//            sleep(1);                                                                                                    0             printf("child is running,please father check next time!\n");//�����̽���ȥ���Լ���һЩ����
//        }
//        else if(rid > 0)//�ӽ��̳ɹ����أ�����������֪���˳����Ƕ���
//        {
//            if(WIFEXITED(status))//����ӽ����Ƿ����������صģ�δ���źŸ��ţ�
//            {
//                 printf("child quit success, child exit codee : %d\n",WEXITSTATUS(status));//����ӽ������������صĻ�ȡ��>    ���˳���
//            }
//            else//����ӽ�������Ϊ�źŵ��µģ���ӡ�ӽ����쳣����
//            {
//                 printf("child quit unnormal!\n");
//            }
//            break;//ֱ���˳�
//        }
//        else
//        {
//            printf("waitpid failed!\n");//�ӽ��̵ȴ�ʧ��
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
//            (char*)"HELLO=123456",//�Զ��廷������HELLO                                                     
//  (char*)"WORLD=789101",//�Զ��廷������WORLD
//            NULL
//        };
//
//
//        //child
//        //execl("/usr/bin/ls","ls",NULL);
//       //execv("/usr/bin/ls",argv);//��ls�����main�������������в���
//      //execvp("ls",argv);//��ls�����main�������������в���,ֻ��Ҫ����Ҫִ�г�������ƣ��������Զ�Ѱ��·>      ��
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
//	write(1, message, strlen(message));//����ֱ��������׼���������ʾ����1��д��message
//
//
//	// umask(0);//�޸�Ĭ��Ȩ�����룬��ֹĬ��Ȩ����������ǵ��趨����Ӱ��
//	//ϵͳ���ýӿ�
//	//int fd = open("log.txt",O_WRONLY | O_CREAT | O_TRUNC,0666);//д��ʽ��,�����ھʹ���,���ھ������ 
//	// int fd1 = open("log.txt",O_WRONLY | O_CREAT | O_APPEND,0666);//д��ʽ��,�����ھʹ���,���ھ�׷��
//	// int fd2 = open("log.txt",O_WRONLY | O_CREAT ,0666);//д��ʽ��,�����ھʹ���,���ھ͸�����д,�����ݿ���ȫ������ԭ���ݿ���ֻ���ǿ�ͷ��һ����
//	// if(fd < 0)
//	// {
//	//     perror("open file");
//	//     return 1;
//	// }
//
//	// const char * message = "hello Linux file!\n";
//	// write(fd,message,strlen(message));//���ļ���д��ʱ����Ҫ��\0
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
//    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);//��ʱ���ļ����ļ�������Ӧ��Ϊ1
//    dup2(fd, 1);//��ʱ�ļ�������1���������ļ�����fd�д�ŵ�ֵ���������ļ�������ͬʱ����ͬһ�ļ�
//
//
//    printf("printf, fd: %d\n", fd);
//    fprintf(stdout, "fprintf, fd: %d\n", fd);
//
//    return 0;
//}

//
//// ��ͷ������
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
//    //���������������������һ��Ϊ�գ���ô������һ��������
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
