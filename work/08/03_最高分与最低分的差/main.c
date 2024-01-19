//
//  main.c
//  03_最高分与最低分的差
//  输入n个成绩，求最高分和最低分的差值
//  输入：5
//       90 80 85 95 100
//  输出：20（100-80）


//  方法一
//  先排序，再取排序后的第一个和最后一个，进行减法运算
//#include <stdio.h>
//int main(int argc, const char * argv[])
//{
//    int scoreCount = 0;
//    int i = 0;
//    int j = 0;
//    scanf("%d",&scoreCount);
//    int scoreArray[scoreCount];
//    for(i=0;i<scoreCount;i++)
//    {
//        scanf("%d",&scoreArray[i]);
//    }
//
//    for(i=0;i<scoreCount-1;i++)
//    {
//        for(j=0;j<scoreCount-i-1;j++)
//        {
//            if(scoreArray[j] > scoreArray[j+1])
//            {
//                int tmp = scoreArray[j];
//                scoreArray[j] = scoreArray[j+1];
//                scoreArray[j+1] = tmp;
//            }
//        }
//    }
//
//    printf("%d\n",scoreArray[scoreCount-1] - scoreArray[0]);
//    return 0;
//}


//  方法二
//  不用排序，取最大值遍历一次数组，取最小值遍历一次数组
//#include <stdio.h>
//int main()
//{
//    int scoreCount = 0;
//    int i = 0;
//    scanf("%d",&scoreCount);
//    int scoreArray[scoreCount];
//    for(i=0;i<scoreCount;i++)
//    {
//        scanf("%d",&scoreArray[i]);
//    }
//
//    int max = scoreArray[0];
//    for(i=0;i<scoreCount;i++)
//    {
//        if(scoreArray[i] > max)
//        {
//            max = scoreArray[i];
//        }
//    }
//
//    int min = scoreArray[0];
//    for(i=0;i<scoreCount;i++)
//    {
//        if(scoreArray[i] < min)
//        {
//            min = scoreArray[i];
//        }
//    }
//
//    printf("%d\n",max-min);
//    return 0;
//}

//  方法三
//  不用排序，直接遍历一次数组，一起取出最大值和最小值
//#include <stdio.h>
//int main()
//{
//    int scoreCount = 0;
//    int i = 0;
//    scanf("%d",&scoreCount);
//    int scoreArray[scoreCount];
//    for(i=0;i<scoreCount;i++)
//    {
//        scanf("%d",&scoreArray[i]);
//    }
//
//    int max = scoreArray[0];
//    int min = scoreArray[0];
//    for(i=0;i<scoreCount;i++)
//    {
//        if(scoreArray[i] > max)
//        {
//            max = scoreArray[i];
//        }
//        if(scoreArray[i] < min)
//        {
//            min = scoreArray[i];
//        }
//    }
//
//    printf("%d\n",max-min);
//    return 0;
//}

//  方法四
//  不用排序，直接在输入数据的时候取出最大值和最小值
#include <stdio.h>
int main()
{
    int scoreCount = 0;
    int i = 0;
    scanf("%d",&scoreCount);
    int scoreArray[scoreCount];
    int max = 0;
    int min = 100;
    for(i=0;i<scoreCount;i++)
    {
        scanf("%d",&scoreArray[i]);
        if(scoreArray[i] > max)
            max = scoreArray[i];
        if(scoreArray[i] < min)
            min = scoreArray[i];
    }

    printf("%d\n",max-min);
    return 0;
}
