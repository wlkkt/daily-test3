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


